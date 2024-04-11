import java.util.List;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
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

class TaskC {static class Edge {
    int from;
    int to;
    Edge rev;
    boolean killed;

    Edge(int from, int to) {
        this.from = from;
        this.to = to;
    }
}

    static void kill(Edge e) {
        e.killed = true;
        e.rev.killed = true;
    }

    static List<Edge>[] edges;
    static int[] sz;
    static int cnv;
    static int[] ans;

    static void dfs(int v, int p) {
        sz[v] = 1;
        for (int i = 0; i < edges[v].size(); i++) {
            Edge e = edges[v].get(i);
            if (e.killed || e.to == p) {
                continue;
            }
            dfs(e.to, v);
            sz[v] += sz[e.to];
        }
    }

    static void solve(int v, int curColor) {
        cnv = 0;
        dfs(v, -1);
        {
            int all = sz[v];
            int p = -1;
            boolean changed = true;
            while (changed) {
                changed = false;
                for (int i = 0; i < edges[v].size(); i++) {
                    Edge e = edges[v].get(i);
                    if (e.killed || e.to == p) {
                        continue;
                    }
                    if (sz[e.to] * 2 > all) {
                        p = v;
                        v = e.to;
                        changed = true;
                        break;
                    }
                }
            }
        }
        ans[v] = curColor;
        int countChildren = 0;
        for (int i = 0; i < edges[v].size(); i++) {
            Edge e = edges[v].get(i);
            if (e.killed) {
                continue;
            }
            countChildren++;
        }
        int[] children = new int[countChildren];
        countChildren = 0;
        for (int i = 0; i < edges[v].size(); i++) {
            Edge e = edges[v].get(i);
            if (e.killed) {
                continue;
            }
            children[countChildren++] = e.to;
        }
        for (int i = 0; i < edges[v].size(); i++) {
            kill(edges[v].get(i));
        }
        for (int i : children) {
            solve(i, curColor + 1);
        }
    }

    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        edges = new List[n];
        for (int i = 0; i < n; i++) {
            edges[i] = new ArrayList<>();
        }
        for (int i = 1; i < n; i++) {
            int a = in.nextInt() - 1;
            int b = in.nextInt() - 1;
            Edge e1 = new Edge(a, b);
            Edge e2 = new Edge(b, a);
            e1.rev = e2;
            e2.rev = e1;
            edges[a].add(e1);
            edges[b].add(e2);
        }
        sz = new int[n];
        ans = new int[n];
        Arrays.fill(ans, -1);
        solve(0, 0);
        for (int i = 0; i < n; i++) {
            if (i > 0) {
                out.print(' ');
            }
            out.print((char) ('A' + ans[i]));
        }
        out.println();
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