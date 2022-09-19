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
public class B {

    private long MOD;
    private long X;
    private long MASK;

    private void solve() throws IOException {
        String s1 = next();
        String s2 = next();
        Random random = new Random(12323424423423L);
        for (int i = 0; i < 5; i++) {
            MOD = BigInteger.probablePrime(31, random).longValue();
            X = random.nextInt((int) (MOD / 2)) + MOD / 2;
            MASK = random.nextLong();
            if (hash(s1) != hash(s2)) {
                out.println("NO");
                return;
            }
        }
        out.println("YES");
    }

    private long hash(String s) {
        if (s.length() % 2 == 1) {
            long res = 0;
            for (int i = 0; i < s.length(); i++) {
                res = (res * X + s.charAt(i)) % MOD;
            }
            return res;
        } else {
            long h1 = hash(s.substring(0, s.length() / 2));
            long h2 = hash(s.substring(s.length() / 2, s.length()));
            h1 ^= MASK;
            h2 ^= MASK;
            if (h1 > h2) {
                long t = h1; h1 = h2; h2 = t;
            }
            return (h1 * X + h2) % MOD;
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