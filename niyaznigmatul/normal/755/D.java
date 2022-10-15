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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        static int get(Fenwick f, int from, int to, int n) {
            int ret = 0;
            if (from <= to) {
                ret += f.getSum(from, to + 1);
            } else {
                ret += f.getSum(from, n) + f.getSum(0, to + 1);
            }
            return ret;
        }

        public void solve(int testNumber, FastScanner in, FastPrinter out) {
            int n = in.nextInt();
            Fenwick fout = new Fenwick(n);
            Fenwick fin = new Fenwick(n);
            int k = in.nextInt();
            int cur = 0;
            long ans = 1;
            if (k > n - k) k = n - k;
            int left = Math.max(1, 2 * k - n + 1);
            int right = Math.min(k - 1, n - k - 1);
            if (left > right) throw new AssertionError();
            for (int i = 0; i < n; i++) {
                int have = 0;
                have += get(fout, (cur + 1) % n, (cur + right) % n, n);
                have += get(fin, (cur + left) % n, (cur + k - 1) % n, n);
                ans += have + 1;
                fout.add(cur, 1);
                cur = (cur + k) % n;
                fin.add(cur, 1);
                if (i > 0) out.print(' ');
                out.print(ans);
            }
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

    static class Fenwick {
        int[] a;

        public Fenwick(int n) {
            a = new int[n];
        }

        public void add(int x, int y) {
            for (int i = x; i < a.length; i |= i + 1) {
                a[i] += y;
            }
        }

        public int getSum(int x) {
            if (x >= a.length) x = a.length - 1;
            int ret = 0;
            for (int i = x; i >= 0; i = (i & (i + 1)) - 1) {
                ret += a[i];
            }
            return ret;
        }

        public int getSum(int l, int r) {
            return getSum(r - 1) - getSum(l - 1);
        }

    }
}