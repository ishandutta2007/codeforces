import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	class Edge implements Comparable<Edge> {
		int fr, to, val;
		boolean ok;

		Edge(int fr, int to, int val) {
			this.fr = fr;
			this.to = to;
			this.val = val;
		}

		@Override
		public int compareTo(Edge o) {
			return Integer.compare(o.val, val);
		}
	}

	int[][] dp;

	boolean go(int v, int p) {
		dp[0][v] = 1;
		dp[1][v] = count[v];
		for (Edge e : g[v]) {
			int to = e.fr + e.to - v;
			if (to == p)
				continue;
			if (!go(to, v))
				return false;
			if (!e.ok) {
				dp[0][v] += dp[0][to];
				dp[1][v] += dp[1][to];
			}
		}
		return dp[0][v] <= totalCount - dp[1][v];
	}

	boolean ok() {
		for (int i = 0; i < 2; i++)
			Arrays.fill(dp[i], 0);
		return go(0, -1);
	}

	ArrayList<Edge>[] g;
	int[] count;
	int totalCount;

	void solve() {
		int n = in.nextInt();
		Edge[] edges = new Edge[n - 1];
		for (int i = 0; i < n - 1; i++) {
			edges[i] = new Edge(in.nextInt() - 1, in.nextInt() - 1,
					in.nextInt());
		}
		count = new int[n];
		for (int i = 0; i < n; i++) {
			count[i] = in.nextInt();
			totalCount += count[i];
		}
		dp = new int[2][n];
		g = new ArrayList[n];
		for (int i = 0; i < n; i++) {
			g[i] = new ArrayList<>();
		}
		for (int i = 0; i < n - 1; i++) {
			Edge e = edges[i];
			g[e.fr].add(e);
			g[e.to].add(e);
		}
		Arrays.sort(edges);
		for (int i = 0; i < n - 1; i++) {
			edges[i].ok = true;
			if (ok()) {
				out.println(edges[i].val);
				return;
			}
		}
		out.println(0);
	}

	void run() {
		try {
			in = new FastScanner(new File("CF.in"));
			out = new PrintWriter(new File("CF.out"));

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
		new CF().runIO();
	}
}