import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	void solve() {
		int n = in.nextInt();
		int[] l = new int[n];
		int[] r = new int[n];
		for (int i = 0; i < n; i++) {
			l[i] = in.nextInt();
			r[i] = in.nextInt();
		}
		int[][] dp = new int[n][n + 1];
		for (int i = 0; i < n; i++) {
			Arrays.fill(dp[i], -1);
		}
		for (int len = 1; len <= n; len++) {
			for (int from = 0; from + len <= n; from++) {
				for (int more = 0; more <= len - 1; more++) {
					int rLen = more * 2 + 1;
					if (rLen >= l[from] && rLen <= r[from]) {
						boolean ok = true;
						if (more > 0 && dp[from + 1][more] == -1) {
							ok = false;
						}
						if (more != len - 1
								&& dp[from + more + 1][len - more - 1] == -1) {
							ok = false;
						}
						if (ok) {
							dp[from][len] = more;
						}
					}
				}
			}
		}
		if (dp[0][n] == -1) {
			out.println("IMPOSSIBLE");
		} else {
			go(0, n, dp);
		}
	}

	void go(int from, int len, int[][] dp) {
		if (len == 0) {
			return;
		}
		int more = dp[from][len];
		out.print("(");
		go(from + 1, more, dp);
		out.print(")");
		go(from + more + 1, len - more - 1, dp);
	}

	void runIO() {

		in = new FastScanner(System.in);
		out = new PrintWriter(System.out);

		solve();

		out.close();
	}

	void run() {
		try {
			in = new FastScanner(new File("test.in"));
			out = new PrintWriter(new File("test.out"));

			solve();

			out.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
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