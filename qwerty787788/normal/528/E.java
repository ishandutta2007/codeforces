import java.io.*;
import java.util.*;

public class E {
	FastScanner in;
	PrintWriter out;

	class Line implements Comparable<Line> {
		int a, b, c;

		public Line(int a, int b, int c) {
			super();
			this.a = a;
			this.b = b;
			this.c = c;
			upd();
		}

		void upd() {
			if (a < 0 || (a == 0 && b < 0)) {
				a *= -1;
				b *= -1;
				c *= -1;
			}
		}

		@Override
		public String toString() {
			return "Line [a=" + a + ", b=" + b + ", c=" + c + "]";
		}

		@Override
		public int compareTo(Line arg0) {
			return Integer.signum(a * arg0.b - b * arg0.a);
		}

	}

	class Point {
		double x, y;

		public Point(double x, double y) {
			super();
			this.x = x;
			this.y = y;
		}

		@Override
		public String toString() {
			return "Point [x=" + x + ", y=" + y + "]";
		}

	}

	final double eps = 1e-7;

	Point intersect(Line l1, Line l2) {
		double d = l1.a * l2.b - l1.b * l2.a;
		double x = l1.b * l2.c - l1.c * l2.b;
		double y = l1.c * l2.a - l1.a * l2.c;
		Point res = new Point(x / d, y / d);
		if (Math.abs(l1.a * res.x + l1.b * res.y + l1.c) > eps) {
			throw new AssertionError();
		}
		if (Math.abs(l2.a * res.x + l2.b * res.y + l2.c) > eps) {
			throw new AssertionError();
		}
		return res;
	}

	void solve() {
		int n = in.nextInt();
		Line[] a = new Line[n];
		for (int i = 0; i < n; i++) {
			a[i] = new Line(in.nextInt(), in.nextInt(), in.nextInt());
		}
		Arrays.sort(a);
		double res = 0;
		for (int i = 0; i < n; i++) {
			Line curL = a[i];
			double sumX = 0, sumY = 0;
			for (int j = 1; j < n; j++) {
				int k = (i + j) % n;
				Point p = intersect(curL, a[k]);
				res -= sumX * p.y - sumY * p.x;
				sumX += p.x;
				sumY += p.y;
			}
		}
		double total = n * (n - 1) * 1.0 * (n - 2) / 3;
		out.println(res / total);
	}

	void run() {
		try {
			in = new FastScanner(new File("E.in"));
			out = new PrintWriter(new File("E.out"));

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
		new E().runIO();
	}
}