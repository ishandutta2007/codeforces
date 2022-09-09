import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	class Point {
		double x, y;

		public Point(double x, double y) {
			super();
			this.x = x;
			this.y = y;
		}

	}

	double getF(Point p1, Point p2, double m) {
		double x = p1.x * m + p2.x * (1 - m);
		double y = p1.y * m + p2.y * (1 - m);
		return x * x + y * y;
	}

	void solve() {
		int n = in.nextInt();
		int x0 = in.nextInt();
		int y0 = in.nextInt();
		double minR = Double.MAX_VALUE;
		double maxR = 0;
		Point[] a = new Point[n];
		for (int i = 0; i < n; i++) {
			int x = in.nextInt() - x0;
			int y = in.nextInt() - y0;
			a[i] = new Point(x, y);
			double r = Math.sqrt(x * 1L * x + y * 1L * y);
			maxR = Math.max(maxR, r);
		}
		for (int i = 0; i < n; i++) {
			Point p1 = a[i];
			Point p2 = a[(i + 1) % n];
			double l = 0, r = 1;
			for (int it = 0; it < 88; it++) {
				double m1 = l + (r - l) / 3.;
				double m2 = r - (r - l) / 3;
				double f1 = getF(p1, p2, m1);
				double f2 = getF(p1, p2, m2);
				if (f1 < f2) {
					r = m2;
				} else {
					l = m1;
				}
			}
			minR = Math.min(minR, Math.sqrt(getF(p1, p2, l)));
		}
		double res = Math.PI * (maxR * maxR - minR * minR);
		out.println(res);
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