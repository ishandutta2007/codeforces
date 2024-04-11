import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

/**
 * @author Pavel Mavrin
 */
public class A {

    private void solve() throws IOException {
        int n = nextInt();
        int k = nextInt();
        boolean[] a = new boolean[n - k + 1];
        for (int i = 0; i < a.length; i++) {
            a[i] = next().equals("YES");
        }
        String[] res = new String[n];
        for (int i = 0; i < n; i++) {
            res[i] = name(i);
        }
        for (int i = 0; i < a.length; i++) {
            if (!a[i]) {
                res[i + k - 1] = res[i];
            }
        }
        for (String re : res) {
            out.print(re + " ");
        }
        out.println();
    }

    private String name(int i) {
        return "A" + (char)('a' + (i / 10)) + (char)('a' + (i % 10));
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
        new A().run();
    }

    private void run() throws IOException {
        solve();
        out.close();
    }

}