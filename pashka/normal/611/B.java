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
        long a = Long.parseLong(next());
        long b = Long.parseLong(next());
        out.println(calc(b + 1) - calc(a));
    }

    private int calc(long x) {
        int res = 0;
        for (int len = 2; len < 64; len++) {
            long xx = (1L << len) - 1;
            for (int pos = 0; pos < len - 1; pos++) {
                long yy = xx - (1L << pos);
                if (yy < x) {
                    res++;
                }
            }
        }
        return res;

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