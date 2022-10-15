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
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {
    static int[] parent;
    static String[] edge;
    static int[] pos;
    static int[] p;
    static String t;
    static long ans;

    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        parent = new int[n];
        edge = new String[n];
        parent[0] = -1;
        for (int i = 1; i < n; i++) {
            parent[i] = in.nextInt() - 1;
            edge[i] = in.next();
        }
        t = in.next();
        p = new int[t.length()];
        p[0] = 0;
        for (int i = 1, k = 0; i < t.length(); i++) {
            while (k > 0 && t.charAt(k) != t.charAt(i)) k = p[k - 1];
            if (t.charAt(k) == t.charAt(i)) ++k;
            p[i] = k;
        }
        ans = 0;
        pos = new int[n];
        Arrays.fill(pos, Integer.MIN_VALUE);
        pos[0] = 0;
        for (int i = 1; i < n; i++) {
            if (pos[i] == Integer.MIN_VALUE) {
                getPos(i);
            }
        }
        out.println(ans);
    }

    static int getPos(int v) {
        if (pos[parent[v]] == Integer.MIN_VALUE) {
            getPos(parent[v]);
        }
        int k = pos[parent[v]];
        String e = edge[v];
        for (int i = 0; i < e.length(); i++) {
            while (k > 0 && (k >= p.length || e.charAt(i) != t.charAt(k))) k = p[k - 1];
            if (k < p.length && e.charAt(i) == t.charAt(k)) ++k;
            if (k == t.length()) {
                ++ans;
            }
        }
        return pos[v] = k;
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

    public String next() {
        StringBuilder sb = new StringBuilder();
        int c = read();
        while (isWhiteSpace(c)) {
            c = read();
        }
        if (c < 0) {
            return null;
        }
        while (c >= 0 && !isWhiteSpace(c)) {
            sb.appendCodePoint(c);
            c = read();
        }
        return sb.toString();
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