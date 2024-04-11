import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	int cmp(int fr, int to, int fr1, int to2, short[][] lcp, char[] a) {
		int l = lcp[fr][fr1];
		int len = to - fr + 1;
		if (l >= len) {
			return 0;
		}
		char c1 = a[fr + l], c2 = a[fr1 + l];
		return Character.compare(c1, c2);
	}

	void solve() {
		final int mod = (int) 1e9 + 7;
		int n = in.nextInt();
		char[] a = in.next().toCharArray();
		short[][] lcp = new short[n][n];
		for (int i = n - 1; i >= 0; i--) {
			for (int j = n - 1; j >= 0; j--) {
				if (a[i] == a[j]) {
					lcp[i][j] = 1;
					if (i + 1 < n && j + 1 < n) {
						lcp[i][j] += lcp[i + 1][j + 1];
					}
				}
			}
		}
		int[][] dp = new int[n][];
		// [last][len]
		int[][] dpSum = new int[n][];
		for (int last = 0; last < n; last++) {
			dp[last] = new int[last + 2];
			dpSum[last] = new int[last + 2];
			for (int len = 1; len <= last + 1; len++) {
				if (a[last - len + 1] == '0') {
					dpSum[last][len] = dp[last][len] + dpSum[last][len - 1];
					continue;
				}
				int maxLen = len;
				int fr = last - len - len + 1;
				if (fr < 0) {
					int more = -fr;
					maxLen -= more;
				} else {
					if (cmp(fr, fr + len - 1, last - len + 1, last, lcp, a) >= 0) {
						maxLen--;
					}
				}
				dp[last][len] = last - len == -1 ? 1 : dpSum[last - len][maxLen];
				dpSum[last][len] = dp[last][len] + dpSum[last][len - 1];
				if (dpSum[last][len] >= mod) {
					dpSum[last][len] -= mod;
				}
			}
		}
		long result = 0;
		for (int x : dp[n - 1]) {
			result += x;
		}
		out.println(result % mod);
	}

	void run() {
		try {
			in = new FastScanner(new File("object.in"));
			out = new PrintWriter(new File("object.out"));

			solve();

			out.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
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