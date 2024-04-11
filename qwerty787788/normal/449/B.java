import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	class Edge implements Comparable<Edge> {
		int to;
		long cost;

		public Edge(int to, long cost) {
			super();
			this.to = to;
			this.cost = cost;
		}

		@Override
		public int compareTo(Edge o) {
			return Long.compare(cost, o.cost);
		}

	}

	void solve() {
		int n = in.nextInt();
		int m = in.nextInt();
		int k = in.nextInt();
		ArrayList<Edge>[] g = new ArrayList[n];
		ArrayList<Edge>[] g2 = new ArrayList[n];
		for (int i = 0; i < n; i++) {
			g[i] = new ArrayList<>();
			g2[i] = new ArrayList<>();
		}
		for (int i = 0; i < m; i++) {
			int fr = in.nextInt() - 1, to = in.nextInt() - 1;
			int cost = in.nextInt();
			g[fr].add(new Edge(to, cost));
			g[to].add(new Edge(fr, cost));
		}
		for (int i = 0; i < k; i++) {
			int to = in.nextInt() - 1;
			int cost = in.nextInt();
			g[0].add(new Edge(to, cost));
			g2[to].add(new Edge(0, cost));
		}
		PriorityQueue<Edge> pq = new PriorityQueue<>();
		long[] dist = new long[n];
		Arrays.fill(dist, Long.MAX_VALUE);
		dist[0] = 0;
		pq.add(new Edge(0, 0));
		boolean[] was = new boolean[n];
		int ans = 0;
		while (pq.size() > 0) {
			Edge e = pq.poll();
			int v = e.to;
			if (was[v])
				continue;
			was[v] = true;
			long curDist = Long.MAX_VALUE;
			for (Edge ee : g[v]) {
				if (dist[ee.to] != Long.MAX_VALUE)
					curDist = Math.min(dist[ee.to] + ee.cost, curDist);
			}
			if (curDist == dist[v] || v == 0) {
				ans += g2[v].size();
			} else {
				ans += g2[v].size() - 1;
			}
			for (Edge ee : g[v]) {
				if (dist[ee.to] > dist[v] + ee.cost) {
					dist[ee.to] = dist[v] + ee.cost;
					pq.add(new Edge(ee.to, dist[ee.to]));
				}
			}
		}
		out.println(ans);
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