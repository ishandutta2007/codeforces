import java.util.List;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.ArrayList;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Reader;
import java.io.Writer;
import java.math.BigInteger;
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
        int[] a = in.readIntArray(n);
        int[] b = in.readIntArray(n);
        long[] dp = new long[n];
        dp[0] = 0;
        int cur = 1;
        long[] x = new long[n];
        long[] y = new long[n];
        long[] inum = new long[n];
        long[] iden = new long[n];
        x[0] = b[0];
        y[0] = 0;
        iden[0] = 1;
        for (int i = 1; i < n; i++) {
            int left = 0;
            int right = cur;
            while (left < right - 1) {
                int mid = left + right >>> 1;
                if (inum[mid] <= iden[mid] * a[i]) {
                    left = mid;
                } else {
                    right = mid;
                }
            }
            dp[i] = x[left] * a[i] + y[left];
//            System.out.println(i  + " " + dp[i] + " " + x[left] + " " + y[left]);
            long nx = b[i];
            long ny = dp[i];
            while (cur > 0) {
                long nz = (ny - y[cur - 1]);
                long dz = (x[cur - 1] - nx);
                long gd = MathUtils.gcd(Math.abs(nz), Math.abs(dz));
                if (gd > 1) {
                    nz /= gd;
                    dz /= gd;
                }
//                System.out.println(nz + " " + dz);
                if (less(nz, dz, inum[cur - 1], iden[cur - 1])) {
//                if (nz * iden[cur - 1] <= dz * inum[cur - 1]) {
                    --cur;
                } else {
                    x[cur] = nx;
                    y[cur] = ny;
                    inum[cur] = nz;
                    iden[cur] = dz;
                    ++cur;
                    break;
                }
            }
            if (cur == 0) {
                x[cur] = nx;
                y[cur++] = ny;
            }
//            System.out.println(cur + " " + Arrays.toString(x) + " " + Arrays.toString(y));
        }
        out.println(dp[n - 1]);
    }

    static boolean less(long a, long b, long c, long d) {
        return BigInteger.valueOf(a).multiply(BigInteger.valueOf(d)).compareTo(BigInteger.valueOf(b).multiply(BigInteger.valueOf(c))) <= 0;
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

class MathUtils {


    public static long gcd(long a, long b) {
        while (b != 0) {
            long t = a % b;
            a = b;
            b = t;
        }
        return a;
    }

    }