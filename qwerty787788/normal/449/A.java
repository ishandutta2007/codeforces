import java.io.*;
import java.util.*;

public class CF22 {
	FastScanner in;
	PrintWriter out;

	long st(int n, int m, int k) {
		if (n - 1 + m - 1 < k)
			return -1;
		long best = 0;
		int bestX = -1;
		for (int x = 0; x <= Math.min(k, n - 1); x++) {
			int y = k - x;
			if (y < m) {
				long cur = Math.max(0, n / (x + 1) * 1L * (m / (y + 1)));
				if (best <= cur) {
					best = cur;
					bestX = x;
				}
			}
		}
		System.err.println(bestX);
		return best;
	}

	long st2(int n, int m, int k) {
		if (n - 1 + m - 1 < k)
			return -1;
		long best = 0;
		final int MAX = (int) (5 + Math.sqrt(n));
		for (int x1 = 0; x1 < MAX; x1++) {
			if (x1 + 1 <= n) {
				int y = k - x1;
				if (y >= 0 && y + 1 <= m) {
					best = Math.max(best, n / (x1 + 1) * 1L * (m / (y + 1)));
				}
			}
		}
		for (int x2 = 1; x2 < MAX; x2++) {
			int x1 = Math.min(k, n / x2 - 1);
			if (x1 + 1 <= n && x1 >= 0) {
				int y = k - x1;
				if (y >= 0 && y + 1 <= m) {
					best = Math.max(best, n / (x1 + 1) * 1L * (m / (y + 1)));
				}
			}
		}
		return best;
	}

	void solve() {
		// out.println(st(in.nextInt(), in.nextInt(), in.nextInt()));
//		Random rnd = new Random(123);
//		final int M = 2000;
//		for (int it = 0; it < 10000; it++) {
//			int n = rnd.nextInt(M) + 1;
//			int m = rnd.nextInt(M) + 1;
//			int k = rnd.nextInt(M) + 1;
//			long v1 = st(n, m, k);
//			long v2 = st2(n, m, k);
//			System.err.println(n+ "  " + m + " " + k);
//			if (v1 != v2) {
//				throw new AssertionError(v1 + " " +v2);
//			}
//		}
		out.println(st2(in.nextInt(), in.nextInt(), in.nextInt()));
	}

	void run() {
		try {
			in = new FastScanner(new File("object.in"));
			out = new PrintWriter(new File("object.out"));

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
		new CF22().runIO();
	}
}