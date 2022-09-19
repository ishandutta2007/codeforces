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
public class B {

    private void solve() throws IOException {
        int n = nextInt();
        long A = Long.parseLong(next());
        long cf = Long.parseLong(next());
        long cm = Long.parseLong(next());
        long m = Long.parseLong(next());
        long[] a = new long[n];
        for (int i = 0; i < n; i++) {
            a[i] = Long.parseLong(next());
        }

        this.x = a;
        p = new int[n];
        for (int i = 0; i < n; i++) {
            p[i] = i;
        }
        sort(0, n - 1);
//        Arrays.sort(a);

        long s1 = 0;
        for (int i = 0; i < n; i++) {
            s1 += (A - a[i]);
        }

        long res = 0;

        int na = 0;
        int nb = 0;
        long nr = 0;

        if (s1 <= m) {
            res = n * cf + A * cm;
            na = n;
        } else {
            int j = 0;
            long s2 = 0;
            for (int i = 0; i < n; i++) {
                s1 -= (A - a[p[i]]);
                if (s1 <= m) {
                    while (j <= i && (a[p[j]] * j - s2) <= m - s1) {
                        s2 += a[p[j]];
                        j++;
                    }
                    long s = (s2 + m - s1) / j;
                    long r = s * cm + (n - i - 1) * cf;
                    if (r > res) {
                        res = r;
                        na = n - i - 1;
                        nb = j;
                        nr = s;
                    }
                }
            }
        }
        out.println(res);
        for (int i = 0; i < na; i++) {
            a[p[n - 1 - i]] = A;
        }
        for (int i = 0; i < nb; i++) {
            a[p[i]] = nr;
        }
        for (int i = 0; i < n; i++) {
            out.print(a[i] + " ");
        }
        out.println();
    }


    long[] x;
    int[] p;

    Random random = new Random();

    private void sort(int l, int r) {
        int i = l;
        int j = r;
        long xx = x[p[l + random.nextInt(r - l + 1)]];
        while (i <= j) {
            while (x[p[i]] < xx) i++;
            while (x[p[j]] > xx) j--;
            if (i <= j) {
                int t = p[i]; p[i] = p[j]; p[j] = t;
                i++; j--;
            }
        }
        if (i < r) sort(i, r);
        if (l < j) sort(l, j);
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