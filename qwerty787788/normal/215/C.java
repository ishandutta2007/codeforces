import java.util.*;
import java.io.*;

public class Solution {
	FastScanner in;
	PrintWriter out;

	public void solve() throws IOException {
		int n = in.nextInt();
		int m = in.nextInt();
		long s = in.nextLong();
		long[][] a = new long[n + 1][m + 1];
		for (int w = 1; w <= n; w++)
			for (int h = 1; h <= m; h++) {
				long sum = 0;
				if (w * h == s)
					sum += 2 * (w / 2 + 1) * (h / 2 + 1) - 1;
				for (int dx = 1; dx <= (w - 1) / 2; dx++) {
					if (((w * h - s) % (4 * dx)) == 0 && w * h > s) {
						int dy = (w * h - (int)s) / 4 / dx;
						if (dy > 0 && dy <= (h - 1) / 2 && w * h - 4 * dx * dy == s)
							sum+= 2;
					}
				}
				a[w][h] = sum;
			}
		//out.println(a[500][500]);
		long[][] dp = new long[n + 1][m + 1];
		for (int i = 1; i <= n; i+= 2)
			for (int j = 1; j <= m; j+=2)
				dp[i][j] = a[i][j];
		for (int i = 1; i <= n; i+= 2)
			for (int j = 1; j <= m; j+=2) {
				if (i != 1)
					dp[i][j] += dp[i - 2][j];
				if (j != 1)
					dp[i][j] += dp[i][j - 2];
				if (i != 1 && j != 1)
					dp[i][j] -= dp[i - 2][j - 2];
			}
			
		long ans = 0;
		for (int x = 1; x <= n; x++)
			for (int y = 1; y <= m; y++) {
				int w = 1 + 2 * Math.min(x - 1, n - x);
				int h = 1 + 2 * Math.min(y - 1, m - y);
				ans += dp[w][h];
			}
		out.println(ans);
	}

	public void run() {
		try {
			//in = new FastScanner(new File("input.txt"));
			//out = new PrintWriter(new File("output.txt"));

			 in = new FastScanner(System.in);
			 out = new PrintWriter(System.out);

			solve();

			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		FastScanner(File f) {
			try {
				br = new BufferedReader(new FileReader(f));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		FastScanner(InputStream f) {
			br = new BufferedReader(new InputStreamReader(f));
		}

		String next() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}
	}

	public static void main(String[] arg) {
		new Solution().run();
	}
}