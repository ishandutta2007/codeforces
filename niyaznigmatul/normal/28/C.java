import java.io.*;
import java.util.*;

public class C implements Runnable {
	public static void main(String[] args) {
		new C().run();
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
		int n = nextInt();
		int m = nextInt();
		int[] a = new int[m];
		for (int i = 0; i < a.length; i++) {
			a[i] = nextInt();
		}
		double[][][] dp = new double[m + 1][n + 1][n + 1];
		for (int i = 0; i <= m; i++) {
			dp[i][0][0] = 1;
		}
		double[][] c = new double[n + 2][n + 2];
		c[0][0] = 1;
		for (int i = 1; i < c.length; i++) {
			c[i][0] = 1;
			for (int j = 1; j <= n + 1; j++) {
				for (int k = 1; k <= i; k++) {
					c[i][j] += c[k][j - 1];
				}
			}
		}
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				for (int k = 0; k <= n; k++) {
					// if (k > 0)
					// dp[i][j][k] += dp[i][j - 1][k];
					for (int t = 0; t <= j; t++) {
						int e = Math.max(k, (t + a[i - 1] - 1) / a[i - 1]);
						if (e > 0)
							dp[i][j][e] += dp[i - 1][j - t][k]
									* c[j - t + 1][t];
					}
				}
			}
		}
		double ans = 0;
		double ans2 = 0;
		for (int i = 0; i <= n; i++) {
			ans += (dp[m][n][i] /*- dp[m][n - 1][i]*/) * i;
			ans2 += dp[m][n][i];
		}
		out.printf("%.15f\n", ans / ans2);
	}
}