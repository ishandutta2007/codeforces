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
        TaskF solver = new TaskF();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskF {
        public void solve(int testNumber, FastScanner in, FastPrinter out) {
//        Random rng = new Random(12323L);
//        for (int tt = 0; tt < 7; tt++) {
//            int n = rng.nextInt(2) + 77;
//            HeroesSmart a = new HeroesSmart(n);
//            HeroesStupid b = new HeroesStupid(n);
//            for (int it = 0; it < 10000; it++) {
//                if (rng.nextBoolean()) {
//                    int add = rng.nextInt(10) + 1;
//                    int l = rng.nextInt(n);
//                    int r = rng.nextInt(n - l) + l + 1;
//                    a.add(l, r, add);
//                    b.add(l, r, add);
//                    System.out.println(l + " " + r + " " + add);
//                } else {
//                    int l = rng.nextInt(n - 1) / 2 * 2 + 1;
//                    int r = rng.nextInt(n - l) + l + 1;
//                    boolean ans1 = a.canBeat(l, r);
//                    boolean ans2 = b.canBeat(l, r);
//                    if (ans1 != ans2) {
//                        System.out.println(l + " " + r);
//                        throw new AssertionError();
//                    }
//                }
//            }
//        }
            int n = in.nextInt();
//        HeroesStupid real = new HeroesStupid(n);
//        HeroesStupid plusOne = new HeroesStupid(n + 1);
            TaskF.HeroesSmart real = new TaskF.HeroesSmart(n);
            TaskF.HeroesSmart plusOne = new TaskF.HeroesSmart(n + 1);
            for (int i = 0; i < n; i++) {
                int x = in.nextInt();
                real.add(i, i + 1, x);
                plusOne.add(i + 1, i + 2, x);
            }
            int m = in.nextInt();
            for (int i = 0; i < m; i++) {
                int op = in.nextInt();
                if (op == 2) {
                    int l = in.nextInt();
                    int r = in.nextInt() + 1;
                    boolean ans;
                    if ((l & 1) == 1) {
                        ans = real.canBeat(l, r);
                    } else {
                        ans = plusOne.canBeat(l + 1, r + 1);
                    }
                    out.println(ans ? 1 : 0);
                } else {
                    int l = in.nextInt();
                    int r = in.nextInt() + 1;
                    int k = in.nextInt();
                    real.add(l, r, k);
                    plusOne.add(l + 1, r + 1, k);
                }
            }
        }

        static class HeroesSmart {
            FenwickRev all;
            TaskF.MultiSegmentTree even;
            TaskF.MultiSegmentTree odd;
            int pairs;

            HeroesSmart(int n) {
                all = new FenwickRev(n);
                pairs = (n + 1) / 2 + 1;
                even = new TaskF.MultiSegmentTree(pairs);
                odd = new TaskF.MultiSegmentTree(pairs);
            }

            void add(int l, int r, int k) {
                all.add(l, r, k);
                if ((l & 1) == 1) {
                    odd.add(l / 2, pairs, k);
                } else {
                    even.add(l / 2, pairs, k);
                }
                if ((r & 1) == 1) {
                    odd.add(r / 2, pairs, -k);
                } else {
                    even.add(r / 2, pairs, -k);
                }
            }

            boolean canBeat(int l, int r) { // [l, r)
                if ((l & 1) == 1) {
                    long evenMin = even.getMin((l + 1) / 2, (r - 1) / 2 + 1);
                    long sumEvenFirst = l == 0 ? 0 : even.getMin((l - 1) / 2, (l - 1) / 2 + 1);
                    evenMin -= sumEvenFirst;
                    long sumFirst = odd.getMin(l / 2, l / 2 + 1);
                    int valFirst = all.getElement(l);
                    long oddMin = odd.getMin(l / 2, (r - 2) / 2 + 1) - sumFirst + valFirst - 1;
                    if (evenMin < 0 || oddMin < 0) {
                        return false;
                    }
                    if ((r & 1) == 0) {
                        return odd.getMin((r - 2) / 2, (r - 2) / 2 + 1) - sumFirst + valFirst - 1 == 0;
                    } else {
                        return even.getMin((r - 1) / 2, (r - 1) / 2 + 1) - sumEvenFirst == 0;
                    }
                }
                throw new AssertionError();
            }

        }

        static class MultiSegmentTree {
            private long[] min;
            private long[] add;
            final int n;

            public MultiSegmentTree(int n) {
                this.n = Integer.highestOneBit(n) << 1;
                min = new long[this.n << 1];
                add = new long[this.n << 1];
            }

            private void add(int node, long x) {
                add[node] += x;
            }

            private void relax(int node) {
                if (add[node] == 0) {
                    return;
                }
                min[node] = getMin(node);
                add((node << 1) | 1, add[node]);
                add((node << 1) + 2, add[node]);
                add[node] = 0;
            }

            private long getMin(int node) {
                return min[node] + add[node];
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
            }

            private long getMin(int node, int l, int r, int left, int right) {
                if (right <= l || r <= left) {
                    return Long.MAX_VALUE;
                }
                if (left <= l && r <= right) {
                    return getMin(node);
                }
                relax(node);
                int m = (l + r) >> 1;
                return Math.min(getMin((node << 1) | 1, l, m, left, right),
                        getMin((node << 1) + 2, m, r, left, right));
            }

            public void add(int l, int r, long x) {
                if (l >= r) {
                    return;
                }
                add(0, 0, n, l, r, x);
            }

            public long getMin(int l, int r) {
                if (l >= r) {
                    return Long.MAX_VALUE;
                }
                return getMin(0, 0, n, l, r);
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

    }

    static class FenwickRev {
        int[] a;

        public FenwickRev(int n) {
            a = new int[n];
        }

        public void add(int x, int y) {
            for (int i = x; i >= 0; i = (i & (i + 1)) - 1) {
                a[i] += y;
            }
        }

        public int getElement(int x) {
            int ret = 0;
            for (int i = x; i < a.length; i |= i + 1) {
                ret += a[i];
            }
            return ret;
        }

        public void add(int left, int right, int y) {
            add(left - 1, -y);
            add(right - 1, y);
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
}