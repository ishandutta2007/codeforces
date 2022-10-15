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
        public void solve(int testNumber, FastScanner in, FastPrinter out) {
            int n = in.nextInt();
            int m = in.nextInt();
            int w = in.nextInt();
            int[] a = in.readIntArray(n);
            int[] b = in.readIntArray(n);
            DisjointSetUnion dsu = new DisjointSetUnion(n);
            for (int i = 0; i < m; i++) {
                int v = in.nextInt() - 1;
                int u = in.nextInt() - 1;
                dsu.union(v, u);
            }
            int[] dp = new int[w + 1];
            int[] vs = new int[n];
            for (int root = 0; root < n; root++) {
                if (dsu.get(root) != root) continue;
                int cn = 0;
                for (int j = 0; j < n; j++) {
                    if (dsu.get(j) == root) vs[cn++] = j;
                }
                int[] next = dp.clone();
                int sumA = 0;
                int sumB = 0;
                for (int it = 0; it < cn; it++) {
                    int i = vs[it];
                    int curA = a[i];
                    int curB = b[i];
                    sumA += curA;
                    sumB += curB;
                    for (int cw = w; cw >= curA; cw--) {
                        next[cw] = Math.max(next[cw], dp[cw - curA] + curB);
                    }
                }
                for (int cw = w; cw >= sumA; cw--) {
                    next[cw] = Math.max(next[cw], dp[cw - sumA] + sumB);
                }
                dp = next;
            }
            out.println(dp[w]);
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

        public int[] readIntArray(int n) {
            int[] ret = new int[n];
            for (int i = 0; i < n; i++) {
                ret[i] = nextInt();
            }
            return ret;
        }

    }

    static class DisjointSetUnion {
        int[] p;

        public DisjointSetUnion(int n) {
            p = new int[n];
            clear();
        }

        public void clear() {
            for (int i = 0; i < p.length; i++) {
                p[i] = i;
            }
        }

        public int get(int x) {
            int y = x;
            while (y != p[y]) {
                y = p[y];
            }
            while (x != p[x]) {
                int t = p[x];
                p[x] = y;
                x = t;
            }
            return y;
        }

        public boolean union(int a, int b) {
            a = get(a);
            b = get(b);
            p[a] = b;
            return a != b;
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