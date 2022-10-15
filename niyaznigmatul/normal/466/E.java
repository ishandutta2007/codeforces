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

    static List<Integer>[] edges;

    static int[] p;
    static int T;
    static int[] en;
    static int[] ex;

    static void dfs(int v) {
        en[v] = T++;
        for (int i = 0; i < edges[v].size(); i++) {
            dfs(edges[v].get(i));
        }
        ex[v] = T;
    }

    static boolean anc(int v, int u) {
        return en[v] <= en[u] && ex[u] <= ex[v];
    }

    static int get(int x) {
        return x == p[x] ? x : (p[x] = get(p[x]));
    }

    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        p = new int[n];
        edges = new List[n];
        for (int i = 0; i < n; i++) edges[i] = new ArrayList<>();
        for (int i = 0; i < n; i++) p[i] = i;
        int docs = 0;
        int[] pb = new int[m];
        int[] pa = new int[m];
        int[] qx = new int[m];
        int[] qd = new int[m];
        int queries = 0;
        for (int i = 0; i < m; i++) {
            int t = in.nextInt();
            if (t == 1) {
                int x = in.nextInt() - 1;
                int y = in.nextInt() - 1;
                edges[y].add(x);
                p[x] = get(y);
            } else if (t == 2) {
                pb[docs] = in.nextInt() - 1;
                pa[docs] = get(pb[docs]);
                ++docs;
            } else {
                qx[queries] = in.nextInt() - 1;
                qd[queries] = in.nextInt() - 1;
                ++queries;
            }
        }
        T = 0;
        en = new int[n];
        ex = new int[n];
        for (int i = 0; i < n; i++) {
            if (get(i) == i) {
                dfs(i);
            }
        }
        for (int i = 0; i < queries; i++) {
            if (anc(pa[qd[i]], qx[i]) && anc(qx[i], pb[qd[i]])) {
                out.println("YES");
            } else {
                out.println("NO");
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

    public FastPrinter(Writer out) {
        super(out);
    }


}