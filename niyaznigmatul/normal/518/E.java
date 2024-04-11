import java.io.Reader;
import java.util.InputMismatchException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.BufferedReader;
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
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {
    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        int k = in.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            String s = in.next();
            if (s.equals("?")) {
                a[i] = Integer.MIN_VALUE;
            } else {
                a[i] = Integer.parseInt(s);
            }
        }
        for (int i = 0; i < k; i++) {
            int cn = 0;
            for (int j = i; j < n; j += k) {
                cn++;
            }
            int[] b = new int[cn];
            for (int j = i; j < n; j += k) {
                b[j / k] = a[j];
            }
            b = solve(b);
            if (b == null) {
                out.println("Incorrect sequence");
                return;
            }
            for (int j = i; j < n; j += k) {
                a[j] = b[j / k];
            }
        }
        out.printArray(a);
    }

    static final int INF = Integer.MAX_VALUE / 2;

    static int[] solve(int[] a) {
        long last = -INF;
        int n = a.length;
        for (int i = -1; i < n; ) {
            int j = i + 1;
            while (j < n && a[j] == Integer.MIN_VALUE) {
                ++j;
            }
            long next = j >= n ? INF : a[j];
            int len = j - i - 1;
            if (next <= last || next - last - 1 < len) {
                return null;
            }
            long first1 = last + 1;
            long first2 = next - len;
            long first3 = -(len / 2);
            long cost1 = getCost(last, next, len, first1);
            long cost2 = getCost(last, next, len, first2);
            long cost3 = getCost(last, next, len, first3);
            long best = Math.min(Math.min(cost1, cost2), cost3);
            if (best == Long.MAX_VALUE) {
                throw new AssertionError();
            }
//            System.out.println(first1 + " " + cost1);
//            System.out.println(first2 + " " + cost2);
//            System.out.println(first3 + " " + cost3);
            long bestFirst = -1;
            if (cost1 == best) {
                bestFirst = first1;
            } else if (cost2 == best) {
                bestFirst = first2;
            } else {
                bestFirst = first3;
            }
            ++i;
            while (i < j) {
                a[i] = (int) bestFirst;
                ++bestFirst;
                ++i;
            }
            last = next;
        }
        return a;
    }

    static long getCost(long prev, long next, int len, long first) {
        if (first <= prev) return Long.MAX_VALUE;
        if (next <= first + len - 1) return Long.MAX_VALUE;
        long left = first;
        long right = first + len - 1;
        if (left <= 0 && 0 <= right) {
            return f(Math.abs(left), 1) + f(right, 1);
        } else if (right < 0) {
            return f(len, Math.abs(right));
        } else {
            return f(len, left);
        }
    }

    static long f(long count, long first) {
        return count * (count - 1) / 2 + first * count;
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

    public void printArray(int[] a) {
        for (int i = 0; i < a.length; i++) {
            if (i > 0) {
                print(' ');
            }
            print(a[i]);
        }
        println();
    }


}