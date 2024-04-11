import java.io.*;
import java.util.*;
import java.math.*;

public class C implements Runnable {

	void solve() {
		int n = nextInt();
		double[] p = new double[n];
		for (int i = 0; i < n; i++) {
			long l = nextLong();
			long r = nextLong();
			p[i] = getProb(l, r);
		}
		int k = nextInt();
		k = (int) Math.ceil(.01 * n * k);
		double[][] dp = new double[n + 1][n + 1];
		dp[0][0] = 1.;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j <= n; j++) {
				if (j > 0) {
					dp[i][j] += dp[i - 1][j - 1] * p[i - 1];
				}
				dp[i][j] += dp[i - 1][j] * (1 - p[i - 1]);
			}
		}
		double ans = 0;
		for (int i = k; i <= n; i++) {
			ans += dp[n][i];
		}
		out.println(ans);
	}

	private double getProb(long l, long r) {
		long count = 0;
		for (long i = 1; i <= r; i *= 10) {
			long j = 2 * i;
			if (l <= i && j <= r) {
				count += j - i;
			} else if (l <= i) {
				count += Math.max(0, r - i + 1);
			} else if (j <= r) {
				count += Math.max(0, j - l);
			} else {
				count += r - l + 1;
			}
			if (r / i < 10) {
				break;
			}
		}
		return 1. * count / (r - l + 1);
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

	class FastScanner extends BufferedReader {
		StringTokenizer st;
		boolean eof;
		String buf;
		String curLine;
		boolean createST;

		public FastScanner(String fileName) throws FileNotFoundException {
			this(fileName, true);
		}

		public FastScanner(String fileName, boolean createST)
				throws FileNotFoundException {
			super(new FileReader(fileName));
			this.createST = createST;
			nextToken();
		}

		public FastScanner(InputStream stream) {
			this(stream, true);
		}

		public FastScanner(InputStream stream, boolean createST) {
			super(new InputStreamReader(stream));
			this.createST = createST;
			nextToken();
		}

		String nextLine() {
			String ret = curLine;
			if (createST) {
				st = null;
			}
			nextToken();
			return ret;
		}

		String nextToken() {
			if (!createST) {
				try {
					curLine = readLine();
				} catch (Exception e) {
					eof = true;
				}
				return null;
			}
			while (st == null || !st.hasMoreTokens()) {
				try {
					curLine = readLine();
					st = new StringTokenizer(curLine);
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

		public void close() {
			try {
				buf = null;
				st = null;
				curLine = null;
				super.close();
			} catch (Exception e) {

			}
		}

		boolean isEOF() {
			return eof;
		}
	}

	public static void main(String[] args) {
		new C().run();
	}
}