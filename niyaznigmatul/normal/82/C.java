import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Comparator;
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

    static int[][] edges;
    static int[] from;
    static int[] to;
    static int[] w;

    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        final int[] a = in.readIntArray(n);
        from = new int[n - 1];
        to = new int[n - 1];
        w = new int[n - 1];
        for (int i = 0; i < n - 1; i++) {
            from[i] = in.nextInt() - 1;
            to[i] = in.nextInt() - 1;
            w[i] = in.nextInt();
        }
        edges = GraphUtils.getEdgesUndirectedWeighted(n, from, to);
        parent = new int[n];
        wToParent = new int[n];
        dfs(0, -1);
        int[] where = new int[n];
        for (int i = 0; i < n; i++) {
            where[i] = i;
        }
        int[] answer = new int[n];
        Integer[] z = new Integer[n];
        for (int i = 0; i < n; i++) {
            z[i] = i;
        }
        Arrays.sort(z, new Comparator<Integer>() {
            public int compare(Integer o1, Integer o2) {
                return a[o1] - a[o2];
            }
        });
        int[] cnt = new int[n];
        for (int day = 0; day < n; day++) {
            Arrays.fill(cnt, 0);
            for (int i : z) {
                int q = where[i];
                if (q == 0) {
                    continue;
                }
                if (cnt[q] == wToParent[q]) {
                    continue;
                }
                ++cnt[q];
                where[i] = parent[q];
                if (where[i] == 0) {
                    answer[i] = day + 1;
                }
            }
        }
        out.printArray(answer);
    }

    static int[] parent;
    static int[] wToParent;

    static void dfs(int v, int p) {
        parent[v] = p;
        for (int i : edges[v]) {
            int go = from[i] ^ to[i] ^ v;
            if (go == p) {
                continue;
            }
            wToParent[go] = w[i];
            dfs(go, v);
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