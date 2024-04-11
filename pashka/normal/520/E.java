import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.StringTokenizer;

/**
 * @author Pavel Mavrin
 */
public class E {

    private void solve() throws IOException {
        int n = nextInt();
        int k = nextInt();
        String s = next();
        init(n);
        long res = 0;
        long m = 0;
        long p10 = 1;
        for (int i = n - 1; i >= 0; i--) {
            long q = c(i, k) * p10;
            q %= MOD;
            q += m;
            q %= MOD;
            q *= (s.charAt(i) - '0');
            q %= MOD;
            res += q;
            res %= MOD;

            m += (c(i - 1, k - 1) * p10) % MOD;
            m %= MOD;

            p10 = p10 * 10 % MOD;
        }
        out.println(res);
    }

    private static final long MOD = (long) (1e9 + 7);
    private static final BigInteger MOD2 = BigInteger.valueOf(MOD);

    long[] fact;
    long[] invf;

    void init(int n) {
        fact = new long[n + 1];
        invf = new long[n + 1];
        fact[0] = 1;
        invf[0] = 1;
        for (int i = 1; i <= n; i++) {
            fact[i] = fact[i - 1] * i;
            fact[i] %= MOD;
            invf[i] = BigInteger.valueOf(fact[i]).modInverse(MOD2).longValue();
        }
    }

    private long c(int n, int k) {
        if (k > n || k < 0) return 0;
        long res = fact[n] * invf[k];
        res %= MOD;
        res *= invf[n - k];
        res %= MOD;
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
        new E().run();
    }

    private void run() throws IOException {
        solve();
        out.close();
    }

}