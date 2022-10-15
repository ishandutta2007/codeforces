import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.OutputStream;
import java.util.Arrays;
import java.io.IOException;
import java.util.InputMismatchException;
import java.util.Random;
import java.io.InputStreamReader;
import java.io.Writer;
import java.io.BufferedReader;
import java.util.Comparator;
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
        TaskC2 solver = new TaskC2();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC2 {
        public void solve(int testNumber, FastScanner in, FastPrinter out) {
            int n = in.nextInt();
            int r = in.nextInt();
            TaskC2.Event[] events = new TaskC2.Event[2 * n];
            int[] ys = new int[2 * n];
            for (int i = 0; i < n; i++) {
                int x0 = in.nextInt();
                int y0 = in.nextInt();
                int x = x0 + y0;
                int y = x0 - y0;
                ys[2 * i] = y;
                ys[2 * i + 1] = y + 2 * r;
                events[2 * i] = new TaskC2.Event(x, y, y + 2 * r, true);
                events[2 * i + 1] = new TaskC2.Event(x + 2 * r, y, y + 2 * r, false);
            }
            ys = ArrayUtils.sortAndUnique(ys);
            Arrays.sort(events, new Comparator<TaskC2.Event>() {

                public int compare(TaskC2.Event o1, TaskC2.Event o2) {
                    int c = Integer.compare(o1.x, o2.x);
                    if (c != 0) return c;
                    if (o1.start == o2.start) return 0;
                    if (o1.start) return -1;
                    return 1;
                }
            });
            MultiSegmentTree tree = new MultiSegmentTree(ys.length);
            int ans = 0;
            for (TaskC2.Event e : events) {
                int from = Arrays.binarySearch(ys, e.y1);
                int to = Arrays.binarySearch(ys, e.y2);
                if (e.start) {
                    tree.add(from, to + 1, 1);
                    ans = (int) Math.max(ans, tree.getMax(0, ys.length));
                } else {
                    tree.add(from, to + 1, -1);
                }
            }
            out.println(ans);
        }

        static class Event {
            int x;
            int y1;
            int y2;
            boolean start;

            public Event(int x, int y1, int y2, boolean start) {
                this.x = x;
                this.y1 = y1;
                this.y2 = y2;
                this.start = start;
            }

        }

    }

    static class FastPrinter extends PrintWriter {
        public FastPrinter(OutputStream out) {
            super(out);
        }

        public FastPrinter(Writer out) {
            super(out);
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

    }

    static class ArrayUtils {
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

    static class MultiSegmentTree {
        private long[] min;
        private long[] max;
        private long[] sum;
        private long[] add;
        private long[] set;
        private boolean[] toSet;
        private int[] count;
        final int n;

        public MultiSegmentTree(int n) {
            this.n = Integer.highestOneBit(n) << 1;
            min = new long[this.n << 1];
            max = new long[this.n << 1];
            sum = new long[this.n << 1];
            add = new long[this.n << 1];
            set = new long[this.n << 1];
            count = new int[this.n << 1];
            toSet = new boolean[this.n << 1];
            count(0, 0, this.n);
        }

        private int count(int node, int l, int r) {
            if (l == r - 1) {
                count[node] = 1;
                return 1;
            }
            int m = (l + r) >> 1;
            return count[node] = count((node << 1) | 1, l, m)
                    + count((node << 1) + 2, m, r);
        }

        private void add(int node, long x) {
            if (toSet[node]) {
                set[node] += x;
            } else {
                add[node] += x;
            }
        }

        private void set(int node, long x) {
            add[node] = 0;
            set[node] = x;
            toSet[node] = true;
        }

        private void relax(int node) {
            if (!toSet[node] && add[node] == 0) {
                return;
            }
            min[node] = getMin(node);
            max[node] = getMax(node);
            sum[node] = getSum(node);
            if (toSet[node]) {
                set((node << 1) | 1, set[node]);
                set((node << 1) + 2, set[node]);
                toSet[node] = false;
            } else {
                add((node << 1) | 1, add[node]);
                add((node << 1) + 2, add[node]);
                add[node] = 0;
            }
        }

        private long getSum(int node) {
            return toSet[node] ? set[node] * count(node) : sum[node]
                    + add[node] * count(node);
        }

        private long count(int node) {
            return count[node];
        }

        private long getMax(int node) {
            return toSet[node] ? set[node] : max[node] + add[node];
        }

        private long getMin(int node) {
            return toSet[node] ? set[node] : min[node] + add[node];
        }

        private void add(int node, int l, int r, int left, int right, long x) {
            if (right <= l || r <= left) {
                return;
            }
            if (left <= l && r <= right) {
                add(node, x);
                return;
            }
            relax(node);
            int m = (l + r) >> 1;
            add((node << 1) | 1, l, m, left, right, x);
            add((node << 1) + 2, m, r, left, right, x);
            min[node] = Math.min(getMin((node << 1) | 1),
                    getMin((node << 1) + 2));
            max[node] = Math.max(getMax((node << 1) | 1),
                    getMax((node << 1) + 2));
            sum[node] = getSum((node << 1) | 1) + getSum((node << 1) + 2);
        }

        private long getMax(int node, int l, int r, int left, int right) {
            if (right <= l || r <= left) {
                return Long.MIN_VALUE;
            }
            if (left <= l && r <= right) {
                return getMax(node);
            }
            relax(node);
            int m = (l + r) >> 1;
            return Math.max(getMax((node << 1) | 1, l, m, left, right),
                    getMax((node << 1) + 2, m, r, left, right));
        }

        public void add(int l, int r, long x) {
            if (l >= r) {
                return;
            }
            add(0, 0, n, l, r, x);
        }

        public long getMax(int l, int r) {
            if (l >= r) {
                return Long.MAX_VALUE;
            }
            return getMax(0, 0, n, l, r);
        }

    }
}