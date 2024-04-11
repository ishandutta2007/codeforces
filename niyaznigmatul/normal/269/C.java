import java.util.List;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Reader;
import java.io.Writer;
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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
    static class Edge {
        int from;
        int to;
        int w;

        Edge(int from, int to, int w) {
            this.from = from;
            this.to = to;
            this.w = w;
        }
    }

    static List<Edge>[] edges;

    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        edges = new List[n];
        for (int i = 0; i < n; i++) {
            edges[i] = new ArrayList<Edge>();
        }
        Edge[] ed = new Edge[m];
        for (int i = 0; i < m; i++) {
            int from = in.nextInt() - 1;
            int to = in.nextInt() - 1;
            int flow = in.nextInt();
            Edge e = new Edge(from, to, flow);
            ed[i] = e;
            edges[from].add(e);
            edges[to].add(new Edge(to, from, flow));
        }
        int[] need = new int[n];
        for (int i = 0; i < n; i++) {
            for (Edge e : edges[i]) {
                need[i] += e.w;
            }
        }
        for (int i = 1; i + 1 < n; i++) {
            need[i] /= 2;
        }
        int[] q = new int[n];
        int head = 0;
        int tail = 1;
        boolean[] was = new boolean[n];
        int[] index = new int[n];
        int cnt = 0;
        was[0] = true;
        while (head < tail) {
            int v = q[head++];
            index[v] = cnt++;
            for (Edge e : edges[v]) {
                if (was[e.to]) {
                    continue;
                }
                need[e.to] -= e.w;
                if (need[e.to] == 0) {
                    was[e.to] = true;
                    q[tail++] = e.to;
                }
            }
        }
        for (int i = 0; i < m; i++) {
            Edge e = ed[i];
            if (index[e.to] < index[e.from]) {
                out.println(1);
            } else {
                out.println(0);
            }
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