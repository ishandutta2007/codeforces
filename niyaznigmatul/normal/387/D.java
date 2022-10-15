import java.io.Reader;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.util.List;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.io.IOException;

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
    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        int[] from = new int[m];
        int[] to = new int[m];
        for (int i = 0; i < m; i++) {
            from[i] = in.nextInt() - 1;
            to[i] = in.nextInt() - 1;
        }
        int ans = Integer.MAX_VALUE;
        for (int i = 0; i < n; i++) {
            KuhnMatchingGraph g = new KuhnMatchingGraph(n, n);
            int count = 0;
            for (int j = 0; j < m; j++) {
                if (from[j] != i && to[j] != i) {
                    g.addEdge(from[j], to[j]);
                    ++count;
                }
            }
            int cur = (n - 1 + count) - 2 * g.getMaximalMatching();
            boolean[] a = new boolean[n];
            boolean[] b = new boolean[n];
            for (int j = 0; j < m; j++) {
                if (from[j] == i) {
                    a[to[j]] = true;
                }
                if (to[j] == i) {
                    b[from[j]] = true;
                }
            }
            for (int j = 0; j < n; j++) {
                if (j == i) {
                    if (!a[j]) ++cur;
                } else {
                    if (!a[j]) ++cur;
                    if (!b[j]) ++cur;
                }
            }
            ans = Math.min(ans, cur);
        }
        out.println(ans);
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


}

class KuhnMatchingGraph {

    int n;
    int m;
    List<Integer>[] edges;
    int[] p1;
    int[] p2;
    int[] was;
    int VER;

    public KuhnMatchingGraph(int n, int m) {
        this.n = n;
        this.m = m;
        edges = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            edges[i] = new ArrayList<Integer>(2);
        }
    }

    public void addEdge(int from, int to) {
        edges[from].add(to);
    }

    public int getMaximalMatching() {
        p1 = new int[n];
        p2 = new int[m];
        was = new int[n];
        VER = 0;
        Arrays.fill(p1, -1);
        Arrays.fill(p2, -1);
        int answer = 0;
        for (int i = 0; i < n; i++) {
            for (int j : edges[i]) {
                if (p2[j] < 0) {
                    p2[j] = i;
                    p1[i] = j;
                    answer++;
                    break;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (p1[i] >= 0) {
                continue;
            }
            VER++;
            if (dfs(i)) {
                answer++;
            }
        }
        return answer;
    }

    boolean dfs(int v) {
        if (was[v] == VER) {
            return false;
        }
        was[v] = VER;
        for (int i = 0; i < edges[v].size(); i++) {
            int e = edges[v].get(i);
            if (p2[e] < 0 || dfs(p2[e])) {
                p2[e] = v;
                p1[v] = e;
                return true;
            }
        }
        return false;
    }
}