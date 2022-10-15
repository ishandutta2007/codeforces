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
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskE {
        public void solve(int testNumber, FastScanner in, FastPrinter out) {
            String s = in.next();
            char[][] c = new char[3][s.length()];
            for (int i = 0; i < s.length(); i++) {
                int x = i;
                for (int j = 0; j < 3; j++) {
                    c[j][i] = (char) (x % 26 + 'a');
                    x /= 26;
                }
            }
            char[][] d = new char[3][];
            for (int i = 0; i < 3; i++) {
                out.println("? " + new String(c[i]));
                out.flush();
                d[i] = in.next().toCharArray();
            }
            int[] p = new int[s.length()];
            for (int i = 0; i < s.length(); i++) {
                int val = 0;
                for (int j = 2; j >= 0; j--) {
                    val *= 26;
                    val += d[j][i] - 'a';
                }
                p[i] = val;
            }
            char[] ans = new char[s.length()];
            for (int i = 0; i < s.length(); i++) {
                ans[p[i]] = s.charAt(i);
            }
            out.println("! " + new String(ans));
            out.flush();
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