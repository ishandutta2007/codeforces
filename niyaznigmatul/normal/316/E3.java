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
		TaskE3 solver = new TaskE3();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE3 {
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
    static int[] add;
    static int N;
    static int[] fib;
    static int[] sFib;
    static int[] count;

    static int shift(int x1, int x2, int cn) {
        int a = cn == 0 ? 0 : fib[cn - 1];
        int b = fib[cn];
        return (int) (((long) x1 * a + (long) x2 * b) % MOD);
    }

    static int getSum2(int v) {
        long ret = t2[v];
        if (add[v] != 0) {
            ret = (ret + (long) add[v] * sFib[count[v] - 1]) % MOD;
        }
        return (int) ret;
    }

    static int getSum1(int v) {
        long ret = t1[v];
        if (add[v] != 0) {
            int cc = count[v] - 2;
            if (cc >= 0) {
                ret = (ret + (long) add[v] * sFib[cc]) % MOD;
            }
        }
        return (int) ret;
    }

    static int ret1;
    static int ret2;
    static int retCount;

    static int addMod(int a, int b) {
        a += b;
        if (a >= MOD) a -= MOD;
        return a;
    }

    static void relax(int v) {
        if (add[v] == 0) {
            return;
        }
        add[v * 2] = addMod(add[v * 2], add[v]);
        add[v * 2 + 1] = addMod(add[v * 2 + 1], add[v]);
        t1[v] = getSum1(v);
        t2[v] = getSum2(v);
        add[v] = 0;
    }

    static void add(int v, int ll, int rr, int left, int right, int d) {
        if (right <= ll || rr <= left) {
            return;
        }
        if (left <= ll && rr <= right) {
            add[v] = addMod(add[v], d);
            return;
        }
        relax(v);
        int mid = (ll + rr) >> 1;
        add(v * 2, ll, mid, left, right, d);
        add(v * 2 + 1, mid, rr, left, right, d);
        int s1 = getSum1(v * 2 + 1);
        int s2 = getSum2(v * 2 + 1);
        t1[v] = addMod(getSum1(v * 2), shift(s1, s2, count[v * 2] - 1));
        t2[v] = addMod(getSum2(v * 2), shift(s1, s2, count[v * 2]));
    }

    static void getSum(int v, int ll, int rr, int left, int right) {
        if (right <= ll || rr <= left) {
            ret1 = 0;
            ret2 = 0;
            retCount = 0;
            return;
        }
        if (left <= ll && rr <= right) {
            ret1 = getSum1(v);
            ret2 = getSum2(v);
            retCount = count[v];
            return;
        }
        relax(v);
        int mid = (ll + rr) >> 1;
        getSum(v * 2, ll, mid, left, right);
        int lsum1 = ret1;
        int lsum2 = ret2;
        int lcount = retCount;
        getSum(v * 2 + 1, mid, rr, left, right);
        int rsum1 = ret1;
        int rsum2 = ret2;
        int rcount = retCount;
        if (lcount == 0) {
            ret1 = rsum1;
            ret2 = rsum2;
        } else {
            ret1 = addMod(lsum1, shift(rsum1, rsum2, lcount - 1));
            ret2 = addMod(lsum2, shift(rsum1, rsum2, lcount));
        }
        retCount = lcount + rcount;
    }

    static void build(int v, int l, int r) {
        if (l >= r) return;
        if (l + 1 == r) {
            count[v] = 1;
            return;
        }
        int mid = (l + r) >> 1;
        build(v * 2, l, mid);
        build(v * 2 + 1, mid, r);
        count[v] = count[v * 2 + 1] + count[v * 2];
    }

    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        N = Integer.highestOneBit(n) << 1;
        t1 = new int[N * 2];
        t2 = new int[N * 2];
        count = new int[N * 2];
        add = new int[N * 2];
        build(1, 0, N);
        fib = getFib(N * 2 + 2);
        sFib = new int[fib.length];
        sFib[0] = fib[0];
        for (int i = 1; i < sFib.length; i++) {
            sFib[i] = (sFib[i - 1] + fib[i]) % MOD;
        }
        for (int i = 0; i < n; i++) {
            getSum(1, 0, N, i, i + 1);
            int v = ret2;
            v = (in.nextInt() - v);
            if (v < 0) v += MOD;
            add(1, 0, N, i, i + 1, v);
        }
//        for (int i = 0; i < 2 * N; i++) {
//            System.out.println(i + " " + t1[i] + " " + t2[i] + " " + add[i] + " " + count[i]);
//        }
        for (int i = 0; i < m; i++) {
            int t = in.nextInt();
            if (t == 1) {
                int x = in.nextInt() - 1;
                int v = in.nextInt();
                getSum(1, 0, N, x, x + 1);
                v = (v - ret2);
                if (v < 0) v += MOD;
                add(1, 0, N, x, x + 1, v);
            } else if (t == 2) {
                int l = in.nextInt() - 1;
                int r = in.nextInt();
                getSum(1, 0, N, l, r);
                out.println(ret2);
            } else if (t == 3) {
                int l = in.nextInt() - 1;
                int r = in.nextInt();
                int d = in.nextInt();
                add(1, 0, N, l, r, d);
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