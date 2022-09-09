import java.io.*;
import java.util.*;

public class CF148DIV1 {
	FastScanner in;
	PrintWriter out;

	class Road {
		int to;
		boolean real;
		
		public Road(int to, boolean real) {
			super();
			this.to = to;
			this.real = real;
		}
	}
	
	ArrayList<Road>[] g;
	
	boolean[] was;
	int dfs(int v) {
		was[v] = true;
		int res = 0;
		for (int i = 0; i < g[v].size(); i++)
			if (!was[g[v].get(i).to]) {
				if (!g[v].get(i).real) res++;
				res += dfs(g[v].get(i).to);
			}
		return res;
	}
	
	int dfs2(int v, int curNotRealMinusReal) {
		was[v] = true;
		int res = curNotRealMinusReal;
		for (int i = 0; i < g[v].size(); i++)
			if (!was[g[v].get(i).to]) {
				if (g[v].get(i).real) {
					res = Math.max(res, dfs2(g[v].get(i).to, Math.max(0, curNotRealMinusReal - 1)));
				} else {
					res = Math.max(res, dfs2(g[v].get(i).to, Math.max(0, curNotRealMinusReal + 1)));
				}
			}
		return res;
	}

	void solve() {
		int n = in.nextInt();
		g = new ArrayList[n];
		for (int i = 0; i < n; i++)
			g[i] = new ArrayList<Road>();
		for (int i = 0; i < n - 1; i++) {
			int fr = in.nextInt() - 1;
			int to = in.nextInt() - 1;
			g[fr].add(new Road(to, true));
			g[to].add(new Road(fr, false));
		}
		int ans = Integer.MAX_VALUE;
		for (int i = 0; i < n; i++) {
			was = new boolean[n];
			int cost = dfs(i);
			was = new boolean[n];
			cost -= dfs2(i, 0);
			ans = Math.min(ans, cost);			
		}
		out.println(ans);
	}

	void run() {
		try {
			in = new FastScanner(new File("test.in"));
			out = new PrintWriter(new File("test.out"));

			solve();

			out.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
	}

	void runIO() {

		in = new FastScanner(System.in);
		out = new PrintWriter(System.out);

		solve();

		out.close();
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner(File f) {
			try {
				br = new BufferedReader(new FileReader(f));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		public FastScanner(InputStream f) {
			br = new BufferedReader(new InputStreamReader(f));
		}

		String next() {
			while (st == null || !st.hasMoreTokens()) {
				String s = null;
				try {
					s = br.readLine();
				} catch (IOException e) {
					e.printStackTrace();
				}
				if (s == null)
					return null;
				st = new StringTokenizer(s);
			}
			return st.nextToken();
		}

		boolean hasMoreTokens() {
			while (st == null || !st.hasMoreTokens()) {
				String s = null;
				try {
					s = br.readLine();
				} catch (IOException e) {
					e.printStackTrace();
				}
				if (s == null)
					return false;
				st = new StringTokenizer(s);
			}
			return true;
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}
	}

	public static void main(String[] args) {
		new CF148DIV1().runIO();
	}
}