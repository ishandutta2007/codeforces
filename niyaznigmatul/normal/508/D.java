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
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {

    static int code(char c) {
        if (Character.isDigit(c)) return c - '0';
        if (Character.isLowerCase(c)) return c - 'a' + 10;
        return c - 'A' + 36;
    }

    static char decode(int x) {
        if (x < 10) return (char) (x + '0');
        x -= 10;
        if (x < 26) return (char) (x + 'a');
        x -= 26;
        return (char) (x + 'A');
    }

    static int[] head;
    static int[][] edges;
    static final int LETTERS = 26 + 26 + 10;
    static final int all = LETTERS * LETTERS;

    static char[] ans;
    static int pos;

    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        edges = new int[all][all];
        for (int i = 0; i < n; i++) {
            String  s= in.next();
            edges[code(s.charAt(0)) * LETTERS + code(s.charAt(1))][code(s.charAt(1)) * LETTERS + code(s.charAt(2))]++;
        }
        int start = -1;
        int finish = -1;
        int any = 0;
        for (int i = 0; i < all; i++) {
            int degIn = 0;
            int degOut = 0;
            for (int j = 0; j < all; j++) {
                degIn += edges[j][i];
                degOut += edges[i][j];
            }
            if (Math.abs(degIn - degOut) > 1) {
                out.println("NO");
                return;
            }
            if (degIn + degOut > 0) any = i;
            if (degIn > degOut) {
                if (finish >= 0) {
                    out.println("NO");
                    return;
                }
                finish = i;
            }
            if (degIn < degOut) {
                if (start >= 0) {
                    out.println("NO");
                    return;
                }
                start = i;
            }
        }
        if (start < 0) start = any;
        pos = n;
        ans = new char[n + 2];
        head = new int[all];
        dfs(start);
        if (pos >= 0) {
            out.println("NO");
            return;
        }
        out.println("YES");
        out.println(ans);
    }

    static void dfs(int v) {
        while (head[v] < all) {
            if (edges[v][head[v]] == 0) {
                ++head[v];
                continue;
            }
            --edges[v][head[v]];
            dfs(head[v]);
        }
        ans[pos] = decode(v / LETTERS);
        ans[pos + 1] = decode(v % LETTERS);
        --pos;
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