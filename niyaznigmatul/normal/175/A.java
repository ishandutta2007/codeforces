import java.io.InputStreamReader;
import java.io.IOException;
import java.util.InputMismatchException;
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
 * @author niyaznigmatul 
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		FastScanner in = new FastScanner(inputStream);
		FastPrinter out = new FastPrinter(outputStream);
		TaskA solver = new TaskA();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskA {
	public void solve(int testNumber, FastScanner in, FastPrinter out) {
        String s = in.next();
        int ans = Integer.MIN_VALUE;
        for (int i = 1; i < s.length(); i++) {
            for (int j = i + 1; j < s.length(); j++) {
                Integer a = get(s.substring(0, i));
                Integer b = get(s.substring(i, j));
                Integer c = get(s.substring(j));
                if (a == null || b == null || c == null) {
                    continue;
                }
                ans = Math.max(ans, a + b + c);
            }
        }
        out.println(ans == Integer.MIN_VALUE ? -1 : ans);
	}

    static Integer get(String s) {
        if (s.isEmpty()) {
            return null;
        }
        if (s.startsWith("0") && s.length() > 1) {
            return null;
        }
        BigInteger a = new BigInteger(s);
        if (a.compareTo(BigInteger.valueOf(1000000)) > 0) {
            return null;
        }
        return a.intValue();
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

    }

class FastPrinter extends PrintWriter {

    public FastPrinter(OutputStream out) {
        super(out);
    }

    public FastPrinter(Writer out) {
        super(out);
    }


}