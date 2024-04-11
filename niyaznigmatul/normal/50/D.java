import java.io.*;
import java.util.*;
import java.math.*;

public class D implements Runnable {

	class Point {
		int x;
		int y;

		public Point(int x, int y) {
			super();
			this.x = x;
			this.y = y;
		}

		double dist(Point p) {
			double dx = x - p.x;
			double dy = y - p.y;
			return Math.sqrt(dx * dx + dy * dy);
		}

	}

	void solve() {
		int n = nextInt();
		int k = nextInt();
		double eps = nextDouble() * .001;
		Point p0 = new Point(nextInt(), nextInt());
		Point[] p = new Point[n];
		for (int i = 0; i < p.length; i++) {
			p[i] = new Point(nextInt(), nextInt());
		}
		double l = 0;
		double r = 1e6;
		double m = (l + r) * .5;
		double[] d = new double[n];
		for (int i = 0; i < d.length; i++) {
			d[i] = p0.dist(p[i]);
		}
		if (check(0, d, p0, k, eps)) {
			out.println(0);
			return;
		}
		while (l != m && r != m) {
			if (check(m, d, p0, k, eps)) {
				r = m;
			} else {
				l = m;
			}
			m = (l + r) * .5;
		}
		out.printf("%.20f\n", r);
	}

	private boolean check(double x, double[] d, Point p0, int k, double prob) {
		double[] pr = new double[d.length];
		for (int i = 0; i < d.length; i++) {			
			if (compare(d[i], x) <= 0) {
				pr[i] = 1;
			} else if (x == 0) {
				pr[i] = 0;
			} else {
				pr[i] = Math.exp(1 - d[i] * d[i] / (x * x));
			}
		}
		int n = d.length;
		double[][] dp = new double[n + 1][n + 1];
		dp[0][0] = 1.;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j <= n; j++) {
				if (j > 0) {
					dp[i][j] += dp[i - 1][j - 1] * pr[i - 1];
				}
				dp[i][j] += dp[i - 1][j] * (1 - pr[i - 1]);
			}
		}
		double ret = 0;
		for (int i = k; i <= n; i++) {
			ret += dp[n][i];
		}
		return compare(1 - ret, prob) <= 0;
	}

	int compare(double a, double b) {
		return Math.abs(a - b) < EPS ? 0 : a < b ? -1 : 1;
	}

	final double EPS = 1e-8;

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
		new D().run();
	}
}