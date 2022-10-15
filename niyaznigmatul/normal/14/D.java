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
    static int curAnswer;
    static boolean[] bad;

    static int dfs(int v, int p, int t) {
        if (v == t) {
            bad[v] = true;
            return 1;
        }
        for (int i : edges[v]) {
            if (i == p) {
                continue;
            }
            int got = dfs(i, v, t);
            if (got > 0) {
                bad[v] = true;
                return got + 1;
            }
        }
        return 0;
    }

    static int dfs2(int v, int p) {
        bad[v] = true;
        int max1 = 0;
        int max2 = 0;
        for (int i : edges[v]) {
            if (i == p || bad[i]) {
                continue;
            }
            int got = dfs2(i, v);
            if (max1 < got) {
                max2 = max1;
                max1 = got;
            } else if (max2 < got) {
                max2 = got;
            }
        }
        curAnswer = Math.max(curAnswer, max1 + max2);
        return max1 + 1;
    }

    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        int[] from = new int[n - 1];
        int[] to = new int[n - 1];
        for (int i = 0; i + 1 < n; i++) {
            from[i] = in.nextInt() - 1;
            to[i] = in.nextInt() - 1;
        }
        edges = GraphUtils.getEdgesUndirectedUnweighted(n, from, to);
        bad = new boolean[n];
        int answer = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    continue;
                }
                Arrays.fill(bad, false);
                int len = dfs(i, -1, j) - 1;
                curAnswer = 0;
                for (int v = 0; v < n; v++) {
                    if (bad[v]) {
                        continue;
                    }
                    dfs2(v, -1);
                }
                answer = Math.max(answer, curAnswer * len);
            }
        }
        out.println(answer);
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

class GraphUtils {
    public static int[][] getEdgesUndirectedUnweighted(int n, int[] v, int[] u) {
        int[][] edges = new int[n][];
        int[] deg = getDegreeUndirected(n, v, u);
        for (int i = 0; i < n; i++) {
            edges[i] = new int[deg[i]];
        }
        int m = v.length;
        Arrays.fill(deg, 0);
        for (int i = 0; i < m; i++) {
            edges[v[i]][deg[v[i]]++] = u[i];
            edges[u[i]][deg[u[i]]++] = v[i];
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