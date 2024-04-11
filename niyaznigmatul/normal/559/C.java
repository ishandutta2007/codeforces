import java.io.Reader;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.util.Comparator;
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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {

    static final int MOD = 1000000007;

    static int mul(int a, int b) {
        return (int) ((long) a * b % MOD);
    }

    static int add(int a, int b) {
        a += b;
        if (a >= MOD) a -= MOD;
        return a;
    }

    static int[] FACT, REVFACT, REV;
    static final int MAXN = 323456;
    static {
        FACT = new int[MAXN];
        REVFACT = new int[MAXN];
        REV = new int[MAXN];
        FACT[1] = FACT[0] = 1;
        REVFACT[1] = REVFACT[0] = 1;
        REV[1] = 1;
        for (int i = 2; i < MAXN; i++) {
            FACT[i] = mul(i, FACT[i - 1]);
            REV[i] = mul(REV[MOD % i], MOD - MOD / i);
            REVFACT[i] = mul(REV[i], REVFACT[i - 1]);
        }
    }

    static int choose(int n, int k) {
        return mul(FACT[n], mul(REVFACT[n - k], REVFACT[k]));
    }

    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        int k = in.nextInt();
        BlackCell[] a = new BlackCell[k + 1];
        for (int i = 0; i < k; i++) {
            a[i] = new BlackCell(in.nextInt(), in.nextInt());
        }
        a[k] = new BlackCell(n, m);
        k++;
        Arrays.sort(a, new Comparator<BlackCell>() {
            public int compare(BlackCell c, BlackCell d) {
                return Integer.compare(c.x + c.y, d.x + d.y);
            }
        });
        int[] ways = new int[k];
        for (int i = 0; i < k; i++) {
            ways[i] = choose(a[i].x + a[i].y - 2, a[i].x - 1);
            for (int j = 0; j < i; j++) {
                if (a[j].x <= a[i].x && a[j].y <= a[i].y) {
                    ways[i] = add(ways[i], MOD - mul(ways[j], choose(a[i].x - a[j].x + a[i].y - a[j].y, a[i].x - a[j].x)));
                }
            }
        }
        out.println(ways[k - 1]);
    }

    static class BlackCell {
        int x;
        int y;

        public BlackCell(int x, int y) {
            this.x = x;
            this.y = y;
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


}