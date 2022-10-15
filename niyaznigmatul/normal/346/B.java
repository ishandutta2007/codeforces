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
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {
    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        char[] s = in.next().toCharArray();
        char[] t = in.next().toCharArray();
        char[] q = in.next().toCharArray();
        int[] p = new int[q.length];
        {
            p[0] = -1;
            int k = -1;
            for (int i = 1; i < q.length; i++) {
                while (k > -1 && q[k + 1] != q[i]) {
                    k = p[k];
                }
                if (q[k + 1] == q[i]) {
                    ++k;
                }
                p[i] = k;
            }
        }
        int[][][] dp = new int[s.length + 1][t.length + 1][q.length];
        int[][][] from = new int[s.length + 1][t.length + 1][q.length];
        for (int i = 0; i <= s.length; i++) {
            for (int j = 0; j <= t.length; j++) {
                for (int k = 0; k < q.length; k++) {
//                    System.out.println(i + " " + j + " " + k + " " + dp[i][j][k]);
                    int val = dp[i][j][k];
                    if (i + 1 <= s.length) {
                        if (dp[i + 1][j][k] < val) {
                            dp[i + 1][j][k] = val;
                            from[i + 1][j][k] = 1;
                        }
                    }
                    if (j + 1 <= t.length) {
                        if (dp[i][j + 1][k] < val) {
                            dp[i][j + 1][k] = val;
                            from[i][j + 1][k] = 2;
                        }
                    }
                    if (i + 1 <= s.length && j + 1 <= t.length && s[i] == t[j]) {
                        int e = k - 1;
                        while (e > -1 && (e + 1 >= q.length || q[e + 1] != s[i])) e = p[e];
                        if (e + 1 < q.length && q[e + 1] == s[i]) {
                            ++e;
                        }
                        if (e < q.length - 1) {
                            if (dp[i + 1][j + 1][e + 1] < val + 1) {
                                dp[i + 1][j + 1][e + 1] = val + 1;
                                from[i + 1][j + 1][e + 1] = ~k;
                            }
                        }
                    }
                }
            }
        }
        int best = -1;
        int bk = -1;
        for (int i = 0; i < q.length; i++) {
            if (best < dp[s.length][t.length][i]) {
                bk = i;
                best = dp[s.length][t.length][i];
            }
        }
        if (best == 0) {
            out.println(0);
            return;
        }
        StringBuilder ans = new StringBuilder();
        for (int i = s.length, j = t.length, k = bk; dp[i][j][k] > 0;) {
//            System.out.println(dp[i][j][k]);
            int cc = from[i][j][k];
            if (cc == 1) {
                --i;
            } else if (cc == 2) {
                --j;
            } else {
                k = ~cc;
                --i;
                --j;
                ans.append(s[i]);
            }
        }
        ans.reverse();
        out.println(ans);
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