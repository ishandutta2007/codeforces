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
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {

    static int[] from, to, w;
    static int[][] edges;
    static int[] sum;
    static int[] count;
    static long answer;

    static final Comparator<Integer> comp = new Comparator<Integer>() {
        public int compare(Integer o1, Integer o2) {
            return Long.signum((long) sum[o1] * count[o2] - (long) sum[o2] * count[o1]);
        }
    };

    static void dfs(int v, int p) {
        sum[v] = 0;
        count[v] = 1;
        Integer[] ver = new Integer[edges[v].length - (p < 0 ? 0 : 1)];
        int cur = 0;
        for (int i : edges[v]) {
            int go = from[i] ^ v ^ to[i];
            if (go == p) {
                continue;
            }
            ver[cur++] = go;
            dfs(go, v);
            sum[go] += 2 * w[i];
            answer += (long) count[go] * w[i];
            sum[v] += sum[go];
            count[v] += count[go];
        }
        Arrays.sort(ver, comp);
        int curCount = count[v] - 1;
        for (int i : ver) {
            curCount -= count[i];
            answer += (long) curCount * sum[i];
        }
    }

    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        from = new int[n - 1];
        to = new int[n - 1];
        w = new int[n - 1];
        for (int i = 0; i + 1 < n; i++) {
            from[i] = in.nextInt() - 1;
            to[i] = in.nextInt() - 1;
            w[i] = in.nextInt();
        }
        edges = GraphUtils.getEdgesUndirectedWeighted(n, from, to);
        count = new int[n];
        sum = new int[n];
        answer = 0;
        dfs(0, -1);
        out.println((double) answer / (n - 1));
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