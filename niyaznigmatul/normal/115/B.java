import static java.lang.Math.min;
import static java.util.Arrays.copyOf;
import static java.util.Arrays.fill;

import java.io.*;
import java.util.*;
import java.math.*;

public class B implements Runnable {

	void solve() {
		int n = nextInt();
		int m = nextInt();
		char[][] c = new char[n][];
		for (int i = 0; i < n; i++) {
			c[i] = sc.nextToken().toCharArray();
		}
		{
			int i = n - 1;
			while (i >= 0) {
				boolean ok = true;
				for (int j = 0; j < m; j++) {
					if (c[i][j] == 'W') {
						ok = false;
						break;
					}
				}
				if (!ok) {
					break;
				}
				i--;
			}
			c = copyOf(c, i + 1);
			n = i + 1;
		}
		if (n == 0) {
			out.println(0);
			return;
		}
		int[] left = new int[n];
		int[] right = new int[n];
		fill(left, m);
		fill(right, -1);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (c[i][j] != 'W') {
					continue;
				}
				if (left[i] == m) {
					left[i] = j;
				}
				right[i] = j;
			}
		}
		int[][] dp = new int[n][m];
		for (int[] d : dp) {
			fill(d, Integer.MAX_VALUE);
		}
		dp[0][0] = 0;
		for (int i = 0; i < n; i++) {
			if ((i & 1) == 0) {
				for (int j = 0; j < m; j++) {
					if (dp[i][j] == Integer.MAX_VALUE) {
						continue;
					}
					if (j + 1 < m) {
						dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + 1);
					}
					if (j >= right[i] && (i + 1 < n && right[i + 1] <= j)) {
						dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1);
					}
				}
			} else {
				for (int j = m - 1; j >= 0; j--) {
					if (dp[i][j] == Integer.MAX_VALUE) {
						continue;
					}
					if (j > 0) {
						dp[i][j - 1] = min(dp[i][j - 1], dp[i][j] + 1);
					}
					if (j <= left[i] && (i + 1 < n && left[i + 1] >= j)) {
						dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1);
					}
				}
			}
		}
		// System.err.println(Arrays.toString(left));
		// System.err.println(Arrays.toString(right));
		// for (int i = 0; i < n; i++) {
		// System.err.println(Arrays.toString(dp[i]));
		// }
		if ((n & 1) == 0) {
			out.println(dp[n - 1][left[n - 1]]);
		} else {
			out.println(dp[n - 1][right[n - 1]]);
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
		new B().run();
	}
}