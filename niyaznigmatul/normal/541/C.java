import java.io.Reader;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.math.BigInteger;
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
		TaskC solver = new TaskC();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskC {
    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        int[] f = new int[n];
        for (int i = 0; i < n; i++) f[i] = in.nextInt() - 1;
        int[] was = new int[n];
        int[] d = new int[n];
        BigInteger ans = BigInteger.ONE;
        for (int i = 0; i < n; i++) {
            Arrays.fill(was, 0);
            int p = i;
            int c = 0;
            while (was[p] == 0) {
                d[p] = c++;
                was[p] = 1;
                p = f[p];
            }
            BigInteger cycle = BigInteger.valueOf(c - d[p]);
            ans = ans.divide(ans.gcd(cycle)).multiply(cycle);
        }
        for (int q = 1; q <= 2 * n; q++) {
            boolean bad = false;
            for (int i = 0; i < n; i++) {
                int v = i;
                for (int j = 0; j < q; j++) v = f[v];
                int u = v;
                for (int j = 0; j < q; j++) u = f[u];
                if (v != u) {
                    bad = true;
                }
            }
            if (!bad) {
                out.println(q);
                return;
            }
        }
        out.println(ans);
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