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
		TaskE2 solver = new TaskE2();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE2 {

    static final int MOD = 1000000000;

    static int[] getFib(int n) {
        n = Math.max(n, 10);
        int[] ret = new int[n];
        ret[0] = ret[1] = 1;
        for (int i = 2; i < n; i++) {
            ret[i] = ret[i - 1] + ret[i - 2];
            if (ret[i] >= MOD) ret[i] -= MOD;
        }
        return ret;
    }

    static int[] t1;
    static int[] t2;
    static int N;
    static int[] fib;

    static int shift(int x1, int x2, int cn) {
        int a = cn == 0 ? 0 : fib[cn - 1];
        int b = fib[cn];
        return (int) (((long) x1 * a + (long) x2 * b) % MOD);
    }

    static void set(int x, int y) {
        x += N;
        t1[x] = 0;
        t2[x] = y;
        int cnt = 1;
        while (x > 1) {
            x >>= 1;
            t1[x] = (t1[2 * x] + shift(t1[x * 2 + 1], t2[x * 2 + 1], cnt - 1)) % MOD;
            t2[x] = (t2[2 * x] + shift(t1[x * 2 + 1], t2[x * 2 + 1], cnt)) % MOD;
//            System.out.println(t1[2 * x] + " " + t2[2 * x] + " " + t1[2 * x + 1] + " " + t2[2 * x + 1] + " " + t1[x] + " " + t2[x]);
            cnt <<= 1;
        }
    }

    static int getSum(int l, int r) {
        --r;
        l += N;
        r += N;
        int retl1 = 0;
        int retl2 = 0;
        int retr1 = 0;
        int retr2 = 0;
        int cntLeft = 0;
        int count = 1;
        while (l <= r) {
            if ((l & 1) == 1) {
                if (cntLeft == 0) {
                    retl1 = t1[l];
                    retl2 = t2[l];
                } else {
                    retl1 = (retl1 + shift(t1[l], t2[l], cntLeft - 1)) % MOD;
                    retl2 = (retl2 + shift(t1[l], t2[l], cntLeft)) % MOD;
                }
                cntLeft += count;
                ++l;
            }
            if ((r & 1) == 0) {
                int nr1 = (t1[r] + shift(retr1, retr2, count - 1)) % MOD;
                int nr2 = (t2[r] + shift(retr1, retr2, count)) % MOD;
                retr1 = nr1;
                retr2 = nr2;
                --r;
            }
            l >>= 1;
            r >>= 1;
            count <<= 1;
        }
        return (retl2 + shift(retr1, retr2, cntLeft)) % MOD;
    }

    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        N = Integer.highestOneBit(n) << 1;
        t1 = new int[N * 2];
        t2 = new int[N * 2];
        fib = getFib(N * 2 + 2);
        for (int i = 0; i < n; i++) {
            set(i, in.nextInt());
        }
        for (int i = 0; i < m; i++) {
            int t = in.nextInt();
            if (t == 1) {
                int x = in.nextInt() - 1;
                int v = in.nextInt();
                set(x, v);
            } else if (t == 2) {
                int l = in.nextInt() - 1;
                int r = in.nextInt();
                out.println(getSum(l, r));
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