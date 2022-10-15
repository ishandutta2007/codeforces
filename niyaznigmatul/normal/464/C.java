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
    static final int MOD = 1000000007;

    static int add(int a, int b) {
        a += b;
        if (a >= MOD) a -= MOD;
        return a;
    }

    static int mul(int a, int b) {
        return (int) ((long) a * b % MOD);
    }

    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        String s = in.next();
        int n = in.nextInt();
        char[] from = new char[n];
        String[] to = new String[n];
        for (int i = 0; i < n; i++) {
            String line = in.next();
            from[i] = line.charAt(0);
            to[i] = line.substring(3);
        }
        int[] map = new int[10];
        long[] length = new long[10];
        for (int i = 0; i < 10; i++) {
            map[i] = i;
            length[i] = 1;
        }
        for (int i = n - 1; i >= 0; i--) {
            int nMap = 0;
            int nLength = 0;
            String t = to[i];
            for (int j = 0; j < t.length(); j++) {
                int d = t.charAt(j) - '0';
                nMap = add(mul(nMap, MathUtils.modPow(10, length[d], MOD)), map[d]);
                nLength += length[d];
                if (nLength >= MOD - 1) {
                    nLength -= MOD - 1;
                }
            }
            map[from[i] - '0'] = nMap;
            length[from[i] - '0'] = nLength;
        }
        {
            int nMap = 0;
            String t = s;
            for (int j = 0; j < t.length(); j++) {
                int d = t.charAt(j) - '0';
                nMap = add(mul(nMap, MathUtils.modPow(10, length[d], MOD)), map[d]);
            }
            out.println(nMap);
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

class MathUtils {


    public static int modPow(int a, long b, int mod) {
        int ret = 1;
        a = (a % mod + mod) % mod;
        while (b > 0) {
            if ((b & 1) == 1) {
                ret = (int) ((long) ret * a % mod);
            }
            a = (int) ((long) a * a % mod);
            b >>= 1;
        }
        return ret;
    }
}