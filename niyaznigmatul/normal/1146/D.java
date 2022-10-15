import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.OutputStream;
import java.util.Arrays;
import java.io.IOException;
import java.util.InputMismatchException;
import java.io.InputStreamReader;
import java.util.TreeSet;
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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        public void solve(int testNumber, FastScanner in, FastPrinter out) {
            int m = in.nextInt();
            int a = in.nextInt();
            int b = in.nextInt();
            int mx = Math.min(m, 4 * (a + b));
            final int[] d = new int[mx + 1];
            Arrays.fill(d, Integer.MAX_VALUE);
            d[0] = 0;
            TreeSet<Integer> q = new TreeSet<>(new Comparator<Integer>() {

                public int compare(Integer o1, Integer o2) {
                    int c = Integer.compare(d[o1], d[o2]);
                    if (c != 0) return c;
                    return Integer.compare(o1, o2);
                }
            });
            q.add(0);
            int[] ans = new int[mx + 1];
            while (!q.isEmpty()) {
                int v = q.pollFirst();
                ans[d[v]]++;
                if (v - b >= 0 && d[v - b] == Integer.MAX_VALUE) {
                    d[v - b] = d[v];
                    q.add(v - b);
                }
                if (v + a <= mx && d[v + a] == Integer.MAX_VALUE) {
                    d[v + a] = Math.max(d[v], v + a);
                    q.add(v + a);
                }
            }
            long answer = 0;
            long current = 0;
            for (int i = 0; i <= mx; i++) {
                current += ans[i];
                answer += current;
            }
//        if (mx == 4 * (a + b) && mx / MathUtils.gcd(a, b) + 1 != current) throw new AssertionError();
            int i = mx + 1;
            int g = MathUtils.gcd(a, b);
            while (i <= m && i % g != 0) {
                answer += i / g + 1;
                ++i;
            }
            if (i <= m) {
                int last = m / g * g;
                int from = i / g + 1;
                int to = last / g + 1;
                answer += ((long) to * (to - 1) - (long) from * (from - 1)) / 2L * g;
                while (last <= m) {
                    answer += last / g + 1;
                    last++;
                }
            }
            out.println(answer);
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

    static class MathUtils {
        public static int gcd(int a, int b) {
            if (a < 0) a = -a;
            if (b < 0) b = -b;
            while (b != 0) {
                int t = a % b;
                a = b;
                b = t;
            }
            return a;
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