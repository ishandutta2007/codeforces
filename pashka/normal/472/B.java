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
        int[] f = new int[n];
        for (int i = 0; i < n; i++) {
            f[i] = nextInt();
        }
        Arrays.sort(f);
        int[] d = new int[n + 1];
        Arrays.fill(d, Integer.MAX_VALUE);
        d[0] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= k; j++) {
                if (i + j > n) break;
                d[i + j] = Math.min(d[i + j], d[i] + f[i + j - 1] - 1);
            }
        }
//        System.out.println(Arrays.toString(d));
        out.println(d[n] * 2);
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