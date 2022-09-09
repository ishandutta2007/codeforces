import java.io.*;
import java.util.*;

public class CF229D {
	FastScanner in;
	PrintWriter out;

	void solve() {
		int n = in.nextInt();
		int[] h = new int[n];
		for (int i = 0; i < n; i++)
			h[i] = in.nextInt();
		int[] sum = new int[n];
		for (int i = 0; i < n; i++)
			sum[i] = (i == 0 ? 0 : sum[i - 1]) + h[i];
		int[][] dp = new int[n][n];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				dp[i][j] = Integer.MAX_VALUE;
		dp[0][0] = 0;
		for (int used = 0; used < n; used++)
			for (int last = 0; last < n; last++)
				if (dp[used][last] != Integer.MAX_VALUE) {
					if (used < n - 1) 
						dp[used + 1][last] = Math.min(dp[used + 1][last], dp[used][last] + 1);
					int curSum = sum[used] - (last != 0 ? sum[last - 1] : 0);
					if (sum[n - 1] - sum[used] < curSum)
						continue;
					int l = used, r = n - 1;
					while (r - l > 1) {
						int m = (l + r) / 2;
						if (sum[m] - sum[used] >= curSum) {
							r = m;
						} else {
							l = m;
						}
					}
					dp[r][used + 1] = Math.min(dp[r][used + 1], dp[used][last] + (r - used) - 1);
				}
		int ans = Integer.MAX_VALUE;
		for (int i = 0; i < n; i++)
			ans = Math.min(ans, dp[n - 1][i]);
		out.println(ans);
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
	}

	public static void main(String[] args) {
		new CF229D().runIO();
	}
}