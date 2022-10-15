import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.util.InputMismatchException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.io.Writer;
import java.io.BufferedReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author Niyaz Nigmatullin
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        FastScanner in = new FastScanner(inputStream);
        FastPrinter out = new FastPrinter(outputStream);
        TaskG solver = new TaskG();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskG {
        public void solve(int testNumber, FastScanner in, FastPrinter out) {
            int n = in.nextInt();
            int q = in.nextInt();
            int[] p = new int[n];
            for (int i = 0; i < n; i++) {
                p[i] = in.nextInt();
            }
            TaskG.Query[] qs = new TaskG.Query[q];
            int[] leftQ = in.readIntArray(q);
            int[] rightQ = in.readIntArray(q);
            for (int i = 0; i < q; i++) {
                qs[i] = new TaskG.Query(leftQ[i] - 1, rightQ[i] - 1);
            }
            solve(p, qs);
            ArrayUtils.reverse(p);
            for (int i = 0; i < q; i++) {
                int v = qs[i].left;
                qs[i].left = n - qs[i].right - 1;
                qs[i].right = n - v - 1;
            }
            solve(p, qs);
            long[] ans = new long[qs.length];
            for (int i = 0; i < qs.length; i++) {
                TaskG.Query e = qs[i];
                ans[i] = e.ans + e.right - e.left + 1;
            }
            out.printArray(ans);
        }

        static void solve(int[] p, TaskG.Query[] qs) {
            int n = p.length;
            int[] stack = new int[n];
            int sn = 0;
            int[] left = new int[n];
            for (int i = 0; i < n; i++) {
                while (sn > 0 && p[stack[sn - 1]] < p[i]) --sn;
                left[i] = sn > 0 ? stack[sn - 1] : -1;
                stack[sn++] = i;
            }
            List<TaskG.Query>[] queries = new List[n];
            List<Integer>[] opens = new List[n];
            for (int i = 0; i < n; i++) opens[i] = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                if (left[i] >= 0) opens[left[i]].add(i);
            }
            for (int i = 0; i < n; i++) queries[i] = new ArrayList<>();
            for (TaskG.Query e : qs) queries[e.left].add(e);
            FenwickLong f1 = new FenwickLong(n);
            Fenwick f1Count = new Fenwick(n);
            for (int i = n - 1; i >= 0; i--) {
                f1.add(i, i);
                f1Count.add(i, 1);
                for (int j : opens[i]) {
                    f1.add(j, -j);
                    f1Count.add(j, -1);
                    f1.add(j, j - left[j] - 1);
                }
                for (TaskG.Query e : queries[i]) {
                    e.ans += f1.getSum(e.left, e.right + 1) - (long) e.left * f1Count.getSum(e.left, e.right + 1);
                }
            }
        }

        static class Query {
            int left;
            int right;
            long ans;

            public Query(int left, int right) {
                this.left = left;
                this.right = right;
            }

        }

    }

    static class FastScanner extends BufferedReader {
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

    static class FastPrinter extends PrintWriter {
        public FastPrinter(OutputStream out) {
            super(out);
        }

        public FastPrinter(Writer out) {
            super(out);
        }

        public void printArray(long[] a) {
            for (int i = 0; i < a.length; i++) {
                if (i > 0) {
                    print(' ');
                }
                print(a[i]);
            }
            println();
        }

    }

    static class Fenwick {
        int[] a;

        public Fenwick(int n) {
            a = new int[n];
        }

        public void add(int x, int y) {
            for (int i = x; i < a.length; i |= i + 1) {
                a[i] += y;
            }
        }

        public int getSum(int x) {
            if (x >= a.length) x = a.length - 1;
            int ret = 0;
            for (int i = x; i >= 0; i = (i & (i + 1)) - 1) {
                ret += a[i];
            }
            return ret;
        }

        public int getSum(int l, int r) {
            return getSum(r - 1) - getSum(l - 1);
        }

    }

    static class ArrayUtils {
        public static void reverse(int[] c, int start, int end) {
            for (int i = start, j = end - 1; i < j; i++, j--) {
                int t = c[i];
                c[i] = c[j];
                c[j] = t;
            }
        }

        public static void reverse(int[] c) {
            reverse(c, 0, c.length);
        }

    }

    static class FenwickLong {
        long[] a;

        public FenwickLong(int n) {
            a = new long[n];
        }

        public void add(int x, long y) {
            for (int i = x; i < a.length; i |= i + 1) {
                a[i] += y;
            }
        }

        public long getSum(int x) {
            if (x >= a.length) x = a.length - 1;
            long ret = 0;
            for (int i = x; i >= 0; i = (i & (i + 1)) - 1) {
                ret += a[i];
            }
            return ret;
        }

        public long getSum(int l, int r) {
            return getSum(r - 1) - getSum(l - 1);
        }

    }
}