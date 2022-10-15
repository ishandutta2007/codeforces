import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.OutputStream;
import java.io.IOException;
import java.util.InputMismatchException;
import java.io.InputStreamReader;
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
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        public void solve(int testNumber, FastScanner in, FastPrinter out) {
            int m = in.nextInt();
            MultiSegmentTree t = new MultiSegmentTree(m);
            int[] value = new int[m];
            for (int i = 0; i < m; i++) {
                int p = m - in.nextInt();
                int type = in.nextInt();
                if (type == 0) {
                    t.add(p, m, -1);
                } else {
                    t.add(p, m, 1);
                    value[p] = in.nextInt();
                }
                int l = -1;
                int r = m;
                while (l < r - 1) {
                    int mid = (l + r) >> 1;
                    if (t.getMax(0, mid + 1) > 0) {
                        r = mid;
                    } else {
                        l = mid;
                    }
                }
                if (r == m) {
                    out.println(-1);
                } else {
                    out.println(value[r]);
                }
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
}