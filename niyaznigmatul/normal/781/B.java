import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.OutputStream;
import java.util.Set;
import java.io.IOException;
import java.util.InputMismatchException;
import java.io.InputStreamReader;
import java.util.HashSet;
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
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskB {
        public void solve(int testNumber, FastScanner in, FastPrinter out) {
            int n = in.nextInt();
            String[][] s = new String[n][];
            Set<String> all = new HashSet<>();
            Set<String> bad = new HashSet<>();
            for (int i = 0; i < n; i++) {
                s[i] = new String[]{in.next(), in.next()};
                String z = s[i][0].substring(0, 3);
                if (!all.add(z)) {
                    bad.add(z);
                }
            }
            String[] ans = new String[n];
            while (true) {
                boolean changed = false;
                for (int i = 0; i < n; i++) {
                    if (ans[i] != null) continue;
                    if (bad.contains(s[i][0].substring(0, 3))) {
                        ans[i] = s[i][0].substring(0, 2) + s[i][1].charAt(0);
                        bad.add(ans[i]);
                        changed = true;
                    }
                }
                if (!changed) break;
            }
            for (int i = 0; i < n; i++) {
                if (ans[i] == null) {
                    ans[i] = s[i][0].substring(0, 3);
                }
            }
            all.clear();
            ;
            for (int i = 0; i < n; i++) {
                if (!all.add(ans[i])) {
                    out.println("NO");
                    return;
                }
            }
            out.println("YES");
            for (int i = 0; i < n; i++) {
                out.println(ans[i]);
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