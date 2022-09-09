import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	class Edge {
		int to;
		Edge rev;
		boolean isBridge;

		public Edge(int to) {
			super();
			this.to = to;
		}

	}

	ArrayList<Edge>[] g;
	boolean[] was;
	int time;
	int[] tin, fup;

	void dfs(int v, Edge prev) {
		was[v] = true;
		tin[v] = fup[v] = time++;
		for (int i = 0; i < g[v].size(); ++i) {
			Edge e = g[v].get(i);
			int to = e.to;
			if (e.rev == prev) {
				continue;
			}
			if (was[to]) {
				fup[v] = Math.min(fup[v], tin[to]);
			} else {
				dfs(to, e);
				fup[v] = Math.min(fup[v], fup[to]);
				if (fup[to] > tin[v]) {
					e.isBridge = true;
					e.rev.isBridge = true;
				}
			}
		}
	}

	int[] ids;

	void go(int v, int newId) {
		ids[v] = newId;
		for (Edge e : g[v]) {
			if (e.isBridge || ids[e.to] != -1) {
				continue;
			}
			go(e.to, newId);
		}
	}

	int[] parent;
	ArrayList<Integer>[] g2;
	final int MAX = 20;
	int[] h;
	int[][] up;

	void go2(int v, int p, int ch) {
		parent[v] = p;
		h[v] = ch;
		for (int to : g2[v]) {
			if (to != p) {
				go2(to, v, ch + 1);
			}
		}
	}

	int[][] upType;

	// 0 - undef
	// 1 - up
	// 2 - down

	int lca(int x, int y) {
		if (h[x] > h[y]) {
			int tmp = x;
			x = y;
			y = tmp;
		}
		for (int i = MAX - 1; i >= 0; i--) {
			if (h[up[i][y]] >= h[x]) {
				y = up[i][y];
			}
		}
		for (int i = MAX - 1; i >= 0; i--) {
			if (up[i][x] != up[i][y]) {
				x = up[i][x];
				y = up[i][y];
			}
		}
		if (x == y) {
			return x;
		}
		return up[0][x];
	}

	void solve() {
		int n = in.nextInt();
		int m = in.nextInt();
		int q = in.nextInt();
		g = new ArrayList[n];
		for (int i = 0; i < n; i++) {
			g[i] = new ArrayList<>();
		}
		for (int i = 0; i < m; i++) {
			int fr = in.nextInt() - 1;
			int to = in.nextInt() - 1;
			Edge e1 = new Edge(to);
			Edge e2 = new Edge(fr);
			e1.rev = e2;
			e2.rev = e1;
			g[fr].add(e1);
			g[to].add(e2);
		}
		was = new boolean[n];
		time = 0;
		tin = new int[n];
		fup = new int[n];
		for (int i = 0; i < n; i++) {
			if (was[i]) {
				continue;
			}
			dfs(i, null);
		}

		ids = new int[n];
		Arrays.fill(ids, -1);
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (ids[i] == -1) {
				go(i, cnt++);
			}
		}
		g2 = new ArrayList[cnt];
		for (int i = 0; i < cnt; i++) {
			g2[i] = new ArrayList<>();
		}
		for (int i = 0; i < n; i++) {
			for (Edge e : g[i]) {
				if (e.isBridge) {
					g2[ids[i]].add(ids[e.to]);
				}
			}
		}
		parent = new int[cnt];
		Arrays.fill(parent, -1);
		h = new int[cnt];
		for (int i = 0; i < parent.length; i++) {
			if (parent[i] == -1) {
				go2(i, i, 0);
			}
		}
		up = new int[MAX][cnt];
		for (int i = 0; i < cnt; i++) {
			up[0][i] = parent[i];
		}
		for (int i = 1; i < MAX; i++) {
			for (int v = 0; v < cnt; v++) {
				up[i][v] = up[i - 1][up[i - 1][v]];
			}
		}
		upType = new int[MAX][cnt];
		for (int i = 0; i < q; i++) {
			int fr = ids[in.nextInt() - 1];
			int to = ids[in.nextInt() - 1];
			if (fr == to) {
				continue;
			}
			if (up[MAX - 1][fr] != up[MAX - 1][to]) {
				out.println("No");
				return;
			}
			int lca = lca(fr, to);
			if (!mark(fr, lca, 1)) {
				out.println("No");
				return;
			}
			if (!mark(to, lca, 2)) {
				out.println("No");
				return;
			}
		}
		for (int i = MAX - 1; i > 0; i--) {
			for (int v = 0; v < cnt; v++) {
				if (upType[i][v] != 0) {
					int xx = up[i - 1][v];
					{
						if (upType[i - 1][v] == 0) {
							upType[i - 1][v] = upType[i][v];
						} else {
							if (upType[i - 1][v] != upType[i][v]) {
								out.println("No");
								return;
							}
						}
					}
					{
						if (upType[i - 1][xx] == 0) {
							upType[i - 1][xx] = upType[i][v];
						} else {
							if (upType[i - 1][xx] != upType[i][v]) {
								out.println("No");
								return;
							}
						}
					}
				}
			}
		}
		out.println("Yes");
	}

	boolean mark(int from, int to, int needType) {
		int needH = h[to];
		for (int i = MAX - 1; i >= 0; i--) {
			int next = up[i][from];
			if (h[next] >= needH && h[next] > 0) {
				if (upType[i][from] == 0) {
					upType[i][from] = needType;
				} else {
					if (upType[i][from] != needType) {
						return false;
					}
				}
				from = next;
			}
		}
		if (needH == 0 && h[from] != 0) {
			if (upType[0][from] == 0) {
				upType[0][from] = needType;
			} else {
				if (upType[0][from] != needType) {
					return false;
				}
			}
		}
		return true;
	}

	void runIO() {

		in = new FastScanner(System.in);
		out = new PrintWriter(System.out);

		solve();

		out.close();
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

		double nextDouble() {
			return Double.parseDouble(next());
		}
	}

	public static void main(String[] args) {
		new CF().runIO();
	}
}