import java.util.Comparator;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.util.List;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.util.ArrayDeque;
import java.io.Reader;
import java.util.TreeSet;
import java.util.Collections;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Niyaz Nigmatullin
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		FastScanner in = new FastScanner(inputStream);
		FastPrinter out = new FastPrinter(outputStream);
		TaskC2 solver = new TaskC2();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC2 {

    final int[] DX = {1, 0, -1, 0};
    final int[] DY = {0, 1, 0, -1};

    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        int[][] a = new int[n][];
        for (int i = 0; i < n; i++) {
            a[i] = in.readIntArray(m);
        }
        boolean[][] has = new boolean[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int dir = 0; dir < 4; dir++) {
                    int x = i + DX[dir];
                    int y = j + DY[dir];
                    if (x < 0 || y < 0 || x >= n || y >= m || a[x][y] != a[i][j]) continue;
                    has[i][j] = true;
                }
            }
        }
        MinCostMaxFlowGraph g = new MinCostMaxFlowGraph(n * m + 2);
        int source = n * m;
        int target = n * m + 1;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (has[i][j]) {
                    continue;
                }
                if ((i + j & 1) == 1) {
                    g.addEdge(i * m + j, target, 0, 1, 0);
                    continue;
                }
                g.addEdge(source, i * m + j, 0, 1, 0);
                ans++;
                ArrayDeque<Integer> q = new ArrayDeque<>();
                int[][] d = new int[n][m];
                for (int[] e : d) {
                    Arrays.fill(e, Integer.MAX_VALUE);
                }
                d[i][j] = 0;
                q.add(i * m + j);
                while (!q.isEmpty()) {
                    int v = q.pollFirst();
                    int cx = v / m;
                    int cy = v % m;
                    for (int dir = 0; dir < 4; dir++) {
                        int x = cx + DX[dir];
                        int y = cy + DY[dir];
                        if (x < 0 || y < 0 || x >= n || y >= m) continue;
                        int cost = 1;
                        if (a[x][y] == a[cx][cy]) cost = 0;
                        if (d[x][y] > d[cx][cy] + cost) {
                            q.addLast(x * m + y);
                            d[x][y] = d[cx][cy] + cost;
                        }
                    }
                }
                for (int x = 0; x < n; x++) {
                    for (int y = 0; y < m; y++) {
                        if ((x + y & 1) == 0) continue;
                        if (has[x][y]) continue;
                        g.addEdge(i * m + j, x * m + y, 0, 1, d[x][y] - 1);
                    }
                }
            }
        }
//        System.out.println(ans);
        ans += g.getMinCostMaxFlow(source, target)[1];
        out.println(ans);
    }

    }

class FastScanner extends BufferedReader {

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

class FastPrinter extends PrintWriter {

    public FastPrinter(OutputStream out) {
        super(out);
    }

    public FastPrinter(Writer out) {
        super(out);
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


    public long[] getMinCostMaxFlow(int source, int target) {
        long[] h = new long[n];
        for (boolean changed = true; changed; ) {
            changed = false;
            for (int i = 0; i < n; i++) {
                for (Edge e : edges[i]) {
                    if (e.cap > 0 && h[e.to] > h[e.from] + e.cost) {
                        h[e.to] = h[e.from] + e.cost;
                        changed = true;
                    }
                }
            }
        }
        Edge[] lastEdge = new Edge[n];
        long[] d = new long[n];
        int flow = 0;
        long cost = 0;
        while (true) {
            dijkstra(source, lastEdge, d, h);
            if (d[target] == Long.MAX_VALUE) {
                break;
            }
            int addFlow = Integer.MAX_VALUE;
            for (int v = target; v != source; ) {
                Edge e = lastEdge[v];
                addFlow = Math.min(addFlow, e.cap - e.flow);
                v = e.from;
            }
            cost += (d[target] + h[target] - h[source]) * addFlow;
            flow += addFlow;
            for (int v = target; v != source; ) {
                Edge e = lastEdge[v];
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

    void dijkstra(int source, Edge[] lastEdge, final long[] d, long[] h) {
        TreeSet<Integer> ts = new TreeSet<Integer>(new Comparator<Integer>() {
            public int compare(Integer o1, Integer o2) {
                if (d[o1] != d[o2]) {
                    return d[o1] < d[o2] ? -1 : 1;
                }
                return o1 - o2;
            }
        });
        Arrays.fill(d, Long.MAX_VALUE);
        d[source] = 0;
        ts.add(source);
        while (!ts.isEmpty()) {
            int v = ts.pollFirst();
            for (Edge e : edges[v]) {
                if (e.flow >= e.cap) {
                    continue;
                }
                if (d[e.to] == Long.MAX_VALUE
                        || d[e.to] > d[e.from] + e.cost + h[e.from]
                        - h[e.to]) {
                    if (e.cost + h[e.from] - h[e.to] < 0) {
                        throw new AssertionError();
                    }
                    ts.remove(e.to);
                    d[e.to] = d[e.from] + e.cost + h[e.from] - h[e.to];
                    lastEdge[e.to] = e;
                    ts.add(e.to);
                }
            }
        }
    }
}