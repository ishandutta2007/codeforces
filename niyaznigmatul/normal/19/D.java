import java.util.NavigableSet;
import java.util.SortedSet;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Random;
import java.io.Writer;
import java.util.List;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Set;
import java.io.Reader;
import java.util.TreeSet;
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
		TaskD solver = new TaskD();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskD {
    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int m = in.nextInt();
        Query[] q = new Query[m];
        int[] x = new int[m];
        int[] y = new int[m];
        for (int i = 0; i < m; i++) {
            String s = in.next();
            int type = s.equals("add") ? 1 : s.equals("remove") ? 2 : 3;
            q[i] = new Query(type, in.nextInt(), in.nextInt());
            x[i] = q[i].x;
            y[i] = q[i].y;
        }
        x = ArrayUtils.sortAndUnique(x);
        y = ArrayUtils.sortAndUnique(y);
        for (int i = 0; i < m; i++) {
            q[i].x = Arrays.binarySearch(x, q[i].x);
            q[i].y = Arrays.binarySearch(y, q[i].y);
        }
        NavigableSet<Integer>[] sets = new NavigableSet[x.length];
        for (int i = 0; i < sets.length; i++) {
            sets[i] = new TreeSet<Integer>();
        }
        count = new int[x.length];
        n = Integer.highestOneBit(x.length) << 1;
        tree = new int[2 * n];
        Arrays.fill(tree, Integer.MIN_VALUE);
        for (Query e : q) {
            if (e.type == 1) {
                sets[e.x].add(e.y);
                add(e.x, sets[e.x].last());
            } else if (e.type == 2) {
                sets[e.x].remove(e.y);
                add(e.x, sets[e.x].isEmpty() ? Integer.MIN_VALUE : sets[e.x].last());
            } else {
                int curX = getMin(e.x + 1, x.length, e.y + 1);
                if (curX < 0) {
                    out.println(-1);
                } else {
                    out.println(x[curX] + " " + y[sets[curX].higher(e.y)]);
                }
            }
        }
    }

    static int[] tree;
    static int[] count;
    static int n;

    static void add(int x, int y) {
        x += n;
        tree[x] = y;
        while (x > 1) {
            x >>= 1;
            tree[x] = Math.max(tree[x * 2], tree[x * 2 + 1]);
        }
    }

    static int getFirst(int v, int l, int r, int left, int right, int x) {
        if (r <= left || right <= l || tree[v] < x) {
            return -1;
        }
        if (l == r - 1) {
            return l;
        }
        int mid = l + r >> 1;
        int ans = getFirst(v * 2, l, mid, left, right, x);
        if (ans >= 0) {
            return ans;
        }
        return getFirst(v * 2 + 1, mid, r, left, right, x);
    }

    static int getMin(int l, int r, int y) {
        return getFirst(1, 0, n, l, r, y);
//        --r;
//        int ret = Integer.MAX_VALUE;
//        l += n;
//        r += n;
//        while (l <= r) {
//            if ((l & 1) == 1) {
//                ret = Math.min(ret, tree[l++]);
//            }
//            if ((r & 1) == 0) {
//                ret = Math.min(ret, tree[r--]);
//            }
//            l >>= 1;
//            r >>= 1;
//        }
//        return ret;
    }

    static class Query {
        int type;
        int x;
        int y;

        Query(int type, int x, int y) {
            this.type = type;
            this.x = x;
            this.y = y;
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

    static public int[] sortAndUnique(int[] a) {
        int[] ret = a.clone();
        sort(ret);
        if (ret.length == 0) {
            return ret;
        }
        int last = ret[0];
        int j = 1;
        for (int i = 1; i < ret.length; i++) {
            if (last != ret[i]) {
                ret[j++] = ret[i];
            }
            last = ret[i];
        }
        return Arrays.copyOf(ret, j);
    }

    public static void sort(int[] a) {
        Random rand = new Random(System.nanoTime());
        for (int i = 0; i < a.length; i++) {
            int j = rand.nextInt(i + 1);
            int t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
        Arrays.sort(a);
    }


    }