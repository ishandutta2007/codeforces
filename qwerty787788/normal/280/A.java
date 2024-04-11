import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	final static double eps = 1e-9;

	class Point implements Comparable<Point> {
		double x, y;
		double angle;

		public Point(double x, double y) {
			super();
			this.x = x;
			this.y = y;
			this.angle = Math.atan2(y, x);
		}

		double dist(Point an) {
			double dx = an.x - x;
			double dy = an.y - y;
			return Math.sqrt(dx * dx + dy * dy);
		}

		@Override
		public int compareTo(Point arg0) {
			return Double.compare(angle, arg0.angle);
		}

		@Override
		public String toString() {
			return "Point [x=" + x + ", y=" + y + ", angle=" + angle + "]";
		}

	}

	class Line {
		double A, B, C;
		boolean normed;

		Line(Point p1, Point p2) {
			A = p2.y - p1.y;
			B = p1.x - p2.x;
			C = -A * p1.x - B * p1.y;
		}

		void norm() {
			double z = Math.sqrt(A * A + B * B);
			A /= z;
			B /= z;
			C /= z;
			normed = true;
		}

		double dist(Point p) {
			if (!normed)
				norm();
			return Math.abs(A * p.x + B * p.y + C);
		}

		Point intersec(Line another) {
			double zn = A * another.B - another.A * B;
			if (Math.abs(zn) <= eps)
				return null;
			double x = another.C * B - another.B * C;
			double y = another.A * C - another.C * A;
			return new Point(x / zn, y / zn);
		}
	}

	double sq(Point p1, Point p2) {
		return Math.abs(p1.x * p2.y - p1.y * p2.x) / 2.;
	}

	// w <= h
	// 0 <= angle <= pi / 2
	double ans(double w, double h, double angle) {
		Point[] p1 = new Point[4];
		p1[0] = new Point(w, h);
		p1[1] = new Point(-w, h);
		p1[2] = new Point(-w, -h);
		p1[3] = new Point(w, -h);
		Point[] pc = new Point[4];
		for (int i = 0; i < 4; i++) {
			pc[i] = new Point((p1[i].x + p1[(i + 1) % 4].x) / 2.,
					(p1[i].y + p1[(i + 1) % 4].y) / 2.);
		}
		Point[] pcR = new Point[4];
		for (int i = 0; i < 4; i++) {
			double r = Math.sqrt(pc[i].x * pc[i].x + pc[i].y * pc[i].y);
			double a = Math.atan2(pc[i].y, pc[i].x);
			a += angle;
			pcR[i] = new Point(r * Math.cos(a), r * Math.sin(a));
		}
		Point[] pcR2 = new Point[4];
		for (int i = 0; i < 4; i++) {
			double x = pcR[i].x - pcR[i].y;
			double y = pcR[i].y + pcR[i].x;
			pcR2[i] = new Point(x, y);
		}
		Line[] l1 = new Line[4];
		for (int i = 0; i < 4; i++) {
			l1[i] = new Line(p1[i], p1[(i + 1) % 4]);
		}
		Line[] l2 = new Line[4];
		for (int i = 0; i < 4; i++) {
			l2[i] = new Line(pcR[i], pcR2[i]);
		}
		Point[] p3 = new Point[4];
		for (int i = 0; i < 4; i++) {
			p3[i] = l2[i].intersec(l2[(i + 1) % 4]);
		}

		Segment[] s1 = new Segment[4];
		for (int i = 0; i < 4; i++) {
			s1[i] = new Segment(p1[i], p1[(i + 1) % 4]);
		}
		Segment[] s2 = new Segment[4];
		for (int i = 0; i < 4; i++) {
			s2[i] = new Segment(p3[i], p3[(i + 1) % 4]);
		}

		ArrayList<Point> intersec = new ArrayList<>();
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++) {
				IntersectionObject is = intersect(s1[i], s2[j]);
				if (is == null)
					continue;
				if (!is.isPoint)
					throw new AssertionError();
				Point pp = is.point;
				if (pp != null) {
					intersec.add(pp);
				}
			}
		Collections.sort(intersec);
		// for (Point p : intersec)
		// System.err.println(p.toString());
		double res = 0;
		for (int i = 0; i < intersec.size(); i++) {
			Point pp1 = intersec.get(i);
			Point pp2 = intersec.get((i + 1) % intersec.size());
			double ss = sq(pp1, pp2);
			res += ss;
		}
		return res;
	}

	boolean insideSorted(double x, double xLeft, double xRight) {
		return x >= xLeft - eps && x <= xRight + eps;
	}

	boolean inside(double x, double xLeft, double xRight) {
		return insideSorted(x, Math.min(xLeft, xRight), Math.max(xLeft, xRight));
	}

	class Segment {
		Point p1, p2;
		Line l;

		public Segment(Point p1, Point p2) {
			this.p1 = p1;
			this.p2 = p2;
			l = new Line(p1, p2);
		}

		boolean onSegment(Point p) {
			if (l.dist(p) > eps)
				return false;
			return inside(p.x, p1.x, p2.x) && inside(p.y, p1.y, p2.y);
		}

		boolean isPoint() {
			return p1.dist(p2) <= eps;
		}
	}

	class IntersectionObject {
		boolean isPoint;
		Point point;
		Segment segment;

		IntersectionObject(Point point) {
			isPoint = true;
			this.point = point;
		}

		IntersectionObject(Segment segment) {
			isPoint = false;
			this.segment = segment;
		}
	}

	boolean intersectSorted(double xLeft, double xRight, double yLeft,
			double yRight) {
		return Math.max(xLeft, yLeft) - eps <= Math.min(xRight, yRight);
	}

	boolean intersect(double xLeft, double xRight, double yLeft, double yRight) {
		return intersectSorted(Math.min(xLeft, xRight),
				Math.max(xLeft, xRight), Math.min(yLeft, yRight),
				Math.max(yLeft, yRight));
	}

	IntersectionObject intersect(Segment s1, Segment s2) {
		if (!intersect(s1.p1.x, s1.p2.x, s2.p1.x, s2.p2.x)
				|| !intersect(s1.p1.y, s1.p2.y, s2.p1.y, s2.p2.y))
			return null;
		boolean isPoint1 = s1.isPoint();
		boolean isPoint2 = s2.isPoint();
		if (isPoint1 && isPoint2)
			return new IntersectionObject(s1.p1);
		if (isPoint1) {
			if (s2.onSegment(s1.p1))
				return new IntersectionObject(s1.p1);
			return null;
		}
		if (isPoint2) {
			if (s1.onSegment(s2.p1))
				return new IntersectionObject(s2.p1);
			return null;
		}
		Point intersecton = s1.l.intersec(s2.l);
		if (intersecton == null) {
			if (Math.abs(s1.l.dist(s2.p1)) > eps
					|| Math.abs(s2.l.dist(s1.p1)) > eps)
				return null;
			double xLeft1 = Math.min(s1.p1.x, s1.p2.x);
			double xLeft2 = Math.min(s2.p1.x, s2.p2.x);
			double xRight1 = Math.max(s1.p1.x, s1.p2.x);
			double xRight2 = Math.max(s2.p1.x, s2.p2.x);
			double yLeft1 = Math.min(s1.p1.y, s1.p2.y);
			double yLeft2 = Math.min(s2.p1.y, s2.p2.y);
			double yRight1 = Math.max(s1.p1.y, s1.p2.y);
			double yRight2 = Math.max(s2.p1.y, s2.p2.y);
			Point p1 = new Point(Math.max(xLeft1, xLeft2), Math.max(yLeft1,
					yLeft2));
			Point p2 = new Point(Math.min(xRight1, xRight2), Math.min(yRight1,
					yRight2));
			if (s1.l.dist(p1) > eps || s1.l.dist(p2) > eps) {
				p1 = new Point(Math.max(xLeft1, xLeft2), Math.min(yRight1,
						yRight2));
				p2 = new Point(Math.min(xRight1, xRight2), Math.max(yLeft1,
						yLeft2));
			}
			if (p1.dist(p2) <= eps)
				return new IntersectionObject(p1);
			Segment newSeg = new Segment(p1, p2);
			return new IntersectionObject(newSeg);
		} else {
			if (!s1.onSegment(intersecton) || !s2.onSegment(intersecton))
				return null;
			return new IntersectionObject(intersecton);
		}
	}

	void solve() {
		int w = in.nextInt();
		int h = in.nextInt();
		int a = in.nextInt();
		if (a == 0 || a == 180 || (w == h && a == 90)) {
			out.println(w * 1L * h);
			return;
		}
		double b = a * Math.PI / 180.;
		out.println(ans(w / 2., h / 2., b));
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
	}

	public static void main(String[] args) {
		new CF().runIO();
	}
}