import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.IOException;
import java.util.InputMismatchException;
import java.io.InputStreamReader;
import java.io.Writer;
import java.io.BufferedReader;
import java.util.Comparator;
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
        TaskA solver = new TaskA();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskA {
        public void solve(int testNumber, FastScanner in, FastPrinter out) {
            int n = in.nextInt();
            Lamp[] a = new Lamp[n];
            for (int i = 0; i < n; i++) {
                a[i] = new Lamp(in.nextInt(), in.nextInt());
            }
            Arrays.sort(a, new Comparator<Lamp>() {

                public int compare(Lamp o1, Lamp o2) {
                    return Integer.compare(o1.a, o2.a);
                }
            });
            int[] dp = new int[n];
            for (int i = 0; i < n; i++) {
                int l = -1;
                int r = i;
                while (l < r - 1) {
                    int mid = l + r >> 1;
                    if (a[mid].a >= a[i].a - a[i].b) {
                        r = mid;
                    } else {
                        l = mid;
                    }
                }
                if (l < 0) {
                    dp[i] = 1;
                } else {
                    dp[i] = dp[l] + 1;
                }
            }
            int ans = 0;
            for (int i : dp) {
                ans = Math.max(ans, i);
            }
            out.println(n - ans);
        }

        static class Lamp {
            int a;
            int b;

            public Lamp(int a, int b) {
                this.a = a;
                this.b = b;
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