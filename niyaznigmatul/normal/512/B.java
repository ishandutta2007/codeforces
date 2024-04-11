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
import java.util.HashSet;
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
        int[] a = new int[n];
        int[] c = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
        }
        for (int i = 0; i < n; i++) {
            c[i] = in.nextInt();
        }
        Factor[][] f = new Factor[n][];
        HashSet<Integer>[] factors = new HashSet[n];
        for (int i = 0; i < n; i++) {
            f[i] = MathUtils.factorize(a[i]);
            factors[i] = new HashSet<>();
            for (Factor e : f[i]) {
                factors[i].add((int) e.prime);
            }
        }
        int ans = Integer.MAX_VALUE;
        for (int one = 0; one < n; one++) {
            int[] dp = new int[1 << f[one].length];
            Arrays.fill(dp, Integer.MAX_VALUE);
            dp[0] = c[one];
            for (int get = one + 1; get < n; get++) {
                int mask = 0;
                for (int i = 0; i < f[one].length; i++) {
                    if (!factors[get].contains((int) f[one][i].prime)) {
                        mask |= 1 << i;
                    }
                }
                for (int j = dp.length - 1; j >= 0; j--) {
                    if (dp[j] == Integer.MAX_VALUE) continue;
                    dp[j | mask] = Math.min(dp[j | mask], dp[j] + c[get]);
                }
            }
            ans = Math.min(ans, dp[dp.length - 1]);
        }
        out.println(ans == Integer.MAX_VALUE ? -1 : ans);
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

class Factor {
    public long prime;
    public int pow;

    public Factor(long prime, int pow) {
        this.prime = prime;
        this.pow = pow;
    }
}

class MathUtils {

    public static Factor[] factorize(long n) {
        List<Factor> ret = new ArrayList<Factor>();
        for (long i = 2; i * i <= n; i++) {
            if (n % i != 0) {
                continue;
            }
            int count = 0;
            while (n % i == 0) {
                n /= i;
                count++;
            }
            ret.add(new Factor(i, count));
        }
        if (n > 1) {
            ret.add(new Factor(n, 1));
        }
        return ret.toArray(new Factor[ret.size()]);
    }


}