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
        List<Integer> a = new ArrayList<>();
        {
            DisjointSetUnion dsu = new DisjointSetUnion(n);
            for (int i = 0; i < m; i++) {
                if (dsu.union(from[i], to[i])) {
                    a.add(i);
                }
            }
        }
        List<Integer> b = new ArrayList<>();
        {
            DisjointSetUnion dsu = new DisjointSetUnion(n);
            for (int i = m - 1; i >= 0; i--) {
                if (dsu.union(from[i], to[i])) {
                    b.add(i);
                }
            }
        }
        int q = in.nextInt();
        DisjointSetUnion dsu = new DisjointSetUnion(n);
        for (int i = 0; i < q; i++) {
            dsu.clear();
            int left = in.nextInt() - 1;
            int right = in.nextInt() - 1;
            int ans = n;
            for (int e : a) {
                if (e >= left) {
                    break;
                }
                if (dsu.union(from[e], to[e])) {
                    --ans;
                }
            }
            for (int e : b) {
                if (e <= right) {
                    break;
                }
                if (dsu.union(from[e], to[e])) {
                    --ans;
                }
            }
            out.println(ans);
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
        return x != p[x] ? p[x] = get(p[x]) : x;
    }

    public boolean union(int a, int b) {
        a = get(a);
        b = get(b);
        p[a] = b;
        return a != b;
    }
}