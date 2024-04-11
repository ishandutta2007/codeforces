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
        int n = nextInt();
        boolean[] p = new boolean[n + 2];
        for (int i = 2; i < p.length; i++) {
            if (i * i >= p.length) break;
            if (!p[i]) {
                for (int j = i * i; j < p.length; j += i) {
                    p[j] = true;
                }
            }
        }
        out.println(n >= 3 ? 2 : 1);
        for (int i = 0; i < n; i++) {
            out.print((p[i + 2] ? 2 : 1) + " ");
        }
        out.println();
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

    public static void main(String[] args) throws IOException {
        new B().run();
    }

    private void run() throws IOException {
        solve();
        out.close();
    }

}