import java.io.*;
import java.util.*;

public class CF2 {
    FastScanner in;
    PrintWriter out;

    class SegmentTree2 {
        long[] a;
        int n;

        SegmentTree2(int n) {
            this.n = n;
            a = new long[n];
        }

        void add(int v, int l, int r, int needL, int needR, long aa) {
            if (needL > needR)
                return;
            for (int i = needL; i <= needR; i++)
                a[i] += aa;
        }

        int getLastLessOrEqK(int v, int l, int r, int fromL, int toR, int k) {
            for (int i = toR; i >= fromL; i--)
                if (a[i] <= k)
                    return i;
            return -1;
        }
    }

    class SegmentTree {
        long[] add;
        long[] min;

        int n;

        SegmentTree(int n) {
            this.n = n;
            add = new long[4 * n];
            min = new long[4 * n];
            Arrays.fill(min, Long.MAX_VALUE / 3);
            build(0, 0, n - 1);
        }

        void build(int v, int l, int r) {
            if (l == r) {
                add[v] = 0;
                min[v] = add[v];
            } else {
                int m = (l + r) >>> 1;
                build(v * 2 + 1, l, m);
                build(v * 2 + 2, m + 1, r);
                updMin(v);
            }
        }

        void relax(int v, int l, int r) {
            if (l != r) {
                add[v * 2 + 1] += add[v];
                add[v * 2 + 2] += add[v];
                add[v] = 0;
                updMin(v);
            }
        }

        void updMin(int v) {
            min[v] = Math.min(min[v * 2 + 1] + add[v * 2 + 1], min[v * 2 + 2]
                    + add[v * 2 + 2]);
        }

        void add(int v, int l, int r, int needL, int needR, long a) {
            if (needL > needR)
                return;
            if (l == needL && r == needR) {
                add[v] += a;
            } else {
                relax(v, l, r);
                int m = (l + r) >>> 1;
                add(v * 2 + 1, l, m, needL, Math.min(needR, m), a);
                add(v * 2 + 2, m + 1, r, Math.max(needL, m + 1), needR, a);
                updMin(v);
            }
        }

        int getLastLessOrEqK(int v, int l, int r, int fromL, int toR, int k) {
            if (fromL > r)
                return -1;
            if (l > toR)
                return -1;
            if (min[v] + add[v] > k)
                return -1;
            if (l == r) {
                return l;
            } else {
                relax(v, l, r);
                int m = (l + r) >>> 1;
                int r1 = getLastLessOrEqK(v * 2 + 2, m + 1, r, fromL, toR, k);
                if (r1 != -1)
                    return r1;
                return getLastLessOrEqK(v * 2 + 1, l, m, fromL, toR, k);
            }

        }

    }

    class Segment {
        int from, to, val;

        Segment(int fr, int to, int val) {
            this.from = fr;
            this.to = to;
            this.val = val;
        }

        @Override
        public String toString() {
            return "Segment [from=" + from + ", to=" + to + ", val=" + val
                    + "]";
        }

    }

    void solve() {
        int n = in.nextInt();
        int k = in.nextInt();
        int d = in.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt() + (int) 1e9 + 123;
        }
        int bestLen = -1, bestFrom = -1;
        if (d == 0) {
            for (int i = 0; i < n;) {
                int j = i;
                while (j != n && a[j] == a[i])
                    j++;
                if (j - i > bestLen) {
                    bestLen = j - i;
                    bestFrom = i;
                }
                i = j;
            }
        } else {
            int[] rem = new int[n];
            for (int i = 0; i < n; i++)
                rem[i] = a[i] % d;
            for (int i = 0; i < n; i++) {
                a[i] /= d;
            }
            int[] sameRem = new int[n];
            for (int i = n - 1; i >= 0; i--) {
                sameRem[i] = i;
                if (i != n - 1 && rem[i] == rem[i + 1])
                    sameRem[i] = sameRem[i + 1];
            }
            HashMap<Integer, Integer> lastPos = new HashMap<>();
            for (int i = n - 1; i >= 0; i--) {
                Integer last = lastPos.get(a[i]);
                if (last != null) {
                    sameRem[i] = Math.min(sameRem[i], last - 1);
                }
                if (i != n - 1)
                    sameRem[i] = Math.min(sameRem[i], sameRem[i + 1]);
                lastPos.put(a[i], i);
            }
            ArrayList<Segment> max = new ArrayList<>();
            ArrayList<Segment> min = new ArrayList<>();
            SegmentTree st = new SegmentTree(n);
            for (int l = n - 1; l >= 0; l--) {
                st.add(0, 0, n - 1, l + 1, n - 1, -1);
                int cur = a[l];
                {
                    while (max.size() > 0 && max.get(max.size() - 1).val < cur) {
                        Segment s = max.get(max.size() - 1);
                        st.add(0, 0, n - 1, s.from, s.to, -s.val);
                        max.remove(max.size() - 1);
                    }
                    int too = n - 1;
                    if (max.size() > 0)
                        too = max.get(max.size() - 1).from - 1;
                    max.add(new Segment(l, too, cur));
                    st.add(0, 0, n - 1, l, too, cur);
                }
                {
                    while (min.size() > 0 && min.get(min.size() - 1).val > cur) {
                        Segment s = min.get(min.size() - 1);
                        st.add(0, 0, n - 1, s.from, s.to, s.val);
                        min.remove(min.size() - 1);
                    }
                    int too = n - 1;
                    if (min.size() > 0)
                        too = min.get(min.size() - 1).from - 1;
                    min.add(new Segment(l, too, cur));
                    st.add(0, 0, n - 1, l, too, -cur);
                }
                int pos = st.getLastLessOrEqK(0, 0, n - 1, l, sameRem[l], k);
                if (bestLen <= pos - l + 1) {
                    bestLen = pos - l + 1;
                    bestFrom = l;
                }
            }
        }
        out.println((bestFrom + 1) + " " + (bestFrom + bestLen));
    }

    void run() {
        try {
            in = new FastScanner(new File("test.in"));
            out = new PrintWriter(new File("test.out"));

            solve();

            out.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    void runIO() {

        in = new FastScanner(System.in);
        out = new PrintWriter(System.out);

        solve();

        out.close();
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(File f) {
            try {
                br = new BufferedReader(new FileReader(f));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        public FastScanner(InputStream f) {
            br = new BufferedReader(new InputStreamReader(f));
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                String s = null;
                try {
                    s = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (s == null)
                    return null;
                st = new StringTokenizer(s);
            }
            return st.nextToken();
        }

        boolean hasMoreTokens() {
            while (st == null || !st.hasMoreTokens()) {
                String s = null;
                try {
                    s = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (s == null)
                    return false;
                st = new StringTokenizer(s);
            }
            return true;
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }
    }

    public static void main(String[] args) {
        new CF2().runIO();
    }
}