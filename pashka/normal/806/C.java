import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

/**
 * @author Pavel Mavrin
 */
public class C {

    public static final int N = 50;

    private void solve() throws IOException {
        int n = nextInt();
        long[] a = new long[n];
        for (int i = 0; i < n; i++) {
            a[i] = nextLong();
        }
        int[] p = new int[N];
        int[] e = new int[N];
        int j = 0;
        for (int i = 0; i < N; i++) {
            while (j < n && a[j] < (1L << i)) {
                e[i]++;
                j++;
            }
            while (j < n && a[j] == (1L << i)) {
                p[i]++;
                j++;
            }
            if (i > 0 && p[i] > p[i - 1]) {
                e[i + 1] += (p[i] - p[i - 1]);
                p[i] = p[i - 1];
            }
        }

        int l = 0;
        int r = p[0] + 1;
        int[] pp = p.clone();
        int[] ee = e.clone();
        while (r > l + 1) {
            int k = (l + r) / 2;
            System.arraycopy(p, 0, pp, 0, p.length);
            System.arraycopy(e, 0, ee, 0, e.length);
            ee[1] += pp[0] - k;
            pp[0] = k;
            for (int i = 0; i < N; i++) {
                if (i > 0 && pp[i] > pp[i - 1]) {
                    ee[i + 1] += (pp[i] - pp[i - 1]);
                    pp[i] = pp[i - 1];
                }
            }
            if (can(pp, ee)) {
                r = k;
            } else {
                l = k;
            }
        }
        if (r == p[0] + 1) {
            out.println(-1);
        } else {
            for (int i = r; i <= p[0]; i++) {
                out.println(i);
            }
        }
    }

    private boolean can(int[] p, int[] e) {
//        System.out.println(Arrays.toString(p) + " " + Arrays.toString(e));
        int s = 0;
        for (int i = N - 2; i >= 0; i--) {
            s += (p[i] - p[i + 1]);
            if (s < e[i + 1]) {
                return false;
            }
            s -= e[i + 1];
        }
        return true;
    }

    // ------------------

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

    long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    public static void main(String[] args) throws IOException {
        new C().run();
    }

    private void run() throws IOException {
        solve();
        out.close();
    }

}