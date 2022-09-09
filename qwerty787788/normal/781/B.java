import java.io.*;
import java.util.*;

public class B {
	FastScanner in;
	PrintWriter out;

	class Edge {
		int fr, to;
		long flow, cap;
		Edge rev;

		Edge(int fr, int to, long cap) {
			this.fr = fr;
			this.to = to;
			this.cap = cap;
		}
	}

	class Flow {
		int n;
		ArrayList<Edge>[] g;

		Flow(int n) {
			this.n = n;
			g = new ArrayList[n];
			for (int i = 0; i < n; i++) {
				g[i] = new ArrayList<>();
			}
			q = new int[n];
			h = new int[n];
			cur = new int[n];
		}

		Edge addEdge(int fr, int to, long cap) {
			Edge e1 = new Edge(fr, to, cap);
			Edge e2 = new Edge(to, fr, 0);
			e1.rev = e2;
			e2.rev = e1;
			g[fr].add(e1);
			g[to].add(e2);
			return e1;
		}

		int[] h;
		int[] cur;
		int[] q;

		boolean bfs() {
			int qIt = 0, qSz = 0;
			q[qSz++] = 0;
			Arrays.fill(h, -1);
			h[0] = 0;
			while (qIt < qSz) {
				int v = q[qIt++];
				for (Edge e : g[v]) {
					if (e.flow == e.cap)
						continue;
					if (h[e.to] == -1) {
						h[e.to] = h[e.fr] + 1;
						q[qSz++] = e.to;
					}
				}
			}
			return h[n - 1] != -1;
		}

		long dfs(int v, long flow) {
			if (v == n - 1 || flow == 0)
				return flow;
			for (; cur[v] < g[v].size(); cur[v]++) {
				Edge e = g[v].get(cur[v]);
				if (h[e.to] != h[e.fr] + 1 || e.flow == e.cap)
					continue;
				long add = dfs(e.to, Math.min(flow, e.cap - e.flow));
				if (add == 0)
					continue;
				e.flow += add;
				e.rev.flow -= add;
				return add;
			}
			return 0;
		}

		long flow() {
			long res = 0;
			while (bfs()) {
				Arrays.fill(cur, 0);
				while (true) {
					long add = dfs(0, Long.MAX_VALUE);
					if (add == 0)
						break;
					res += add;
				}
			}
			return res;
		}
	}

	void solve() {
		int n = in.nextInt();
		String[][] s = new String[n][2];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 2; j++) {
				s[i][j] = in.next();
			}
			s[i][0] = s[i][0].substring(0, 3);
		}
		boolean[] can = new boolean[n];
		int[][] ids = new int[n][2];
		HashMap<String, Integer> hm = new HashMap<>();
		String[] vals = new String[n * 2];
		for (int i = 0; i < n; i++) {
			if (hm.containsKey(s[i][0])) {
				ids[i][0] = hm.get(s[i][0]);
			} else {
				ids[i][0] = hm.size();
				vals[hm.size()] = s[i][0];
				hm.put(s[i][0], hm.size());
			}
			String key2 = s[i][0].substring(0, 2) + s[i][1].charAt(0);
			if (hm.containsKey(key2)) {
				ids[i][1] = hm.get(key2);
			} else {
				ids[i][1] = hm.size();
				vals[hm.size()] = key2;
				hm.put(key2, ids[i][1]);
			}
		}
		for (int i = 0; i < n; i++) {
			can[i] = true;
			for (int j = 0; j < n; j++) {
				if (s[i][0].equals(s[j][0]) && i != j) {
					can[i] = false;
				}
			}
		}
		Flow f = new Flow(1 + n + hm.size() + 1);
		Edge[][] edges = new Edge[2][n];
		for (int i = 0; i < n; i++) {
			f.addEdge(0, 1 + i, 1);
			edges[1][i] = f.addEdge(1 + i, 1 + n + ids[i][1], 1);
			if (can[i]) {
				edges[0][i] = f.addEdge(1 + i, 1 + n + ids[i][0], 1);
			}
		}
		for (int i = 0; i < hm.size(); i++) {
			f.addEdge(1 + n + i, f.n - 1, 1);
		}
		if (f.flow() != n) {
			out.println("NO");
		} else {
			out.println("YES");
			for (int i = 0; i < n; i++) {
				if (edges[1][i].flow == 1) {
					out.println(vals[ids[i][1]]);
				} else {
					out.println(vals[ids[i][0]]);
				}
			}
		}
	}

	void run() {
		try {
			in = new FastScanner(new File("object.in"));
			out = new PrintWriter(new File("object.out"));

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

		double nextDouble() {
			return Double.parseDouble(next());
		}
	}

	public static void main(String[] args) {
		new B().runIO();
	}
}