import java.io.*;
import java.util.*;

public class B implements Runnable {
	public static void main(String[] args) {
		new B().run();
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;
		boolean eof;
		String buf;

		public FastScanner(String fileName) throws FileNotFoundException {
			br = new BufferedReader(new FileReader(fileName));
			nextToken();
		}

		public FastScanner(InputStream stream) {
			br = new BufferedReader(new InputStreamReader(stream));
			nextToken();
		}

		String nextToken() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (Exception e) {
					eof = true;
					break;
				}
			}
			String ret = buf;
			buf = eof ? "-1" : st.nextToken();
			return ret;
		}

		int nextInt() {
			return Integer.parseInt(nextToken());
		}

		long nextLong() {
			return Long.parseLong(nextToken());
		}

		double nextDouble() {
			return Double.parseDouble(nextToken());
		}

		void close() {
			try {
				br.close();
			} catch (Exception e) {

			}
		}

		boolean isEOF() {
			return eof;
		}
	}

	FastScanner sc;
	PrintWriter out;

	public void run() {
		Locale.setDefault(Locale.US);
		try {
			sc = new FastScanner(System.in);
			out = new PrintWriter(System.out);
			solve();
			sc.close();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	int nextInt() {
		return sc.nextInt();
	}

	String nextToken() {
		return sc.nextToken();
	}

	long nextLong() {
		return sc.nextLong();
	}

	double nextDouble() {
		return sc.nextDouble();
	}

	class Edge implements Comparable<Edge> {
		int from, to, cost;

		public Edge(int from, int to, int cost) {
			this.from = from;
			this.to = to;
			this.cost = cost;
		}

		@Override
		public int compareTo(Edge o) {
			return cost < o.cost ? -1 : cost > o.cost ? 1 : 0;
		}
	}

	void solve() {
		int n = nextInt();
		for (int i = 0; i < n; i++) {
			nextToken();
		}
		int m = nextInt();
		Edge[] edges = new Edge[m];
		for (int i = 0; i < m; i++) {
			int x = nextInt() - 1;
			int y = nextInt() - 1;
			int z = nextInt();
			edges[i] = new Edge(x, y, z);
		}
		Arrays.sort(edges);
		boolean[] has = new boolean[n];
		int ans = 0;
		int left = n - 1;
		for (int i = 0; i < m && left > 0; i++) {
			if (has[edges[i].to]) {
				continue;
			}
			ans += edges[i].cost;
			--left;
			has[edges[i].to] = true;
		}
		if (left > 0) {
			out.println(-1);
		} else {
			out.println(ans);
		}
	}
}