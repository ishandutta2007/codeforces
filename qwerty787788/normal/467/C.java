import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	void solve() {
		int n = in.nextInt();
		int m = in.nextInt();
		int k = in.nextInt();
		long[] a = new long[n];
		for (int i = 0; i < n; i++) {
			a[i] = in.nextInt();
		}
		long[] s = new long[n];
		for (int i = 0; i < n; i++) {
			s[i] = a[i];
			if (i > 0)
				s[i] += s[i - 1];
		}
		long[] dp1 = new long[n + 1];
		long[] dp2 = new long[n + 1];
		for (int i = 0; i < k; i++) {
			for (int j = 1; j <= n; j++)
				dp1[j] = Math.max(dp1[j], dp1[j - 1]);
			for (int last = m - 1; last < n; last++) {
				long cur = s[last];
				if (last - m >= 0) {
					cur -= s[last - m];
					cur += dp1[last - m];
				}
				dp2[last] = cur;
			}
			long[] tmp = dp1;
			dp1 = dp2;
			dp2 = tmp;
			Arrays.fill(dp2, 0);
		}
		long max = 0;
		for (int i = 0; i < n; i++) {
			max = Math.max(max, dp1[i]);
		}
		out.println(max);
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