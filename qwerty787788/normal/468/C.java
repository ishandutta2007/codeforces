import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	long sum(long x, long y) {
		double res = x + 0.0 + y;
		if (res > Long.MAX_VALUE / 2)
			return Long.MAX_VALUE;
		return x + y;
	}

	long mul(long x, long y) {
		double res = x * 1.0 * y;
		if (res > Long.MAX_VALUE / 2)
			return Long.MAX_VALUE;
		return x * y;
	}

	long sum(long max) {
		long dpLess = 0, dpEq = 0;
		String s = Long.toString(max);
		long dpCntLess = 0;
		for (int i = 0; i < s.length(); i++) {
			long dpLessNew = 0, dpEqNew = 0;
			for (int j = 0; j < 10; j++) {
				dpLessNew = sum(dpLessNew, dpLess);
				dpLessNew = sum(dpLessNew, mul(j, dpCntLess));
				if (j < s.charAt(i) - '0') {
					dpLessNew = sum(dpLessNew, dpEq);
					dpLessNew = sum(dpLessNew, mul(j, 1));
				} else {
					if (j == s.charAt(i) - '0') {
						dpEqNew = sum(dpEqNew, dpEq);
						dpEqNew = sum(dpEqNew, mul(j, 1));
					}
				}
			}
			dpLess = dpLessNew;
			dpEq = dpEqNew;
			dpCntLess = sum(mul(dpCntLess, 10), mul(1, s.charAt(i) - '0'));
		}
		return sum(dpLess, dpEq);
	}

	void solve() {
		long mod = in.nextLong();
		long l = 0, r = (long) 1e18;
		while (r - l > 1) {
			long mid = (l + r) >> 1;
			long sum = sum(mid);
			if (sum >= mod) {
				r = mid;
			} else {
				l = mid;
			}
		}
		long from = 1, to = r;
		while (true) {
			long cur = sum(to) - sum(from - 1);
			if (cur == mod) {
				out.println(from + " " + to);
				return;
			} else {
				if (cur > mod) {
					from++;
				} else {
					to++;
				}
			}
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