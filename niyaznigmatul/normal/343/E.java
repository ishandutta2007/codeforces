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
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {
    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        int[] from = new int[m];
        int[] to = new int[m];
        int[] cap = new int[m];
        for (int i = 0; i < m; i++) {
            from[i] = in.nextInt() - 1;
            to[i] = in.nextInt() - 1;
            cap[i] = in.nextInt();
        }
        int[] color = new int[n];
        for (int i = 0; i < n; i++) {
            color[i] = 0;
        }
//        {
//            for (int v = 0; v < n; v++) {
//                for (int u = v + 1; u < n; u++) {
//                    DinicGraph g = new DinicGraph(n);
//                    for (int j = 0; j < m; j++) {
//                        g.addEdge(from[j], to[j], cap[j]);
//                        g.addEdge(to[j], from[j], cap[j]);
//                    }
//                    System.out.println(v + " " + u + " " + g.getMaxFlow(v, u));
//                }
//            }
//        }
        int colorsCount = 1;
        int[] ansFrom = new int[n];
        int[] ansTo = new int[n];
        int[] ansCap = new int[n];
        int edges = 0;
        while (true) {
            int[] nColors = new int[colorsCount];
            for (int i : color) {
                nColors[i]++;
            }
            int id = -1;
            for (int i = 0; i < colorsCount; i++) {
                if (nColors[i] > 1) {
                    id = i;
                    break;
                }
            }
            if (id < 0) {
                break;
            }
            int first = -1;
            int second = -1;
            for (int i = 0; i < n; i++) {
                if (color[i] == id) {
                    if (first < 0) {
                        first = i;
                    } else if (second < 0) {
                        second = i;
                    }
                }
            }
            int vCount = colorsCount + nColors[id];
            DinicGraph g = new DinicGraph(vCount);
            DisjointSetUnionFast dsu = new DisjointSetUnionFast(colorsCount);
            for (int i = 0; i < edges; i++) {
                if (ansFrom[i] == id || ansTo[i] == id) {
                    continue;
                }
                dsu.union(ansFrom[i], ansTo[i]);
            }
            int[] number = new int[n];
            int curNumber = colorsCount;
            for (int i = 0; i < n; i++) {
                if (color[i] == id) {
                    number[i] = curNumber++;
                } else {
                    number[i] = dsu.get(color[i]);
                }
            }
            for (int i = 0; i < m; i++) {
                g.addUndirectedEdge(number[from[i]], number[to[i]], cap[i]);
            }
            long flow = g.getMaxFlow(number[first], number[second]);
            boolean[] cut = g.getCut(number[first], number[second]);
            for (int i = 0; i < n; i++) {
                if (color[i] == id) {
                    if (!cut[number[i]]) {
                        color[i] = colorsCount;
                    }
                }
            }
            for (int i = 0; i < edges; i++) {
                if (ansFrom[i] == id) {
                    if (!cut[dsu.get(ansTo[i])]) {
                        ansFrom[i] = colorsCount;
                    }
                }
                if (ansTo[i] == id) {
                    if (!cut[dsu.get(ansFrom[i])]) {
                        ansTo[i] = colorsCount;
                    }
                }
            }
            ansFrom[edges] = id;
            ansTo[edges] = colorsCount;
            ansCap[edges] = (int) flow;
            ++edges;
            ++colorsCount;
        }
        int[] rev = new int[n];
        for (int i = 0; i < n; i++) {
            rev[color[i]] = i;
        }
        for (int i = 0; i < edges; i++) {
            ansFrom[i] = rev[ansFrom[i]];
            ansTo[i] = rev[ansTo[i]];
        }
        int ans = 0;
        for (int i = 0; i < edges; i++) {
            ans += ansCap[i];
        }
        out.println(ans);
        List<Integer> eds = new ArrayList<>();
        for (int i = 0; i < edges; i++) {
            eds.add(i);
        }
        List<Integer> answer = new ArrayList<>();
        boolean[] vs = new boolean[n];
        Arrays.fill(vs, true);
        getAns(eds, answer, ansFrom, ansTo, ansCap, n, vs);
//        System.out.println(Arrays.toString(ansFrom));
//        System.out.println(Arrays.toString(ansTo));
//        System.out.println(Arrays.toString(ansCap));
        for (int i : answer) {
            out.print(i + 1 + " ");
        }
//        {
//            System.out.println(answer);
//            int cans = 0;
//            for (int i = 1; i < answer.size(); i++) {
//                DinicGraph g = new DinicGraph(n);
//                for (int j = 0; j < m; j++) {
//                    g.addEdge(from[j], to[j], cap[j]);
//                    g.addEdge(to[j], from[j], cap[j]);
//                }
//                long cur2 = g.getMaxFlow(answer.get(i - 1), answer.get(i));
//                cans += cur2;
//                System.out.println(answer.get(i - 1) + " " + answer.get(i) + " " + cur2);
//            }
//            System.out.println(cans);
//        }
    }

    static void getAns(List<Integer> edges, List<Integer> answer, int[] ansFrom, int[] ansTo, int[] ansCap, int n, boolean[] vs) {
        if (edges.isEmpty()) {
            for (int i = 0; i < n; i++) {
                if (vs[i]) {
                    answer.add(i);
                }
            }
            return;
        }
        int minimal = -1;
        for (int i : edges) {
            if (minimal < 0 || ansCap[minimal] > ansCap[i]) {
                minimal = i;
            }
        }
//        System.out.println(edges + " " + Arrays.toString(vs) + " " + minimal);
        DisjointSetUnionFast dsu = new DisjointSetUnionFast(n);
        for (int i : edges) {
            if (i == minimal) continue;
            dsu.union(ansFrom[i], ansTo[i]);
        }
        int[] cc = new int[n];
        Arrays.fill(cc, -1);
        int was = 0;
        List<Integer> first = new ArrayList<>();
        List<Integer> second = new ArrayList<>();
        boolean[] fs = new boolean[n];
        boolean[] sc = new boolean[n];
        fs[ansFrom[minimal]] = true;
        sc[ansTo[minimal]] = true;
        for (int i = 0; i < n; i++) {
            if (!vs[i]) {
                continue;
            }
            int comp = dsu.get(i);
            if (cc[comp] < 0) {
                cc[comp] = was++;
            }
            if (cc[comp] == 0) {
                fs[i] = true;
            } else {
                sc[i] = true;
            }
        }
        if (was > 2) throw new AssertionError();
        for (int i : edges) {
            if (i == minimal) continue;
            int comp = dsu.get(ansFrom[i]);
            if (cc[comp] == 0) {
                first.add(i);
            } else if (cc[comp] == 1) {
                second.add(i);
            }
        }
        getAns(first, answer, ansFrom, ansTo, ansCap, n, fs);
        getAns(second, answer, ansFrom, ansTo, ansCap, n, sc);
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
    }

    public Edge addUndirectedEdge(int from, int to, int cap) {
        Edge e1 = new Edge(from, to, 0, cap);
        Edge e2 = new Edge(to, from, 0, cap);
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
            for (Edge e : edges[x]) {
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
        cur = new int[n];
        q = new int[n];
        d = new int[n];
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


}

class DisjointSetUnionFast {
    int[] p;
    int[] r;

    public DisjointSetUnionFast(int n) {
        p = new int[n];
        r = new int[n];
        clear();
    }

    public void clear() {
        for (int i = 0; i < p.length; i++) {
            p[i] = i;
            r[i] = 0;
        }
    }

    public int get(int x) {
        return x != p[x] ? p[x] = get(p[x]) : x;
    }

    public boolean union(int a, int b) {
        a = get(a);
        b = get(b);
        if (a == b) {
            return false;
        }
        if (r[a] >= r[b]) {
            if (r[a] == r[b]) r[a]++;
            p[b] = a;
        } else {
            p[a] = b;
        }
        return true;
    }
}