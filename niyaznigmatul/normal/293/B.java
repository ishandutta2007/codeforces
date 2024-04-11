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
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {
    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        n = in.nextInt();
        m = in.nextInt();
        k = in.nextInt();
        a = new int[n][];
        for (int i = 0; i < n; i++) {
            a[i] = in.readIntArray(m);
        }
        if (n + m - 1 > k) {
            out.println(0);
            return;
        }
        mask = new int[n][m];
        map = new int[k];
        curColor = new int[n][m];
        Arrays.fill(map, -1);
        cntMatched = 0;
        answer = 0;
        was = new boolean[k];
        go(0, 0, 0);
        out.println(answer);
    }

    static int[][] a;
    static int[][] mask;
    static int[][] curColor;
    static int k;
    static int n, m;
    static long answer;
    static int[] map;
    static int cntMatched;
    static boolean[] was;
    static int[][] C;
    static int[] fact;
    static {
        C = new int[21][21];
        fact = new int[12];
        for (int i = 0; i < C.length; i++) {
            C[i][0] = 1;
            for (int j = 1; j <= i; j++) {
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
            }
        }
        fact[0] = 1;
        for (int i = 1; i < fact.length; i++) {
            fact[i] = fact[i - 1] * i;
        }
    }

    static final int MOD = 1000000007;

    static void go(int x, int y, int colors) {
        if (y == m) {
            go(x + 1, 0, colors);
            return;
        }
        if (x == n) {
            answer = (answer + (long) fact[(colors - cntMatched)] * C[k - cntMatched][colors - cntMatched]) % MOD;
            return;
        }
        mask[x][y] = 0;
        if (x > 0) {
            mask[x][y] |= mask[x - 1][y] | (1 << curColor[x - 1][y]);
        }
        if (y > 0) {
            mask[x][y] |= mask[x][y - 1] | (1 << curColor[x][y - 1]);
        }
        int curMask = mask[x][y];
        int already = a[x][y] - 1;
        for (int i = 0; i <= colors && i < k; i++) {
            if (((curMask >> i) & 1) == 1) {
                continue;
            }
            if (already >= 0) {
                if (map[already] >= 0 && map[already] != i) {
                    continue;
                }
                if (map[already] < 0 && was[i]) {
                    continue;
                }
            }
            boolean set = false;
            if (already >= 0 && map[already] < 0) {
                set = true;
                map[already] = i;
                ++cntMatched;
                was[i] = true;
            }
            curColor[x][y] = i;
            go(x, y + 1, Math.max(colors, i + 1));
            if (set) {
                map[already] = -1;
                --cntMatched;
                was[i] = false;
            }
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

    public int[] readIntArray(int n) {
        int[] ret = new int[n];
        for (int i = 0; i < n; i++) {
            ret[i] = nextInt();
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