import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.OutputStream;
import java.io.Writer;
import java.io.IOException;
import java.util.InputMismatchException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
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
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskB {
        static int getC(int x) {
            int i = 0;
            while (i * (i - 1) / 2 < x) ++i;
            if (i * (i - 1) / 2 == x) return i;
            return -1;
        }

        public void solve(int testNumber, FastScanner in, FastPrinter out) {
            int a00 = in.nextInt();
            int a01 = in.nextInt();
            int a10 = in.nextInt();
            int a11 = in.nextInt();
            if (a00 == 0 && a01 == 0 && a10 == 0 && a11 == 0) {
                out.println("0");
                return;
            }
            int c0 = getC(a00);
            int c1 = getC(a11);
            if (a01 + a10 != 0) {
                if (c0 == 0) ++c0;
                if (c1 == 0) ++c1;
            }
            if (c0 < 0 || c1 < 0 || a01 + a10 != (long) c0 * c1) {
                out.println("Impossible");
                return;
            }
            int all = c0 * c1;
            int countRight = 0;
            while (all != a01 && all - c1 >= a01) {
                ++countRight;
                all -= c1;
            }
            if (all == a01) {
                for (int i = 0; i < c0 - countRight; i++) out.print('0');
                for (int i = 0; i < c1; i++) out.print('1');
                for (int i = 0; i < countRight; i++) out.print('0');
                out.println();
                return;
            }
            int move = all - a01;
            int countLeft = c0 - countRight - 1;
            for (int i = 0; i < countLeft; i++) out.print('0');
            for (int i = 0; i < move; i++) out.print('1');
            out.print('0');
            for (int i = move; i < c1; i++) out.print('1');
            for (int i = 0; i < countRight; i++) out.print('0');
            out.println();
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

    static class FastPrinter extends PrintWriter {
        public FastPrinter(OutputStream out) {
            super(out);
        }

        public FastPrinter(Writer out) {
            super(out);
        }

    }
}