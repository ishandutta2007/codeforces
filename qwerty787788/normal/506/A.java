import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	void solve() {
		int n = in.nextInt();
		int d = in.nextInt();
		final int MAX_X = 30000 + 10;
		final int MAX = 333;
		int[] have = new int[MAX_X];
		int[][] dp = new int[MAX * 2][MAX_X];
		for (int i = 0; i < dp.length; i++) {
			Arrays.fill(dp[i], -1);
		}
		for (int i = 0; i < n; i++) {
			have[in.nextInt()]++;
		}
		dp[MAX][d] = have[d];
		int result = 0;
		for (int time = 0; time < MAX_X; time++) {
			for (int cur = 0; cur < dp.length; cur++) {
				int ans = dp[cur][time];
				if (ans == -1)
					continue;
				result = Math.max(result, ans);
				int realL = cur - MAX + d;
				for (int dl = -1; dl < 2; dl++) {
					if (realL + dl > 0 && cur + dl >= 0 && cur + dl < dp.length) {
						int newTime = time + realL + dl;
						if (newTime < MAX_X) {
							dp[cur + dl][newTime] = Math.max(
									dp[cur + dl][newTime], ans
											+ (have[newTime]));
						}
					}
				}
			}
		}
		out.println(result);
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