import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	void solve() {
		int n = in.nextInt();
		int h = in.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = in.nextInt();
		}
		final int MOD = (int) 1e9 + 7;
		int[][] dp = new int[n][n + 3];
		dp[n - 1][0] = a[n - 1] >= h - 1 && a[n - 1] <= h ? 1 : 0;
		dp[n - 1][1] = a[n - 1] == h - 1 ? 1 : 0;
		for (int start = n - 2; start >= 0; start--)
			for (int alr = 0; alr <= n; alr++) {
				for (int newOne = 0; newOne < 2; newOne++)
					for (int endHere = 0; endHere < 2; endHere++) {
						int mul = 1;
						if (endHere > 0) {
							mul *= alr + newOne;
						}
						if (alr + newOne + a[start] == h && alr +newOne -endHere >= 0) {
							dp[start][alr] = (int) ((dp[start][alr] + mul*1L*dp[start + 1][alr + newOne - endHere]) % MOD);
						}
					}
			}
		out.println(dp[0][0]);
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