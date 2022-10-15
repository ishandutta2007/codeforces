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
 * @author niyaznigmatul 
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
        int m = in.nextInt();
        int[] a = new int[2 * n];
        int maximal = 0;
        for (int i = 0; i < n; i++) {
            a[i] = a[i + n] = in.nextInt();
            maximal = Math.max(maximal, a[i]);
        }
        int[] b = new int[m];
        for (int i = 0; i < m; i++) {
            b[i] = in.nextInt();
            maximal = Math.max(maximal, b[i]);
        }
        int[] c = new int[maximal + 1];
        Arrays.fill(c, -1);
        for (int i = 0; i < m; i++) {
            c[b[i]] = i;
        }
        b = null;
        int[] deque = new int[2 * m];
        int head = 0;
        int tail = 0;
        int begin = 0;
        int ans = 0;
        for (int i = 0; i < 2 * n; i++) {
            while (i - begin > n) {
                head++;
                if (head == deque.length) {
                    head = 0;
                }
                begin++;
            }
            int pos = c[a[i]];
            if (pos < 0) {
                begin = i + 1;
                head = tail = 0;
                continue;
            }
            int from = get(deque, head);
            int to = get(deque, tail - 1);
            while (head != tail && !can(pos, from, to)) {
                head++;
                if (head == deque.length) {
                    head = 0;
                }
                ++begin;
                from = get(deque, head);
                to = get(deque, tail - 1);
            }
            deque[tail++] = pos;
            if (tail == deque.length) {
                tail = 0;
            }
            ans = Math.max(ans, size(head, tail, deque));
        }
        out.println(ans);
	}

    static int size(int head, int tail, int[] deque) {
        int ret = tail - head;
        if (ret < 0) {
            ret += deque.length;
        }
        return ret;
    }

    static boolean can(int pos, int from, int to) {
        return from <= to ? (pos < from || pos > to) : (to < pos && pos < from);
    }

    static  int get(int[] deque, int i) {
        if (i < 0) {
            i += deque.length;
        }
        return deque[i];
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