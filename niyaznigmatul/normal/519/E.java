import java.io.Reader;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.List;
import java.io.BufferedReader;
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
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {
    static final int K = 20;
    static List<Integer>[] edges;
    static int[] down;
    static int[] parent;
    static int[] depth;
    static int[][] up;

    static void dfs(int v, int pv, int de) {
        parent[v] = pv;
        down[v] = 1;
        depth[v] = de;
        for (int i = 0; i < edges[v].size(); i++) {
            int to = edges[v].get(i);
            if (to != pv) {
                dfs(to, v, de + 1);
                down[v] += down[to];
            }
        }
    }

    static int goUp(int v, int count) {
        for (int i = 0; i < K; i++) {
            if (((count >> i) & 1) == 1) v = up[i][v];
        }
        return v;
    }

    static int lca(int v, int u) {
        if (depth[v] > depth[u]) {
            int t = v;
            v = u;
            u = t;
        }
        u = goUp(u, depth[u] - depth[v]);
        if (u == v) return u;
        for (int i = K - 1; i >= 0; i--) {
            if (up[i][v] != up[i][u]) {
                v = up[i][v];
                u = up[i][u];
            }
        }
        return parent[v];
    }

    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        edges = new List[n];
        for (int i = 0; i < n; i++) edges[i] = new ArrayList<>();
        for (int i = 0; i < n - 1; i++) {
            int v = in.nextInt() - 1;
            int u = in.nextInt() - 1;
            edges[v].add(u);
            edges[u].add(v);
        }
        down = new int[n];
        depth = new int[n];
        parent = new int[n];
        dfs(0, -1, 0);
        up = new int[K][n];
        for (int i = 0; i < n; i++) up[0][i] = parent[i] < 0 ? i : parent[i];
        for (int i = 1; i < K; i++) {
            for (int v = 0; v < n; v++) {
                up[i][v] = up[i - 1][up[i - 1][v]];
            }
        }
        int m = in.nextInt();
        for (int i = 0; i < m; i++) {
            int x = in.nextInt() - 1;
            int y = in.nextInt() - 1;
            if (x == y) {
                out.println(n);
                continue;
            }
            int lca = lca(x, y);
            int dist = depth[x] + depth[y] - 2 * depth[lca];
            if ((dist & 1) == 1) {
                out.println(0);
                continue;
            }
            if (depth[x] == depth[y]) {
                x = goUp(x, dist / 2 - 1);
                y = goUp(y, dist / 2 - 1);
                out.println(n - down[x] - down[y]);
            } else {
                if (depth[x] > depth[y]) {
                    int t = x;
                    x = y;
                    y = t;
                }
                y = goUp(y, dist / 2 - 1);
                out.println(down[parent[y]] - down[y]);
            }
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


}