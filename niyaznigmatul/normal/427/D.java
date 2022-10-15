import java.io.Reader;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Writer;
import java.io.IOException;

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
        char[] c = in.next().toCharArray();
        char[] d = in.next().toCharArray();
        int[][] dp1 = getLCP(d, c);
        int[][] dp2 = getLCP(d, d);
        int[] q = new int[c.length + 1];
        int ans = Integer.MAX_VALUE;
        for (int i = 0; i < d.length; i++) {
            int max = 0;
            int[] dp2i = dp2[i];
            for (int j = 0; j < d.length; j++) {
                if (i != j) {
                    max = Math.max(max, dp2i[j]);
                }
            }
            Arrays.fill(q, 0);
            int[] dp1i = dp1[i];
            for (int j = 0; j < c.length; j++) {
                q[dp1i[j]]++;
            }
            for (int j = q.length - 2; j >= 0; j--) q[j] += q[j + 1];
            for (int j = 0; j < q.length; j++) {
                if (q[j] == 1 && j > max) {
                    ans = Math.min(ans, j);
                }
            }
        }
        out.println(ans == Integer.MAX_VALUE ? -1 : ans);
    }

    static int[][] getLCP(char[] c, char[] d) {
        int[][] ret = new int[c.length][d.length];
        for (int i = 0; i < c.length; i++) {
            int[] reti = ret[i];
            int[] reti1 = i == 0 ? null : ret[i - 1];
            for (int j = 0; j < d.length; j++) {
                if (c[i] == d[j]) {
                    reti[j] = (i > 0 && j > 0 ? reti1[j - 1] : 0) + 1;
                } else
                    reti[j] = 0;
            }
        }
        return ret;
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


}