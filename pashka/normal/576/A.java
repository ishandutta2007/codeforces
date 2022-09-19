import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

/**
 * @author Pavel Mavrin
 */
public class A {

    private void solve() throws IOException {
        int n = nextInt();
        boolean[] p = new boolean[n + 1];
        Arrays.fill(p, true);
        int[] res = new int[n + 1];
        int c = 0;
        for (int i = 2; i <= n; i++) {
            if (p[i]) {
                int k = i;
                while (k <= n) {
                    res[c++] = k;
                    k *= i;
                }
                for (int j = i * i; j <= n; j += i) {
                    p[j] = false;
                }
            }
        }
        out.println(c);
        for (int i = 0; i < c; i++) {
            out.print(res[i] + " ");
        }
        out.println();
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