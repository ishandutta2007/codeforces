import java.awt.Shape;
import java.awt.geom.Line2D;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.awt.geom.AffineTransform;
import java.io.PrintWriter;
import java.awt.geom.Path2D;
import java.io.Writer;
import java.util.List;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.awt.geom.PathIterator;
import java.awt.geom.Area;
import java.io.Reader;
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
		TaskA solver = new TaskA();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskA {
    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        double w = in.nextInt() * .5;
        double h = in.nextInt() * .5;
        double angle = in.nextInt() * Math.PI / 180;
        double[] x = new double[]{-w, w, w, -w};
        double[] y = new double[]{-h, -h, h, h};
        Path2D.Double path = new Path2D.Double();
        for (int i = 0; i < 4; i++) {
            path.append(new Line2D.Double(x[i], y[i], x[i + 1 & 3], y[i + 1 & 3]), true);
        }
        path.closePath();
        Area a = new Area(path);
        double sin = Math.sin(angle);
        double cos = Math.cos(angle);
        Path2D.Double path2 = new Path2D.Double();
        for (int i = 0; i < 4; i++) {
            double xx = x[i] * cos - y[i] * sin;
            double yy = x[i] * sin + y[i] * cos;
            x[i] = xx;
            y[i] = yy;
        }
        for (int i = 0; i < 4; i++) {
            path2.append(new Line2D.Double(x[i], y[i], x[i + 1 & 3], y[i + 1 & 3]), true);
        }
        path2.closePath();
        Area b = new Area(path2);
        a.intersect(b);
        double ans = 0;
        PathIterator it = a.getPathIterator(null);
        List<double[]> p = new ArrayList<>();
        for (; !it.isDone();) {
            double[] cur = new double[2];
            it.currentSegment(cur);
            p.add(cur);
            it.next();
        }
        p.remove(p.size() - 1);
        for (int i = 0; i < p.size(); i++) {
            double[] c = p.get(i);
            double[] d = p.get((i + 1) % p.size());
            ans += c[0] * d[1] - d[0] * c[1];
        }
        out.println(Math.abs(ans) * .5);
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

    }

class FastPrinter extends PrintWriter {

    public FastPrinter(OutputStream out) {
        super(out);
    }

    public FastPrinter(Writer out) {
        super(out);
    }


}