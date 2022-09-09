import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	void solve() {
		int n = in.nextInt();
		int m = in.nextInt();
		int maxErr = in.nextInt();
		int mod = in.nextInt();
		int[][] dp = new int[m + 1][maxErr + 1];
		dp[0][0] = 1 % mod;
		for (int i = 0; i < n; i++) {
			int addErr = in.nextInt();
			for (int curLine = 0; curLine <= m; curLine++) {
				for (int curErr = 0; curErr <= maxErr; curErr++) {
					if (curLine < m && curErr + addErr <= maxErr) {
						dp[curLine + 1][curErr + addErr] += dp[curLine][curErr];
						if (dp[curLine + 1][curErr + addErr] >= mod) {
							dp[curLine + 1][curErr + addErr] -= mod;
						}
					}
				}
			}
		}
		long sum = 0;
		for (int err = 0; err <= maxErr; err++) {
			sum += dp[m][err];
		}
		out.println(sum % mod);
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