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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        public void solve(int testNumber, FastScanner in, FastPrinter out) {
            int n = in.nextInt();
            int m = in.nextInt();
            TaskD.Circulation g = new TaskD.Circulation(n);
            long ans = 0;
            final int INF = 100000000;
            for (int i = 0; i < m; i++) {
                int from = in.nextInt() - 1;
                int to = in.nextInt() - 1;
                int cap = in.nextInt();
                int flow = in.nextInt();
                if (flow <= cap) {
                    g.addEdge(from, to, flow, flow, 0);
                    g.addEdge(from, to, 0, cap - flow, 1);
                    g.addEdge(from, to, 0, INF, 2);
                    g.addEdge(to, from, 0, flow, 1);
                } else {
                    ans += flow - cap;
                    g.addEdge(from, to, flow, flow, 0);
                    g.addEdge(from, to, 0, INF, 2);
                    g.addEdge(to, from, 0, flow - cap, 0);
                    g.addEdge(to, from, 0, cap, 1);
                }
            }
            g.addEdge(n - 1, 0, 0, INF, 0);
            ans += g.getCost();
            out.println(ans);
        }

        static class Circulation extends MinCostMaxFlowGraph {
            int src;
            int tar;

            public Circulation(int n) {
                super(n + 2);
                src = n;
                tar = n + 1;
            }

            public void addEdge(int from, int to, int lowCap, int highCap, int cost) {
                if (lowCap > 0) {
                    addEdge(src, to, lowCap, cost);
                    addEdge(from, tar, lowCap, cost);
                }
                addEdge(from, to, highCap - lowCap, cost);
            }

            public long getCost() {
                long[] ret = getMinCostMaxFlowSlow(src, tar);
                return ret[1];
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

    static class MinCostMaxFlowGraph {
        int n;
        ArrayList<MinCostMaxFlowGraph.Edge>[] edges;

        public MinCostMaxFlowGraph(int n) {
            this.n = n;
            edges = new ArrayList[n];
            for (int i = 0; i < edges.length; i++) {
                edges[i] = new ArrayList<MinCostMaxFlowGraph.Edge>();
            }
        }

        public MinCostMaxFlowGraph.Edge addEdge(int from, int to, int cap, long cost) {
            MinCostMaxFlowGraph.Edge e1 = new MinCostMaxFlowGraph.Edge(from, to, 0, cap, cost);
            MinCostMaxFlowGraph.Edge e2 = new MinCostMaxFlowGraph.Edge(to, from, 0, 0, -cost);
            e1.rev = e2;
            e2.rev = e1;
            edges[from].add(e1);
            edges[to].add(e2);
            return e1;
        }

        void dijkstraSlow(int source, boolean[] was, MinCostMaxFlowGraph.Edge[] lastEdge, long[] d, long[] h) {
            Arrays.fill(d, Long.MAX_VALUE);
            Arrays.fill(was, false);
            d[source] = 0;
            while (true) {
                int min = -1;
                for (int i = 0; i < d.length; i++) {
                    if (d[i] == Long.MAX_VALUE || was[i]) {
                        continue;
                    }
                    if (min < 0 || d[min] > d[i]) {
                        min = i;
                    }
                }
                if (min < 0) {
                    break;
                }
                was[min] = true;
                for (int i = 0; i < edges[min].size(); i++) {
                    MinCostMaxFlowGraph.Edge e = edges[min].get(i);
                    if (e.cap == e.flow) {
                        continue;
                    }
                    long val = d[e.from] + h[e.from] - h[e.to] + e.cost;
                    if (d[e.to] > val) {
                        d[e.to] = val;
                        lastEdge[e.to] = e;
                    }
                }
            }
        }

        public long[] getMinCostMaxFlowSlow(int source, int target) {
            long[] h = new long[n];
            for (boolean changed = true; changed; ) {
                changed = false;
                for (int i = 0; i < n; i++) {
                    for (MinCostMaxFlowGraph.Edge e : edges[i]) {
                        if (e.cap > 0 && h[e.to] > h[e.from] + e.cost) {
                            h[e.to] = h[e.from] + e.cost;
                            changed = true;
                        }
                    }
                }
            }
            MinCostMaxFlowGraph.Edge[] lastEdge = new MinCostMaxFlowGraph.Edge[n];
            long[] d = new long[n];
            int flow = 0;
            long cost = 0;
            boolean[] was = new boolean[n];
            while (true) {
                dijkstraSlow(source, was, lastEdge, d, h);
                if (d[target] == Long.MAX_VALUE) {
                    break;
                }
                int addFlow = Integer.MAX_VALUE;
                for (int v = target; v != source; ) {
                    MinCostMaxFlowGraph.Edge e = lastEdge[v];
                    addFlow = Math.min(addFlow, e.cap - e.flow);
                    v = e.from;
                }
                cost += (d[target] + h[target] - h[source]) * addFlow;
                flow += addFlow;
                for (int v = target; v != source; ) {
                    MinCostMaxFlowGraph.Edge e = lastEdge[v];
                    e.flow += addFlow;
                    e.rev.flow -= addFlow;
                    v = e.from;
                }
                for (int i = 0; i < n; i++) {
                    h[i] += d[i] == Long.MAX_VALUE ? 0 : d[i];
                }
            }
            return new long[]{flow, cost};
        }

        public static class Edge {
            int from;
            int to;
            public int flow;
            int cap;
            long cost;
            MinCostMaxFlowGraph.Edge rev;

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