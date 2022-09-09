import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	void solve() {
		int n = in.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = in.nextInt();
		}
		int[][] dp = new int[n][n];
		int[][] dp2 = new int[n][n];
		for (int i = 0; i < n; i++) {
			dp[i][i] = 1;
		}
		for (int len = 2; len <= n; len++) {
			for (int fr = 0; fr + len <= n; fr++) {
				int to = fr + len - 1;
				dp[fr][to] = Integer.MAX_VALUE;
				for (int l1 = 1; l1 < len; l1++) {
					dp[fr][to] = Math.min(dp[fr][to], dp[fr][fr + l1 - 1]
							+ dp[fr + l1][to]);
				}
				if (a[fr] == a[to]) {
					dp[fr][to] = Math.min(dp[fr][to], 1 + dp2[fr + 1][to - 1]);
				}
				dp2[fr][to] = Integer.MAX_VALUE;
				for (int l1 = 1; l1 < len; l1++) {
					dp2[fr][to] = Math.min(dp2[fr][to], dp[fr][fr + l1 - 1]
							+ dp2[fr + l1][to]);
					dp2[fr][to] = Math.min(dp2[fr][to], dp2[fr][fr + l1 - 1]
							+ dp[fr + l1][to]);
				}
				if (a[fr] == a[to]) {
					dp2[fr][to] = Math.min(dp2[fr][to], dp2[fr + 1][to - 1]);
				}
			}
		}
		out.println(dp[0][n - 1]);
	}

	void run() {
		try {
			in = new FastScanner(new File("CF.in"));
			out = new PrintWriter(new File("CF.out"));

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