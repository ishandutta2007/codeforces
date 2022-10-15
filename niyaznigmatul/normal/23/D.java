import java.io.InputStreamReader;
import java.io.IOException;
import java.util.InputMismatchException;
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
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskD {

    static final double EPS = 1e-8;

    DoubleComparator dblcmp = new DoubleComparator() {
        public int compare(double a, double b) {
            return Math.abs(a - b) < EPS ? 0 : a < b ? -1 : 1;
        }
    };

    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        Point2DDouble[] three = new Point2DDouble[3];
        for (int i = 0; i < 3; i++) {
            three[i] = new Point2DDouble(in.nextInt(), in.nextInt());
        }
        if (dblcmp.compare(three[0].subtract(three[1]).vmul(three[0].subtract(three[2])), 0) == 0) {
            out.println("NO");
            out.println();
            return;
        }
        all:
        for (int c = 0; c < 3; c++) {
            Point2DDouble[] z = null;
            for (int i = 0; i < 3; i++) {
                if (c == i) {
                    continue;
                }
                int j = 3 - i - c;
                Point2DDouble first = three[i];
                Point2DDouble second = three[c];
                Point2DDouble third = three[j];
                if (dblcmp.compare(0, second.subtract(first).vmul(third.subtract(second))) < 0) {
                    z = new Point2DDouble[]{first, second, third};
                    break;
                }
            }
            if (z == null) {
                continue;
            }
            Line2DDouble line1 = Line2DDouble.getPerpendicularBisection(z[1].add(z[1]).subtract(z[0]), z[1]);
            Line2DDouble line2 = Line2DDouble.getPerpendicularBisection(z[1], z[2]);
            Point2DDouble p1 = line1.intersect(line2, dblcmp);
            if (p1 == null) {
                continue;
            }
            Point2DDouble p2 = z[2].add(z[2]).subtract(p1);
            Point2DDouble p4 = z[1].add(z[1]).subtract(p1);
            Point2DDouble p3 = z[0].add(z[0]).subtract(p4);
            Point2DDouble[] p = new Point2DDouble[]{p1, p2, p3, p4};
            for (int i = 0; i < 4; i++) {
                double w = p[i + 1 & 3].subtract(p[i]).vmul(p[i].subtract(p[i - 1 & 3]));
                if (dblcmp.compare(w, 0) >= 0) {
                    continue all;
                }
            }
            out.println("YES");
            for (Point2DDouble e : p) {
                out.print(e.x + " " + e.y + " ");
            }
            out.println();
            return;
        }
        out.println("NO\n");
    }
}

interface DoubleComparator {
    public int compare(double a, double b);
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

    public String next() {
        StringBuilder sb = new StringBuilder();
        int c = read();
        while (isWhiteSpace(c)) {
            c = read();
        }
        while (!isWhiteSpace(c)) {
            sb.appendCodePoint(c);
            c = read();
        }
        return sb.toString();
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

    public double vmul(Point2DDouble p) {
        return x * p.y - y * p.x;
    }


    public Point2DDouble add(Point2DDouble p) {
        return new Point2DDouble(x + p.x, y + p.y);
    }

    public String toString() {
        return "Point2DDouble{" +
                "x=" + x +
                ", y=" + y +
                '}';
    }
}

class Line2DDouble {

    public double a;
    public double b;
    public double c;

    public Line2DDouble(double a, double b, double c) {
        this.a = a;
        this.b = b;
        this.c = c;
    }

    public static Line2DDouble getPerpendicularBisection(Point2DDouble first, Point2DDouble second) {
        double a = second.x - first.x;
        double b = second.y - first.y;
        double c = -a * (second.x + first.x) - b * (second.y + first.y);
        c *= .5;
        return new Line2DDouble(a, b, c);
    }

    public Point2DDouble intersect(Line2DDouble line, DoubleComparator comparator) {
        double z = a * line.b - b * line.a;
        if (comparator.compare(z, 0) == 0) {
            return null;
        }
        return new Point2DDouble((b * line.c - c * line.b) / z, (c * line.a - a * line.c) / z);
    }

}