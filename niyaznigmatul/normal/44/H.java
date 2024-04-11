import java.io.*;
import java.util.*;
import java.math.*;

public class H implements Runnable {
	public static void main(String[] args) {
		new H().run();
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
		char[] s = nextToken().toCharArray();
		int[] a = new int[s.length];
		for (int i = 0; i < a.length; i++) {
			a[i] = s[i] - '0';
		}
		long[][] dp = new long[a.length][10];
		Arrays.fill(dp[0], 1);
		for (int i = 1; i < dp.length; i++) {
			for (int j = 0; j < 10; j++) {
				int sum = j + a[a.length - i];
				if ((sum & 1) == 0) {
					dp[i][j] = dp[i - 1][sum >> 1];
				} else {
					dp[i][j] = dp[i - 1][sum >> 1] + dp[i - 1][(sum >> 1) + 1];
				}
			}
		}
		boolean ok = true;
		for (int i = 1; i < a.length; i++) {
			int sum = a[i - 1] + a[i];
			if (sum / 2 != a[i] && (sum + 1) / 2 != a[i]) {
				ok = false;
				break;
			}
		}
		long ans = 0;
		if (ok) {
			--ans;
		}
		for (int i = 0; i < 10; i++) {
			ans += dp[a.length - 1][i];
		}
		out.println(ans);
	}

	// 123456789123456789123456789123456789123456789
	// 54961209
	int go(int x, int[] a, int[] b) {
		if (x == a.length) {
			boolean ok = false;
			for (int i = 0; i < b.length; i++) {
				if (a[i] != b[i]) {
					ok = true;
					break;
				}
			}
			if (!ok) {
				return 0;
			}
			return 1;
		}
		int sum = a[x] + b[x - 1];
		if ((sum & 1) == 0) {
			b[x] = sum >> 1;
			return go(x + 1, a, b);
		}
		int ret = 0;
		b[x] = sum >> 1;
		ret += go(x + 1, a, b);
		b[x] = (sum >> 1) + 1;
		ret += go(x + 1, a, b);
		return ret;
	}
}