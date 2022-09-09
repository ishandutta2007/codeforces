import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	double[] get(double min1, double max1, double min2, double max2) {
		double[] vals = new double[] { min1 * min2, min1 * max2, max1 * min2,
				max1 * max2 };
		Arrays.sort(vals);
		return new double[] { vals[0], vals[3] };
	}

	void solve() {
		int a = in.nextInt();
		int b = in.nextInt();
		int c = in.nextInt();
		int d = in.nextInt();
		double left = 0, right = 2e9;
		for (int it = 0; it < 100; it++) {
			double mid = (left + right) / 2;
			double aMin = a - mid, aMax = a + mid;
			double bMin = b - mid, bMax = b + mid;
			double cMin = c - mid, cMax = c + mid;
			double dMin = d - mid, dMax = d + mid;
			double[] seg1 = get(aMin, aMax, dMin, dMax);
			double[] seg2 = get(bMin, bMax, cMin, cMax);
			if (Math.min(seg1[1], seg2[1]) >= Math.max(seg1[0], seg2[0])) {
				right = mid;
			} else {
				left = mid;
			}
		}
		out.println((left + right) / 2);
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