import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.OutputStream;
import java.io.IOException;
import java.util.InputMismatchException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
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
        static final int MOD = 998244353;
        static List<Integer>[] edges;

        static int add(int a, int b) {
            a += b;
            if (a >= MOD) a -= MOD;
            return a;
        }

        static int mul(int a, int b) {
            return (int) ((long) a * b % MOD);
        }

        public void solve(int testNumber, FastScanner in, FastPrinter out) {
            int n = in.nextInt();
            edges = new List[n];
            for (int i = 0; i < n; i++) edges[i] = new ArrayList<>();
            int[] deg = new int[n];
            for (int i = 1; i < n; i++) {
                int p = in.nextInt() - 1;
                edges[p].add(i);
                deg[p]++;
            }
            int[] dp = new int[n];
            int[] dpHave = new int[n];
            for (int v = n - 1; v >= 0; v--) {
                if (edges[v].size() == 0) {
                    dp[v] = 1;
                    dpHave[v] = 1;
                    continue;
                }
                int z = 1;
                int y = 1;
                int[] b = new int[edges[v].size()];
                int[] c = new int[edges[v].size()];
                for (int it = 0; it < edges[v].size(); it++) {
                    int j = edges[v].get(it);
                    b[it] = dp[j];
                    c[it] = dpHave[j];
                }
                int[] d = b.clone();
                for (int it = 0; it < b.length; it++) {
                    int cur = b[it];
                    z = mul(z, cur);
                    cur = add(cur, c[it]);
                    y = mul(y, cur);
                }
                for (int i = 1; i < d.length; i++) {
                    d[i] = mul(d[i], d[i - 1]);
                }
                int x = 0;
                int rightC = 1;
                for (int i = d.length - 1; i >= 0; i--) {
                    int cur = mul(c[i], rightC);
                    if (i > 0) {
                        cur = mul(cur, d[i - 1]);
                    }
                    x = add(x, cur);
                    rightC = mul(rightC, b[i]);
                }
                dp[v] = y;
                dp[v] = add(dp[v], MOD - x);
                dpHave[v] = y;
                dpHave[v] = add(dpHave[v], MOD - z);
            }
            out.println(dp[0]);
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