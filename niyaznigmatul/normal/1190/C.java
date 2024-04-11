import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.OutputStream;
import java.util.SortedSet;
import java.util.Set;
import java.util.NavigableSet;
import java.io.IOException;
import java.util.InputMismatchException;
import java.io.InputStreamReader;
import java.util.TreeSet;
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
            int k = in.nextInt();
            char[] c = in.next().toCharArray();
            NavigableSet<Integer> ones = new TreeSet<>();
            NavigableSet<Integer> zeros = new TreeSet<>();
            for (int i = 0; i < n; i++) {
                if (c[i] == '0') zeros.add(i);
                else ones.add(i);
            }
            if (ones.isEmpty() || zeros.isEmpty() || ones.last() - ones.first() + 1 <= k || zeros.last() - zeros.first() + 1 <= k) {
                out.println("tokitsukaze");
                return;
            }
            if (check(ones, n, k) && check(zeros, n, k)) {
                out.println("quailty");
                return;
            }
            out.println("once again");
        }

        private boolean check(NavigableSet<Integer> ones, int n, int k) {
            for (int i = 0; i + k <= n; i++) {
                int left = ones.first();
                int right = ones.last();
                if (left >= i) {
                    left = ones.higher(i + k - 1);
                }
                if (right < i + k) {
                    right = ones.lower(i);
                }
                if (right - left + 1 > k) {
                    return false;
                }
            }
            return true;
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

        public String readLine() {
            try {
                return super.readLine();
            } catch (IOException e) {
                return null;
            }
        }

    }
}