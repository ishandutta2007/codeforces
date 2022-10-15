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
        int n = in.nextInt();
        int[] p = in.readIntArray(n);
        for (int i = 0; i < n; i++) p[i]--;
//        int q = in.nextInt();
//        for (int it = 0; it < q; it++) {
//            int type = in.nextInt();
//            int x = in.nextInt() - 1;
//            int y = in.nextInt() - 1;
//            if (type == 1) {
//                out.println(getAns(p, x, y));
//            } else {
//                int t = p[x];
//                p[x] = p[y];
//                p[y] = t;
//            }
//        }
        Fenwick f = new Fenwick(n);
        int[] rev = new int[n];
        for (int i = 0; i < n; i++) rev[p[i]] = i;
        for (int i = 0; i < n; i++) {
            if (i == 0 || rev[i] < rev[i - 1]) {
                f.add(i, 1);
            }
        }
        int q = in.nextInt();
        for (int it = 0; it < q; it++) {
            int type = in.nextInt();
            int x = in.nextInt() - 1;
            int y = in.nextInt() - 1;
            if (type == 1) {
                out.println(1 + f.getSum(y) - f.getSum(x));
            } else {
                int t = p[x];
                p[x] = p[y];
                p[y] = t;
                rev[p[x]] = x;
                rev[p[y]] = y;
                for (int i = p[x] - 1; i <= p[x] + 1; i++) {
                    if (i < 0 || i >= n) continue;
                    int val;
                    if (i == 0 || rev[i] < rev[i - 1]) {
                        val = 1;
                    } else {
                        val = 0;
                    }
                    f.add(i, val - (f.getSum(i) - f.getSum(i - 1)));
                }
                for (int i = p[y] - 1; i <= p[y] + 1; i++) {
                    if (i < 0 || i >= n) continue;
                    int val;
                    if (i == 0 || rev[i] < rev[i - 1]) {
                        val = 1;
                    } else {
                        val = 0;
                    }
                    f.add(i, val - (f.getSum(i) - f.getSum(i - 1)));
                }
            }
        }
    }

//    static int getAns(int[] p, int left, int right) {
//        int n = p.length;
//        int[] dp = new int[n + 1];
//        Arrays.fill(dp, Integer.MAX_VALUE);
//        dp[0] = Integer.MIN_VALUE;
//        int cur = 1;
//        for (int i = n - 1; i >= 0; i--) {
//            if (p[i] < left || p[i] > right) continue;
//            int x = -p[i];
//            int l = 0;
//            int r = cur;
//            while (l < r - 1) {
//                int mid = l + r >> 1;
//                if (dp[mid] > x) {
//                    r = mid;
//                } else {
//                    l = mid;
//                }
//            }
//            dp[r] = x;
//            if (r == cur) {
//                ++cur;
//            }
//        }
//        return right - left + 1 - cur + 2;
//    }
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

class Fenwick {
    int[] a;

    public Fenwick(int n) {
        a = new int[n];
    }

    public void add(int x, int y) {
        for (int i = x; i < a.length; i |= i + 1) {
            a[i] += y;
        }
    }

    public int getSum(int x) {
        if (x >= a.length) x = a.length - 1;
        int ret = 0;
        for (int i = x; i >= 0; i = (i & (i + 1)) - 1) {
            ret += a[i];
        }
        return ret;
    }

    }