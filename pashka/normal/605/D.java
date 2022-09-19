import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Random;
import java.util.StringTokenizer;

/**
 * @author Pavel Mavrin
 */
public class D {

    private int n;
    private int[] x1, y1, x2, y2;
    private int[] p;

    private void solve() throws IOException {
        n = nextInt();
        n++;
        x1 = new int[n];
        y1 = new int[n + 1];
        y1[n] = Integer.MAX_VALUE;
        x2 = new int[n];
        y2 = new int[n];
        for (int i = 0; i < n - 1; i++) {
            x1[i] = nextInt();
            y1[i] = nextInt();
            x2[i] = nextInt();
            y2[i] = nextInt();
        }
        p = new int[n];
        for (int i = 0; i < n; i++) {
            p[i] = i;
        }
        sort(0, n - 1);
        int[] pr = new int[n];
        for (int i = 0; i < n; i++) {
            pr[p[i]] = i;
        }
        SegmentTree segmentTree = new SegmentTree(n);
        for (int i = 0; i < n; i++) {
            segmentTree.set(i, p[i]);
        }
//        for (int ii = 0; ii < n; ii++) {
//            System.out.print(segmentTree.min(ii, ii + 1) + " ");
//        }
//        System.out.println();
        segmentTree.set(pr[n - 1], n);
//        for (int ii = 0; ii < n; ii++) {
//            System.out.print(segmentTree.min(ii, ii + 1) + " ");
//        }
//        System.out.println();
        int[] q = new int[n];
        q[0] = n - 1;
        int[] d = new int[n];
        Arrays.fill(d, -1);
        d[n - 1] = 0;
        int h = 0;
        int t = 1;
        int[] pp = new int[n];
        while (t > h) {
            int i = q[h++];
//            System.out.println(Arrays.toString(q));
//            System.out.println(i);
            int x = x2[i];
            int y = y2[i];
            int l = -1;
            int r = n;
            while (r > l + 1) {
                int m = (l + r) >> 1;
                if (x1[p[m]] <= x) {
                    l = m;
                } else {
                    r = m;
                }
            }
//            System.out.println(Arrays.toString(p) + " " + r);
            while (true) {
                int j = segmentTree.min(0, r);
//                System.out.println(" " + j);
                if (y1[j] > y) {
                    break;
                }
//                System.out.println(j + " " + y1[j] + " " + y);
                segmentTree.set(pr[j], n);
//                for (int ii = 0; ii < n; ii++) {
//                    System.out.print(segmentTree.min(ii, ii + 1) + " ");
//                }
//                System.out.println();
                d[j] = d[i] + 1;
                pp[j] = i;
                q[t++] = j;
            }
        }
//        System.out.println(Arrays.toString(d));
        out.println(d[n - 2]);
        int j = n - 2;
        int[] res = new int[n];
        for (int i = d[n - 2] - 1; i >= 0; i--) {
            res[i] = j;
            j = pp[j];
        }
        for (int i = 0; i < d[n - 2]; i++) {
            out.print((res[i] + 1) + " ");
        }
        out.println();
    }

    Random random = new Random();

    private void sort(int l, int r) {
        int i = l;
        int j = r;
        int x = x1[p[l + random.nextInt(r - l + 1)]];
        while (i <= j) {
            while (x1[p[i]] < x) i++;
            while (x1[p[j]] > x) j--;
            if (i <= j) {
                int t = p[i]; p[i] = p[j]; p[j] = t;
                i++; j--;
            }
        }
        if (i < r) sort(i, r);
        if (l < j) sort(l, j);
    }

    class SegmentTree {

        private int[] a;
        private int size;

        public SegmentTree(int size) {
            this.size = size;
            a = new int[4 * size];
        }

        private void set(int i, int v) {
//            System.out.println(i + " " + v);
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
                int ll = y1[a[n * 2 + 1]];
                int rr = y1[a[n * 2 + 2]];
                if (ll < rr) {
                    a[n] = a[n * 2 + 1];
                } else {
                    a[n] = a[n * 2 + 2];
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
                return D.this.n;
            } else {
                int m = (ll + rr) / 2;
                int a1 = min(n * 2 + 1, ll, m, l, r);
                int a2 = min(n * 2 + 2, m, rr, l, r);
                int z1 = y1[a1];
                int z2 = y1[a2];
                if (z1 < z2) {
                    return a1;
                } else {
                    return a2;
                }
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
        new D().run();
    }

    private void run() throws IOException {
        solve();
        out.close();
    }

}