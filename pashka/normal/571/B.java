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
        int k = nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = nextInt();
        }
        Arrays.sort(a);
        int x = n / k;
        int c = n % k;
        // c: x + 1
        // k - c: x
        long[][] d = new long[c + 1][k - c + 1];
        for (long[] longs : d) {
            Arrays.fill(longs, Long.MAX_VALUE);
        }
        d[0][0] = 0;
        for (int i = 0; i <= c; i++) {
            for (int j = 0; j <= k - c; j++) {
                int m = i * (x + 1) + j * x;
                if (i < c) {
                    d[i + 1][j] = Math.min(d[i + 1][j], d[i][j] + a[m + x] - a[m]);
                }
                if (j < k - c) {
                    d[i][j + 1] = Math.min(d[i][j + 1], d[i][j] + a[m + x - 1] - a[m]);
                }
            }
        }
        out.println(d[c][k - c]);
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