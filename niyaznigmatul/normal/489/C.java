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
    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int m = in.nextInt();
        int s = in.nextInt();
        if (s == 0) {
            if (m == 1) {
                out.println("0 0");
                return;
            }
            out.println("-1 -1");
            return;
        }
        if (s > 9 * m || s < 1) {
            out.println("-1 -1");
            return;
        }
        out.println(getMin(m, s) + " " + getMax(m, s));
    }

    static String getMin(int m, int s) {
        int first = Math.max(s - 9 * (m - 1), 1);
        s -= first;
        char[] ansMin = new char[m];
        ansMin[0] = (char) (first + '0');
        for (int i = m - 1; i > 0; i--) {
            int cur = Math.min(9, s);
            s -= cur;
            ansMin[i] = (char) (cur + '0');
        }
        return new String(ansMin);
    }

    static String getMax(int m, int s) {
        char[] ans = new char[m];
        for (int i = 0; i < m; i++) {
            int cur = Math.min(9, s);
            s -= cur;
            ans[i] = (char) (cur + '0');
        }
        return new String(ans);
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