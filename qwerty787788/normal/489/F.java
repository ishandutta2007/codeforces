import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	void solve() {
		int n = in.nextInt();
		int m = in.nextInt();
		int mod = in.nextInt();
		if (mod < 2 || mod > 1e9)
			throw new AssertionError();
		int[] cnt = new int[n];
		Arrays.fill(cnt, 2);
		final int MAX = 505;
		int[][] c = new int[MAX][10];
		for (int i = 0; i < MAX; i++) {
			c[i][0] = 1;
			if (i != 0)
				for (int j = 1; j < 10; j++) {
					c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]);
					if (c[i][j] >= mod)
						c[i][j] -= mod;
				}
		}
		for (int i = 0; i < m; i++) {
			String s = in.next();
			for (int j = 0; j < n; j++)
				if (s.charAt(j) == '1') {
					cnt[j]--;
				}
		}
		int cnt1 = 0;
		for (int i = 0; i < n; i++) {
			if (cnt[i] == 1) {
				cnt1++;
			}
		}
		int[] dp = new int[n + 1];
		int[] dp2 = new int[n + 1];
		dp[cnt1] = 1;
		for (int i = m; i < n; i++) {
			int sum = n * 2 - 2 * i;
			for (int c1 = 0; c1 <= n; c1++) {
				if ((sum - c1) % 2 == 1)
					continue;
				int c2 = (sum - c1) / 2;
				int val = dp[c1];
				if (val == 0)
					continue;
				for (int u1 = 0; u1 <= 2; u1++) {
					int u2 = 2 - u1;
					if (u1 <= c1 && u2 <= c2) {
						int nres = (int) ((dp2[c1 - u1 + u2] + val * 1L
								* c[c1][u1] % mod * c[c2][u2]) % mod);
						dp2[c1 - u1 + u2] = nres;
					}
				}

			}
			int[] tmp = dp;
			dp = dp2;
			dp2 = tmp;
			for (int c1 = 0; c1 <= n; c1++)
				dp2[c1] = 0;
		}
		out.println(dp[0]);
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