import java.io.IOException;
import java.io.InputStreamReader;
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
		TaskC1 solver = new TaskC1();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC1 {

    static final int N = 1000002;

    static int[] dp = new int[N];
    static int[] last = new int[N];

    static {
        dp[0] = 0;
        for (int i = 1; i < dp.length; i++) {
            int x = i;
            dp[i] = Integer.MAX_VALUE;
            int maxD = 0;
            while (x > 0) {
                int d = x % 10;
                maxD = Math.max(maxD, d);
                if (d != 0) {
                    if (dp[i] > dp[i - d] + 1) {
                        dp[i] = dp[i - d] + 1;
                        last[i] = d;
                    }
                }
                x /= 10;
            }
            if (dp[i] != dp[i - maxD] + 1) throw new AssertionError();
        }
    }

    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        for (int i = 1; i < 10; i++) {
            Matrix z = new Matrix();
            for (int j = 0; j < 9; j++) {
                z.a[j][j + 1] = 0;
            }
            z.a[9][10 - i] = 1;
            all[0][i] = z;
        }
        {
            Matrix z = new Matrix();
            for (int j = 0; j < 10; j++) {
                z.a[j][j] = 0;
            }
            all[0][0] = z;
        }
        for (int i = 1; i < all.length; i++) {
            for (int j = 0; j < 10; j++) {
                Matrix f = new Matrix();
                for (int k = 0; k < 10; k++) f.a[k][k] = 0;
                for (int k = 0; k < 10; k++) {
                    Matrix on = all[i - 1][Math.max(k, j)];
//                    if (on != null)
                        f = on.mul(f);
                }
                all[i][j] = f;
            }
        }
        long n = in.nextLong();
//        if (n < 5000) {
//            out.println(dp[(int) n]);
//            return;
//        }
        int[] d = new int[(n + "").length()];
        {
            long m = n;
            for (int i = 0; i < d.length; i++) {
                d[d.length - i - 1] = (int) (m % 10);
                m /= 10;
            }
        }
        Matrix z = new Matrix();
        for (int i = 0; i < 10; i++) z.a[i][i] = 0;
        int maxD = 0;
        for (int i = 0; i < d.length; i++) {
            int length = d.length - i - 1;
            for (int j = 0; j < d[i]; j++) {
                Matrix on = all[length][Math.max(j, maxD)];
//                if (on != null)
                    z = on.mul(z);
//                System.out.println(all[length][Math.max(j, maxD)]);
            }
            maxD = Math.max(maxD, d[i]);
        }
        z = all[0][maxD].mul(z);
//        System.out.println(z);
//        System.out.println(z);
        out.println(z.a[9][9]);
//        System.out.println(dp[(int) n]);
    }

    static Matrix[][] all = new Matrix[20][10];

    static class Matrix {
        long[][] a;

        Matrix() {
            a = new long[10][10];
            for (long[] e : a) {
                Arrays.fill(e, Long.MAX_VALUE);
            }
        }

        public Matrix mul(Matrix b) {
            Matrix ret = new Matrix();
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 10; j++) {
                    long best = Long.MAX_VALUE;
                    for (int k = 0; k < 10; k++) {
                        if (a[i][k] != Long.MAX_VALUE && b.a[k][j] != Long.MAX_VALUE) {
                            best = Math.min(best, a[i][k] + b.a[k][j]);
                        }
                    }
                    ret.a[i][j] = best;
                }
            }
            return ret;
        }

        public String toString() {
            StringBuilder sb = new StringBuilder();
            for (long[] e : a) {
                sb.append(Arrays.toString(e)).append('\n');
            }
            return sb.toString();
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

    public long nextLong() {
        return Long.parseLong(next());
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