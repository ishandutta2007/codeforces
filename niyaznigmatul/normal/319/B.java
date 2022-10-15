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
        int[] a = in.readIntArray(n);
        MaxSegmentTree t1 = new MaxSegmentTree(n);
        MaxSegmentTree t2 = new MaxSegmentTree(n);
        int[] rev = new int[n];
        for (int i = 0; i < n; i++) {
            --a[i];
            rev[a[i]] = i;
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int got = t1.getMax(a[i] + 1, n);
            if (got == Integer.MIN_VALUE) {
                t2.set(i, -1);
            } else {
                int got2 = t2.getMax(got + 1, i);
                if (got2 == Integer.MIN_VALUE) {
                    got2 = 0;
                }
                t2.set(i, got2 + 1);
                if (got2 + 1 > ans) {
                    ans = got2 + 1;
                }
            }
            t1.set(a[i], i);
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

class MaxSegmentTree {
    int[] max;
    int[] maxId;
    int n;

    public MaxSegmentTree(int n) {
        this.n = Integer.highestOneBit(n) << 1;
        max = new int[this.n * 2];
        maxId = new int[this.n * 2];
        Arrays.fill(max, Integer.MIN_VALUE);
        for (int i = 0; i < n; i++) {
            maxId[i + n] = i;
        }
        for (int i = 0; i < n; i++) {
            set(i, Integer.MIN_VALUE);
        }
    }

    public void set(int x, int y) {
        x += n;
        max[x] = y;
        while (x > 1) {
            x >>= 1;
            int left = max[x << 1];
            int right = max[(x << 1) | 1];
            if (left >= right) {
                max[x] = left;
                maxId[x] = maxId[x << 1];
            } else {
                max[x] = right;
                maxId[x] = maxId[(x << 1) | 1];
            }
        }
    }

    public int getMax(int left, int right) {
        --right;
        left += n;
        right += n;
        int ret = Integer.MIN_VALUE;
        while (left <= right) {
            if ((left & 1) == 1) {
                ret = Math.max(ret, max[left]);
                left++;
            }
            if ((right & 1) == 0) {
                ret = Math.max(ret, max[right]);
                right--;
            }
            left >>= 1;
            right >>= 1;
        }
        return ret;
    }

}