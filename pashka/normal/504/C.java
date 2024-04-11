import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

/**
 * @author Pavel Mavrin
 */
public class C {

    private void solve() throws IOException {
        int n = nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = nextInt() - 1;
        }
        int x = 0;
        while (x < n && a[x] == a[n - 1 - x]) x++;
        if (x == n) {
            out.print(1l * n * (n + 1) / 2);
            return;
        }
        int[] d = new int[n];
        for (int i = x; i < n - x; i++) {
            d[a[i]]++;
        }
        int q = 0;
        int w = 0;
        for (int i = 0; i < n; i++) {
            if (d[i] % 2 == 1) {
                w = i;
                q++;
            }
        }
        if (q > 1) {
            out.println(0);
            return;
        }

        int[] dd = d.clone();
        calc(a, n, d, x, w);
        int l1 = l;
        int r1 = r;
        int[] aa = new int[n];
        for (int i = 0; i < n; i++) {
            aa[i] = a[n - 1 - i];
        }
        calc(aa, n, dd, x, w);
        int l2 = n - r;
        int r2 = n - l;

        l = Math.min(l1, l2);
        r = Math.max(r1, r2);

//        System.out.println(l1 + " " + r1);
//        System.out.println(l2 + " " + r2);
        long res = (1l * (l1 + 1) * (n - r1 + 1)) + (1l * (l2 + 1) * (n - r2 + 1)) - (1l * (l + 1) * (n - r + 1));
        out.println(res);

    }

    private void calc(int[] a, int n, int[] d, int x, int w) {
        l = x;
        r = n - x;
        while (d[a[l]] >= 2) {
            d[a[l]] -= 2;
            l++;
        }
        if (n % 2 == 1) {
            if (l == n / 2) {
                if (a[n / 2] == w) {
                    l++;
                    while (a[l] == a[n - 1 - l]) l++;
                }
            }
        } else {
            if (l == n / 2) {
                while (a[l] == a[n - 1 - l]) l++;
            }
        }
    }

    int l, r;


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
        new C().run();
    }

    private void run() throws IOException {
        solve();
        out.close();
    }

}