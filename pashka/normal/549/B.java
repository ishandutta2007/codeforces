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
        boolean[][] a = new boolean[n][n];
        for (int i = 0; i < n; i++) {
            String s = next();
            for (int j = 0; j < n; j++) {
                a[i][j] = s.charAt(j) == '1';
            }
        }
        int[] b = new int[n];
        for (int i = 0; i < n; i++) {
            b[i] = nextInt();
        }
        int[] c = new int[n];
        boolean[] z = new boolean[n];
        int res = 0;
        while (true) {
            boolean ok = true;
            for (int i = 0; i < n; i++) {
                if (c[i] == b[i]) {
                    z[i] = true;
                    for (int j = 0; j < n; j++) {
                        if (a[i][j]) c[j]++;
                    }
                    ok = false;
                    res++;
                }
            }
            if (ok) break;
        }
        out.println(res);
        for (int i = 0; i < n; i++) {
            if (z[i]) out.print((i + 1) + " ");
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
        new B().run();
    }

    private void run() throws IOException {
        solve();
        out.close();
    }

}