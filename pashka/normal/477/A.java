import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

/**
 * @author Pavel Mavrin
 */
public class A {

    private static final long MOD = (long) (1e9+7);

    private void solve() throws IOException {
        long a = nextInt();
        long b = nextInt();
        long s = 0;
        for (int x = 1; x < b; x++) {
            long c = a * (a + 1) / 2;
            c %= MOD;
            c *= b;
            c %= MOD;
            c += a;
            c %= MOD;
            c *= x;
            c %= MOD;
            s += c;
            s %= MOD;
        }
        out.println(s);
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