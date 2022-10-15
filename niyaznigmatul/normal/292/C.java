import java.util.List;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {

    static boolean[] hasToBe;
    static boolean[] canBe;
    static int[] p;
    static int[] d;
    static boolean[][] dp;

    static void go(int x, int n) {
        int cnt = 0;
        for (boolean e : hasToBe) {
            if (e) ++cnt;
        }
        if (cnt > n - x) return;
        if (cnt == 0) {
            check(x);
        }
        if (x == n) {
            return;
        }
        for (int i = 0; i < 10; i++) {
            if (!canBe[i]) {
                continue;
            }
            p[x] = i;
            if (hasToBe[i]) {
                hasToBe[i] = false;
                go(x + 1, n);
                hasToBe[i] = true;
            } else {
                go(x + 1, n);
            }
        }
    }

    static void check(int len) {
        {
            for (int i = 0; i < len; i++) {
                d[i] = p[i];
                d[len + len - i - 1] = p[i];
            }
            check2(len + len);
        }
        {
            for (int i = 0; i < len; i++) {
                d[i] = p[i];
                d[len + len - i - 2] = p[i];
            }
            check2(len + len - 1);
        }
    }

    static void check2(int len) {
        for (boolean[] e : dp) {
            Arrays.fill(e, false);
        }
        dp[0][0] = true;
        for (int i = 1; i <= len; i++) {
            for (int c = 1; c <= 4; c++) {
                int x = 0;
                for (int j = i - 1, k = 1; j >= i - 3 && j >= 0; j--, k *= 10) {
                    x += k * d[j];
                    if ((k == 1 || d[j] != 0) && x < 256 && x >= 0) {
                        dp[i][c] |= dp[j][c - 1];
                    }
                }
            }
        }
        if (dp[len][4]) {
            getAll(len, 4);
        }
    }

    static void getAll(int i, int c) {
        if (i == 0 && c == 0) {
            answer.add(((long) cur[0] << 24) | (cur[1] << 16) | (cur[2] << 8) | cur[3]);
            return;
        }
        int x = 0;
        for (int j = i - 1, k = 1; j >= i - 3 && j >= 0; j--, k *= 10) {
            x += k * d[j];
            if ((k == 1 || d[j] != 0) && x < 256 && x >= 0) {
                if (dp[j][c - 1]) {
                    cur[c - 1] = x;
                    getAll(j, c - 1);
                }
            }
        }
    }

    static int[] cur;
    static List<Long> answer;

    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        hasToBe = new boolean[10];
        canBe = new boolean[10];
        if (n > 6) {
            out.println(0);
            return;
        }
        p = new int[6];
        d = new int[14];
        dp = new boolean[14][5];
        cur = new int[4];
        answer = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            int x = in.nextInt();
            hasToBe[x] = true;
            canBe[x] = true;
        }
        go(0, 6);
        out.println(answer.size());
        for (long e : answer) {
            out.println((e >> 24) + "." + ((e >> 16) & 0xFF) + "." + ((e >> 8) & 0xFF) + "." + (e & 0xFF));
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