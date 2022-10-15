import java.io.*;
import java.util.*;
import java.math.*;

public class D implements Runnable {

	final int INF = Integer.MAX_VALUE / 2;

	void solve() {
		char[] s1 = nextToken().toCharArray();
		char[] s2 = nextToken().toCharArray();
		int[][] dp = new int[s1.length + 1][s2.length + 1];
		int[][] p = new int[s1.length + 1][s2.length + 1];
		for (int i = 0; i < dp.length; i++) {
			Arrays.fill(dp[i], INF);
		}
		dp[0][0] = 0;
		for (int i = 0; i <= s1.length; i++) {
			for (int j = 0; j <= s2.length; j++) {
				if (i == 0 && j == 0) {
					continue;
				}
				if (i > 0) {
					if (dp[i][j] > dp[i - 1][j] + 1) {
						dp[i][j] = dp[i - 1][j] + 1;
						p[i][j] = 1;
					}
				}
				if (j > 0) {
					if (dp[i][j] > dp[i][j - 1] + 1) {
						dp[i][j] = dp[i][j - 1] + 1;
						p[i][j] = 2;
					}
				}
				if (i > 0 && j > 0) {
					if (s1[i - 1] == s2[j - 1]) {
						if (dp[i][j] > dp[i - 1][j - 1]) {
							dp[i][j] = dp[i - 1][j - 1];
							p[i][j] = 0;
						}
					} else {
						if (dp[i][j] > dp[i - 1][j - 1] + 1) {
							dp[i][j] = dp[i - 1][j - 1] + 1;
							p[i][j] = 3;
						}
					}
				}
			}
		}
		ArrayList<String> ans = new ArrayList<String>();
		for (int i = s1.length, j = s2.length; i > 0 || j > 0;) {
			int got = p[i][j];
			if (got == 0) {
				i--;
				j--;
			} else if (got == 3) {
				ans.add("REPLACE " + i + " " + s2[j - 1]);
				i--;
				j--;
			} else if (got == 1) {
				ans.add("DELETE " + i);
				i--;
			} else {
				ans.add("INSERT " + (i + 1) + " " + s2[j - 1]);
				j--;
			}
		}
		out.println(ans.size());
		for (String s : ans) {
			out.println(s);
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
		new D().run();
	}
}