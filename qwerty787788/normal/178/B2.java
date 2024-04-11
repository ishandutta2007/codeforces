import java.util.*;
import java.io.*;

public class Solution {
	FastScanner in;
	PrintWriter out;

	int N, M, K, co = 0;
	compa[] xx;
	boolean[] used;
	city[] g;
	
	class city {
		ArrayList<Integer> roads;
		ArrayList<Integer> bridges;
		int comp;
	}
	
	class compa {
		ArrayList<Integer> r;
		ArrayList<Integer> g;
		int id;
	}
	
	void IS_BRIDGE(int v, int to) {
		g[v].bridges.add(to);
		g[to].bridges.add(v);
	}
	
	int timer;
	int[] tin;
	int[] fup;
	 
	void dfs (int v, int p) {
		used[v] = true;
		tin[v] = fup[v] = timer++;
		for (int i = 0; i < g[v].roads.size(); ++i) {
			int to = g[v].roads.get(i);
			if (to == p)  continue;
			if (used[to])
				fup[v] = Math.min(fup[v], tin[to]);
			else {
				dfs (to, v);
				fup[v] = Math.min (fup[v], fup[to]);
				if (fup[to] > tin[v])
					IS_BRIDGE(v,to);
			}
		}
	}
	
	void dfs2 (int v, int co) {
		g[v].comp = co;
		for (int i = 0; i < g[v].roads.size(); i++) {
			int to = g[v].roads.get(i);
			if (g[to].comp == 0) {
				g[to].comp = co;
				dfs2(to, co);
			}
		}
	}
	
	void dfs3 (int v, int id) {
		xx[v].id = id;
		for (int i = 0; i < xx[v].r.size(); i++) {
			int to = xx[v].r.get(i);
			if (xx[to].id == 0) {
				xx[v].g.add(to);
				dfs3(to, id + 1);
			}
		}
	}
	
	//
	int l;
	int[] tin2;
	int[] tout2;
	int timer2;
	int[][] up2;
	
	void dfs4 (int v, int p) {
		tin2[v] = ++timer2;
		up2[v][0] = p;
		for (int i=1; i<=l; ++i)
			up2[v][i] = up2[up2[v][i-1]][i-1];
		for (int i=0; i<xx[v].g.size(); ++i) {
			int to = xx[v].g.get(i);
			if (to != p)
				dfs4 (to, v);
		}
		tout2[v] = ++timer2;
	}

	boolean upper2 (int a, int b) {
		return tin2[a] <= tin2[b] && tout2[a] >= tout2[b];
	}

	int lca (int a, int b) {
		if (upper2 (a, b))  return a;
		if (upper2 (b, a))  return b;
		for (int i = l; i>=0; --i)
			if (! upper2 (up2[a][i], b))
				a = up2[a][i];
		return up2[a][0];
	}
	
	//
	
	
	public void solve() throws IOException {
		N = in.nextInt();
		g = new city[N];
		used = new boolean[N];
		tin = new int[N];
		fup = new int[N];
		for (int i = 0; i < N; i++) {
			g[i] = new city();
			g[i].roads = new ArrayList<Integer>();
			g[i].bridges = new ArrayList<Integer>();
		}
		M = in.nextInt();
		for (int i = 0; i < M; i++) {
			int x = in.nextInt();
			int y = in.nextInt();
			g[x - 1].roads.add(y - 1);
			g[y - 1].roads.add(x - 1);
		}
		
		for (int i = 0; i < N; ++i)
			used[i] = false;
		timer = 0;
		for (int i=0; i < N; ++i)
			if (!used[i])
				dfs (i, -1);
		
		for (int i = 0; i < N; i++) {
			int[] tmp = new int[g[i].bridges.size()];
			for (int j = 0; j < g[i].bridges.size(); j++)
				tmp[j] = g[i].bridges.get(j);
			Arrays.sort(tmp);
			g[i].bridges = new ArrayList<Integer>();
			for (int j = 0; j < tmp.length; j++)
				g[i].bridges.add(tmp[j]);
			
			tmp = new int[g[i].roads.size()];
			for (int j = 0; j < g[i].roads.size(); j++)
				tmp[j] = g[i].roads.get(j);
			Arrays.sort(tmp);
			int uk = 0;
			g[i].roads = new ArrayList<Integer>();
			for (int j = 0; j < tmp.length; j++) {
				while (uk != g[i].bridges.size() && g[i].bridges.get(uk) < tmp[j]) uk++;
				if (uk == g[i].bridges.size() || (int)g[i].bridges.get(uk) != tmp[j]) 
					g[i].roads.add(tmp[j]);
			}
		}
		
		for (int i = 0; i < N; i++) {
			if (g[i].comp == 0) {
				++co;
				dfs2(i, co);
			}
		}
		
		xx = new compa[co];
		for (int i = 0; i < co; i++) {
			xx[i] = new compa();
			xx[i].r = new ArrayList<Integer>();
			xx[i].g = new ArrayList<Integer>();
		}
		
		for (int i = 0; i < N; i++) {
			int c = g[i].comp - 1;
			for (int j = 0; j < g[i].bridges.size(); j++) {
				int to = g[g[i].bridges.get(j)].comp - 1;
				xx[c].r.add(to);
			}
		}
		
		int from = 0;
		for (int i = 0; i < co; i++) {
			if (xx[i].r.size() <= 1) {
				dfs3(i, 1);
				from = i;
				break;
			}
		}
		
		int n = xx.length;
		tin2 = new int[n];
		tout2 = new int[n];
		up2 = new int[n][];
		l = 1;
		while ((1<<l) <= n)  ++l;
		for (int i=0; i<n; ++i) up2[i] = new int[l + 1];
		dfs4 (from, from);
		
		K = in.nextInt();
		for (int i = 0; i < K; i++) {
			int x = in.nextInt();
			int y = in.nextInt();
			int c1 = g[x - 1].comp - 1;
			int c2 = g[y - 1].comp - 1;
			int lc = lca(c1, c2);
			int res = (xx[c1].id - xx[lc].id) + (xx[c2].id - xx[lc].id);
			out.println(res);
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
	}

	public static void main(String[] arg) {
		new Solution().run();
	}
}