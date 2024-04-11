import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.OutputStream;
import java.util.Arrays;
import java.util.HashMap;
import java.io.IOException;
import java.util.InputMismatchException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Map;
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
            in.nextInt();
            String s = in.next();
            int m = in.nextInt();
            Map<String, Integer> all = new HashMap<>();
            for (int i = 0; i < m; i++) {
                String p = in.next();
                int c = in.nextInt();
                Integer got = all.get(p);
                if (got == null || got < c) {
                    got = c;
                }
                all.put(p, got);
            }
            final int X = in.nextInt();
            int n = s.length();
            TaskG.MinCostMaxFlowGraph g = new TaskG.MinCostMaxFlowGraph(n + 1);
            for (int i = 0; i < n; i++) {
                g.addEdge(i, i + 1, X, 0);
            }
            TaskG.Edge[] lastEdge = new TaskG.Edge[n + 1];
            long[] d = new long[n + 1];
            int[] q = new int[n + 2];
            boolean[] inQueue = new boolean[n + 1];
            long ans = 0;
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j <= n; j++) {
                    String sub = s.substring(i, j);
                    if (!all.containsKey(sub)) continue;
                    int c = all.get(sub);
                    Arrays.fill(d, Long.MAX_VALUE);
                    d[i] = 0;
                    int head = 0;
                    int tail = 0;
                    q[tail++] = i;
                    inQueue[i] = true;
                    while (head != tail) {
                        int v = q[head++];
                        if (head == n + 2) {
                            head = 0;
                        }
                        inQueue[v] = false;
                        for (TaskG.Edge e : g.edges[v]) {
                            if (e.flow < e.cap && d[e.from] != Long.MAX_VALUE && d[e.to] > d[e.from] + e.cost) {
                                d[e.to] = d[e.from] + e.cost;
                                lastEdge[e.to] = e;
                                if (!inQueue[e.to]) {
                                    q[tail++] = e.to;
                                    inQueue[e.to] = true;
                                    if (tail == n + 2) tail = 0;
                                }
                            }
                        }
                    }
                    if (d[j] == Long.MAX_VALUE) continue;
                    long pathLen = -c + d[j];
                    if (pathLen >= 0) {
                        g.addEdge(j, i, 1, -c);
                        continue;
                    }
                    ans += pathLen;
                    for (int v = j; v != i; v = lastEdge[v].from) {
                        lastEdge[v].flow++;
                        lastEdge[v].rev.flow--;
                    }
                    g.addEdge(j, i, 1, 1, -c);
//                for (int v = 0; v <= n; v++) {
//                    for (Edge e : g.edges[v]) {
//                        System.out.println(e.from + " " + e.to + " " + e.flow + " " + e.cap + " " + e.cost);
//                    }
//                }
//                System.out.println("==========================");
                }
            }
            out.println(-ans);
        }

        public static class Edge {
            int from;
            int to;
            public int flow;
            int cap;
            long cost;
            TaskG.Edge rev;

            public Edge(int from, int to, int flow, int cap, long cost) {
                this.from = from;
                this.to = to;
                this.flow = flow;
                this.cap = cap;
                this.cost = cost;
            }


            public String toString() {
                return "Edge [from=" + from + ", to=" + to + ", flow=" + flow
                        + ", cap=" + cap + ", cost=" + cost + "]";
            }

        }

        static class MinCostMaxFlowGraph {
            int n;
            ArrayList<TaskG.Edge>[] edges;

            public MinCostMaxFlowGraph(int n) {
                this.n = n;
                edges = new ArrayList[n];
                for (int i = 0; i < edges.length; i++) {
                    edges[i] = new ArrayList<TaskG.Edge>();
                }
            }

            public TaskG.Edge addEdge(int from, int to, int cap, long cost) {
                TaskG.Edge e1 = new TaskG.Edge(from, to, 0, cap, cost);
                TaskG.Edge e2 = new TaskG.Edge(to, from, 0, 0, -cost);
                e1.rev = e2;
                e2.rev = e1;
                edges[from].add(e1);
                edges[to].add(e2);
                return e1;
            }

            public TaskG.Edge addEdge(int from, int to, int cap, int flow, long cost) {
                TaskG.Edge e1 = new TaskG.Edge(from, to, flow, cap, cost);
                TaskG.Edge e2 = new TaskG.Edge(to, from, -flow, 0, -cost);
                e1.rev = e2;
                e2.rev = e1;
                edges[from].add(e1);
                edges[to].add(e2);
                return e1;
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