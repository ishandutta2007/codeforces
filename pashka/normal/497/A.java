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
        int m = nextInt();
        String[] a = new String[n];
        for (int i = 0; i < n; i++) {
            a[i] = next();
        }
        int[] c = new int[n];
        int res = m;
        for (int j = 0; j < m; j++) {
            boolean ok = true;
            int[] cc = new int[n];
            for (int i = 1; i < n; i++) {
                if (c[i] == c[i - 1]) {
                    if (a[i].charAt(j) < a[i - 1].charAt(j)) {
                        ok = false;
                        break;
                    } else if (a[i].charAt(j) == a[i - 1].charAt(j)) {
                        cc[i] = cc[i - 1];
                    } else {
                        cc[i] = cc[i - 1] + 1;
                    }
                } else {
                    cc[i] = cc[i - 1] + 1;
                }
            }
            if (ok) {
                res--;
                c = cc;
            }
        }
        out.println(res);
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
        new A().run();
    }

    private void run() throws IOException {
        solve();
        out.close();
    }

}