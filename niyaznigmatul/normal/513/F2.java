import java.util.List;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Reader;
import java.io.Writer;
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
		TaskF1 solver = new TaskF1();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskF1 {
    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        int males = in.nextInt();
        int females = in.nextInt();
        char[][] c = in.readCharacterFieldTokens(n, m);
        if (males + 1 != females && females + 1 != males) {
            out.println(-1);
            return;
        }
        List<Creature> man = new ArrayList<>();
        List<Creature> woman = new ArrayList<>();
        Creature boss = new Creature(in.nextInt() - 1, in.nextInt() - 1, in.nextInt());
        if (males + 1 == females) {
            man.add(boss);
        } else {
            woman.add(boss);
        }
        for (int i = 0; i < males; i++) {
            man.add(new Creature(in.nextInt() - 1, in.nextInt() - 1, in.nextInt()));
        }
        for (int i = 0; i < females; i++) {
            woman.add(new Creature(in.nextInt() - 1, in.nextInt() - 1, in.nextInt()));
        }
        DinicGraph g = new DinicGraph(2 + man.size() + woman.size() + n * m * 2);
        int[][] a = new int[n * m][n * m];
        for (int[] e : a) {
            Arrays.fill(e, Integer.MAX_VALUE);
        }
        for (int i = 0; i < n * m; i++) a[i][i] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (c[i][j] == '#') continue;
                for (int dx = -1; dx <= 1; dx++) {
                    for (int dy = -1; dy <= 1; dy++) {
                        if (Math.abs(dx) + Math.abs(dy) != 1) continue;
                        int x = i + dx;
                        int y = j + dy;
                        if (x < 0 || y < 0 || x >= n || y >= m || c[x][y] == '#') continue;
                        a[i * m + j][x * m + y] = 1;
                    }
                }
            }
        }
        for (int k = 0; k < a.length; k++) {
            int[] ak = a[k];
            for (int i = 0; i < a.length; i++) {
                int[] ai = a[i];
                for (int j = 0; j < a.length; j++) {
                    int first = ai[k];
                    int second = ak[j];
                    if (first != Integer.MAX_VALUE && second != Integer.MAX_VALUE) {
                        ai[j] = Math.min(ai[j], first + second);
                    }
                }
            }
        }
        DinicGraph.Edge[][][] manEdges = new DinicGraph.Edge[n][m][man.size()];
        DinicGraph.Edge[][][] womanEdges = new DinicGraph.Edge[n][m][woman.size()];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (c[i][j] == '#') continue;
                g.addEdge(i * m + j, i * m + j + n * m, 1);
                for (int k = 0; k < man.size(); k++) {
                    Creature cr = man.get(k);
                    if (a[i * m + j][cr.x * m + cr.y] == Integer.MAX_VALUE) continue;
                    manEdges[i][j][k] = g.addEdge(2 * n * m + k, i * m + j, 1);
                }
                for (int k = 0; k < woman.size(); k++) {
                    Creature cr = woman.get(k);
                    if (a[i * m + j][cr.x * m + cr.y] == Integer.MAX_VALUE) continue;
                    womanEdges[i][j][k] = g.addEdge(i * m + j + n * m, 2 * n * m + man.size() + k, 1);
                }
            }
        }
        if (man.size() != woman.size()) throw new AssertionError();
        int src = n * m * 2 + man.size() + woman.size();
        int tar = src + 1;
        for (int k = 0; k < man.size(); k++) {
            g.addEdge(src, 2 * n * m + k, 1);
        }
        for (int k = 0; k < woman.size(); k++) {
            g.addEdge(2 * n * m + man.size() + k, tar, 1);
        }
        if (g.getMaxFlow(src, tar) != man.size()) {
            out.println(-1);
            return;
        }
        g.clear();
        long l = -1;
        long r = 1L << 40;
        long lastFlow = 0;
        while (l < r - 1) {
            long mid = l + r >> 1;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (c[i][j] == '#') continue;
                    DinicGraph.Edge[] cur = manEdges[i][j];
                    for (int k = 0; k < man.size(); k++) {
                        Creature cr = man.get(k);
                        int val = a[i * m + j][cr.x * m + cr.y];
                        if (val == Integer.MAX_VALUE) {
                            continue;
                        }
                        if ((long) val * cr.speed <= mid) {
                            cur[k].cap = 1;
                        } else {
                            cur[k].cap = 0;
                        }
                    }
                    cur = womanEdges[i][j];
                    for (int k = 0; k < woman.size(); k++) {
                        Creature cr = woman.get(k);
                        int val = a[i * m + j][cr.x * m + cr.y];
                        if (val == Integer.MAX_VALUE) {
                            continue;
                        }
                        if ((long) val * cr.speed <= mid) {
                            cur[k].cap = 1;
                        } else {
                            cur[k].cap = 0;
                        }
                    }
                }
            }
            long curFlow = g.getMaxFlow(src, tar) + lastFlow;
            if (curFlow == man.size()) {
                r = mid;
                g.clear();
                lastFlow = 0;
            } else {
                l = mid;
                lastFlow = curFlow;
            }
        }
        out.println(r);
    }

    static class Creature {
        int x;
        int y;
        int speed;

        Creature(int x, int y, int speed) {
            this.x = x;
            this.y = y;
            this.speed = speed;
        }
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

    public char[][] readCharacterFieldTokens(int n, int m) {
        char[][] ret = new char[n][];
        for (int i = 0; i < n; i++) {
            ret[i] = next().toCharArray();
            if (ret[i].length != m) {
                throw new AssertionError("length expected " + m + ", found " + ret[i].length);
            }
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

class DinicGraph {

    public static class Edge {
        public int from;
        public int to;
        public int flow;
        public int cap;
        public Edge rev;

        public Edge(int from, int to, int flow, int cap) {
            super();
            this.from = from;
            this.to = to;
            this.flow = flow;
            this.cap = cap;
        }

    }

    public ArrayList<Edge>[] edges;
    int[] cur;
    int[] q;
    public int[] d;
    int n;

    public DinicGraph(int n) {
        edges = new ArrayList[n];
        this.n = n;
        for (int i = 0; i < edges.length; i++) {
            edges[i] = new ArrayList<Edge>();
        }
        q = new int[n];
        d = new int[n];
        cur = new int[n];
    }

    public Edge addEdge(int from, int to, int cap) {
        Edge e1 = new Edge(from, to, 0, cap);
        Edge e2 = new Edge(to, from, 0, 0);
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
                Edge e = edges[x].get(i);
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
            Edge e = edges[x].get(i);
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

    public void clear() {
        for (List<Edge> f : edges) {
            for (Edge e : f) {
                e.flow = 0;
            }
        }
    }


}