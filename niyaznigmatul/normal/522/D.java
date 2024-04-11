import java.io.Reader;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Random;
import java.io.BufferedReader;
import java.util.List;
import java.io.OutputStream;
import java.util.Comparator;
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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }
}

class TaskD {
    static class Query {
        int left;
        int right;
        int answer;

        public Query(int left, int right) {
            this.left = left;
            this.right = right;
        }
    }

    public void solve(int testNumber, FastScanner in, FastPrinter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        int[] a = in.readIntArray(n);
        Query[] q = new Query[m];
        for (int i = 0; i < m; i++) {
            q[i] = new Query(in.nextInt() - 1, in.nextInt());
        }
        Query[] sortedQ = q.clone();
        Arrays.sort(sortedQ, new Comparator<Query>() {
            public int compare(Query o1, Query o2) {
                return Integer.compare(o1.left, o2.left);
            }
        });
        int[] as = ArrayUtils.sortAndUnique(a);
        for (int i = 0; i < a.length; i++) {
            a[i] = Arrays.binarySearch(as, a[i]);
        }
        int[] last = new int[as.length];
        Arrays.fill(last, -1);
        FenwickMin f = new FenwickMin(n);
        int currentQuery = m - 1;
        for (int i = n - 1; i >= 0; i--) {
            int x = a[i];
            if (last[x] >= 0) {
                f.setAndMin(last[x], last[x] - i);
            }
            last[x] = i;
            while (currentQuery >= 0 && sortedQ[currentQuery].left == i) {
                sortedQ[currentQuery].answer = f.getMin(sortedQ[currentQuery].right - 1);
                --currentQuery;
            }
        }
        for (Query e : q) {
            if (e.answer == Integer.MAX_VALUE) {
                out.println(-1);
            } else {
                out.println(e.answer);
            }
        }
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


}

class ArrayUtils {


    static final long seed = System.nanoTime();

    static final Random rand = new Random(seed);

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
                last = ret[i];
            }
        }
        return Arrays.copyOf(ret, j);
    }

    public static void sort(int[] a) {
        shuffle(a);
        Arrays.sort(a);
    }

    public static void shuffle(int[] a) {
        for (int i = 0; i < a.length; i++) {
            int j = rand.nextInt(i + 1);
            int t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }


}

class FenwickMin {
    int[] min;

    public FenwickMin(int n) {
        min = new int[n];
        Arrays.fill(min, Integer.MAX_VALUE);
    }

    public void setAndMin(int x, int y) {
        for (int i = x; i < min.length; i |= i + 1) {
            min[i] = Math.min(min[i], y);
        }
    }

    public int getMin(int x) {
        x = Math.min(x, min.length - 1);
        int ret = Integer.MAX_VALUE;
        for (int i = x; i >= 0; i = (i & i + 1) - 1) {
            ret = Math.min(ret, min[i]);
        }
        return ret;
    }
}