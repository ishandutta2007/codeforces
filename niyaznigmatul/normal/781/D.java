import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.OutputStream;
import java.io.IOException;
import java.util.InputMismatchException;
import java.io.InputStreamReader;
import java.io.Writer;
import java.util.BitSet;
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
        public void solve(int testNumber, FastScanner in, FastPrinter out) {
            int n = in.nextInt();
            int m = in.nextInt();
            final int BITS = 64;
            BitSet[][][] can = new BitSet[2][BITS][];
            can[0][0] = new BitSet[n];
            can[1][0] = new BitSet[n];
            for (int i = 0; i < n; i++) {
                can[0][0][i] = new BitSet(n);
                can[1][0][i] = new BitSet(n);
            }
            for (int i = 0; i < m; i++) {
                int from = in.nextInt() - 1;
                int to = in.nextInt() - 1;
                int type = in.nextInt();
                can[type][0][from].set(to);
            }
            for (int i = 1; i < BITS; i++) {
                for (int type = 0; type < 2; type++) {
                    can[type][i] = merge(n, can[type][i - 1], can[type ^ 1][i - 1]);
                }
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (can[0][BITS - 1][i].get(j)) {
                        out.println("-1");
                        return;
                    }
                }
            }
            long[][] val = new long[2][n];
            boolean[][] was = new boolean[2][n];
            for (int i = 0; i < BITS; i++) {
                for (int v = 0; v < n; v++) {
                    for (int type = 0; type < 2; type++) {
                        if (was[type][v]) continue;
                        if (can[type][i][v].nextSetBit(0) >= 0) continue;
                        was[type][v] = true;
                        if (i == 0) {
                            continue;
                        }
                        long best = 0;
                        BitSet z = can[type][i - 1][v];
                        for (int u = z.nextSetBit(0); u >= 0; u = z.nextSetBit(u + 1)) {
                            best = Math.max(best, val[type ^ 1][u]);
                        }
                        val[type][v] = (1L << (i - 1)) + best;
                    }
                }
            }
            long ans = 0;
            for (int i = 0; i < 1; i++) ans = Math.max(ans, val[0][i]);
            if (ans > 1000000000000000000L) out.println(-1);
            else
                out.println(ans);
        }

        static BitSet[] merge(int n, BitSet[] a, BitSet[] bb) {
            BitSet[] b = new BitSet[n];
            for (int i = 0; i < n; i++) {
                b[i] = new BitSet(n);
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (bb[i].get(j)) {
                        b[j].set(i);
                    }
                }
            }
            BitSet[] ret = new BitSet[n];
            for (int i = 0; i < n; i++) {
                ret[i] = new BitSet(n);
            }
            BitSet tmp = new BitSet(n);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    tmp.or(a[i]);
                    tmp.and(b[j]);
                    if (tmp.nextSetBit(0) >= 0) {
                        ret[i].set(j);
                    }
                }
                tmp.clear();
            }
            return ret;
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