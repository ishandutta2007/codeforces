import java.io.*;
import java.util.*;

public class CF {

	long mod = (long) 1e9 + 7;

	long[][] c;
	int MAX = 1011;

	void prec() {
		c = new long[MAX][MAX];
		for (int i = 0; i < MAX; i++) {
			c[i][0] = 1;
			if (i != 0)
				for (int j = 1; j < MAX; j++)
					c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
		}
	}

	void solve() {
		prec();
		int n = in.nextInt();
		int[] a = new int[n];
		int[] b = new int[n];
		for (int i = 0; i < n; i++)
			a[i] = in.nextInt();
		for (int i = 0; i < n; i++)
			b[i] = in.nextInt();
		long[][] dp = new long[n + 1][MAX];
		dp[0][0] = 1;
		for (int i = 0; i < n; i++)
			for (int was = 0; was < MAX; was++)
				if (dp[i][was] != 0) {
					int now = was + a[i];
					for (int here = 0; here <= b[i]; here++) {
						if (here > now)
							break;
						dp[i + 1][now - here] += (dp[i][was] * c[now][here])
								% mod;
						if (dp[i + 1][now - here] >= mod)
							dp[i + 1][now - here] -= mod;
					}
				}
		long res = dp[n][0];
		int now = 0;
		for (int i = 0; i < n; i++)
			now += a[i];
		for (int i = 0; i < n; i++) {
			res = res * c[now][a[i]];
			res %= mod;
			now -= a[i];
		}
		out.println(res);
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