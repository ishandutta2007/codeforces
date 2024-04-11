import java.io.*;
import java.util.*;
import java.math.*;

public class C implements Runnable {

	static class Point {
		double x;
		double y;
		double z;

		public Point(int x, int y, int z) {
			super();
			this.x = x;
			this.y = y;
			this.z = z;
		}

		public Point(double x, double y, double z) {
			super();
			this.x = x;
			this.y = y;
			this.z = z;
		}

		Point mul(double d) {
			return new Point(x * d, y * d, z * d);
		}

		Point add(Point p) {
			return new Point(x + p.x, y + p.y, z + p.z);
		}

		double dist(Point p) {
			double dx = x - p.x;
			double dy = y - p.y;
			double dz = z - p.z;
			return Math.sqrt(dx * dx + dy * dy + dz * dz);
		}

		Point subtract(Point p) {
			return new Point(x - p.x, y - p.y, z - p.z);
		}

		double abs() {
			return Math.sqrt(x * x + y * y + z * z);
		}

		Point setLength(double d) {
			double e = abs() / d;
			return new Point(x / e, y / e, z / e);
		}

		@Override
		public String toString() {
			return x + " " + y + " " + z;
		}
	}

	void solve() {
		int n = nextInt();
		Point[] p = new Point[n + 1];
		for (int i = 0; i < p.length; i++) {
			p[i] = new Point(nextInt(), nextInt(), nextInt());
		}
		double vp = nextDouble();
		double vs = nextDouble();
		Point harry = new Point(nextDouble(), nextDouble(), nextDouble());
		double sum = 0;
		for (int i = 0; i < n; i++) {
			sum += p[i].dist(p[i + 1]);
		}
		double l = 0;
		double r = sum;
		double m = (l + r) * .5;
		while (l != m && r != m) {
			Point q = getPoint(p, m);
			double len = harry.dist(q);
			if (len * vs <= m * vp) {
				r = m;
			} else {
				l = m;
			}
			m = (l + r) * .5;
		}
		double len = harry.dist(getPoint(p, l));
		if (compare(len * vs, m * vp) > 0) {
			out.println("NO");
			return;
		}
		out.println("YES");
		out.println(l / vs);
		out.println(getPoint(p, l));
	}

	static int compare(double a, double b) {
		final double EPS = 1e-6;
		return Math.abs(a - b) < EPS ? 0 : Double.compare(a, b);
	}

	static Point getPoint(Point[] p, double m) {
		int n = p.length - 1;
		double left = m;
		Point q = null;
		for (int i = 0; i < n; i++) {
			if (left >= p[i].dist(p[i + 1])) {
				left -= p[i].dist(p[i + 1]);
			} else {
				q = p[i].add(p[i + 1].subtract(p[i]).setLength(left));
				break;
			}
		}
		if (q == null) {
			q = p[n + 1];
		}
		return q;
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