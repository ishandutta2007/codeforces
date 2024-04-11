import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Reader;
import java.io.Writer;
import java.util.StringTokenizer;
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

    static final String[][] VERTICAL_STRING = {
            {
                    "...",
                    "...",
                    "..."
            },
            {
                    "...",
                    ".O.",
                    "..."
            },
            {
                    "..O",
                    "...",
                    "O.."
            },
            {
                    "..O",
                    ".O.",
                    "O.."
            },
            {
                    "O.O",
                    "...",
                    "O.O"
            },
            {
                    "O.O",
                    ".O.",
                    "O.O"
            },
            {
                    "O.O",
                    "O.O",
                    "O.O"
            }
    };

    static char[][][] VERTICAL, HORIZONTAL;

    static {
        VERTICAL = new char[VERTICAL_STRING.length][][];
        for (int i = 0; i < VERTICAL.length; i++) {
            VERTICAL[i] = new char[VERTICAL_STRING[i].length][];
            for (int j = 0; j < VERTICAL[i].length; j++) {
                VERTICAL[i][j] = VERTICAL_STRING[i][j].toCharArray();
            }
        }
        HORIZONTAL = new char[VERTICAL.length][][];
        for (int i = 0; i < VERTICAL.length; i++) {
            HORIZONTAL[i] = transpose(VERTICAL[i]);
        }
    }

    private static char[][] transpose(char[][] c) {
        char[][] ret = new char[c[0].length][c.length];
        for (int i = 0; i < c.length; i++) {
            for (int j = 0; j < c[i].length; j++) {
                ret[c[i].length - j - 1][i] = c[i][j];
            }
        }
        return ret;
    }

    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < 4 * n; i++) {
            sb.append(in.next());
        }
        StringTokenizer st = new StringTokenizer(sb.toString(), " \t#");
        char[][][][] field = new char[n][m][3][];
        for (int i = 0; i < n; i++) {
            for (int k = 0; k < 3; k++) {
                for (int j = 0; j < m; j++) {
                    field[i][j][k] = st.nextToken().toCharArray();
                }
            }
        }
        boolean[][] cv = new boolean[n][m];
        boolean[][] ch = new boolean[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (char[][] e : VERTICAL) {
                    if (Arrays.deepEquals(e, field[i][j])) {
                        cv[i][j] = true;
                    }
                }
                for (char[][] e : HORIZONTAL) {
                    if (Arrays.deepEquals(e, field[i][j])) {
                        ch[i][j] = true;
                    }
                }
            }
        }
        boolean[] colH = new boolean[m];
        int[] dp = new int[m + 1];
        dp[0] = 1;
        for (int i = 1; i <= m; i++) {
            boolean allV = (n & 1) == 0;
            for (int j = 0; j < n; j++) {
                allV &= cv[j][i - 1];
            }
            colH[i - 1] = allV;
            if (allV) {
                dp[i] += dp[i - 1];
                if (dp[i] >= MOD) {
                    dp[i] -= MOD;
                }
            }
            if (i == 1) {
                continue;
            }
            int[] cur = new int[n + 1];
            cur[0] = 1;
            for (int j = 1; j <= n; j++) {
                if (j > 1 && cv[j - 1][i - 1] && cv[j - 1][i - 2] && cv[j - 2][i - 1] && cv[j - 2][i - 2]) {
                    cur[j] += cur[j - 2];
                    if (cur[j] >= MOD) {
                        cur[j] -= MOD;
                    }
                }
                if (ch[j - 1][i - 1] && ch[j - 1][i - 2]) {
                    cur[j] += cur[j - 1];
                    if (cur[j] >= MOD) {
                        cur[j] -= MOD;
                    }
                }
            }
            int add = cur[n];
            if (colH[i - 1] && colH[i - 2]) {
                --add;
                if (add < 0) {
                    add += MOD;
                }
            }
            dp[i] = (int) ((dp[i] + (long) add * dp[i - 2]) % MOD);
        }
        out.println(dp[m]);
    }

    static final int MOD = 1000000007;
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
        while (!isWhiteSpace(c)) {
            sb.appendCodePoint(c);
            c = read();
        }
        return sb.toString();
    }

    static boolean isWhiteSpace(int c) {
        return c >= -1 && c <= 32;
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
        while (!isWhiteSpace(c)) {
            if (c < '0' || c > '9') {
                throw new NumberFormatException("digit expected " + (char) c
                        + " found");
            }
            ret = ret * 10 + c - '0';
            c = read();
        }
        return ret * sgn;
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