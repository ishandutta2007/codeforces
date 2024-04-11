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
        int t = nextInt();
        for (int i = 0; i < t; i++) {
            long x = nextInt();
            long y = nextInt();
            long p = nextInt();
            long q = nextInt();
            if (p == q && x < y || x > 0 && p == 0) {
                out.println(-1);
            } else {
                long l = -1;
                long r = 2000000001;
                while (r > l + 1) {
                    long m = (l + r) / 2;
                    long qq = q * m;
                    long pp = p * m;
                    if (y > qq) {
                        l = m;
                    } else {
                        long minP = x;
                        long maxP = x + qq - y;
                        if (pp >= minP && pp <= maxP) {
//                            System.out.println("!");
                            r = m;
                        } else {
                            l = m;
                        }
                    }
                }
                out.println(r * q - y);
            }
        }
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