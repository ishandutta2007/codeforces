import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.OutputStream;
import java.io.IOException;
import java.util.InputMismatchException;
import java.io.InputStreamReader;
import java.io.Writer;
import java.io.BufferedReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
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

    static class TaskC {
        public void solve(int testNumber, FastScanner in, FastPrinter out) {
            int n = in.nextInt();
            int x1 = in.nextInt();
            int y1 = in.nextInt();
            int x2 = in.nextInt();
            int y2 = in.nextInt();
            double ansMin = Double.NEGATIVE_INFINITY;
            double ansMax = Double.POSITIVE_INFINITY;
            for (int i = 0; i < n; i++) {
                Point2DInteger start = new Point2DInteger(in.nextInt(), in.nextInt());
                Point2DInteger v = new Point2DInteger(in.nextInt(), in.nextInt());
                double leftX = Double.POSITIVE_INFINITY;
                double rightX = Double.NEGATIVE_INFINITY;
                if (v.x != 0) {
                    for (int x : new int[]{x1, x2}) {
                        double t = 1. * (x - start.x) / v.x;
                        leftX = Math.min(leftX, t);
                        rightX = Math.max(rightX, t);
                    }
                } else if (start.x <= x1 || start.x >= x2) {
                    out.println(-1);
                    return;
                } else {
                    leftX = Double.NEGATIVE_INFINITY;
                    rightX = Double.POSITIVE_INFINITY;
                }
                double leftY = Double.POSITIVE_INFINITY;
                double rightY = Double.NEGATIVE_INFINITY;
                if (v.y != 0) {
                    for (int y : new int[]{y1, y2}) {
                        double t = 1. * (y - start.y) / v.y;
                        leftY = Math.min(leftY, t);
                        rightY = Math.max(rightY, t);
                    }
                } else if (start.y <= y1 || start.y >= y2) {
                    out.println(-1);
                    return;
                } else {
                    leftY = Double.NEGATIVE_INFINITY;
                    rightY = Double.POSITIVE_INFINITY;
                }
                double left = Math.max(leftY, leftX);
                double right = Math.min(rightY, rightX);
                left = Math.max(left, 0);
                ansMin = Math.max(ansMin, left);
                ansMax = Math.min(ansMax, right);
            }
            if (ansMin + 1e-11 >= ansMax) {
                out.println(-1);
            } else {
                out.println(ansMin);
            }
        }

    }

    static class Point2DInteger {
        public int x;
        public int y;

        public Point2DInteger(int x, int y) {
            this.x = x;
            this.y = y;
        }


        public String toString() {
            return "{" +
                    "x=" + x +
                    ", y=" + y +
                    '}';
        }


        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;

            Point2DInteger that = (Point2DInteger) o;

            if (x != that.x) return false;
            if (y != that.y) return false;

            return true;
        }


        public int hashCode() {
            int result = x;
            result = 31 * result + y;
            return result;
        }

    }

    static class FastPrinter extends PrintWriter {
        public FastPrinter(OutputStream out) {
            super(out);
        }

        public FastPrinter(Writer out) {
            super(out);
        }

    }

    static class FastScanner extends BufferedReader {
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
}