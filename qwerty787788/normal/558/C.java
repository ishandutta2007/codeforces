import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	void solve() {
		int n = in.nextInt();
		final int MAX = (int) 1e6 + 1;
		int[] last = new int[MAX];
		int[] cnt = new int[MAX];
		int[] cost = new int[MAX];
		Arrays.fill(last, -1);
		for (int i = 0; i < n; i++) {
			int val = in.nextInt();
			int curCost = 0;
			while (true) {
				last[val] = i;
				cnt[val]++;
				cost[val] += curCost;
				int tmpCost = curCost;
				for (int z = val * 2; z < MAX; z *= 2) {
					tmpCost++;
					if (last[z] == i) {
						break;
					}
					last[z] = i;
					cnt[z]++;
					cost[z] += tmpCost;
				}
				if (val == 0) {
					break;
				}
				val /= 2;
				curCost++;
			}
		}
		int res = Integer.MAX_VALUE;
		for (int i = 0; i < MAX; i++) {
			if (cnt[i] == n) {
				res = Math.min(res, cost[i]);
			}
		}
		out.println(res);
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