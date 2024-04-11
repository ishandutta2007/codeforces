import java.util.List;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Random;
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
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {
    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        int d = in.nextInt();
        long[] h = new long[n];
        for (int i = 0; i < n; i++) {
            h[i] = in.nextLong();
        }
        long[] xs = h.clone();
        xs = ArrayUtils.sortAndUnique(xs);
        MaxSegmentTree tree = new MaxSegmentTree(xs.length);
        int[] who = new int[xs.length];
        Arrays.fill(who, -1);
        int[] from = new int[n];
        int[] dp = new int[n];
        for (int i = 0; i < n; i++) {
            dp[i] = 1;
            {
                int left = -1;
                int right = xs.length;
                while (left < right - 1) {
                    int mid = left + right >> 1;
                    if (xs[mid] <= h[i] - d) {
                        left = mid;
                    } else {
                        right = mid;
                    }
                }
                int got = tree.getMax(0, right);
                if (got != Integer.MIN_VALUE && got + 1 > dp[i]) {
                    dp[i] = got + 1;
                    from[i] = who[tree.getMaxId(0, right)];
                }
            }
            {
                int left = -1;
                int right = xs.length;
                while (left < right - 1) {
                    int mid = left + right >> 1;
                    if (xs[mid] >= h[i] + d) {
                        right = mid;
                    } else {
                        left = mid;
                    }
                }
                int got = tree.getMax(right, xs.length);
                if (got != Integer.MIN_VALUE && got + 1 > dp[i]) {
                    dp[i] = got + 1;
                    int maxId = tree.getMaxId(right, xs.length);
                    from[i] = who[maxId];
                }
            }
            int id = Arrays.binarySearch(xs, h[i]);
            if (who[id] < 0 || dp[who[id]] < dp[i]) {
                who[id] = i;
                tree.set(id, dp[i]);
            }
        }
//        System.out.println(Arrays.toString(who));
//        System.out.println(Arrays.toString(from));
        int ansI = -1;
        for (int i = 0; i < n; i++) {
            if (ansI < 0 || dp[i] > dp[ansI]) ansI = i;
        }
        int[] ans = new int[n];
        int ac = 0;
        for (int i = ansI; ;) {
            ans[ac++] = i;
            if (dp[i] == 1) {
                break;
            }
            i = from[i];
        }
        out.println(ac);
        for (int i = ac - 1; i >= 0; i--) {
            if (i + 1 < ac) out.print(' ');
            out.print(ans[i] + 1);
        }
        out.println();
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

class ArrayUtils {


    static final long seed = System.nanoTime();

    static final Random rand = new Random(seed);

    static public long[] sortAndUnique(long[] a) {
        long[] ret = a.clone();
        sort(ret);
        if (ret.length == 0) {
            return ret;
        }
        long last = ret[0];
        int j = 1;
        for (int i = 1; i < ret.length; i++) {
            if (last != ret[i]) {
                ret[j++] = ret[i];
                last = ret[i];
            }
        }
        return Arrays.copyOf(ret, j);
    }


    public static void sort(long[] a) {
        shuffle(a);
        Arrays.sort(a);
    }

    public static void shuffle(long[] a) {
        for (int i = 0; i < a.length; i++) {
            int j = rand.nextInt(i + 1);
            long t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
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
        for (int i = 0; i < this.n; i++) {
            maxId[i + this.n] = i;
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

    public int getMaxId(int left, int right) {
        --right;
        left += n;
        right += n;
        int ret = Integer.MIN_VALUE;
        int retPos = -1;
        while (left <= right) {
            if ((left & 1) == 1) {
                if (ret < max[left]) {
                    ret = max[left];
                    retPos = maxId[left];
                }
                left++;
            }
            if ((right & 1) == 0) {
                if (ret < max[right]) {
                    ret = max[right];
                    retPos = maxId[right];
                }
                right--;
            }
            left >>= 1;
            right >>= 1;
        }
        return retPos;
    }

}