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
        TaskG solver = new TaskG();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskG {
        public void solve(int testNumber, FastScanner in, FastPrinter out) {
            int n = in.nextInt();
            int h = in.nextInt();
            int m = in.nextInt();
            final int INF = 100000000;
            DinicGraph g = new DinicGraph(2 + h * n + m);
            int src = h * n + m;
            int tar = src + 1;
            for (int i = 0; i < n; i++) {
//            g.addEdge(src, i * h, 0);
                g.addEdge(i * h + h - 1, tar, h * h);
                for (int j = 0; j + 1 < h; j++) {
                    int sub = h - j - 1;
                    g.addEdge(i * h + j, i * h + j + 1, h * h - sub * sub);
                    g.addEdge(i * h + j + 1, i * h + j, INF);
                }
            }
            for (int i = 0; i < m; i++) {
                int left = in.nextInt() - 1;
                int right = in.nextInt() - 1;
                int x = in.nextInt();
                int c = in.nextInt();
                for (int e = left; e <= right; e++) {
                    if (x == h) {

                    } else {
                        g.addEdge(h * n + i, e * h + (h - x - 1), INF);
                    }
                }
                g.addEdge(src, h * n + i, c);
            }
            long penalty = g.getMaxFlow(src, tar);
            out.println(h * h * n - penalty);
//        boolean[] z = g.getCut(src, tar);
//        for (int i = 0; i < n; i++) {
//            int mx = -1;
//            for (int j = 0; j < h; j++) {
//                if (z[i * h + j]) {
//                    mx = Math.max(mx, j);
//                }
//            }
//        }
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