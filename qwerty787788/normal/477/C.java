import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	void solve() {
		String s = in.next();
		String p = in.next();
		int[][] last = new int[s.length()][p.length() + 1];
		for (int pos = s.length() - 1; pos >= 0; pos--)
			for (int alr = 0; alr < p.length(); alr++) {
				if (pos + 1 != s.length()) {
					last[pos][alr] = last[pos + 1][alr];
				} else {
					last[pos][alr] = Integer.MAX_VALUE;
				}
				if (s.charAt(pos) == p.charAt(alr)) {
					if (alr == p.length() - 1) {
						last[pos][alr] = pos;
					} else {
						if (pos + 1 != s.length()) {
							last[pos][alr] = last[pos + 1][alr + 1];
						}
					}
				}
			}
		int[][] dp = new int[s.length() + 1][s.length() + 1];
		for (int pos = 0; pos <= s.length(); pos++) {
			for (int rem = 0; rem <= pos; rem++) {
				if (pos > 0) {
					dp[pos][rem] = Math.max(dp[pos][rem], dp[pos - 1][rem]);
					if (rem > 0) {
						dp[pos][rem] = Math.max(dp[pos][rem],
								dp[pos - 1][rem - 1]);
					}
				}
				if (pos != s.length()) {
					int ne = last[pos][0];
					if (ne != Integer.MAX_VALUE) {
						int needRemove = (ne - pos + 1) - p.length();
						if (rem + needRemove <= s.length()) {
							dp[ne + 1][rem + needRemove] = Math.max(
									dp[ne + 1][rem + needRemove], dp[pos][rem] + 1);
						}
					}
				}
			}
		}
		for (int i = 0; i <= s.length(); i++) {
			out.print(dp[s.length()][i] + " ");
		}
	}

	void runIO() {

		in = new FastScanner(System.in);
		out = new PrintWriter(System.out);

		solve();

		out.close();
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