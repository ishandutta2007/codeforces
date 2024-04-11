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
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        long left = in.nextLong();
        long right = in.nextLong();
        int k = in.nextInt();
        if (right - left <= 10) {
            int count = (int) (right - left + 1);
            long best = Long.MAX_VALUE;
            int bMask = 0;
            for (int mask = 1; mask < 1 << count; mask++) {
                if (Integer.bitCount(mask) > k) continue;
                long xor = 0;
                for (int i = 0; i < count; i++) {
                    if (((mask >> i) & 1) == 1) xor ^= (left + i);
                }
                if (xor < best) {
                    best = xor;
                    bMask = mask;
                }
            }
            out.println(best);
            out.println(Integer.bitCount(bMask));
            for (int i = 0; i < count; i++) {
                if (((bMask >> i) & 1) == 1) {
                    out.print(left + i + " ");
                }
            }
            out.println();
            return;
        }
        if (k == 1) {
            out.println(left);
            out.println(1);
            out.println(left);
            return;
        }
        if (k >= 4) {
            left = (left + 3) / 4 * 4;
            out.println(0);
            out.println(4);
            out.println(left + " " + (left + 1) + " " + (left + 2) + " " + (left + 3));
            return;
        }
        if (k == 3) {
            for (int bit = 2; bit < 50; bit++) {
                long first = (1L << bit - 1) - 1;
                long second = ((1L << bit) - 1) ^ (1L << bit - 2);
                long third = first ^ second;
                if (first >= second || second >= third) throw new AssertionError();
                if (first >= left && third <= right) {
                    out.println(0);
                    out.println(3);
                    out.println(first + " " + second + " " + third);
                    return;
                }
            }
        }
        if ((left & 1) == 1) ++left;
        out.println(1);
        out.println(2);
        out.println(left + " " + (left + 1));
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

    public long nextLong() {
        return Long.parseLong(next());
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