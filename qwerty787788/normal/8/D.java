import java.io.*;
import java.util.*;

public class CF {

	class Point {
		double x, y;

		public Point(double x, double y) {
			super();
			this.x = x;
			this.y = y;
		}

		public Point(int x, int y) {
			super();
			this.x = x;
			this.y = y;
		}

	}

	class Circle {
		Point center;
		double r;

		public Circle(Point center, double r) {
			super();
			this.center = center;
			this.r = r;
		}

	}

	double dist(Point p1, Point p2) {
		double dx = p1.x - p2.x;
		double dy = p1.y - p2.y;
		return Math.sqrt(dx * dx + dy * dy);
	}

	double eps = 1e-6;

	Point[] intersect(Circle c1, Circle c2) {
		double d = dist(c1.center, c2.center);
		if (c1.r + c2.r < d - eps || c1.r + d < c2.r - eps
				|| c2.r + d < c1.r - eps)
			return new Point[] {};
		double d1 = (d * d + c1.r * c1.r - c2.r * c2.r) / 2. / d;
		double alpha = d1 / d;
		Point c = new Point(c1.center.x + (c2.center.x - c1.center.x) * alpha,
				c1.center.y + (c2.center.y - c1.center.y) * alpha);
		double dx = c2.center.x - c1.center.x;
		double dy = c2.center.y - c1.center.y;
		dx /= d;
		dy /= d;
		double h = Math.sqrt(Math.max(0, c1.r * c1.r - d1 * d1));
		Point p1 = new Point(c.x + dy * h, c.y - dx * h);
		Point p2 = new Point(c.x - dy * h, c.y + dx * h);
		return new Point[] { p1, p2 };
	}

	boolean insideCircle(Point p, Circle c) {
		return dist(p, c.center) <= c.r;
	}

	boolean intersect(Circle c1, Circle c2, Circle c3) {
		Point[] pp = intersect(c1, c2);
		for (int i = 0; i < pp.length; i++) {
			if (insideCircle(pp[i], c3))
				return true;
		}
		if (insideCircle(c1.center, c2) && insideCircle(c1.center, c3))
			return true;
		if (insideCircle(c2.center, c1) && insideCircle(c2.center, c3))
			return true;
		if (insideCircle(c3.center, c2) && insideCircle(c3.center, c1))
			return true;
		return false;
	}

	boolean isIntersect(Circle c1, Circle c2, Circle c3) {
		if (c1.r < 0 || c2.r < 0 || c3.r < 0)
			return false;
		if (intersect(c1, c2, c3))
			return true;
		if (intersect(c1, c3, c2))
			return true;
		if (intersect(c2, c3, c1))
			return true;
		return false;
	}

	void realSolve() {
		int t1 = in.nextInt();
		int t2 = in.nextInt();
		Point cinema = new Point(in.nextInt(), in.nextInt());
		Point home = new Point(in.nextInt(), in.nextInt());
		Point shop = new Point(in.nextInt(), in.nextInt());
		double ch = dist(home, cinema);
		double cs = dist(cinema, shop);
		double sh = dist(shop, home);
		if (cs + sh - ch <= t2) {
			out.println(Math.min(t1 + cs + sh, t2 + ch));
		} else {
			if (-cs - sh + t1 - t2 >= 0) {
				out.println(t2 + ch);
			} else {
				double l = 0, r = Math.max(cs + sh + t1, t2 + ch);
				System.err.println(l + " " + r);
				Circle cinemaC = new Circle(cinema, 0);
				Circle homeC = new Circle(home, 0);
				Circle shopC = new Circle(shop, 0);
				for (int it = 0; it < 50; it++) {
					double m = (l + r) / 2;
					boolean ok = false;
					cinemaC.r = m;
					homeC.r = t2 + ch - m;
					shopC.r = t1 + cs - m;
					if (isIntersect(cinemaC, homeC, shopC))
						ok = true;
					if (ok)
						l = m;
					else
						r = m;
				}
				out.println(l);
			}
		}
	}

	private class InputReader {
		StringTokenizer st;
		BufferedReader br;

		public InputReader(File f) {
			try {
				br = new BufferedReader(new FileReader(f));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		public InputReader(InputStream f) {
			br = new BufferedReader(new InputStreamReader(f));
		}

		String next() {
			while (st == null || !st.hasMoreElements()) {
				String s;
				try {
					s = br.readLine();
				} catch (IOException e) {
					return null;
				}
				if (s == null)
					return null;
				st = new StringTokenizer(s);
			}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}

		boolean hasMoreElements() {
			while (st == null || !st.hasMoreElements()) {
				String s;
				try {
					s = br.readLine();
				} catch (IOException e) {
					return false;
				}
				st = new StringTokenizer(s);
			}
			return st.hasMoreElements();
		}

		long nextLong() {
			return Long.parseLong(next());
		}
	}

	InputReader in;
	PrintWriter out;

	void solve() {
		in = new InputReader(new File("object.in"));
		try {
			out = new PrintWriter(new File("object.out"));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}

		realSolve();

		out.close();
	}

	void solveIO() {
		in = new InputReader(System.in);
		out = new PrintWriter(System.out);

		realSolve();

		out.close();

	}

	public static void main(String[] args) {
		new CF().solveIO();
	}
}