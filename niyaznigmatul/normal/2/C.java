import java.io.IOException;
import java.io.InputStreamReader;
import java.util.InputMismatchException;
import java.util.Locale;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Reader;
import java.io.Writer;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Niyaz Nigmatullin
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		FastScanner in = new FastScanner(inputStream);
		FastPrinter out = new FastPrinter(outputStream);
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
    static class Point {
        double x;
        double y;

        Point(double x, double y) {
            this.x = x;
            this.y = y;
        }


        Point add(Point p) {
            return new Point(x + p.x, y + p.y);
        }

        Point sub(Point p) {
            return new Point(x - p.x, y - p.y);
        }

        double abs() {
            return Math.sqrt(x * x + y * y);
        }

        Point mul(double d) {
            return new Point(x * d, y * d);
        }

        public double dist(Point p) {
            double dx = x - p.x;
            double dy = y - p.y;
            return Math.sqrt(dx * dx + dy * dy);
        }
    }

    static interface Figure {
        Point[] intersect(Figure f);
    }

    static class Line implements Figure {
        double a;
        double b;
        double c;

        Line(double a, double b, double c) {
            this.a = a;
            this.b = b;
            this.c = c;
        }

        public Point[] intersect(Figure f) {
            if (f instanceof Circle) {
                return intersectLineCircle(this, (Circle) f);
            }
            if (f instanceof Line) {
                return intersectLines((Line) f, this);
            }
            throw new UnsupportedOperationException();

        }

        public static Line midper(Point p, Point q) {
            Point a = p.add(q).mul(0.5);
            Point v = q.sub(p);
            return new Line(v.x, v.y, -v.x * a.x - v.y * a.y);
        }
    }

    static class Circle implements Figure {
        Point p;
        double r;

        Circle(Point p, double r) {
            this.p = p;
            this.r = r;
        }

        public Point[] intersect(Figure f) {
            if (f instanceof Circle) {
                return intersectCircles(this, (Circle) f);
            }
            if (f instanceof Line) {
                return intersectLineCircle((Line) f, this);
            }
            throw new UnsupportedOperationException();
        }

    }

    static Point[] intersectLines(Line line1, Line line2) {
        double z = line1.a * line2.b - line1.b * line2.a;
        double x = (line1.b * line2.c - line2.b * line1.c) / z;
        double y = (line1.c * line2.a - line2.c * line1.a) / z;
        return new Point[]{new Point(x, y)};
    }

    static Point[] intersectCircles(Circle c1, Circle c2) {
        double dist = c1.p.dist(c2.p);
        if (compare(dist, c1.r + c2.r) > 0 || compare(dist + Math.min(c1.r, c2.r), Math.max(c1.r, c2.r)) < 0) {
            return new Point[0];
        }
        double dif = (c1.r * c1.r - c2.r * c2.r) / dist;
        double d1 = (dist + dif) / 2;
        Point v = c2.p.sub(c1.p);
        Point nv = new Point(v.y, -v.x);
        v = v.mul(d1 / v.abs());
        double dv = Math.sqrt(Math.max(0, c1.r * c1.r - d1 * d1));
        nv = nv.mul(dv / nv.abs());
        return new Point[]{c1.p.add(v).add(nv), c1.p.add(v).sub(nv)};
    }

    static Point[] intersectLineCircle(Line line, Circle c) {
        double dist = (line.a * c.p.x + line.b * c.p.y + line.c) / Math.sqrt(line.a * line.a + line.b * line.b);
        if (compare(Math.abs(dist), c.r) > 0) {
            return new Point[0];
        }
        Point v = new Point(line.a, line.b);
        double dv = Math.sqrt(Math.max(0, c.r * c.r - dist * dist));
        Point nv = new Point(line.b, -line.a);
        v = v.mul(-dist / v.abs());
        nv = nv.mul(dv / nv.abs());
        return new Point[] {c.p.add(v).add(nv), c.p.add(v).sub(nv)};
    }

    static final double EPS = 1e-7;

    static int compare(double a, double b) {
        return Math.abs(a - b) < EPS ? 0 : a < b ? -1 : 1;
    }

    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        Circle[] c = new Circle[3];
        for (int i = 0; i < 3; i++) {
            c[i] = new Circle(new Point(in.nextInt(), in.nextInt()), in.nextInt());
        }
        Figure[] f = new Figure[2];
        for (int j = 1; j < 3; j++) {
            f[j - 1] = compare(c[0].r, c[j].r) == 0 ? Line.midper(c[0].p, c[j].p) : getIt(c[0], c[j]);
        }
        double best = Double.NEGATIVE_INFINITY;
        Point bestP = null;
        for (Point p : f[0].intersect(f[1])) {
            double ang = Math.atan(c[0].r / c[0].p.dist(p));
            if (ang > best) {
                best = ang;
                bestP = p;
            }
        }
        if (!Double.isInfinite(best)) {
            out.printf(Locale.US, "%.5f %.5f\n", bestP.x, bestP.y);
        }
    }

    static Circle getIt(Circle c1, Circle c2) {
        double dist = c1.p.dist(c2.p);
        Point v = c2.p.sub(c1.p);
        Point p1 = c1.p.add(v.mul(dist * c1.r / (c1.r + c2.r) / v.abs()));
        Point p2 = c1.p.add(v.mul(dist * c1.r / (c1.r - c2.r) / v.abs()));
        return new Circle(p1.add(p2).mul(0.5), p1.dist(p2) * .5);
    }
}

class FastScanner extends BufferedReader {

    boolean isEOF;

    public FastScanner(InputStream is) {
        super(new InputStreamReader(is));
    }

    public int read() {
        try {
            int ret = super.read();
            if (isEOF && ret < 0) {
                throw new InputMismatchException();
            }
            isEOF = ret == -1;
            return ret;
        } catch (IOException e) {
            throw new InputMismatchException();
        }
    }

    static boolean isWhiteSpace(int c) {
        return c >= -1 && c <= 32;
    }

    public int nextInt() {
        int c = read();
        while (isWhiteSpace(c)) {
            c = read();
        }
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        int ret = 0;
        while (!isWhiteSpace(c)) {
            if (c < '0' || c > '9') {
                throw new NumberFormatException("digit expected " + (char) c
                        + " found");
            }
            ret = ret * 10 + c - '0';
            c = read();
        }
        return ret * sgn;
    }

    }

class FastPrinter extends PrintWriter {

    public FastPrinter(OutputStream out) {
        super(out);
    }

    public FastPrinter(Writer out) {
        super(out);
    }


}