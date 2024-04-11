import java.io.*;
import java.util.*;

public class CF {

	long mod = (long) 1e9 + 7;

	void solve() {
		int n = in.nextInt();
		int k = in.nextInt();
		String s = in.next();
		long[][] dp = new long[n + 1][k + 1];
		long[][] prefSum = new long[n + 1][k + 1];
		dp[0][0] = 1;
		prefSum[0][0] = 1;
		for (int i = 0; i < n; i++)
			for (int curK = 0; curK <= k; curK++) {
				// bigger
				int cntBigger = 25 - (s.charAt(i) - 'a');
				int cntLess = 25 - cntBigger;
				int add = n - i;
				for (int cntEq = 0;; cntEq++) {
					if (add * (cntEq + 1) > curK)
						break;
					if (i - cntEq < 0)
						break;
					dp[i + 1][curK] += cntBigger
							* dp[i - cntEq][curK - add * (cntEq + 1)];
				}
				// less
				dp[i + 1][curK] += prefSum[i][curK] * cntLess; 
				dp[i + 1][curK] %= mod;
				prefSum[i + 1][curK] = (prefSum[i][curK] + dp[i + 1][curK])
						% mod;
			}
		out.println(prefSum[n][k] % mod);
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