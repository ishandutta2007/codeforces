import java.io.*;
import java.util.*;

public class CF {

	void solve() {
		int n = in.nextInt();
		int[][] a = new int[3][n];
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < n; j++)
				a[i][j] = in.nextInt();
		int[][] dp = new int[2][n];
		dp[0][0] = a[1][0];
		dp[1][0] = a[0][0];
		for (int i = 1; i < n; i++) {
			int curBefore = dp[0][i - 1];
			int curAfter = dp[1][i - 1];
			dp[0][i] = Math.max(curBefore + a[1][i], curAfter + a[2][i]);
			dp[1][i] = Math.max(curBefore + a[0][i], curAfter + a[1][i]);
		}
		out.println(dp[1][n - 1]);
	}

	FastScaner in;
	PrintWriter out;

	void run() {
		in = new FastScaner(System.in);
		out = new PrintWriter(System.out);

		solve();

		out.close();
	}

	void runWithFiles() {
		in = new FastScaner(new File("input.txt"));
		try {
			out = new PrintWriter(new File("output.txt"));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}

		solve();

		out.close();
	}

	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		new CF().run();
	}

	class FastScaner {
		BufferedReader br;
		StringTokenizer st;

		FastScaner(InputStream is) {
			br = new BufferedReader(new InputStreamReader(is));
		}

		FastScaner(File f) {
			try {
				br = new BufferedReader(new FileReader(f));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		String next() {
			while (st == null || !st.hasMoreElements()) {
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
}