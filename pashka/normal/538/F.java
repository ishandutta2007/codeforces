import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

/**
 * @author Pavel Mavrin
 */
public class F {

    private void solve() throws IOException {
        int n = nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = nextInt();
        }

        int[] s = new int[n + 1];

        for (int i = 1; i < n; i++) {
            int k = 1;
            while (k <= n - 1) {
                int j = (i - 1) / k;
                int kk = j == 0 ? n - 1 : (i - 1) / j;
                if (kk > n - 1) {
                    kk = n - 1;
                }
                if (a[i] < a[j]) {
                    s[k]++;
                    s[kk + 1]--;
                }
                k = kk + 1;
            }
        }

        int q = 0;
        for (int i = 1; i < n; i++) {
            q += s[i];
            out.println(q);
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
        new F().run();
    }

    private void run() throws IOException {
        solve();
        out.close();
    }

}