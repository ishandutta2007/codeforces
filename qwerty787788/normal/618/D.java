import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	ArrayList<Integer>[] g;

	long[] useUp;
	long[] notUseUp;

	void go(int v, int p) {
		long[] dp = new long[3];
		for (int to : g[v]) {
			if (to != p) {
				go(to, v);
				long[] ndp = new long[3];
				Arrays.fill(ndp, Long.MAX_VALUE / 3);
				for (int used = 0; used <= 2; used++) {
					for (int use = 0; use <= 1; use++) {
						if (use + used <= 2) {
							long ncost = dp[used]
									+ (use == 0 ? (otherCost + notUseUp[to])
											: (treeCost + useUp[to]));
							ndp[used + use] = Math.min(ndp[used + use], ncost);
						}
					}
				}
				dp = ndp;
			}
		}
		useUp[v] = Math.min(dp[0], dp[1]);
		notUseUp[v] = Math.min(dp[0], Math.min(dp[1], dp[2]));
	}

	int treeCost, otherCost;

	void solve() {
		int n = in.nextInt();
		treeCost = in.nextInt();
		otherCost = in.nextInt();
		int[] a = new int[n];
		g = new ArrayList[n];
		for (int i = 0; i < n; i++) {
			g[i] = new ArrayList<>();
		}
		for (int i = 0; i + 1 < n; i++) {
			int fr = in.nextInt() - 1;
			int to = in.nextInt() - 1;
			a[fr]++;
			a[to]++;
			g[fr].add(to);
			g[to].add(fr);
		}
		if (treeCost <= otherCost) {
			useUp = new long[n];
			notUseUp = new long[n];
			go(0, -1);
			out.println(notUseUp[0]);
		} else {
			for (int i = 0; i < n; i++) {
				if (a[i] == n - 1) {
					out.println(treeCost + otherCost * 1L * (n - 2));
					return;
				}
			}
			out.println(otherCost * 1L * (n - 1));
		}
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