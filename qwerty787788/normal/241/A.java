import java.io.*;
import java.util.*;

public class SolutionA {
	FastScanner in;
	PrintWriter out;

	void solve() {
		int n = in.nextInt();
		int k = in.nextInt();
		int MAX = 1000;
		int[][] dp = new int[n + 1][MAX + 1];
		for (int i = 0; i <= n; i++)
			for (int j = 0; j <= MAX; j++)
				dp[i][j] = Integer.MAX_VALUE;
		int[] d = new int[n];
		int[] s = new int[n + 1];
		for (int i = 0; i < n; i++)
			d[i] = in.nextInt();
		for (int i = 0; i < n; i++)
			s[i] = in.nextInt();
		int nowL = 0;
		int maxAdd = 0;
		int ans = 0;
		for (int i = 0; i < n; i++) {
			maxAdd = Math.max(maxAdd, s[i]);
			nowL += s[i];
			if (nowL < d[i]) {
				int need = 1 + (d[i] - nowL - 1) / maxAdd;
				ans += need * k;
				nowL += need * maxAdd;
			}
			nowL -= d[i];
			ans += d[i];
		}
		out.println(ans);
	}

	void run() {
		try {
			in = new FastScanner(new File("input.txt"));
			out = new PrintWriter(new File("output.txt"));

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
	}

	public static void main(String[] args) {
		new SolutionA().runIO();
	}
}