import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Comparator;
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
    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        long k = in.nextLong();
        final int[] a = in.readIntArray(n);
        long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += a[i];
        }
        if (sum < k) {
            out.println(-1);
            return;
        }
        if (sum == k) {
            return;
        }
        Integer[] id = new Integer[n];
        for (int i = 0; i < n; i++) {
            id[i] = i;
        }
        Arrays.sort(id, new Comparator<Integer>() {
            public int compare(Integer o1, Integer o2) {
                return a[o1] - a[o2];
            }
        });
        int last = 0;
        for (int man = 0; man < n; ) {
            int next = man;
            while (next < n && a[id[man]] == a[id[next]]) {
                ++next;
            }
            int cur = a[id[man]];
            if (k >= (long) (n - man) * (cur - last)) {
                k -= (long) (n - man) * (cur - last);
            } else {
                long howMany = k / (n - man);
                int day = (int) (last + howMany + 1);
                k %= n - man;
                int i = 0;
                while (k > 0) {
                    if (a[i] >= day) {
                        --k;
                    }
                    ++i;
                }
                for (int j = i; j < n; j++) {
                    if (a[j] >= day) {
                        out.print(j + 1 + " ");
                    }
                }
                for (int j = 0; j < i; j++) {
                    if (a[j] > day) {
                        out.print(j + 1 + " ");
                    }
                }
                return;
            }
            man = next;
            last = cur;
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
        while (!isWhiteSpace(c)) {
            sb.appendCodePoint(c);
            c = read();
        }
        return sb.toString();
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

    public long nextLong() {
        return Long.parseLong(next());
    }

    public int[] readIntArray(int n) {
        int[] ret = new int[n];
        for (int i = 0; i < n; i++) {
            ret[i] = nextInt();
        }
        return ret;
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