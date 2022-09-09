import java.io.*;
import java.util.*;

public class CFB {
	FastScanner in;
	PrintWriter out;

	void solve() {
		int n = in.nextInt();
		int m = in.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = in.nextInt() - 1;
			String d = in.next();
		}
		int[][] dp = new int[n + 1][m];
		for (int i = 0; i <= n; i++)
			for (int j = 0; j < m; j++)
				dp[i][j] = Integer.MAX_VALUE;
		dp[0][0] = 0;
		for (int i = 0; i < n; i++) {
			int less = Integer.MAX_VALUE;
			for (int j = 0; j < m; j++)
				if (dp[i][j] != Integer.MAX_VALUE)
					dp[i + 1][j] = dp[i][j] + 1;
			for (int x = 0; x <= a[i]; x++)
				less = Math.min(dp[i][x], less);
			dp[i + 1][a[i]] = Math.min(dp[i + 1][a[i]], less);
		}
		int ans = Integer.MAX_VALUE;
		for (int i = 0; i < m; i++)
			ans = Math.min(ans, dp[n][i]);
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
		new CFB().runIO();
	}
}