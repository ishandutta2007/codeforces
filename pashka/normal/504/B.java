import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

/**
 * @author Pavel Mavrin
 */
public class B {

    private void solve() throws IOException {
        int n = nextInt();
        int[] a = getP(n);
        int[] b = getP(n);
        int[] c = new int[n];
        int x = 0;
        for (int i = 0; i < n; i++) {
            c[i] = a[i] + b[i] + x;
            x = c[i] / (i + 1);
            c[i] = c[i] % (i + 1);
        }
//        System.out.println(Arrays.toString(a));
//        System.out.println(Arrays.toString(b));
//        System.out.println(Arrays.toString(c));
        int[] res = new int[n];
        SegmentTree st = new SegmentTree(n);
        for (int i = 0; i < n; i++) {
            st.set(i, 1);
        }
        for (int i = 0; i < n; i++) {
            res[i] = st.get(c[n - 1 - i]);
            st.set(res[i], 0);
        }
        for (int i = 0; i < n; i++) {
            out.print(res[i] + " ");
        }
        out.println();

    }

    private int[] getP(int n) throws IOException {
        int[] p = new int[n];
        for (int i = 0; i < n; i++) {
            p[i] = nextInt();
        }
        int[] res = new int[n];
        SegmentTree st = new SegmentTree(n);
        for (int i = 0; i < n; i++) {
            int x = p[n - 1 - i];
            int s = st.sum(0, x);
            res[i] = s;
            st.set(x, 1);
        }
        return res;
    }

    class SegmentTree {

        private int[] a;
        private int size;

        public SegmentTree(int size) {
            this.size = size;
            a = new int[4 * size];
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
                a[n] = a[n * 2 + 1] + a[n * 2 + 2];
            }
        }

        private int get(int i) {
            return get(0, 0, size, i);
        }

        private int get(int n, int l, int r, int i) {
            if (r == l + 1) {
                return l;
            } else {
                int m = (l + r) / 2;
                if (a[n * 2 + 1] > i) {
                    return get(n * 2 + 1, l, m, i);
                } else {
                    return get(n * 2 + 2, m, r, i - a[n * 2 + 1]);
                }
            }
        }

        private int sum(int l, int r) {
            return sum(0, 0, size, l, r);
        }

        private int sum(int n, int ll, int rr, int l, int r) {
            if (ll >= l && rr <= r) {
                return a[n];
            } else if (ll >= r || l >= rr) {
                return 0;
            } else {
                int m = (ll + rr) / 2;
                return sum(n * 2 + 1, ll, m, l, r) + sum(n * 2 + 2, m, rr, l, r);
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