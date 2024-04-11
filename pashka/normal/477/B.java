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
        int k = nextInt();
        boolean[] z = new boolean[100000];
        int[][] res = new int[n][4];
        for (int i = 0; i < n; i++) {
            res[i][0] = i * 6 + 1;
            res[i][1] = i * 6 + 3;
            res[i][2] = i * 6 + 5;
            int j = 2;
            while (z[j] || j % 3 == 0 || gcd(j, res[i][0]) > 1 ||  gcd(j, res[i][1]) > 1 ||  gcd(j, res[i][2]) > 1) {
                j += 2;
            }
            res[i][3] = j;
            for (int q = 0; q < 4; q++) {
                z[res[i][q]] = true;
            }
        }
        int m = 0;
        for (int i = 0; i < z.length; i++) {
            if (z[i]) m = i;
        }
        out.println(m * k);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 4; j++) {
                out.print(res[i][j] * k + " ");
            }
            out.println();
        }
    }

    private int gcd(int a, int b) {
        while (b > 0) {
            int c = a % b;
            a = b;
            b = c;
        }
        return a;
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