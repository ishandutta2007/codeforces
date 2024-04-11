import java.io.*;
import java.util.*;
import java.math.*;

public class C implements Runnable {

	static class Point {
		double x;
		double y;

		public Point(double x, double y) {
			super();
			this.x = x;
			this.y = y;
		}

		Point subtract(Point p) {
			return new Point(x - p.x, y - p.y);
		}

		public double len() {
			return Math.sqrt(x * x + y * y);
		}

		public Point setLength(double len) {
			double e = len();
			return new Point(x * len / e, y * len / e);
		}

		public Point rotate(double ang) {
			return new Point(x * Math.cos(ang) - y * Math.sin(ang), x
					* Math.sin(ang) + y * Math.cos(ang));
		}

		public Point add(Point p) {
			return new Point(x + p.x, y + p.y);
		}

		@Override
		public String toString() {
			return "Point [x=" + String.format("%.3f", x) + ", y="
					+ String.format("%.3f", y) + "]";
		}

		public Point multiply(double d) {
			return new Point(d * x, d * y);
		}

		@Override
		public boolean equals(Object obj) {
			if (!(obj instanceof Point)) {
				return false;
			}
			Point p = (Point) obj;
			return compare(x, p.x) == 0 && compare(y, p.y) == 0;
		}
	}

	static final double EPS = 5.41e-5;

	static int compare(double a, double b) {
		return Math.abs(a - b) < EPS ? 0 : Double.compare(a, b);
	}

	static double check(int n, Point[] p) {
		double ret = Double.POSITIVE_INFINITY;
		double angle = 0;
		double one = 2 * Math.PI / n;
		Point v = p[1].subtract(p[0]);
		double d = v.len();
		for (int i = 1; i < n; i++) {
			angle += one;
			double r = d / (2 * Math.sin(angle * .5));
			double angle2;
			if (angle >= Math.PI) {
				angle2 = -(Math.PI - (2 * Math.PI - angle)) * .5;
			} else {
				angle2 = (Math.PI - angle) * .5;
			}
			Point v2 = v.setLength(r).rotate(angle2);
			Point center = p[0].add(v2);
			v2 = v2.multiply(-1);
			for (int j = 0; j < n; j++) {
				// System.err.println(p[2] + " " + center.add(v2));
				if (p[2].equals(center.add(v2))) {
					ret = Math.min(ret, n * r * r * Math.sin(one) * .5);
					break;
				}
				v2 = v2.rotate(one);
			}
		}
		return ret;
	}

	void solve() {
		Point[] p = new Point[3];
		for (int i = 0; i < 3; i++) {
			p[i] = new Point(nextDouble(), nextDouble());
		}
		double ans = Double.POSITIVE_INFINITY;
		for (int i = 3; i <= 100; i++) {
			ans = Math.min(ans, check(i, p));
		}
		out.println(ans);
	}

	FastScanner sc;
	PrintWriter out;

	public void run() {
		Locale.setDefault(Locale.US);
		try {
			sc = new FastScanner(System.in);
			out = new PrintWriter(System.out);
			solve();
			sc.close();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	int nextInt() {
		return sc.nextInt();
	}

	String nextToken() {
		return sc.nextToken();
	}

	long nextLong() {
		return sc.nextLong();
	}

	double nextDouble() {
		return sc.nextDouble();
	}

	BigInteger nextBigInteger() {
		return sc.nextBigInteger();
	}

	class FastScanner extends BufferedReader {
		StringTokenizer st;
		boolean eof;
		String buf;
		String curLine;
		boolean createST;

		public FastScanner(String fileName) throws FileNotFoundException {
			this(fileName, true);
		}

		public FastScanner(String fileName, boolean createST)
				throws FileNotFoundException {
			super(new FileReader(fileName));
			this.createST = createST;
			nextToken();
		}

		public FastScanner(InputStream stream) {
			this(stream, true);
		}

		public FastScanner(InputStream stream, boolean createST) {
			super(new InputStreamReader(stream));
			this.createST = createST;
			nextToken();
		}

		String nextLine() {
			String ret = curLine;
			if (createST) {
				st = null;
			}
			nextToken();
			return ret;
		}

		String nextToken() {
			if (!createST) {
				try {
					curLine = readLine();
				} catch (Exception e) {
					eof = true;
				}
				return null;
			}
			while (st == null || !st.hasMoreTokens()) {
				try {
					curLine = readLine();
					st = new StringTokenizer(curLine);
				} catch (Exception e) {
					eof = true;
					break;
				}
			}
			String ret = buf;
			buf = eof ? "-1" : st.nextToken();
			return ret;
		}

		int nextInt() {
			return Integer.parseInt(nextToken());
		}

		long nextLong() {
			return Long.parseLong(nextToken());
		}

		double nextDouble() {
			return Double.parseDouble(nextToken());
		}

		BigInteger nextBigInteger() {
			return new BigInteger(nextToken());
		}

		public void close() {
			try {
				buf = null;
				st = null;
				curLine = null;
				super.close();
			} catch (Exception e) {

			}
		}

		boolean isEOF() {
			return eof;
		}
	}

	public static void main(String[] args) {
		new C().run();
	}
}