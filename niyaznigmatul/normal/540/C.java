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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        char[][] c = in.readCharacterFieldTokens(n, m);
        int r1 = in.nextInt() - 1;
        int c1 = in.nextInt() - 1;
        int r2 = in.nextInt() - 1;
        int c2 = in.nextInt() - 1;
        boolean isX = c[r2][c2] == 'X';
        c[r1][c1] = '.';
        c[r2][c2] = '.';
        DisjointSetUnion dsu = new DisjointSetUnion(n * m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (c[i][j] != '.') continue;
                if (i + 1 < n && c[i + 1][j] == '.') dsu.union(i * m + j, (i + 1) * m + j);
                if (j + 1 < m && c[i][j + 1] == '.') dsu.union(i * m + j, i * m + j + 1);
            }
        }
        if (r1 == r2 && c1 == c2) {
            int neighbours = 0;
            for (int dx = -1; dx <= 1; dx++) {
                for (int dy = -1; dy <= 1; dy++)
                    if (dx * dx + dy * dy == 1) {
                        int x = r2 + dx;
                        int y = c2 + dy;
                        if (x < 0 || y < 0 || x >= n || y >= m || c[x][y] == 'X') continue;
                        ++neighbours;
                    }
            }
            if (neighbours >= 1) {
                out.println("YES");
            } else {
                out.println("NO");
            }
            return;
        }
        if (isX) {
            if (dsu.get(r1 * m + c1) == dsu.get(r2 * m + c2)) {
                out.println("YES");
            } else {
                out.println("NO");
            }
        } else {
            int neighbours = 0;
            for (int dx = -1; dx <= 1; dx++) {
                for (int dy = -1; dy <= 1; dy++)
                    if (dx * dx + dy * dy == 1) {
                        int x = r2 + dx;
                        int y = c2 + dy;
                        if (x < 0 || y < 0 || x >= n || y >= m || c[x][y] == 'X') continue;
                        ++neighbours;
                    }
            }
            if (neighbours >= 2 && dsu.get(r1 * m + c1) == dsu.get(r2 * m + c2)) {
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

    public char[][] readCharacterFieldTokens(int n, int m) {
        char[][] ret = new char[n][];
        for (int i = 0; i < n; i++) {
            ret[i] = next().toCharArray();
            if (ret[i].length != m) {
                throw new AssertionError("length expected " + m + ", found " + ret[i].length);
            }
        }
        return ret;
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