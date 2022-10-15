import java.io.*;
import java.util.*;

public class D implements Runnable {
	public static void main(String[] args) {
		new D().run();
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

	void solve() {
		// long time = System.currentTimeMillis();
		int n = nextInt();
		int m = nextInt();
		boolean[][] edges = new boolean[n][n];
		boolean[] edge = new boolean[(n << 5) | n];
		for (int i = 0; i < m; i++) {
			int x = nextInt() - 1;
			int y = nextInt() - 1;
			edges[x][y] = edges[y][x] = true;
			edge[(x << 5) | y] = edge[(y << 5) | x] = true;
		}
		long[][] dp = new long[n][1 << n];
		long ans = 0;
		for (int i = 0; i < n; i++) {
			for (int mask2 = 1; mask2 < 1 << (n - i - 1); ++mask2) {
				for (int j = i + 1; j < n; j++) {
					dp[j][mask2 << i << 1] = 0;
				}
			}
			for (int j = i + 1; j < n; j++) {
				if (edges[i][j]) {
					dp[j][1 << j] = 1;
				}
			}
			for (int mask2 = 1; mask2 < 1 << (n - i - 1); ++mask2) {
				int mask = (mask2 << i << 1);
				if ((mask & (mask - 1)) == 0) {
					continue;
				}
				for (int j = i + 1; j < n; j++) {
					if (((mask >> j) & 1) == 0) {
						continue;
					}
					dp[j][mask] = 0;
					for (int k = i + 1; k < n; k++) {
						if (((mask >> k) & 1) == 0 || !edge[(j << 5) | k]) {
							continue;
						}
						dp[j][mask] += dp[k][mask & ~(1 << j)];
					}
					if (edge[(i << 5) | j]) {
						ans += dp[j][mask];
					}
				}
			}
		}
//		if (n >= 3) {
//			if (edges[n - 3][n - 2] && edges[n - 3][n - 1]
//					&& edges[n - 2][n - 1]) {
//				ans += 2;
//			}
//		}
		out.println(ans / 2);
		// System.err.println(System.currentTimeMillis() - time);

		// out.println(19 + " " + 19 * 9);
		// for (int i = 0; i < 19; ++i) {
		// for (int j = i + 1; j < 19; ++j) {
		// out.println((i + 1) + " " + (j + 1));
		// }
		// }
	}
}