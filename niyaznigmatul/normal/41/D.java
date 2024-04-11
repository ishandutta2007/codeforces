import java.io.*;
import java.util.*;
import java.math.*;

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

		BigInteger nextBigInteger() {
			return new BigInteger(nextToken());
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

	BigInteger nextBigInteger() {
		return sc.nextBigInteger();
	}

	void solve() {
		int n = nextInt();
		int m = nextInt();
		int k = nextInt();
		char[][] c = new char[n][];
		for (int i = 0; i < c.length; i++) {
			c[i] = nextToken().toCharArray();
		}
		int[][] a = new int[n][m];
		for (int i = 0; i < a.length; i++) {
			for (int j = 0; j < a[i].length; j++) {
				a[i][j] = c[i][j] - '0';
			}
		}
		int[][][] dp = new int[k + 1][n][m];
		for (int i = 0; i < dp.length; i++) {
			for (int j = 0; j < dp[i].length; j++) {
				Arrays.fill(dp[i][j], Integer.MIN_VALUE);
			}
		}
		for (int i = 0; i < m; i++) {
			dp[a[n - 1][i] % (k + 1)][n - 1][i] = a[n - 1][i];
		}
		for (int i = n - 2; i >= 0; i--) {
			for (int j = 0; j < m; j++) {
				for (int t = 0; t <= k; t++) {
					int mod = (k + 1 + t - a[i][j] % (k + 1)) % (k + 1);
					if (j > 0 && dp[mod][i + 1][j - 1] != Integer.MIN_VALUE) {
						dp[t][i][j] = Math.max(dp[t][i][j],
								dp[mod][i + 1][j - 1] + a[i][j]);
					}
					if (j + 1 < m && dp[mod][i + 1][j + 1] != Integer.MIN_VALUE) {
						dp[t][i][j] = Math.max(dp[t][i][j],
								dp[mod][i + 1][j + 1] + a[i][j]);
					}

				}
			}
		}
		int ans = Integer.MIN_VALUE;
		int ansY = -1;
		for (int i = 0; i < m; i++) {
			if (ans < dp[0][0][i]) {
				ans = dp[0][0][i];
				ansY = i;
			}
		}
		if (ans == Integer.MIN_VALUE) {
			out.println("-1");
			return;
		}
		out.println(ans);
		StringBuilder sb = new StringBuilder();
		for (int i = 0, j = ansY, t = 0; i + 1 < n; ansY = j) {
			int mod = (k + 1 + t - a[i][j] % (k + 1)) % (k + 1);
			if (j > 0 && dp[mod][i + 1][j - 1] + a[i][j] == dp[t][i][j]) {
				sb.append("R");
				i++;
				j--;
				t = mod;
			} else if (j + 1 < m
					&& dp[mod][i + 1][j + 1] + a[i][j] == dp[t][i][j]) {
				sb.append("L");
				i++;
				j++;
				t = mod;
			} else {
				throw new AssertionError();
			}
		}
		out.println(ansY + 1);
		sb.reverse();
		out.println(sb.toString());
	}
}