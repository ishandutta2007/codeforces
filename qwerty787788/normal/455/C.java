import java.awt.geom.Area;
import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	class Dsu {
		int n;
		int[] p;
		int[] d;

		Dsu(int n) {
			this.n = n;
			p = new int[n];
			for (int i = 0; i < n; i++) {
				p[i] = i;
			}
			d = new int[n];
		}

		int get(int v) {
			return p[v] == v ? p[v] : (p[v] = get(p[v]));
		}

		void union(int v, int u) {
			v = get(v);
			u = get(u);
			if (v == u)
				return;
			p[u] = v;
			d[v] = un(d[v], d[u]);
		}

		int un(int d1, int d2) {
			int l1 = (1 + d1) / 2;
			int l2 = (1 + d2) / 2;
			return Math.max(Math.max(d1, d2), l1 + l2 + 1);
		}
	}

	final int MAX = (int) 1e6;
	int[] q = new int[MAX];

	void bfs(int[] dist, int from, ArrayList<Integer> used,
			ArrayList<Integer>[] g, int[] color, int curColor) {
		int sz = 1, it = 0;
		q[0] = from;
		dist[from] = 0;
		while (it < sz) {
			int v = q[it++];
			used.add(v);
			color[v] = curColor;
			for (int to : g[v]) {
				if (dist[to] == -1) {
					dist[to] = dist[v] + 1;
					q[sz++] = to;
				}
			}
		}
	}

	void solve() {
		int n = in.nextInt();
		int m = in.nextInt();
		int q = in.nextInt();
		ArrayList<Integer>[] g = new ArrayList[n];
		for (int i = 0; i < n; i++) {
			g[i] = new ArrayList<>();
		}
		for (int i = 0; i < m; i++) {
			int x = in.nextInt() - 1, y = in.nextInt() - 1;
			g[x].add(y);
			g[y].add(x);
		}
		int[] color = new int[n];
		Arrays.fill(color, -1);
		int cntColors = 0;
		int[] dist = new int[n];
		Arrays.fill(dist, -1);
		ArrayList<Integer> used = new ArrayList<>();
		ArrayList<Integer> lengths = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			if (color[i] == -1) {
				used.clear();
				bfs(dist, i, used, g, color, cntColors);
				int maxId = i;
				for (int to : used) {
					if (dist[to] > dist[maxId])
						maxId = to;
				}
				for (int to : used) {
					dist[to] = -1;
				}
				used.clear();
				bfs(dist, maxId, used, g, color, cntColors++);
				int maxLen = 0;
				for (int to : used) {
					maxLen = Math.max(maxLen, dist[to]);
				}
				lengths.add(maxLen);
			}
		}
		Dsu dsu = new Dsu(lengths.size());
		for (int i = 0; i < lengths.size(); i++) {
			dsu.d[i] = lengths.get(i);
		}
		for (int qq = 0; qq < q; qq++) {
			if (in.nextInt() == 1) {
				out.println(dsu.d[dsu.get(color[in.nextInt() - 1])]);
			} else {
				dsu.union(color[in.nextInt() - 1], color[in.nextInt() - 1]);
			}
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
		new CF().runIO();
	}
}