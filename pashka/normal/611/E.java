import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

/**
 * @author Pavel Mavrin
 */
public class E {

    private void solve() throws IOException {
        int n = nextInt();
        int[] a = new int[3];
        for (int i = 0; i < 3; i++) {
            a[i] = nextInt();
        }
        int[] t = new int[n];
        for (int i = 0; i < n; i++) {
            t[i] = nextInt();
        }
        Arrays.sort(a);
        Arrays.sort(t);
        if (t[n - 1] > a[0] + a[1] + a[2]) {
            out.println(-1);
            return;
        }

        int res = 0;
        while (n > 0 && t[n - 1] > a[1] + a[2]) {
            res++;
            n--;
        }
        int x = 0;
        int y = 0;
        int z = 0;
        while (n > 0 && t[n - 1] > a[0] + a[2]) {
            res++;
            n--;
            x++;
        }
        while (n > 0 && t[n - 1] > Math.max(a[0] + a[1], a[2])) {
            res++;
            n--;
            y++;
        }
        if (a[0] + a[1] > a[2]) {
            while (n > 0 && t[n - 1] > a[2]) {
                res++;
                n--;
                z++;
            }
        }

        int l = -1;
        int r = n;
        while (r > l + 1) {
            int m = (l + r) / 2;
            int xx = x + m;
            int yy = y + m;
            int zz = z + m;
            int mm = m;
            boolean ok = true;
            int nn = n;
            while (nn > 0 && zz > 0 && t[nn - 1] <= a[2]) {
                nn--;
                zz--;
            }
            while (nn > 0 && xx > 0 && yy > 0 && mm > 0 && t[nn - 1] <= a[0] + a[1] && t[nn - 1] > a[1]) {
                nn--;
                xx--;
                yy--;
                mm--;
            }
            for (int i = 0; i < nn; i++) {
                if (xx > 0 && t[i] <= a[0]) {
                    xx--;
                } else if (yy > 0 && t[i] <= a[1]) {
                    yy--;
                } else {
                    ok = false;
                }
            }
            if (ok) {
                r = m;
            } else {
                l = m;
            }
        }
        out.println(res + r);
    }

//    private boolean can(int[] t, int[] a, int m) {
//        int n = t.length;
//        while (n > 0 && t[n - 1] > a[1] + a[2]) {
//            n--;
//            m--;
//        }
//        if (m < 0) return false;
//        int x = 0;
//        while (x < m && t[x] <= a[0]) {
//            x++;
//        }
//        int y = 0;
//        while (y < m && x + y < t.length && t[x + y] <= a[1]) {
//            y++;
//        }
//        int[] tt = new int[n - x - y];
//        System.arraycopy(t, x + y, tt, 0, n - x - y);
//        return can(tt, a, m - x, m - y, m);
//    }
//
//    private boolean can(int[] t, int[] a, int x, int y, int z) {
//        return false;
//    }


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
        new E().run();
    }

    private void run() throws IOException {
        solve();
        out.close();
    }

}