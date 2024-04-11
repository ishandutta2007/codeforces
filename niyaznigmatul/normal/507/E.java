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
    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        int[] he = new int[n];
        Arrays.fill(he, -1);
        int m = in.nextInt();
        int[] from = new int[2 * m];
        int[] to = new int[2 * m];
        int[] repaired = new int[2 * m];
        for (int i = 0; i < m; i++) {
            from[i] = in.nextInt() - 1;
            to[i] = in.nextInt() - 1;
            repaired[i] = in.nextInt();
            from[i + m] = to[i];
            to[i + m] = from[i];
            repaired[i + m] = repaired[i];
        }
        int[] next = new int[2 * m];
        for (int i = 0; i < 2 * m; i++) {
            next[i] = he[from[i]];
            he[from[i]] = i;
        }
        int[] q = new int[n];
        int head = 0;
        int tail = 1;
        int[] dp = new int[n];
        Arrays.fill(dp, Integer.MIN_VALUE);
        int[] last = new int[n];
        Arrays.fill(last, -1);
        int[] d = new int[n];
        Arrays.fill(d, Integer.MAX_VALUE);
        d[0] = 0;
        dp[0] = 0;
        while (head < tail) {
            int v = q[head++];
            for (int e = he[v]; e >= 0; e = next[e]) {
                int go = to[e];
                if (d[go] > d[v] + 1) {
                    q[tail++] = go;
                    d[go] = d[v] + 1;
                }
                if (d[go] == d[v] + 1 && dp[go] < dp[v] + repaired[e]) {
                    last[go] = e;
                    dp[go] = dp[v] + repaired[e];
                }
            }
        }
        boolean[] onPath = new boolean[m];
        for (int e = n - 1; e > 0; e = from[last[e]]) {
            onPath[last[e] >= m ? last[e] - m : last[e]] = true;
        }
        int[] who = new int[m];
        int ac = 0;
        for (int i = 0; i < m; i++) {
            if ((repaired[i] == 1) != onPath[i]) {
                who[ac++] = i;
            }
        }
        out.println(ac);
        for (int i = 0; i < ac; i++) {
            int e = who[i];
            out.println((from[e] + 1) + " " + (to[e] + 1) + " " + (1 - repaired[e]));
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