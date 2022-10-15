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
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {

    static final int MOD = 1000000007;

    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int m = in.nextInt() + 1;
        String mS = m + "";
        int[] number = new int[mS.length()];
        for (int i = 0; i < mS.length(); i++) {
            number[i] = mS.charAt(i) - '0';
        }
        int[] count = new int[mS.length() + 1];
        long[][][] dp = new long[mS.length() + 1][10][mS.length() + 1];
        dp[0][0][0] = 1;
        for (int i = 1; i <= mS.length(); i++) {
            for (int last = 0; last < 10; last++) {
                for (int lucky = 0; lucky <= i; lucky++) {
                    for (int prev = 0; prev < 10; prev++) {
                        int newLucky = lucky - (last == 4 || last == 7 ? 1 : 0);
                        if (newLucky < 0) {
                            continue;
                        }
                        dp[i][last][lucky] += dp[i - 1][prev][newLucky];
                    }
                }
            }
        }
        int alreadyLucky = 0;
        for (int i = 0; i < mS.length(); i++) {
            for (int cur = 0; cur < number[i]; cur++) {
                for (int otherLucky = 0; alreadyLucky + otherLucky <= mS.length(); otherLucky++) {
                    count[alreadyLucky + otherLucky] += dp[mS.length() - i][cur][otherLucky];
                }
            }
            if (number[i] == 4 || number[i] == 7) {
                ++alreadyLucky;
            }
        }
        --count[0];
        long[] f = new long[mS.length()];
        for (int i = 0; i < mS.length(); i++) {
            part = new int[6];
            z = new int[mS.length()];
            f[i] = go(0, 6, i, count);
        }
        long ans = 0;
        for (int i = 0; i <= mS.length(); i++) {
            for (int j = 0; j < i; j++) {
                ans = (ans + count[i] * f[j]) % MOD;
            }
        }
        out.println(ans);
    }

    static int[] part;
    static int[] z;

    static long go2(int[] count) {
        Arrays.fill(z, 0);
        for (int i : part) {
            z[i]++;
        }
        long ret = 1;
        for (int i = 0; i < z.length; i++) {
            if (z[i] > 0) {
                ret *= c(count[i], z[i]);
                ret %= MOD;
            }
        }
        return ret;
    }

    static long c(int n, int k) {
        long ret = 1;
        for (int i = 0; i < k; i++) {
            ret = ret * (n - i) % MOD;
        }
        return ret;
    }

    static long go(int x, int n, int toGet, int[] count) {
        if (x == n) {
            return toGet == 0 ? go2(count) : 0;
        }
        long ret = 0;
        for (int cur = 0; cur <= toGet && cur < count.length; cur++) {
            part[x] = cur;
            ret = (ret + go(x + 1, n, toGet - cur, count)) % MOD;
        }
        return ret;
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

    static boolean isWhiteSpace(int c) {
        return c >= -1 && c <= 32;
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
        while (!isWhiteSpace(c)) {
            if (c < '0' || c > '9') {
                throw new NumberFormatException("digit expected " + (char) c
                        + " found");
            }
            ret = ret * 10 + c - '0';
            c = read();
        }
        return ret * sgn;
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