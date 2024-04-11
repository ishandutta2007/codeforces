import java.io.InputStreamReader;
import java.io.IOException;
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
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {
    static boolean cactus(int[][] e) {
        int n = e.length;
        DisjointSetUnion dsu = new DisjointSetUnion(n);
        int[] deg = new int[n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                deg[i] += e[i][j];
                if (e[i][j] > 0) dsu.union(i, j);
            }
            if (deg[i] > 2) return false;
        }
        boolean[] has = new boolean[n];
        int[] size = new int[n];
        for (int i = 0; i < n; i++) {
            if (deg[i] < 2) has[dsu.get(i)] = true;
            size[dsu.get(i)]++;
        }
        for (int i = 0; i < n; i++) {
            if (size[i] > 0 && size[i] != n && !has[i]) return false;
        }
        return true;
    }

    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        int[][] edges = new int[n][n];
        for (int i = 0; i < m; i++) {
            int v = in.nextInt() - 1;
            int u = in.nextInt() - 1;
            edges[v][u]++;
            edges[u][v]++;
        }
        if (!cactus(edges)) {
            out.println("NO");
            return;
        }
        int[] ax = new int[n * n];
        int[] ay = new int[n * n];
        int ac = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                while (true) {
                    edges[i][j]++;
                    edges[j][i]++;
                    if (!cactus(edges)) {
                        edges[i][j]--;
                        edges[j][i]--;
                        break;
                    } else {
                        ax[ac] = i;
                        ay[ac] = j;
                        ++ac;
                    }
                }
            }
        }
        out.println("YES");
        out.println(ac);
        for (int i = 0; i < ac; i++) {
            out.println((ax[i] + 1) + " " + (ay[i] + 1));
        }
    }
}

class DisjointSetUnion {
    int[] p;

    public DisjointSetUnion(int n) {
        p = new int[n];
        clear();
    }

    public void clear() {
        for (int i = 0; i < p.length; i++) {
            p[i] = i;
        }
    }

    public int get(int x) {
        int y = x;
        while (y != p[y]) {
            y = p[y];
        }
        while (x != p[x]) {
            int t = p[x];
            p[x] = y;
            x = t;
        }
        return y;
    }

    public boolean union(int a, int b) {
        a = get(a);
        b = get(b);
        p[a] = b;
        return a != b;
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