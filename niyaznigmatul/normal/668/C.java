import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
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
            double[] max = new double[n];
            double[] min = new double[n];
            for (int i = 0; i < n; i++) {
                max[i] = in.nextDouble();
            }
            for (int i = 0; i < n; i++) {
                min[i] = in.nextDouble();
            }
            for (int i = 1; i < n; i++) {
                max[i] += max[i - 1];
            }
            for (int i = n - 2; i >= 0; i--) {
                min[i] += min[i + 1];
            }
            double[] a = new double[n];
            double[] b = new double[n];
            for (int i = 0; i < n; i++) {
                double c = max[i];
                double d = 1 + c - (i + 1 == n ? 0 : min[i + 1]);
                double D = d * d - 4 * c;
                if (D < 0) D = 0;
                double sqrtD = Math.sqrt(D);
                a[i] = (d + sqrtD) * .5;
                b[i] = d - a[i];
            }
            for (int i = n - 1; i > 0; i--) {
                a[i] -= a[i - 1];
                b[i] -= b[i - 1];
            }
            for (int i = 0; i < n; i++) {
                if (i > 0) out.print(' ');
                out.print(a[i]);
            }
            out.println();
            for (int i = 0; i < n; i++) {
                if (i > 0) out.print(' ');
                out.print(b[i]);
            }
            out.println();
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

        public String next() {
            StringBuilder sb = new StringBuilder();
            int c = read();
            while (isWhiteSpace(c)) {
                c = read();
            }
            if (c < 0) {
                return null;
            }
            while (c >= 0 && !isWhiteSpace(c)) {
                sb.appendCodePoint(c);
                c = read();
            }
            return sb.toString();
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

        public double nextDouble() {
            return Double.parseDouble(next());
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