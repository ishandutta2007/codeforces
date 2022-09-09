import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	boolean can(long n, long k, long d1, long d2) {
		long tmp = k - d2  - d1 -d1;
		if (tmp % 3 != 0 || tmp < 0)
			return false;
		tmp /= 3;
		long[] vals = new long[]{tmp, tmp + d1, tmp + d1 + d2};
		for (long t : vals)
			if (t < 0)
				return false;
		long max = Math.max(vals[0], Math.max(vals[1], vals[2]));
		n -= k;
		for (int i = 0; i <3; i++)
		{
			n -= max - vals[i];
			vals[i] = max;
		}
		if (n < 0 || n % 3 != 0)
			return false;
		return true;
	}

	void solve() {
		int t = in.nextInt();
		for (int tt = 0; tt < t; tt++) {
			long n = in.nextLong();
			long k = in.nextLong();
			long d1 = in.nextLong();
			long d2 = in.nextLong();
			if (can(n, k, d1, d2) || can(n, k, -d1, d2) || can(n, k, d1, -d2)
					|| can(n, k, -d1, -d2)) {
				out.println("yes");
			} else {
				out.println("no");
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