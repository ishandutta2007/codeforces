import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

/**
 * @author Pavel Mavrin
 */
public class B {

    private void solve() throws IOException {
        int n = nextInt();
        int s = nextInt();
        int l = nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = nextInt();
        }
        int size = 1;
        while (size < n + 1) size *= 2;
        SegmentTree mins = new SegmentTree(size);
        SegmentTree maxs = new SegmentTree(size);
        for (int i = 0; i < n; i++) {
            mins.set(i, a[i]);
            maxs.set(i, -a[i]);
        }
        SegmentTree d = new SegmentTree(size);
        for (int i = 0; i < n; i++) {
            int rr = i - l + 1;
            int l1 = -1;
            int r1 = i;
            while (r1 > l1 + 1) {
                int m = (l1 + r1) / 2;
                int mx = -maxs.min(m, i + 1);
                int mn = mins.min(m, i + 1);
                int dd = mx - mn;
                if (dd > s) {
                    l1 = m;
                } else {
                    r1 = m;
                }
            }
            int ll = r1;
            int zz = Integer.MAX_VALUE;
            if (rr >= ll) {
                int z = d.min(ll, rr + 1);
                if (z < Integer.MAX_VALUE) {
                    zz = z + 1;
                }
            }
            d.set(i + 1, zz);
//            System.out.println(i + " " + ll + " " + rr + " " + zz);
        }
        int res = d.min(n, n + 1);
        if (res == Integer.MAX_VALUE) {
            out.println(-1);
        } else {
            out.println(res);
        }
    }


    class SegmentTree {

        private int[] a;
        private int size;

        public SegmentTree(int size) {
            this.size = size;
            a = new int[2 * size];
        }

        private void set(int i, int v) {
            set(0, 0, size, i, v);
        }

        private void set(int n, int l, int r, int i, int v) {
            if (r == l + 1) {
                a[n] = v;
            } else {
                int m = (l + r) / 2;
                if (i < m) {
                    set(n * 2 + 1, l, m, i, v);
                } else {
                    set(n * 2 + 2, m, r, i, v);
                }
                a[n] = Math.min(a[n * 2 + 1], a[n * 2 + 2]);
            }
        }

        private int get(int i) {
            return get(0, 0, size, i);
        }

        private int get(int n, int l, int r, int i) {
            if (r == l + 1) {
                return a[n];
            } else {
                int m = (l + r) / 2;
                if (i < m) {
                    return get(n * 2 + 1, l, m, i);
                } else {
                    return get(n * 2 + 2, m, r, i);
                }
            }
        }

        private int min(int l, int r) {
            return min(0, 0, size, l, r);
        }

        private int min(int n, int ll, int rr, int l, int r) {
            if (ll >= l && rr <= r) {
                return a[n];
            } else if (ll >= r || l >= rr) {
                return Integer.MAX_VALUE;
            } else {
                int m = (ll + rr) / 2;
                return Math.min(min(n * 2 + 1, ll, m, l, r), min(n * 2 + 2, m, rr, l, r));
            }
        }
    }

    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st;
    PrintWriter out = new PrintWriter(System.out);

    String next() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return st.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    public static void main(String[] args) throws IOException {
        new B().run();
    }

    private void run() throws IOException {
        solve();
        out.close();
    }

}