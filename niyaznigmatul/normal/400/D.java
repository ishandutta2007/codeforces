import java.io.Reader;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.io.InputStream;
import java.io.InputStreamReader;
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
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        int groups = in.nextInt();
        DisjointSetUnion dsu = new DisjointSetUnion(n);
        int[][] a = new int[groups][groups];
        for (int i = 0; i < groups; i++) {
            Arrays.fill(a[i], Integer.MAX_VALUE);
            a[i][i] = 0;
        }
        int[] type = new int[n];
        for (int i = 0, j = 0; i < groups; i++) {
            int cn = in.nextInt();
            for (int k = 0; k < cn; k++) {
                type[j++] = i;
            }
        }
        for (int i = 0; i < m; i++) {
            int v = in.nextInt() - 1;
            int u = in.nextInt() - 1;
            int w = in.nextInt();
            if (w == 0) {
                dsu.union(v, u);
            }
            int from = type[v];
            int to = type[u];
            a[to][from] = a[from][to] = Math.min(a[from][to], w);
        }
        for (int i = 0; i + 1 < n; i++) {
            if (type[i] == type[i + 1] && dsu.get(i) != dsu.get(i + 1)) {
                out.println("No");
                return;
            }
        }
        for (int k = 0; k < groups; k++) {
            for (int i = 0; i < groups; i++) {
                for (int j = 0; j < groups; j++) {
                    if (a[i][k] != Integer.MAX_VALUE && a[k][j] != Integer.MAX_VALUE) {
                        a[i][j] = Math.min(a[i][j], a[i][k] + a[k][j]);
                    }
                }
            }
        }
        out.println("Yes");
        for (int i = 0; i < groups; i++) {
            for (int j = 0; j < groups; j++) {
                if (j > 0) out.print(' ');
                int ans = a[i][j];
                if (ans == Integer.MAX_VALUE) ans = -1;
                out.print(ans);
            }
            out.println();
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