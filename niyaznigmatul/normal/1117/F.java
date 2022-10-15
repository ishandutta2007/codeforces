import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.OutputStream;
import java.util.Arrays;
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
        TaskF solver = new TaskF();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskF {
        public void solve(int testNumber, FastScanner in, FastPrinter out) {
            int n = in.nextInt();
            int p = in.nextInt();
            char[] c = in.next().toCharArray();
            boolean[][][] can = new boolean[p][p][1 << p];
            for (boolean[][] e : can) for (boolean[] f : e) Arrays.fill(f, true);
            boolean[][] neigh = new boolean[p][p];
            for (int i = 0; i < p; i++) {
                for (int j = 0; j < p; j++) {
                    neigh[i][j] = in.nextInt() == 1;
                }
            }
            int[] a = new int[p];
            int sz = 0;
            int[] has = new int[p];
            for (char e : c) has[e - 'a']++;
            int[] hasInMask = new int[1 << p];
            hasInMask[0] = 0;
            for (int i = 1; i < 1 << p; i++) {
                hasInMask[i] = hasInMask[i & (i - 1)] + has[Integer.numberOfTrailingZeros(i)];
            }
            for (int i = n - 1; i >= 0; i--) {
                int cur = c[i] - 'a';
                int mask = 0;
                for (int j = 0; j < sz; j++) {
                    if (!neigh[cur][a[j]]) {
                        can[cur][a[j]][mask] = false;
                    }
                    mask |= 1 << a[j];
                    if (a[j] == cur) break;
                }
                int where = -1;
                for (int j = 0; j < sz; j++) {
                    if (a[j] == cur) {
                        where = j;
                        break;
                    }
                }
                if (where < 0) where = sz++;
                while (where > 0) {
                    a[where] = a[where - 1];
                    --where;
                }
                a[where] = cur;
            }
            boolean[] good = new boolean[1 << p];
            Arrays.fill(good, true);
            for (int e = 0; e < p; e++) {
                for (int f = 0; f < p; f++) {
                    for (int mask = 0; mask < 1 << p; mask++) {
                        if (((mask >> e) & 1) == 1 || ((mask >> f) & 1) == 1) continue;
                        if (can[e][f][mask]) continue;
                        good[mask] = false;
                        for (int i = 0; i < p; i++) {
                            if (i == e || i == f) continue;
                            if (((mask >> i) & 1) == 0) {
                                can[e][f][mask | (1 << i)] = false;
                            }
                        }
                    }
                }
            }
            boolean[] canGetTo = new boolean[1 << p];
            canGetTo[0] = true;
            int ans = n;
            for (int i = 0; i < 1 << p; i++) {
                if (!canGetTo[i]) continue;
                ans = Math.min(ans, hasInMask[((1 << p) - 1) & ~i]);
                for (int j = 0; j < p; j++) {
                    int ni = i | (1 << j);
                    if (i != ni && good[ni]) {
                        canGetTo[ni] = true;
                    }
                }
            }
            out.println(ans);
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

    static class FastPrinter extends PrintWriter {
        public FastPrinter(OutputStream out) {
            super(out);
        }

        public FastPrinter(Writer out) {
            super(out);
        }

    }
}