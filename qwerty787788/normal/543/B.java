import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	void bfs(int v, int[] dist, int[] q, ArrayList<Integer>[] g) {
		Arrays.fill(dist, -1);
		dist[v] = 0;
		int qIt = 0, qSz = 1;
		q[0] = v;
		while (qIt < qSz) {
			int u = q[qIt++];
			for (int to : g[u]) {
				if (dist[to] == -1) {
					dist[to] = dist[u] + 1;
					q[qSz++] = to;
				}
			}
		}
	}

	void solve() {
		int n = in.nextInt();
		int m = in.nextInt();
		ArrayList<Integer>[] g = new ArrayList[n];
		for (int i = 0; i < n; i++) {
			g[i] = new ArrayList<>();
		}
		for (int i = 0; i < m; i++) {
			int fr = in.nextInt() - 1;
			int to = in.nextInt() - 1;
			g[fr].add(to);
			g[to].add(fr);
		}
		int[][] dist = new int[n][n];
		int[] q = new int[n];
		for (int v = 0; v < n; v++) {
			bfs(v, dist[v], q, g);
		}
		int result = 0;
		int s1 = in.nextInt() - 1, t1 = in.nextInt() - 1, l1 = in.nextInt();
		int s2 = in.nextInt() - 1, t2 = in.nextInt() - 1, l2 = in.nextInt();
		if (dist[s1][t1] > l1 || dist[s2][t2] > l2) {
			out.println(-1);
			return;
		}
		result = m - dist[s1][t1] - dist[s2][t2];
		for (int f = 0; f < n; f++) {
			for (int s = 0; s < n; s++) {
				if (dist[s1][f] + dist[f][s] + dist[s][t1] <= l1) {
					if (dist[s2][f] + dist[f][s] + dist[s][t2] <= l2) {
						result = Math.max(result, m - dist[s1][f] - dist[s2][f]
								- dist[f][s] - dist[s][t1] - dist[s][t2]);
					}
				}
			}
		}

		for (int f = 0; f < n; f++) {
			for (int s = 0; s < n; s++) {
				if (dist[s1][f] + dist[f][s] + dist[s][t1] <= l1) {
					if (dist[s2][s] + dist[f][s] + dist[f][t2] <= l2) {
						result = Math.max(result, m - dist[s1][f] - dist[s2][s]
								- dist[f][s] - dist[s][t1] - dist[f][t2]);
					}
				}
			}
		}

		out.println(result);
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