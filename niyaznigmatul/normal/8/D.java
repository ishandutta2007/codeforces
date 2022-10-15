import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Comparator;
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
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int t1 = in.nextInt();
        int t2 = in.nextInt();
        Point2DDouble cinema = new Point2DDouble(in.nextInt(), in.nextInt());
        Point2DDouble home = new Point2DDouble(in.nextInt(), in.nextInt());
        Point2DDouble store = new Point2DDouble(in.nextInt(), in.nextInt());
        double shortestHome = cinema.distance(home);
        double distToStore = cinema.distance(store);
        double storeToHome = store.distance(home);
        double shortestStore = distToStore + storeToHome;
        DoubleComparator cmp = new DoubleComparator() {
            @Override
            public int compare(double a, double b) {
                return Math.abs(a - b) < 1e-11 ? 0 : a < b ? -1 : 1;
            }
        };
        if (cmp.compare(shortestHome + t2, shortestStore) >= 0) {
            out.println(Math.min(shortestHome + t2, shortestStore + t1));
        } else if (cmp.compare(shortestHome + t2 + storeToHome * 2, shortestStore + t1) <= 0) {
            out.println(shortestHome + t2);
        } else {
            double l = 0;
            double r = Math.min(distToStore + t1, shortestHome + t2);
            bsearch:
            for (int it = 0; it < 100; it++) {
                double mid = (l + r) * .5;
                Circle2DDouble f = new Circle2DDouble(new Point2DDouble(store.x, store.y), distToStore + t1 - mid);
                Circle2DDouble g = new Circle2DDouble(new Point2DDouble(home.x, home.y), shortestHome + t2 - mid);
                Circle2DDouble h = new Circle2DDouble(new Point2DDouble(cinema.x, cinema.y), mid);
                Circle2DDouble[] a = new Circle2DDouble[]{f, g, h};
//                System.out.println(mid);
//                System.out.println(f.p.distance(home) + " " + f.radius);
//                System.out.println(g.p.distance(home) + " " + g.radius);
//                System.out.println(h.p.distance(home) + " " + h.radius);
                for (int i = 0; i < 3; i++) {
                    for (int j = i + 1; j < 3; j++) {
                        for (Point2DDouble e : a[i].intersect(a[j], cmp)) {
                            if (    cmp.compare(a[0].p.distance(e), a[0].radius) <= 0 &&
                                    cmp.compare(a[1].p.distance(e), a[1].radius) <= 0 &&
                                    cmp.compare(a[2].p.distance(e), a[2].radius) <= 0) {
                                l = mid;
                                continue bsearch;
                            }
                        }
                    }
                }
                r = mid;
            }
            out.println((l + r) * .5);
        }
    }
}

class FastScanner extends BufferedReader {

    public FastScanner(InputStream is) {
        super(new InputStreamReader(is));
    }

    public int read() {
        try {
            int ret = super.read();
//            if (isEOF && ret < 0) {
//                throw new InputMismatchException();
//            }
//            isEOF = ret == -1;
            return ret;
        } catch (IOException e) {
            throw new InputMismatchException();
        }
    }

    static boolean isWhiteSpace(int c) {
        return c >= 0 && c <= 32;
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
        while (c >= 0 && !isWhiteSpace(c)) {
            if (c < '0' || c > '9') {
                throw new NumberFormatException("digit expected " + (char) c
                        + " found");
            }
            ret = ret * 10 + c - '0';
            c = read();
        }
        return ret * sgn;
    }

    public String readLine() {
        try {
            return super.readLine();
        } catch (IOException e) {
            return null;
        }
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

class Point2DDouble {
    public double x;
    public double y;

    public Point2DDouble(double x, double y) {
        this.x = x;
        this.y = y;
    }

    public Point2DDouble subtract(Point2DDouble p) {
        return new Point2DDouble(x - p.x, y - p.y);
    }


    public Point2DDouble add(Point2DDouble p) {
        return new Point2DDouble(x + p.x, y + p.y);
    }


    public double distanceSquared(Point2DDouble p) {
        double dx = x - p.x;
        double dy = y - p.y;
        return dx * dx + dy * dy;
    }

    public double distance(Point2DDouble p) {
        return Math.sqrt(distanceSquared(p));
    }

    public String toString() {
        return "Point2DDouble{" +
                "x=" + x +
                ", y=" + y +
                '}';
    }

    public Point2DDouble multiply(double d) {
        return new Point2DDouble(x * d, y * d);
    }

    public double squaredLength() {
        return x * x + y * y;
    }

    public double length() {
        return Math.sqrt(squaredLength());
    }

}

abstract class DoubleComparator {

    abstract public int compare(double a, double b);

}

class Circle2DDouble {
    public Point2DDouble p;
    public double radius;

    public Circle2DDouble(Point2DDouble p, double radius) {
        this.p = p;
        this.radius = radius;
    }

    public Point2DDouble[] intersect(Circle2DDouble c, DoubleComparator dblComp) {
        double d = p.distance(c.p);
        if (dblComp.compare(d, radius + c.radius) > 0 ||
                dblComp.compare(d + Math.min(radius, c.radius), Math.max(radius, c.radius)) < 0) {
            return new Point2DDouble[0];
        }
        if (dblComp.compare(d, 0) == 0) {
            return null;
        }
        double diff = (radius * radius - c.radius * c.radius) / d;
        double d1 = (d + diff) * .5;
        Point2DDouble v = c.p.subtract(p);
        Point2DDouble v1 = v.multiply(d1 / v.length());
        double z = radius * radius - d1 * d1;
        Point2DDouble p0 = p.add(v1);
//        if (dblComp.compare(z, 0) < 0) {
//            System.out.println(this + " " + c);
//            System.out.println(d + " " + (radius + c.radius));
//            throw new AssertionError();
//        }
        if (dblComp.compare(z, 0) <= 0) {
            return new Point2DDouble[]{p0};
        }
        z = Math.sqrt(z);
        Point2DDouble v2 = new Point2DDouble(-v.y, v.x).multiply(z / v.length());
        return new Point2DDouble[]{p0.add(v2), p0.subtract(v2)};
    }

    public String toString() {
        return p.toString() + " " + radius;
    }
}