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
		TaskA solver = new TaskA();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskA {
    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        String s = in.next();
        String t = in.next();
        int c1 = 0;
        int c2 = 0;
        int c3 = 0;
        int c4 = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '1' && t.charAt(i) == '1') {
                ++c1;
            } else if (s.charAt(i) == '0' && t.charAt(i) == '0') {
                ++c2;
            } else if (s.charAt(i) == '1') {
                ++c3;
            } else {
                ++c4;
            }
        }
        int first = 0;
        int second = 0;
        for (int i = 0; i < s.length(); i++) {
            if ((i & 1) == 0) {
                if (c1 > 0) {
                    --c1;
                    first++;
                } else if (c3 > 0) {
                    --c3;
                    first++;
                } else if (c4 > 0) {
                    --c4;
                } else {
                    --c2;
                }
            } else {
                if (c1 > 0) {
                    --c1;
                    second++;
                } else if (c4 > 0) {
                    --c4;
                    ++second;
                } else if (c3 > 0) {
                    --c3;
                } else {
                    --c2;
                }
            }
        }
        if (first > second) {
            out.println("First");
        } else if (first < second) {
            out.println("Second");
        } else {
            out.println("Draw");
        }
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