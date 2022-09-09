import java.io.*;
import java.util.*;

public class D {
	FastScanner in;
	PrintWriter out;

	void solve() {
		int n = in.nextInt();
		char[] s = in.next().toCharArray();
		final int mod = (int) 1e9 + 7;
		int[][] dp = new int[26][n + 1];
		int[] sum = new int[n + 1];
		sum[0] = 1;
		for (int i = 0; i < n; i++) {
			int id = s[i] - 'a';
			for (int j = 1; j <= n; j++) {
				sum[j] -= dp[id][j];
				if (sum[j] < 0) {
					sum[j] += mod;
				}
				dp[id][j] = sum[j - 1] - dp[id][j - 1];
				if (dp[id][j] < 0) {
					dp[id][j] += mod;
				}
				sum[j] += dp[id][j];
				if (sum[j] >= mod) {
					sum[j] -= mod;
				}
			}
		}
		long res = 0;
		int[] cPrev = new int[n + 1];
		cPrev[0] = 1;
		int[] cNext = new int[n + 1];
		for (int diff = 1; diff < n; diff++) {
			cNext[0] = 1;
			for (int j = 1; j <= n; j++) {
				cNext[j] = cPrev[j - 1] + cPrev[j];
				if (cNext[j] >= mod) {
					cNext[j] -= mod;
				}
			}
			int[] tmp = cPrev;
			cPrev = cNext;
			cNext = tmp;
		}
		for (int diff = 1; diff <= n; diff++) {
			res += sum[diff] * 1L * cPrev[diff - 1] % mod;
			res %= mod;
		}
		out.println(res);
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
		new D().runIO();
	}
}