import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.OutputStream;
import java.util.Arrays;
import java.io.IOException;
import java.util.InputMismatchException;
import java.util.Random;
import java.io.InputStreamReader;
import java.util.ArrayList;
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
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskE {
        public void solve(int testNumber, FastScanner in, FastPrinter out) {
            int n = in.nextInt();
            int m = in.nextInt();
            int[] ys = new int[2 * m + 2];
            int[] xs = new int[2 * m + 2];
            int[] x1 = new int[m];
            int[] x2 = new int[m];
            int[] y1 = new int[m];
            int[] y2 = new int[m];
            ys[2 * m] = 0;
            ys[2 * m + 1] = n;
            xs[2 * m] = 0;
            ys[2 * m + 1] = n;
            for (int i = 0; i < m; i++) {
                x1[i] = in.nextInt() - 1;
                y1[i] = in.nextInt() - 1;
                x2[i] = in.nextInt();
                y2[i] = in.nextInt();
                ys[2 * i] = y1[i];
                ys[2 * i + 1] = y2[i];
                xs[2 * i] = x1[i];
                xs[2 * i + 1] = x2[i];
            }
            xs = ArrayUtils.sortAndUnique(xs);
            ys = ArrayUtils.sortAndUnique(ys);
            int xn = xs.length - 1;
            int yn = ys.length - 1;
            DinicGraph g = new DinicGraph(2 + xn + yn);
            int src = xn + yn;
            int tar = src + 1;
            for (int i = 0; i < xn; i++) {
                for (int j = 0; j < yn; j++) {
                    for (int e = 0; e < m; e++) {
                        if (x1[e] <= xs[i] && x2[e] >= xs[i + 1] && y1[e] <= ys[j] && y2[e] >= ys[j + 1]) {
                            int cap = Math.min(xs[i + 1] - xs[i], ys[j + 1] - ys[j]);
                            g.addEdge(i, xn + j, cap);
                            break;
                        }
                    }
                }
            }
            for (int i = 0; i < xn; i++) {
                g.addEdge(src, i, xs[i + 1] - xs[i]);
            }
            for (int i = 0; i < yn; i++) {
                g.addEdge(xn + i, tar, ys[i + 1] - ys[i]);
            }
            out.println(g.getMaxFlow(src, tar));
        }

    }

    static class ArrayUtils {
        static final long seed = System.nanoTime();
        static final Random rand = new Random(seed);

        static public int[] sortAndUnique(int[] a) {
            int[] ret = a.clone();
            sort(ret);
            if (ret.length == 0) {
                return ret;
            }
            int last = ret[0];
            int j = 1;
            for (int i = 1; i < ret.length; i++) {
                if (last != ret[i]) {
                    ret[j++] = ret[i];
                    last = ret[i];
                }
            }
            return Arrays.copyOf(ret, j);
        }

        public static void sort(int[] a) {
            shuffle(a);
            Arrays.sort(a);
        }

        public static void shuffle(int[] a) {
            for (int i = 0; i < a.length; i++) {
                int j = rand.nextInt(i + 1);
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
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

    static class DinicGraph {
        public ArrayList<DinicGraph.Edge>[] edges;
        int[] cur;
        int[] q;
        public int[] d;
        int n;

        public DinicGraph(int n) {
            edges = new ArrayList[n];
            this.n = n;
            for (int i = 0; i < edges.length; i++) {
                edges[i] = new ArrayList<DinicGraph.Edge>();
            }
            q = new int[n];
            d = new int[n];
            cur = new int[n];
        }

        public DinicGraph.Edge addEdge(int from, int to, int cap) {
            DinicGraph.Edge e1 = new DinicGraph.Edge(from, to, 0, cap);
            DinicGraph.Edge e2 = new DinicGraph.Edge(to, from, 0, 0);
            e1.rev = e2;
            e2.rev = e1;
            edges[from].add(e1);
            edges[to].add(e2);
            return e1;
        }

        boolean bfs(int source, int target) {
            int head = 0;
            int tail = 1;
            Arrays.fill(d, Integer.MAX_VALUE);
            d[source] = 0;
            q[0] = source;
            while (head < tail) {
                int x = q[head++];
                for (int i = 0; i < edges[x].size(); i++) {
                    DinicGraph.Edge e = edges[x].get(i);
                    if (e.cap - e.flow > 0 && d[e.to] == Integer.MAX_VALUE) {
                        d[e.to] = d[x] + 1;
                        q[tail++] = e.to;
                        if (e.to == target) {
                            return true;
                        }
                    }
                }
            }
            return false;
        }

        public int dfs(int x, int target, int cMin) {
            if (x == target) {
                return cMin;
            }
            for (int i = cur[x]; i < edges[x].size(); cur[x] = ++i) {
                DinicGraph.Edge e = edges[x].get(i);
                if (d[e.to] != d[x] + 1 || e.cap - e.flow == 0) {
                    continue;
                }
                int add = dfs(e.to, target, Math.min(cMin, e.cap - e.flow));
                if (add == 0) {
                    continue;
                }
                e.flow += add;
                e.rev.flow -= add;
                return add;
            }
            return 0;
        }

        public long getMaxFlow(int source, int target) {
            long flow = 0;
            while (bfs(source, target)) {
                Arrays.fill(cur, 0);
                while (true) {
                    int add = dfs(source, target, Integer.MAX_VALUE);
                    if (add == 0) {
                        break;
                    }
                    flow += add;
                }
            }
            return flow;
        }

        public static class Edge {
            public int from;
            public int to;
            public int flow;
            public int cap;
            public DinicGraph.Edge rev;

            public Edge(int from, int to, int flow, int cap) {
                super();
                this.from = from;
                this.to = to;
                this.flow = flow;
                this.cap = cap;
            }

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