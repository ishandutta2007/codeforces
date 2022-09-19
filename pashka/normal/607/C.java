import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Random;
import java.util.StringTokenizer;

/**
 * @author Pavel Mavrin
 */
public class C {

    private void solve() throws IOException {
        int n = nextInt() - 1;
        int[] a = new int[n];
        int[] b = new int[n];
        {
            String s = next();
            for (int i = 0; i < n; i++) {
                a[i] = "NSEW".indexOf(s.charAt(i));
            }
            s = next();
            for (int i = 0; i < n; i++) {
                b[n - 1 - i] = "SNWE".indexOf(s.charAt(i));
            }
        }

        Random random = new Random();
        for (int tt = 0; tt < 3; tt++) {
            long mod = BigInteger.probablePrime(30, random).longValue();
            long x = random.nextInt((int) mod);
            long ha = 0;
            long hb = 0;
            long p = 1;
            boolean ok = true;
            for (int i = 0; i < n; i++) {
                ha = (ha * x) % mod;
                ha = (ha + a[n - 1 - i]) % mod;
                hb = (hb + p * b[i]) % mod;
                p = (p * x) % mod;
                if (ha == hb) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                out.println("YES");
                return;
            }
        }
        out.println("NO");

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