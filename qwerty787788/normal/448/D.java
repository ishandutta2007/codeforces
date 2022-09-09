import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	long numberLessOrEq(int n, int m, long need) {
		long result = 0;
		for (int x = 1; x <= n; x++) {
			result += Math.min(m, need / x);
		}
		return result;
	}

	void solve() {
		int n = in.nextInt();
		int m = in.nextInt();
		long k = in.nextLong();
		long l = 0, r = n * 1L * m + 10;
		while (r - l > 1) {
			long mid = (l + r) >> 1;
			if (numberLessOrEq(n, m, mid) >= k) {
				r = mid;
			} else {
				l = mid;
			}
		}
		out.println(r);
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