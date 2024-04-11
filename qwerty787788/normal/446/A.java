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
		int best = 1;
		int[][][] dp = new int[2][3][n];
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 3; j++)
				Arrays.fill(dp[i][j], -1);
		dp[0][1][0] = 1;
		dp[1][2][0] = 1;
		int[] nextVals = new int[3];
		int[] curVals = new int[3];
		for (int pos = 0; pos < n; pos++) {
			nextVals[0] = a[pos] + 1;
			if (pos < n - 1)
				nextVals[1] = a[pos + 1];
			if (pos + 1 < n - 1)
				nextVals[2] = a[pos + 2] - 1;
			if (pos != 0)
				curVals[0] = a[pos - 1] + 1;
			curVals[1] = a[pos];
			if (pos < n - 1)
				curVals[2] = a[pos + 1] - 1;
			for (int used = 0; used < 2; used++)
				for (int curVal = 0; curVal < 3; curVal++)
					if (dp[used][curVal][pos] != -1) {
						int curDP = dp[used][curVal][pos];
						best = Math.max(best, curDP);
						if (pos != n - 1) {
							for (int nextOne = 0; nextOne < 3; nextOne++) {
								int nDP = 1;
								if (nextVals[nextOne] > curVals[curVal])
									nDP += curDP;
								int ncost = used + (nextOne == 1 ? 0 : 1);
								if (ncost < 2) {
									dp[ncost][nextOne][pos + 1] = Math.max(
											dp[ncost][nextOne][pos + 1], nDP);
								}
							}
						}
					}
		}
		out.println(best);
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