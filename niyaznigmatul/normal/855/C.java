import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.OutputStream;
import java.util.Arrays;
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
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        static int[][] g;
        static int m;
        static int k;
        static int x;
        static final int MOD = 1000000007;
        static int[][][] dp;

        static int add(int a, int b) {
            a += b;
            if (a >= MOD) a -= MOD;
            return a;
        }

        static int mul(int a, int b) {
            return (int) ((long) a * b % MOD);
        }

        static int any(int v, int e) {
            return add(add(dp[0][v][e], dp[1][v][e]), dp[2][v][e]);
        }

        static int less(int v, int e) {
            return dp[0][v][e];
        }

        static int nonequal(int v, int e) {
            return add(dp[0][v][e], dp[2][v][e]);
        }

        static void dfs(int v, int pv) {
            for (int to : g[v]) {
                if (to == pv) continue;
                dfs(to, v);
            }
            int[] less = new int[x + 1];
            less[0] = k - 1;
            int[] nless = new int[x + 1];
            int[] nequal = new int[x + 1];
            int[] ngreater = new int[x + 1];
            int[] equal = new int[x + 1];
            equal[1] = 1;
            int[] greater = new int[x + 1];
            greater[0] = m - k;
            for (int to : g[v]) {
                if (to == pv) continue;
                Arrays.fill(nless, 0);
                Arrays.fill(ngreater, 0);
                Arrays.fill(nequal, 0);
                for (int have = x; have >= 0; have--) {
                    int value = less[have];
                    if (value == 0) continue;
                    for (int get = 0; get + have <= x; get++) {
                        nless[get + have] = add(nless[get + have], mul(value, any(to, get)));
                    }
                }
                for (int have = x; have >= 0; have--) {
                    int value = equal[have];
                    if (value == 0) continue;
                    for (int get = 0; get + have <= x; get++) {
                        nequal[get + have] = add(nequal[get + have], mul(value, less(to, get)));
                    }
                }
                for (int have = x; have >= 0; have--) {
                    int value = greater[have];
                    if (value == 0) {
                        continue;
                    }
                    for (int get = 0; get + have <= x; get++) {
                        ngreater[get + have] = add(ngreater[get + have], mul(value, nonequal(to, get)));
                    }
                }
                {
                    int[] t = nequal;
                    nequal = equal;
                    equal = t;
                }
                {
                    int[] t = nless;
                    nless = less;
                    less = t;
                }
                {
                    int[] t = ngreater;
                    ngreater = greater;
                    greater = t;
                }
            }
            dp[0][v] = less;
            dp[1][v] = equal;
            dp[2][v] = greater;
        }

        public void solve(int testNumber, FastScanner in, FastPrinter out) {
            int n = in.nextInt();
            m = in.nextInt();
            int[] from = new int[n - 1];
            int[] to = new int[n - 1];
            for (int i = 0; i < n - 1; i++) {
                from[i] = in.nextInt() - 1;
                to[i] = in.nextInt() - 1;
            }
            g = GraphUtils.getEdgesUndirectedUnweighted(n, from, to);
            k = in.nextInt();
            x = in.nextInt();
            dp = new int[3][n][];
            dfs(0, -1);
            int ans = 0;
            for (int i = 0; i <= x; i++) {
                ans = add(ans, any(0, i));
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

    static class GraphUtils {
        public static int[][] getEdgesUndirectedUnweighted(int n, int[] v, int[] u) {
            int[][] edges = new int[n][];
            int[] deg = getDegreeUndirected(n, v, u);
            for (int i = 0; i < n; i++) {
                edges[i] = new int[deg[i]];
            }
            int m = v.length;
            Arrays.fill(deg, 0);
            for (int i = 0; i < m; i++) {
                edges[v[i]][deg[v[i]]++] = u[i];
                edges[u[i]][deg[u[i]]++] = v[i];
            }
            return edges;
        }

        public static int[] getDegreeUndirected(int n, int[] v, int[] u) {
            int[] deg = new int[n];
            for (int i : v) {
                deg[i]++;
            }
            for (int i : u) {
                deg[i]++;
            }
            return deg;
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