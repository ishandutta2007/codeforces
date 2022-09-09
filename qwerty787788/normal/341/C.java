import java.io.*;
import java.util.*;

public class CF {

	MyScanner in;
	PrintWriter out;

	long mod = (long) 1e9 + 7;

	void solve() {
		int n = in.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = in.nextInt();
		}
		long[][] dp = new long[n + 1][n + 1];
		dp[0][0] = 1;
		for (int free = 1; free <= n; free++)
			dp[free][0] = (dp[free - 1][0] * free) % mod;
		for (int notMe = 1; notMe <= n; notMe++) {
			for (int free = 0; free <= n; free++) {
				dp[free][notMe] += dp[free][notMe - 1] * free;
				if (notMe > 1 && free + 1 <= n)
					dp[free][notMe] += dp[free + 1][notMe - 2] * (notMe - 1);
				dp[free][notMe] %= mod;
			}
		}
		int free = 0;
		int notMe = 0;
		boolean[] have = new boolean[n + 1];
		Arrays.fill(have, true);
		for (int i = 0; i < n; i++) {
			if (a[i] != -1) {
				have[a[i]] = false;
			}
		}
		for (int i = 1; i <= n; i++)
			if (have[i])
				if (a[i - 1] == -1) {
					notMe++;
				} else {
					free++;
				}
		out.println(dp[free][notMe] % mod);
	}

	void run() {
		try {
			in = new MyScanner();
			out = new PrintWriter(System.out);

			solve();

			out.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	class MyScanner {
		BufferedReader in;
		StringTokenizer st;

		public MyScanner() {
			in = new BufferedReader(new InputStreamReader(System.in));

		}

		String nextToken() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(in.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
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
	}

	public static void main(String[] args) {
		new CF().run();
	}
}