import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
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
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {

    static int[][] edges;
    static int[] from;
    static int[] to;
    static int[] weight;
    static int[] size;
    static long[] count;
    static int n;

    static void dfs(int v, int p) {
        size[v] = 1;
        for (int e : edges[v]) {
            int go = v ^ from[e] ^ to[e];
            if (go == p) continue;
            dfs(go, v);
            long down = size[go];
            long up = n - size[go];
            count[e] = (down * up * (up - 1) + up * down * (down - 1)) / 2;
            size[v] += size[go];
        }
    }

    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        n = in.nextInt();
        from = new int[n - 1];
        to = new int[n - 1];
        weight = new int[n - 1];
        for (int i = 0; i + 1 < n; i++) {
            from[i] = in.nextInt() - 1;
            to[i] = in.nextInt() - 1;
            weight[i] = in.nextInt();
        }
        edges = GraphUtils.getEdgesUndirectedWeighted(n, from, to);
        size = new int[n];
        count = new long[n - 1];
        dfs(0, -1);
        double exp = 0;
        for (int i = 0; i < n - 1; i++) {
            exp += weight[i] * count[i];
        }
        int q = in.nextInt();
        for (int i = 0; i < q; i++) {
            int e = in.nextInt() - 1;
            int nw = in.nextInt();
            exp -= (weight[e] - nw) * count[e];
            weight[e] = nw;
            out.println(12. * exp / n / (n - 1) / (n - 2));
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

class GraphUtils {

    public static int[][] getEdgesUndirectedWeighted(int n, int[] v, int[] u) {
        int[][] edges = new int[n][];
        int[] deg = getDegreeUndirected(n, v, u);
        for (int i = 0; i < n; i++) {
            edges[i] = new int[deg[i]];
        }
        int m = v.length;
        Arrays.fill(deg, 0);
        for (int i = 0; i < m; i++) {
            edges[v[i]][deg[v[i]]++] = i;
            edges[u[i]][deg[u[i]]++] = i;
        }
        return edges;
    }

    public static int[] getDegreeUndirected(int n, int[] v, int[] u) {
        int[] deg = new int[n];
        for (int i : v) {
            deg[i]++;
        }
        for (int i : u) {
            deg[i]++;
        }
        return deg;
    }


}