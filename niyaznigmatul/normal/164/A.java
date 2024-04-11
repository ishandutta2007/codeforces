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
 * @author niyaznigmatul 
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		FastScanner in = new FastScanner(inputStream);
		FastPrinter out = new FastPrinter(outputStream);
		TaskA solver = new TaskA();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskA {
	public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        int[] f = new int[n];
        for (int i = 0; i < n; i++) {
            f[i] = in.nextInt();
        }
        List<Integer>[] edges = new ArrayList[n];
        List<Integer>[] revEdges = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            edges[i] = new ArrayList<Integer>(2);
            revEdges[i] = new ArrayList<Integer>(2);
        }
        for (int i = 0; i < m; i++) {
            int from = in.nextInt() - 1;
            int to = in.nextInt() - 1;
            edges[from].add(to);
            revEdges[to].add(from);
        }
        boolean[] a = bfs(1, -1, edges, f);
        boolean[] b = bfs(2, 1, revEdges, f);
        for (int i = 0; i < n; i++) {
            out.println(a[i] && b[i] ? 1 : 0);
        }
	}

    static boolean[] bfs(int from, int ignore, List<Integer>[] edges, int[] f) {
        int n = edges.length;
        int[] q = new int[n];
        int head = 0;
        int tail = 0;
        boolean[] was = new boolean[n];
        for (int i = 0; i < n; i++) {
            if (f[i] == from) {
                was[i] = true;
                q[tail++] = i;
            }
        }
        while (head < tail) {
            int v = q[head++];
            if (f[v] == ignore) {
                continue;
            }
            for (int i : edges[v]) {
                if (was[i]) {
                    continue;
                }
                q[tail++] = i;
                was[i] = true;
            }
        }
        return was;
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