import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.OutputStream;
import java.util.Arrays;
import java.io.IOException;
import java.util.InputMismatchException;
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
            int src = in.nextInt() - 1;
            int tar = in.nextInt() - 1;
            DinicGraph g = new DinicGraph(n);
            int[] from = new int[m];
            int[] to = new int[m];
            int[] w = new int[m];
            for (int i = 0; i < m; i++) {
                from[i] = in.nextInt() - 1;
                to[i] = in.nextInt() - 1;
                w[i] = in.nextInt();
            }
            final int INF = 1000000000;
            for (int i = 0; i < m; i++) {
                g.addEdge(from[i], to[i], w[i] == 0 ? INF : 1);
                if (w[i] == 1) {
                    g.addEdge(to[i], from[i], INF);
                }
            }
            long flow = g.getMaxFlow(src, tar);
//        if (flow >= INF) {
//            while (true);
//        }
            boolean[] cut = g.getCut(src, tar);
            DinicGraph.Edge[] edges = new DinicGraph.Edge[m];
            TaskE.Circulation h = new TaskE.Circulation(n);
            int count = 0;
            for (int i = 0; i < m; i++) {
                if (w[i] == 0) continue;
                edges[i] = h.addEdge(from[i], to[i], 1, 2000);
                count++;
            }
            h.addEdge(tar, src, 0, INF);
            long got = h.getCirculation();
//        if (got != count) throw new AssertionError();
            out.println(flow);
//        count = 0;
//        g = new DinicGraph(n);
//        long cutValue = 0;
//        long[] deg = new long[n];
            for (int i = 0; i < m; i++) {
                int curFlow = w[i] == 0 ? 0 : edges[i].flow + 1;
//            deg[from[i]] -= curFlow;
//            deg[to[i]] += curFlow;
                out.print(curFlow + " ");
                if (cut[from[i]] && !cut[to[i]]) {
//                g.addEdge(from[i], to[i], curFlow);
//                cutValue += curFlow;
                    out.println(curFlow);
                    count++;
                } else {
//                g.addEdge(from[i], to[i], curFlow + 1);
                    out.println(curFlow + 1);
                }
            }
//        for (int i = 0; i < n; i++) {
//            if (i != src && i != tar) {
//                if (deg[i] != 0) throw new AssertionError();
//            } else {
////                if (Math.abs(deg[i]) != cutValue) {
////                    throw new AssertionError();
////                }
//            }
//        }
//        if (cutValue != g.getMaxFlow(src, tar)) {
//            throw new AssertionError();
//        }
//        if (count != flow) {
//            int[][] f = new int[10][];
//            for (int i = 0; i < 10; i++) {
//                f[i] = new int[10000000];
//            }
//        }
        }

        static class Circulation extends DinicGraph {
            int src;
            int tar;

            public Circulation(int n) {
                super(n + 2);
                src = n;
                tar = n + 1;
            }

            public DinicGraph.Edge addEdge(int from, int to, int lowCap, int highCap) {
                if (lowCap > 0) {
                    addEdge(src, to, lowCap);
                    addEdge(from, tar, lowCap);
                }
                return addEdge(from, to, highCap - lowCap);
            }

            public long getCirculation() {
                return getMaxFlow(src, tar);
            }

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

        public boolean[] getCut(int source, int target) {
            if (bfs(source, target)) {
                return null;
            }
            boolean[] ret = new boolean[n];
            for (int i = 0; i < n; i++) {
                ret[i] = d[i] != Integer.MAX_VALUE;
            }
            return ret;
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