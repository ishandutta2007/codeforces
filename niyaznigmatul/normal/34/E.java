import java.io.*;
import java.util.*;
import java.math.*;

public class E implements Runnable {
	public static void main(String[] args) {
		new E().run();
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;
		boolean eof;
		String buf;

		public FastScanner(String fileName) throws FileNotFoundException {
			br = new BufferedReader(new FileReader(fileName));
			nextToken();
		}

		public FastScanner(InputStream stream) {
			br = new BufferedReader(new InputStreamReader(stream));
			nextToken();
		}

		String nextToken() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					st = new StringTokenizer(br.readLine());
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

		void close() {
			try {
				br.close();
			} catch (Exception e) {

			}
		}

		boolean isEOF() {
			return eof;
		}
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

	class Ball {
		double x, v, m;

		public Ball(int x, int v, int m) {
			this.x = x;
			this.v = v;
			this.m = m;
		}

		double getIt(Ball b) {
			double ret = (b.x - x) / (v - b.v);
			return compare(ret, 0) <= 0 ? Double.POSITIVE_INFINITY : ret;
		}
	}

	int compare(double a, double b) {
		return Math.abs(a - b) < EPS ? 0 : a < b ? -1 : 1;
	}

	final double EPS = 1e-6;

	void solve() {
		int n = nextInt();
		int t = nextInt();
		Ball[] a = new Ball[n];
		for (int i = 0; i < a.length; i++) {
			a[i] = new Ball(nextInt(), nextInt(), nextInt());
		}
		double curTime = 0;
		while (true) {
			double minTime = Double.POSITIVE_INFINITY;
			for (int i = 0; i < a.length; i++) {
				for (int j = i + 1; j < a.length; j++) {
					double tR = a[i].getIt(a[j]);
					if (minTime > tR) {
						minTime = tR;
					}
				}
			}
			if (curTime + minTime >= t) {
				minTime = t - curTime;
				for (int i = 0; i < a.length; i++) {
					a[i].x += a[i].v * minTime;
				}
				break;
			}
			for (int i = 0; i < a.length; i++) {
				a[i].x += a[i].v * minTime;
			}
			for (int i = 0; i < a.length; i++) {
				for (int j = i + 1; j < a.length; j++) {
					if (compare(a[i].x, a[j].x) == 0) {
						double v1 = ((a[i].m - a[j].m) * a[i].v + 2 * a[j].m
								* a[j].v)
								/ (a[i].m + a[j].m);
						double v2 = ((a[j].m - a[i].m) * a[j].v + 2 * a[i].m
								* a[i].v)
								/ (a[i].m + a[j].m);
						a[i].v = v1;
						a[j].v = v2;
					}
				}
			}
			curTime += minTime;
		}
		for (int i = 0; i < a.length; i++) {
			out.printf("%.20f\n", a[i].x);
		}
	}
}