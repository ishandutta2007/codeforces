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
        String[][] s = new String[n][2];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 2; j++) {
                s[i][j] = next();
            }
        }
        int[] p = new int[n];
        for (int i = 0; i < n; i++) {
            p[i] = nextInt() - 1;
        }
        boolean[][] d = new boolean[n][2];
        d[0][0] = true;
        d[0][1] = true;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    int ii = p[i];
                    int iii = p[i - 1];
                    if (d[i - 1][k] && s[ii][j].compareTo(s[iii][k]) > 0) {
                        d[i][j] = true;
                    }
                }
            }
        }
        out.println((d[n - 1][0] || d[n - 1][1]) ? "YES" : "NO");

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
        new C().run();
    }

    private void run() throws IOException {
        solve();
        out.close();
    }

}