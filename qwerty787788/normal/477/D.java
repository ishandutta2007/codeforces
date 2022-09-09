import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	void solve() {
		String s = in.next();
		int n = s.length();
		int[][] f = new int[n][];
		for (int i = 0; i < n; i++) {
			f[i] = new int[i + 1];
		}
		for (int x = n - 1; x >= 0; x--)
			for (int y = x - 1; y >= 0; y--) {
				if (s.charAt(x) != s.charAt(y)) {
					f[x][y] = 0;
				} else {
					if (x + 1 == n) {
						f[x][y] = 1;
					} else {
						f[x][y] = 1 + f[x + 1][y + 1];
					}
				}
			}
		final int mod = (int) 1e9 + 7;
		int[][] dp = new int[n + 1][];
		int[][] dpMin = new int[n + 1][];
		for (int used = 0; used <= n; used++) {
			dp[used] = new int[used + 1];
			dpMin[used] = new int[used + 1];
			Arrays.fill(dpMin[used], Integer.MAX_VALUE / 2);
			if (used == 0) {
				Arrays.fill(dp[used], 1);
				Arrays.fill(dpMin[used], 0);
				continue;
			}
			for (int length = 1; length < used + 1; length++) {
				int from = used - length;
				int from2 = from - length;
				int len = length;
				if (from2 >= 0) {
					int l = f[from][from2];
					boolean ok = true;
					if (from2 + l < from) {
						if (s.charAt(from2 + l) > s.charAt(from + l)) {
							ok = false;
						}
					}
					if (!ok) {
						len--;
					}
				} else {
					len = from;
				}
				if (s.charAt(from) == '0') {
					dp[used][length] = dp[used][length - 1];
					dpMin[used][length] = dpMin[used][length - 1];
				} else {
					dp[used][length] = dp[used][length - 1] + dp[from][len];
					if (dp[used][length] >= mod)
						dp[used][length] -= mod;
					dpMin[used][length] = Math.min(dpMin[used][length - 1],
							1 + dpMin[from][len]);
				}
			}
		}
		int numberOfWays = dp[n][n];
		out.println(numberOfWays);
		long best = Integer.MAX_VALUE;
		for (int lastLength = 1; lastLength <= Math.min(n, 10); lastLength++) {
			long cur = 0;
			for (int i = 0; i < lastLength; i++) {
				cur = cur * 2 + (s.charAt(n - lastLength + i) - '0');
			}
			cur += dpMin[n][lastLength];
			best = Math.min(best, cur);
		}
		if (best < Integer.MAX_VALUE / 3) {
			out.println(best);
			return;
		}
		for (int lastLength = 1; lastLength <= n; lastLength++) {
			if (dpMin[n][lastLength] >= Integer.MAX_VALUE / 3)
				continue;
			long cur = 0;
			for (int i = 0; i < lastLength; i++) {
				cur = cur * 2 + (s.charAt(n - lastLength + i) - '0');
				if (cur >= mod)
					cur -= mod;
			}
			cur += dpMin[n][lastLength];
			cur %= mod;
			out.println(cur);
			return;
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