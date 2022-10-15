import java.io.*;
import java.util.*;
import java.math.*;

public class C implements Runnable {

	static final int ALPHABET = 27;

	void solve() {
		char[] c = nextToken().toCharArray();
		int k = nextInt();
		int m = nextInt();
		int[][] cost = new int[ALPHABET][ALPHABET];
		for (int i = 0; i < m; i++) {
			int c1 = nextToken().charAt(0) - 'a';
			int c2 = nextToken().charAt(0) - 'a';
			cost[c1][c2] = nextInt();
		}
		int n = c.length;
		int[][][] dp = new int[ALPHABET][k + 1][n + 1];
		for (int[][] d1 : dp) {
			for (int[] d2 : d1) {
				Arrays.fill(d2, Integer.MIN_VALUE);
			}
		}
		dp[26][0][0] = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < ALPHABET; j++) {
				for (int e = 0; e <= k; e++) {
					if (dp[j][e][i] == Integer.MIN_VALUE) {
						continue;
					}
					for (int t = 0; t + 1 < ALPHABET; t++) {
						if (t == c[i] - 'a') {
							dp[t][e][i + 1] = Math.max(dp[t][e][i + 1],
									dp[j][e][i] + cost[j][t]);
						} else {
							if (e == k) {
								continue;
							}
							dp[t][e + 1][i + 1] = Math.max(dp[t][e + 1][i + 1],
									dp[j][e][i] + cost[j][t]);
						}
					}
				}
			}
		}
		int ans = Integer.MIN_VALUE;
		for (int i = 0; i < ALPHABET; i++) {
			for (int j = 0; j <= k; j++) {
				ans = Math.max(ans, dp[i][j][n]);
			}
		}
		out.println(ans);
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