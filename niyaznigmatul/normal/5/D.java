import java.io.*;
import java.util.*;

public class D implements Runnable {
	public static void main(String[] args) {
		new Thread(new D()).start();
	}

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
				eof = true;
				return "0";
			}
		}
		return st.nextToken();
	}

	public void run() {
		try {
			br = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			solve();
			out.flush();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
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

	static final double EPS = 1e-9;

	static double qEq(double a, double b, double c) {
		double d = b * b - 4 * a * c;
		if (d < -EPS) {
			return Double.NaN;
		}
		return Math.max((-b + Math.sqrt(d)) / (2 * a), (-b - Math.sqrt(d))
				/ (2 * a));
	}

	static int compare(double a, double b) {
		return Math.abs(a - b) < EPS ? 0 : Double.compare(a, b);
	}

	void solve() {
		double a = nextDouble();
		double v = nextDouble();
		double l = nextDouble();
		double d = nextDouble();
		double w = nextDouble();
		if (compare(w, v) >= 0) {
			double t1 = v / a;
			double d1 = a * t1 * t1 * .5;
			if (compare(d1, l) >= 0) {
				out.println(Math.sqrt(2 * l / a));
			} else {
				out.println(t1 + (l - d1) / v);
			}
			return;
		}
		double t1 = w / a;
		double d1 = a * t1 * t1 * .5;
		if (compare(d1, d) >= 0) {
			double t2 = v / a;
			double d2 = a * t2 * t2 * .5;
			if (compare(d2, l) >= 0) {
				out.println(Math.sqrt(2 * l / a));
			} else {
				out.println(t2 + (l - d2) / v);
			}
			return;
		}
		double left = d - d1;
		double timeToV = (v - w) / a;
		double distToV = a * timeToV * timeToV * .5 + w * timeToV;
		// System.err.println(t1 + " " + left + " " + timeToV + " " + distToV
		// + " " + d1);
		if (compare(distToV, left * .5) >= 0) {
			double t2 = qEq(a * .5, w, -left * .5);
			// System.err.println(t2 + " " + (a * t2 * t2 * .5 + w * t2));
			t2 += t1 + t2;
			if (compare(distToV, l - d) >= 0) {
				out.println(t2 + qEq(a * .5, w, d - l));
			} else {
				out.println(t2 + timeToV + (l - d - distToV) / v);
			}
			return;
		}
		double t2 = t1 + 2 * timeToV + (left - 2 * distToV) / v;
		if (compare(distToV, l - d) >= 0) {
			out.println(t2 + qEq(a * .5, w, d - l));
		} else {
			out.println(t2 + timeToV + (l - d - distToV) / v);
		}
	}
}