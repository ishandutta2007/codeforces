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

	final int MOD = 1000000007;

	void solve() {
		int n = nextInt();
		int[] x = new int[n];
		int sum = 0;
		for (int i = 0; i < x.length; i++) {
			x[i] = nextInt();
			sum += x[i];
		}
		int[] y = new int[n];
		for (int i = 0; i < y.length; i++) {
			y[i] = nextInt();
		}
		int[][] c = new int[sum + 1][sum + 1];
		c[0][0] = 1;
		for (int i = 1; i < c.length; i++) {
			c[i][0] = 1;
			for (int j = 1; j <= i; j++) {
				c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
				if (c[i][j] >= MOD) {
					c[i][j] -= MOD;
				}
			}
		}
		for (int i = 1; i < x.length; i++) {
			x[i] += x[i - 1];
		}
		int[][] dp = new int[n + 1][sum + 1];
		dp[0][0] = 1;
		for (int i = 1; i <= n; i++) {
			int t = i == 1 ? 0 : x[i - 2];
			for (int j = 0; j <= t; j++) {
				for (int k = 0; k <= y[i - 1] && k <= x[i - 1] - j; k++) {
					dp[i][j + k] += (int) ((long) c[x[i - 1] - j][k]
							* dp[i - 1][j] % MOD);
					if (dp[i][j + k] >= MOD) {
						dp[i][j + k] -= MOD;
					}
				}
			}
		}
		long ans = dp[n][sum];
		for (int i = 2; i <= sum; i++) {
			ans = (ans * i) % MOD;
		}
		for (int i = 0; i < x.length; i++) {
			int t = i == 0 ? x[0] : x[i] - x[i - 1];
			for (int j = 2; j <= t; j++) {
				ans = (ans * modInverse(j, MOD)) % MOD;
			}
		}
		out.println(ans);
	}

	int modInverse(int a, int mod) {
		return modPow(a, mod - 2, mod);
	}

	int modPow(int a, int b, int mod) {
		int ret = 1;
		while (b > 0) {
			if ((b & 1) == 1) {
				ret = (int) ((long) ret * a % mod);
			}
			a = (int) ((long) a * a % mod);
			b >>= 1;
		}
		return ret;
	}
}