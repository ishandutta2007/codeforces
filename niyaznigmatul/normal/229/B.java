import java.util.List;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Random;
import java.util.TreeSet;
import java.io.Reader;
import java.io.Writer;
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
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {
    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        DijkstraGraph g = new DijkstraGraph(n);
        int[][] z = new int[n][];
        for (int i = 0; i < m; i++) {
            int from = in.nextInt() - 1;
            int to = in.nextInt() - 1;
            int w = in.nextInt();
            g.addEdge(from, to, w);
            g.addEdge(to, from, w);
        }
        for (int i = 0; i < n; i++) {
            z[i] = new int[in.nextInt()];
            for (int j = 0; j < z[i].length; j++) {
                z[i][j] = in.nextInt();
            }
            ArrayUtils.sort(z[i]);
        }
        g.z = z;
        long[] answer = g.dijkstra(0);
        out.println(answer[n - 1] == Long.MAX_VALUE ? -1 : answer[n - 1]);
    }

    static class DijkstraGraph {

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
        int[][] z;


        public DijkstraGraph(int n) {
            this.n = n;
            @SuppressWarnings("unchecked")
            ArrayList<Edge>[] edges = new ArrayList[n];
            this.edges = edges;
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
                long current = d[el.v];
                for (int i = 0; i < z[el.v].length; i++) {
                    if (z[el.v][i] == current) {
                        ++current;
                    }
                }
                for (int i = 0; i < edges[el.v].size(); i++) {
                    Edge e = edges[el.v].get(i);
                    if (d[e.to] > current + e.w) {
                        queue.remove(q[e.to]);
                        d[e.to] = q[e.to].d = current + e.w;
                        queue.add(q[e.to]);
                    }
                }
            }
            return d;
        }
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


}

class ArrayUtils {

    static Random rand;

    static public void sort(int[] a) {
        if (rand == null) {
            rand = new Random(System.nanoTime());
        }
        for (int i = 1; i < a.length; i++) {
            int j = rand.nextInt(i + 1);
            int t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
        Arrays.sort(a);
    }
}