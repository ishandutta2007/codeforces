import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.StringTokenizer;

/**
 * @author Pavel Mavrin
 */
public class C {

    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st;
    PrintStream out = System.out;
    private int left;
    private int right;
    private boolean reversed;
    private int[] a;
    private int size;

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
        new C().solve();
    }

    private void solve() throws IOException {
        int n = nextInt();
        left = 0;
        right = n;
        reversed = false;
        size = 1;
        while (size < n) size *= 2;
        a = new int[size * 2];
        for (int i = 0; i < n; i++) {
            add(i, 1);
        }
        int q = nextInt();
        for (int i = 0; i < q; i++) {
            int c = nextInt();
            if (c == 1) {
                int p = nextInt();
                fold(p);
//                for (int j = left; j < right; j++) {
//                    System.out.print(get(j) + " ");
//                }
//                System.out.println(sum(0, right - left));
            } else {
                int l = nextInt();
                int r = nextInt();
                out.println(sum(l, r));
            }
        }
    }

    private void fold(int p) {
        if (reversed) {
            p = right - left - p;
        }
        if (p <= (right - left) / 2) {
            for (int i = 0; i < p; i++) {
                add(left + p + p - i - 1, get(left + i));
            }
            left += p;
            reversed = false;
        } else {
            for (int i = 0; i < right - left - p; i++) {
                add(left + p - i - 1, get(left + p + i));
            }
            right = left + p;
            reversed = true;
        }

    }

    private void add(int i, int v) {
        add(0, 0, size, i, v);
    }

    private void add(int n, int l, int r, int i, int v) {
        if (r == l + 1) {
            a[n] += v;
        } else {
            int m = (l + r) / 2;
            if (i < m) {
                add(n * 2 + 1, l, m, i, v);
            } else {
                add(n * 2 + 2, m, r, i, v);
            }
            a[n] = a[n * 2 + 1] + a[n * 2 + 2];
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

    private int sum(int l, int r) {
        if (reversed) {
            int ll = right - left - r;
            int rr = right - left - l;
            l = ll;
            r = rr;
        }
        return sum(0, 0, size, left + l, left + r);
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