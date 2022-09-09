import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	class Obj implements Comparable<Obj> {
		int id;
		int dist;

		public Obj(int id, int dist) {
			super();
			this.id = id;
			this.dist = dist;
		}

		@Override
		public int compareTo(Obj o) {
			return Integer.compare(dist, o.dist);
		}

	}

	class Edge {
		int to;
		int cost;

		public Edge(int to, int cost) {
			super();
			this.to = to;
			this.cost = cost;
		}

	}

	void go(int v, long[] dist) {
		for (Edge e : g[v]) {
			if (dist[e.to] == Long.MAX_VALUE) {
				dist[e.to] = dist[v] + e.cost;
				go(e.to, dist);
			}
		}
	}

	ArrayList<Edge>[] g;

	void solve() {
		int n = in.nextInt();
		int[][] d = new int[n][n];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				d[i][j] = in.nextInt();
		Obj[] a = new Obj[n];
		for (int i = 0; i < n; i++) {
			a[i] = new Obj(i, d[0][i]);
		}
		Arrays.sort(a);
		g = new ArrayList[n];
		for (int i = 0; i < n; i++) {
			g[i] = new ArrayList<>();
		}
		boolean[] was = new boolean[n];
		for (int i = n - 1; i > 0; i--) {
			int id = a[i].id;
			int min = Integer.MAX_VALUE, minId = -1;
			for (int j = 0; j < n; j++)
				if (j != id && d[id][j] < min && !was[j]) {
					min = d[id][j];
					minId = j;
				}
			if (min == 0) {
				out.println("NO");
				return;
			}
			g[minId].add(new Edge(id, min));
			g[id].add(new Edge(minId, min));
			was[id] = true;
		}
		long[] dist = new long[n];
		for (int i = 0; i < n; i++) {
			Arrays.fill(dist, Long.MAX_VALUE);
			dist[i] = 0;
			go(i, dist);
			for (int j = 0; j < n; j++) {
				if (dist[j] != d[i][j]) {
					out.println("NO");
					return;
				}
			}
		}
		out.println("YES");
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