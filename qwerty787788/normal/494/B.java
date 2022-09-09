import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	int[] prefix_function(String s) {
		int n = s.length();
		int[] pi = new int[n];
		for (int i = 1; i < n; ++i) {
			int j = pi[i - 1];
			while (j > 0 && s.charAt(i) != s.charAt(j))
				j = pi[j - 1];
			if (s.charAt(i) == s.charAt(j))
				++j;
			pi[i] = j;
		}
		return pi;
	}

	void solve() {
		String s = in.next();
		String t = in.next();
		String ss = t + "#" + s;
		final int mod = (int) 1e9 + 7;
		int[] dp = new int[s.length() + 1];
		int[] dpSum = new int[s.length() + 1];
		int[] dpSum2 = new int[s.length() + 1];
		dpSum[0] = dpSum2[0] = 1;
		int[] pref = prefix_function(ss);
		int maxR = -1;
		for (int i = 0; i < s.length(); i++) {
			int curP = pref[i + t.length() + 1];
			if (curP == t.length()) {
				maxR = Math.max(maxR, i - t.length() + 1);
			}
			if (maxR != -1) {
				dp[i + 1] = dpSum2[maxR];
			}
			dpSum[i + 1] = (dpSum[i] + dp[i + 1]);
			if (dpSum[i + 1] >= mod) {
				dpSum[i + 1] -= mod;
			}
			dpSum2[i + 1] = (dpSum2[i] + dpSum[i + 1]);
			if (dpSum2[i + 1] >= mod) {
				dpSum2[i + 1] -= mod;
			}
		}
		out.println((mod + dpSum[s.length()] - 1) % mod);
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