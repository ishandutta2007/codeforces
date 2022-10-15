import java.util.List;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.TreeSet;
import java.io.Reader;
import java.io.Writer;
import java.util.Collections;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author niyaznigmatul 
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
}

class TaskC {
    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        int k = in.nextInt();
        int startAll = 0;
        int start = 2 * n + 2;
        int finish = 2 * n + 1;
        MinCostMaxFlowGraph g = new MinCostMaxFlowGraph(2 * n + 3);
        int[] s = new int[n];
        int[] t = new int[n];
        int[] c = new int[n];
        for (int i = 0; i < n; i++) {
            s[i] = in.nextInt();
            t[i] = in.nextInt();
            c[i] = in.nextInt();
        }
        g.addEdge(startAll, start, 0, k, 0);
        MinCostMaxFlowGraph.Edge[] edges = new MinCostMaxFlowGraph.Edge[n];
        for (int i = 0; i < n; i++) {
            g.addEdge(start, 2 * i + 1, 0, 1, 0);
            edges[i] = g.addEdge(2 * i + 1, 2 * i + 2, 0, 1, -c[i]);
            g.addEdge(2 * i + 2, finish, 0, 1, 0);
        }
        for (int i = 0; i < n; i++) {
            int minimal = -1;
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    continue;
                }
                if (minimal >= 0 && s[minimal] + t[minimal] <= s[j] + t[j]) {
                    continue;
                }
                if (s[i] + t[i] <= s[j]) {
                    minimal = j;
                }
            }
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    continue;
                }
                if (s[i] + t[i] <= s[j] && s[j] <= s[minimal] + t[minimal]) {
                    g.addEdge(2 * i + 2, 2 * j + 1, 0, 2 * k, 0);
                    g.addEdge(2 * i + 1, 2 * j + 1, 0, 2 * k, 0);
                }
            }
        }
        g.getMinCostFlowSlowAcyclic(startAll, finish);
        int[] answer = new int[n];
        for (int i = 0; i < n; i++) {
            answer[i] = edges[i].flow;
        }
        out.printArray(answer);
    }
}

class FastScanner extends BufferedReader {

    boolean isEOF;

    public FastScanner(InputStream is) {
        super(new InputStreamReader(is));
    }

    public int read() {
        try {
            int ret = super.read();
            if (isEOF && ret < 0) {
                throw new InputMismatchException();
            }
            isEOF = ret == -1;
            return ret;
        } catch (IOException e) {
            throw new InputMismatchException();
        }
    }

    static boolean isWhiteSpace(int c) {
        return c >= -1 && c <= 32;
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
        while (!isWhiteSpace(c)) {
            if (c < '0' || c > '9') {
                throw new NumberFormatException("digit expected " + (char) c
                        + " found");
            }
            ret = ret * 10 + c - '0';
            c = read();
        }
        return ret * sgn;
    }

    }

class FastPrinter extends PrintWriter {

    public FastPrinter(OutputStream out) {
        super(out);
    }

    public FastPrinter(Writer out) {
        super(out);
    }

    public void printArray(int[] a) {
        for (int i = 0; i < a.length; i++) {
            if (i > 0) {
                print(' ');
            }
            print(a[i]);
        }
        println();
    }


}

class MinCostMaxFlowGraph {
    public static class Edge {
        int from;
        int to;
        public int flow;
        int cap;
        long cost;
        Edge rev;

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

    int n;
    ArrayList<Edge>[] edges;

    public MinCostMaxFlowGraph(int n) {
        this.n = n;
        edges = new ArrayList[n];
        for (int i = 0; i < edges.length; i++) {
            edges[i] = new ArrayList<Edge>();
        }
    }

    public Edge addEdge(int from, int to, int flow, int cap, long cost) {
        Edge e1 = new Edge(from, to, flow, cap, cost);
        Edge e2 = new Edge(to, from, flow, 0, -cost);
        e1.rev = e2;
        e2.rev = e1;
        edges[from].add(e1);
        edges[to].add(e2);
        return e1;
    }

    public long[] getMinCostFlowSlowAcyclic(int source, int target) {
        long[] h = getPotentialsAcyclic();
        boolean[] was = new boolean[n];
        Edge[] lastEdge = new Edge[n];
        long[] d = new long[n];
        int flow = 0;
        long cost = 0;
        while (true) {
            dijkstraSlow(source, was, lastEdge, d, h);
            if (d[target] == Long.MAX_VALUE) {
                break;
            }
            int addFlow = Integer.MAX_VALUE;
            int v = target;
            while (v != source) {
                addFlow = Math.min(addFlow, lastEdge[v].cap - lastEdge[v].flow);
                v = lastEdge[v].from;
            }
            long curCost = d[target] + h[target] - h[source];
            if (curCost >= 0) {
                break;
            }
            cost += curCost * addFlow;
            flow += addFlow;
            v = target;
            while (v != source) {
                lastEdge[v].flow += addFlow;
                lastEdge[v].rev.flow -= addFlow;
                v = lastEdge[v].from;
            }
            for (int i = 0; i < n; i++) {
                h[i] += d[i] == Long.MAX_VALUE ? 0 : d[i];
            }
        }
        return new long[]{flow, cost};
    }

    private long[] getPotentialsAcyclic() {
        long[] h = new long[n];
        {
            List<Integer> topSort = new ArrayList<Integer>();
            boolean[] was = new boolean[n];
            for (int i = 0; i < n; i++) {
                if (!was[i]) {
                    dfs(i, was, topSort);
                }
            }
            Collections.reverse(topSort);
            for (int i : topSort) {
                for (Edge e : edges[i]) {
                    if (e.rev.cap > 0) {
                        h[i] = Math.min(h[i], h[e.to] + e.rev.cost);
                    }
                }
            }
        }
        return h;
    }

    void dijkstraSlow(int source, boolean[] was, Edge[] lastEdge, long[] d, long[] h) {
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
                Edge e = edges[min].get(i);
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


    void dfs(int v, boolean[] was, List<Integer> topSort) {
        was[v] = true;
        for (Edge e : edges[v]) {
            if (e.cap == e.flow || was[e.to]) {
                continue;
            }
            dfs(e.to, was, topSort);
        }
        topSort.add(v);
    }

    }