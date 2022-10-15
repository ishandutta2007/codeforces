import java.io.*;
import java.util.*;

public class D {

	static void solve() throws IOException {
		int n = nextInt();
		List<Integer>[] edges = new List[n];
		for (int i = 0; i < n; i++) {
			edges[i] = new ArrayList<>();
		}
		for (int i = 1; i < n; i++) {
			int x = nextInt() - 1;
			edges[x].add(i);
		}
		int[][] dp = new int[2][n];
		for (int v = n - 1; v >= 0; v--) {
			int even = 1;
			int odd = 0;
			for (int e = 0; e < edges[v].size(); e++) {
				int to = edges[v].get(e);
				int neven = add(mul(even, add(dp[0][to], 1)),
						mul(odd, dp[1][to]));
				int nodd = add(mul(even, dp[1][to]),
						mul(odd, add(dp[0][to], 1)));
				even = neven;
				odd = nodd;
			}
			even = add(even, even);
			odd = add(odd, odd);
			int[][][][] cdp = new int[2][2][2][edges[v].size() + 1];
			cdp[0][1][1][0] = 1;
			cdp[0][0][1][0] = 1;
			for (int e = 0; e < edges[v].size(); e++) {
				int to = edges[v].get(e);
				for (int oddity = 0; oddity < 2; oddity++) {
					for (int prev = 0; prev < 2; prev++) {
						for (int current = 0; current < 2; current++) {
							int val = cdp[oddity][prev][current][e];
							if (val == 0)
								continue;
							cdp[oddity][prev][current][e + 1] = add(
									cdp[oddity][prev][current][e + 1], val);
							for (int get = 0; get < 2; get++) {
								if ((current ^ get) == prev)
									cdp[get ^ oddity][current][current ^ get][e + 1] = add(
											cdp[get ^ oddity][current][current
													^ get][e + 1],
											mul(val, dp[get][to]));
							}
						}
					}
				}
			}
			even = add(even, MOD - cdp[0][1][1][edges[v].size()]);
			even = add(even, MOD - cdp[0][1][0][edges[v].size()]);
			odd = add(odd, MOD - cdp[1][1][1][edges[v].size()]);
			odd = add(odd, MOD - cdp[1][1][0][edges[v].size()]);
			dp[0][v] = odd;
			dp[1][v] = even;
		}
		out.println(add(dp[0][0], dp[1][0]));
	}

	static final int MOD = 1000000007;

	static int add(int a, int b) {
		a += b;
		if (a >= MOD)
			a -= MOD;
		return a;
	}

	static int mul(int a, int b) {
		return (int) ((long) a * b % MOD);
	}

	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter out;

	public static void main(String[] args) throws IOException {
		InputStream input = System.in;
		PrintStream output = System.out;
		File file = new File("d.in");
		if (file.exists() && file.canRead()) {
			input = new FileInputStream(file);
			output = new PrintStream("d.out");
		}
		br = new BufferedReader(new InputStreamReader(input));
		out = new PrintWriter(output);
		solve();
		out.close();
		br.close();
	}

	static boolean hasNext() throws IOException {
		while (st == null || !st.hasMoreTokens()) {
			String line = br.readLine();
			if (line == null) {
				return false;
			}
			st = new StringTokenizer(line);
		}
		return true;
	}

	static String next() throws IOException {
		return hasNext() ? st.nextToken() : null;
	}

	static int nextInt() throws IOException {
		return Integer.parseInt(next());
	}

	static double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}

	static long nextLong() throws IOException {
		return Long.parseLong(next());
	}
}