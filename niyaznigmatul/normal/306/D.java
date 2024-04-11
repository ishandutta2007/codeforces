import java.io.InputStreamReader;
import java.io.IOException;
import java.util.InputMismatchException;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Random;
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
        int n = in.nextInt();
        if (n <= 4) {
            out.println("No solution");
            return;
        }
        Point2DDouble[] p = new Point2DDouble[n];
        for (int i = 0; i < n; i++) {
            p[i] = new Point2DDouble(Math.cos(i * 2 * Math.PI / n), Math.sin(i * 2 * Math.PI / n));
        }
        Random rand = new Random(58L);
        for (int i = 0; i < n; i++) {
            p[i] = p[i].multiply(rand.nextDouble() * 100 + 600);
        }
        Point2DDouble vect = new Point2DDouble(0, 0);
        for (Point2DDouble e : p) {
            vect = vect.add(e);
        }
        vect = vect.multiply(-1);
        double angle = Math.atan2(vect.y, vect.x);
        if (angle < 0) angle += 2 * Math.PI;
        for (int i = 0; i < n; i++) {
            if (angle <= (i + 1) * 2 * Math.PI / n) {
                double ang1 = i * 2 * Math.PI / n;
                double ang2 = (i + 1) * 2 * Math.PI / n;
                double alpha = ang2 - angle;
                double beta = angle - ang1;
                double theta = Math.PI - alpha - beta;
                double a = vect.length() / Math.sin(theta) * Math.sin(alpha);
                double b = vect.length() / Math.sin(theta) * Math.sin(beta);
                Point2DDouble add1 = new Point2DDouble(Math.cos(ang1), Math.sin(ang1)).multiply(a);
                Point2DDouble add2 = new Point2DDouble(Math.cos(ang2), Math.sin(ang2)).multiply(b);
//                System.out.println(vect + " " + (add1.add(add2)));
                p[i] = p[i].add(add1);
                p[(i + 1) % n] = p[(i + 1) % n].add(add2);
                break;
            }
        }
        int cur = 0;
        Point2DDouble curPoint = new Point2DDouble(0, 0);
        Point2DDouble[] q = new Point2DDouble[n];
        for (int i = 0; i < n; i++) {
            out.println(-curPoint.x + " " + curPoint.y);
            q[i] = curPoint;
            curPoint = curPoint.add(p[cur]);
            cur = (cur + n - 1) % n;
        }
//        System.out.println(curPoint);
//        for (int i = 0; i < n; i++) {
//            int prev = (i + n - 1) % n;
//            int next = (i + 1) % n;
//            Point2DDouble v = q[prev].subtract(q[i]);
//            Point2DDouble u = q[next].subtract(q[i]);
//            double curAngle = Math.atan2(v.vmul(u), u.smul(v));
//            System.out.println("ang[" + i + "] = " + curAngle);
//        }
//        for (int i = 0; i < n; i++) {
//            int next = (i + 1) % n;
//            Point2DDouble u = q[next].subtract(q[i]);
//            System.out.println("dist[" + i + "] = " + u.length());
//        }
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


    public Point2DDouble add(Point2DDouble p) {
        return new Point2DDouble(x + p.x, y + p.y);
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