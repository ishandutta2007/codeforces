import java.io.*;
import java.util.*;
import java.util.concurrent.Executor;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class CF {
	FastScanner in;
	PrintWriter out;

	void solve() {
		int n = in.nextInt();
		int[] l = new int[n];
		int[] c = new int[n];
		for (int i = 0; i < n; i++) {
			l[i] = in.nextInt();
		}
		for (int i = 0; i < n; i++) {
			c[i] = in.nextInt();
		}
		ArrayList<Integer>[] primes = new ArrayList[n];
		for (int i = 0; i < n; i++) {
			primes[i] = new ArrayList<>();
			int tmp = l[i];
			for (int x = 2; x * x <= tmp; x++) {
				if (tmp % x == 0) {
					while (tmp % x == 0) {
						tmp /= x;
					}
					primes[i].add(x);
				}
			}
			if (tmp != 1) {
				primes[i].add(tmp);
			}
		}
		int ans = Integer.MAX_VALUE / 2;
		for (int use = 0; use < n; use++) {
			int cnt = primes[use].size();
			int[] dp = new int[1 << cnt];
			Arrays.fill(dp, Integer.MAX_VALUE / 2);
			dp[(1 << cnt) - 1] = c[use];
			for (int i = 0; i < n; i++)
				if (i != use) {
					int myMask = 0;
					for (int j = 0; j < cnt; j++) {
						if (l[i] % primes[use].get(j) == 0) {
							myMask |= 1 << j;
						}
					}
					for (int mask = 0; mask < 1 << cnt; mask++) {
						dp[mask & myMask] = Math.min(dp[mask & myMask],
								dp[mask] + c[i]);
					}
				}
			ans = Math.min(ans, dp[0]);
		}
		out.println(ans >= Integer.MAX_VALUE / 2 ? -1 : ans);
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