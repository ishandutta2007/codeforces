import java.util.*;
import java.io.*;

public class Solution {
	FastScanner in;
	PrintWriter out;

	class road {
		int to, id;
		road(int to, int id) {
			this.to = to;
			this.id = id;
		}
	}
	
	int n;
	ArrayList<road>[] g;
	long r[];
	int stat[];
	
	int l;
	int tin[], tout[];
	int timer;
	int up[][];
	
	void dfs (int v, int p) {
		tin[v] = ++timer;
		up[v][0] = p;
		for (int i=1; i<=l; ++i)
			up[v][i] = up[up[v][i-1]][i-1];
		for (int i=0; i<g[v].size(); ++i) {
			int to = g[v].get(i).to;
			if (to != p)
				dfs (to, v);
		}
		tout[v] = ++timer;
	}
	
	boolean upper (int a, int b) {
		return tin[a] <= tin[b] && tout[a] >= tout[b];
	}
	
	int lca (int a, int b) {
		if (upper (a, b))  return a;
		if (upper (b, a))  return b;
		for (int i=l; i>=0; --i)
			if (! upper (up[a][i], b))
				a = up[a][i];
		return up[a][0];
	}
	
	long rec(int v, int p) {
		long sum = stat[v];
		for (int i = 0; i < g[v].size(); i++) {
			if (g[v].get(i).to != p) {
				long x = rec(g[v].get(i).to, v);
				sum += x;
				r[g[v].get(i).id] += x;
			}
		}
		return sum;
	}
	
	public void solve() throws IOException {
		n = in.nextInt();
		g = new ArrayList[n];
		r = new long[n - 1];
		for (int i = 0; i < n; i++)
			g[i] = new ArrayList<Solution.road>();
		for (int i = 0; i < n - 1; i++) {
			int x = in.nextInt() - 1;
			int y = in.nextInt() - 1;
			g[x].add(new road(y, i));
			g[y].add(new road(x, i));
		}
		//
		tin = new int[n];
		tout = new int[n];
		up = new int[n][];
		l = 1;
		while ((1<<l) <= n)  ++l;
		for (int i=0; i<n; ++i)  up[i] = new int[l+1];
		dfs (0, 0);		
		//		
		stat = new int[n];
		int m = in.nextInt();
		for (int i = 0; i < m; i++) {
			int x = in.nextInt() - 1;
			int y = in.nextInt() - 1;
			//
			int lc = lca(x, y);
			stat[x] ++;
			stat[y] ++;
			stat[lc] -= 2;
		}
		rec(0, 0);
		for (int i = 0; i < n - 1; i++) {
			out.print(r[i]);
			out.print(" ");
		}
			
	}

	public void run() {
		try {
			//in = new FastScanner(new File("input.txt"));
			//out = new PrintWriter(new File("output.txt"));

			in = new FastScanner(System.in);
			out = new PrintWriter(System.out);

			solve();

			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		FastScanner(File f) {
			try {
				br = new BufferedReader(new FileReader(f));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		FastScanner(InputStream f) {
			br = new BufferedReader(new InputStreamReader(f));
		}

		String next() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		String nextLine() {
			try {
				return br.readLine();
			} catch (IOException e) {
				e.printStackTrace();
			}
			return null;
		}
	}

	public static void main(String[] arg) {
		new Solution().run();
	}
}