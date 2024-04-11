import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

/**
 * @author Pavel Mavrin
 */
public class B {

    private void solve() throws IOException {
        String s = next();
        int n = s.length();
        int m = nextInt();
        int[] a = new int[(n + 1) / 2];
        for (int i = 0; i < m; i++) {
            int x = nextInt();
            a[x - 1]++;
        }
        char[] res = s.toCharArray();
        int z = 0;
        for (int i = 0; i < n / 2; i++) {
            z += a[i];
            if (z % 2 == 1) {
                char t = res[i];
                res[i] = res[n - i - 1];
                res[n - i - 1] = t;
            }
        }
        out.println(new String(res));
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