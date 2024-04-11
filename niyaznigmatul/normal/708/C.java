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
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        static int[][] edges;
        static int[] sz;
        static int[] maxSz;
        static boolean[] can;
        static int half;
        static int n;

        static void dfs(int v, int pv) {
            sz[v] = 1;
            maxSz[v] = 0;
            for (int to : edges[v]) {
                if (to == pv) continue;
                dfs(to, v);
                sz[v] += sz[to];
                maxSz[v] = Math.max(maxSz[v], maxSz[to]);
                if (sz[to] <= half) {
                    maxSz[v] = Math.max(maxSz[v], sz[to]);
                }
            }
        }

        static void dfs2(int v, int pv, int maxSzUp) {
            int szUp = n - sz[v];
            can[v] = true;
            if (szUp - maxSzUp > half) {
                can[v] = false;
            }
            int[] mxPref = new int[edges[v].length - (pv < 0 ? 0 : 1)];
            int[] mxSuf = new int[edges[v].length - (pv < 0 ? 0 : 1)];
            int cc = 0;
            for (int to : edges[v]) {
                if (to == pv) continue;
                if (sz[to] - maxSz[to] > half) {
                    can[v] = false;
                }
                mxPref[cc] = maxSz[to];
                if (sz[to] <= half) {
                    mxPref[cc] = Math.max(mxPref[cc], sz[to]);
                }
                mxSuf[cc] = mxPref[cc];
                ++cc;
            }
            for (int i = 1; i < mxPref.length; i++) mxPref[i] = Math.max(mxPref[i], mxPref[i - 1]);
            for (int i = mxSuf.length - 2; i >= 0; i--) mxSuf[i] = Math.max(mxSuf[i], mxSuf[i + 1]);
            cc = 0;
            for (int to : edges[v]) {
                if (to == pv) continue;
                int newMxSzUp = maxSzUp;
                if (szUp <= half) newMxSzUp = Math.max(newMxSzUp, szUp);
                if (cc > 0) newMxSzUp = Math.max(newMxSzUp, mxPref[cc - 1]);
                if (cc + 1 < mxSuf.length) newMxSzUp = Math.max(newMxSzUp, mxSuf[cc + 1]);
                dfs2(to, v, newMxSzUp);
                ++cc;
            }
        }

        public void solve(int testNumber, FastScanner in, FastPrinter out) {
            n = in.nextInt();
            half = n / 2;
            int[] from = new int[n - 1];
            int[] to = new int[n - 1];
            for (int i = 0; i + 1 < n; i++) {
                from[i] = in.nextInt() - 1;
                to[i] = in.nextInt() - 1;
            }
            edges = GraphUtils.getEdgesUndirectedUnweighted(n, from, to);
            sz = new int[n];
            maxSz = new int[n];
            dfs(0, -1);
            can = new boolean[n];
            dfs2(0, -1, 0);
            for (int i = 0; i < n; i++) {
                if (i > 0) out.print(' ');
                out.print(can[i] ? 1 : 0);
            }
            out.println();
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

    static class FastPrinter extends PrintWriter {
        public FastPrinter(OutputStream out) {
            super(out);
        }

        public FastPrinter(Writer out) {
            super(out);
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
}