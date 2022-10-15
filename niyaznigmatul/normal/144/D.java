import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.ArrayList;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.TreeSet;
import java.io.Writer;
import java.util.StringTokenizer;
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
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
	public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        int s = in.nextInt() - 1;
        DijkstraGraph g = new DijkstraGraph(n);
        DijkstraGraph.Edge[] edges = new DijkstraGraph.Edge[m];
        for (int i = 0; i < m; i++) {
            int from = in.nextInt() - 1;
            int to = in.nextInt() - 1;
            int w = in.nextInt();
            edges[i] = g.addEdge(from, to, w);
            g.addEdge(to, from, w);
        }
        int length = in.nextInt();
        long[] d = g.dijkstra(s);
        int ans = 0;
        for (long e : d) {
            if (e == length) {
                ans++;
            }
        }
        for (DijkstraGraph.Edge e : edges) {
            long len1 = length - d[e.from];
            long len2 = length - d[e.to];
            int add = 0;
            if (len1 < e.w && len1 > 0 && e.w - len1 + d[e.to] >= length) {
                add++;
            }
            if (len2 < e.w && len2 > 0 && e.w - len2 + d[e.from] >= length) {
                add++;
            }
            if (add == 2 && len1 + len2 == e.w) {
                add--;
            }
            ans += add;
        }
        out.println(ans);
	}
}

class FastScanner {
    BufferedReader br;
    StringTokenizer st;
    IOException happened;

    public FastScanner(InputStream is) {
        br = new BufferedReader(new InputStreamReader(is));
    }

    public String next() {
        while (st == null || !st.hasMoreTokens()) {
            try {
                String line = br.readLine();
                st = new StringTokenizer(line);
            } catch (IOException e) {
                happened = e;
                return null;
            }
        }
        return st.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(next());
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

class DijkstraGraph {

    public static class Edge {
        public int from;
        public int to;
        public int w;

        public Edge(int from, int to, int w) {
            this.from = from;
            this.to = to;
            this.w = w;
        }

    }

    static class Element implements Comparable<Element> {
        int v;
        long d;

        public Element(int v, long d) {
            this.v = v;
            this.d = d;
        }

        public int compareTo(Element o) {
            if (d != o.d) {
                return d < o.d ? -1 : 1;
            }
            return v - o.v;
        }
    }

    ArrayList<Edge>[] edges;
    int n;

    public DijkstraGraph(int n) {
        this.n = n;
        edges = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            edges[i] = new ArrayList<Edge>();
        }
    }

    public Edge addEdge(int from, int to, int w) {
        Edge ret = new Edge(from, to, w);
        edges[from].add(ret);
        return ret;
    }

    public long[] dijkstra(int source) {
        long[] d = new long[n];
        Arrays.fill(d, Long.MAX_VALUE);
        Element[] q = new Element[n];
        for (int i = 0; i < q.length; i++) {
            q[i] = new Element(i, Long.MAX_VALUE);
        }
        q[source].d = d[source] = 0;
        TreeSet<Element> queue = new TreeSet<Element>();
        queue.add(q[source]);
        while (!queue.isEmpty()) {
            Element el = queue.pollFirst();
            for (int i = 0; i < edges[el.v].size(); i++) {
                Edge e = edges[el.v].get(i);
                if (d[e.to] > d[e.from] + e.w) {
                    queue.remove(q[e.to]);
                    d[e.to] = q[e.to].d = d[e.from] + e.w;
                    queue.add(q[e.to]);
                }
            }
        }
        return d;
    }
}