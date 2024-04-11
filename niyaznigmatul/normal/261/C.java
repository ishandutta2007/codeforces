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

//    static {
//        for (int n = 2; n <= 80; n++) {
//            int[][] a = new int[n][n];
//            a[0][n - 1] = 1;
//            for (int i = 1; i < n; i++) {
//                for (int j = 0; j < n; j++) {
//                    if (j > 0) {
//                        a[i][j] ^= a[i - 1][j - 1];
//                    }
//                    if (j + 1 < n) {
//                        a[i][j] ^= a[i - 1][j + 1];
//                    }
//                }
//            }
//            for (int[] d : a) {
//                for (int e : d) {
//                    System.err.print(e == 1 ? 'O' : '.');
//                }
//                System.err.println("");
//            }
//            System.err.println("");
//        }
//    }

    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        long n = in.nextLong() + 1;
        long t = in.nextLong();
        if ((t & t - 1) != 0) {
            out.println(0);
            return;
        }
        long answer = 0;
        if (n >= 2 && t == 1) {
            ++answer;
        }
        if (n >= 3 && t == 2) {
            ++answer;
        }
        out.println(solve(n - 3, Long.numberOfTrailingZeros(t)) + answer);
    }

    static long solve(long n, int t) {
        if (n <= 0) {
            return 0;
        }
        long ret = 0;
        for (long x = 4; n >= x; x <<= 1) {
            n -= x;
            int bits = Long.numberOfTrailingZeros(x);
            ret += c(bits, t);
        }
        return ret + solve2(n, t);
    }

    static long solve2(long n, int t) {
        int[] number = new int[Long.toBinaryString(n).length()];
        long m = n;
        for (int i = number.length - 1; i >= 0; i--) {
            number[i] = (int) (m & 1);
            m >>= 1;
        }
        int ones = 0;
        long ret = 0;
        for (int i = 0; i < number.length; i++) {
            if (number[i] == 1) {
                ret += c(number.length - i - 1, t - ones);
                ++ones;
            }
        }
        return ret;
    }

    static long c(int n, int k) {
        if (k < 0 || k > n) {
            return 0;
        }
        return C[n][k];
    }

    static long[][] C;
    static {
        C = new long[60][60];
        for (int i = 0; i < C.length; i++) {
            C[i][0] = 1;
            for (int j = 1; j <= i; j++) {
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
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

    public long nextLong() {
        return Long.parseLong(next());
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