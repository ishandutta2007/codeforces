import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.StringTokenizer;

/**
 * @author Pavel Mavrin
 */
public class B {

    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st;
    PrintStream out = System.out;

    String next() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return st.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    public static void main(String[] args) {
        try {
            new B().solve();
        } catch (IOException e) {
        }
    }

    private void solve() throws IOException {
        int n = nextInt();
        int[][] d = new int[n + 1][n];
        for (int i = 0; i < n + 1; i++) {
            for (int j = 0; j < n; j++){
                d[i][nextInt() - 1] = n - j;
            }
        }
        int[] res = new int[n];
        for (int i = 0; i < n; i++){
            int z = -1;
            int zz = -1;
            for (int j = 0; j < n; j++) {
                if (j == i) continue;
                if (z == -1 || d[n][j] > d[n][z]) {
                    z = j;
                    if (zz == -1 || d[i][j] > d[i][zz]) {
                        zz = j;
                    }
                }
            }
            res[i] = zz;
        }
        for (int i = 0; i < n; i++) {
            out.print((res[i] + 1) + " ");
        }
        out.close();
    }


}