import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
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
        public void solve(int testNumber, FastScanner in, FastPrinter out) {
            int n = in.nextInt();
            int q = in.nextInt();
            Group[] g = new Group[2];
            int[] a = new int[n >> 1];
            for (int i = 0; i < n; i += 2) {
                a[i / 2] = i;
            }
            g[0] = new Group(a.clone());
            for (int i = 1; i < n; i += 2) {
                a[i / 2] = i;
            }
            g[1] = new Group(a.clone());
            for (int i = 0; i < q; i++) {
                int t = in.nextInt();
                if (t == 2) {
                    Group tt = g[0];
                    g[0] = g[1];
                    g[1] = tt;
                } else {
                    int x = in.nextInt();
                    x = (x % n + n) % n;
                    g[0].shift(x / 2);
                    g[1].shift((x + 1) / 2);
                    if ((x & 1) == 1) {
                        Group tt = g[0];
                        g[0] = g[1];
                        g[1] = tt;
                    }
                }
            }
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < (n >> 1); i++) {
                if (i > 0) sb.append(' ');
                sb.append(g[0].get(i) + 1);
                sb.append(' ');
                sb.append(g[1].get(i) + 1);
            }
            out.println(sb);
        }

        static class Group {
            int[] a;
            int shift;

            public Group(int[] a) {
                this.a = a;
                shift = 0;
            }

            void shift(int x) {
                shift = (shift - x + a.length) % a.length;
            }

            int get(int x) {
                return a[(shift + x) % a.length];
            }

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