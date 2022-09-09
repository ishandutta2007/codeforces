import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class A {
    private FastScanner in;
    private PrintWriter out;

    void solve() {
        int k = in.nextInt();
        long pa = in.nextInt();
        long pb = in.nextInt();
        final int mod = (int) 1e9 + 7;
        BigInteger MOD = BigInteger.valueOf(mod);
        int inv = BigInteger.valueOf(pa + pb).modInverse(MOD).intValue();
        pa = (int) ((pa * 1L * inv) % mod);
        pb = (int) ((pb * 1L * inv) % mod);
        long[][] dp = new long[k + 1][k];
        dp[1][0] = 1;
        long res = 0;
        long sInv = BigInteger.valueOf((mod - pa + 1) % mod).modInverse(MOD).intValue();
        for (int cntA = 0; cntA <= k; cntA++) {
            for (int curK = 0; curK < k; curK++) {
                long pr = dp[cntA][curK];
                if (pr == 0) {
                    continue;
                }
                if (cntA != k) {
                    dp[cntA + 1][curK] = (int) ((dp[cntA + 1][curK] + pr * pa) % mod);
                } else {
                    long tmpPR = (int) (pr * pa % mod);
                    res += tmpPR * curK % mod;
                    tmpPR = (int) (tmpPR * pb % mod);
                    res += cntA *sInv % mod * tmpPR % mod;
                    res += sInv * sInv % mod * tmpPR % mod;
                    res %= mod;
                }
                if (curK + cntA >= k) {
                    res = (res + pr * pb % mod * (curK + cntA)) % mod;
//                    System.err.println("add " + res);
                } else {
                    dp[cntA][curK + cntA] = ((dp[cntA][curK + cntA] + pr * pb) % mod);
                }
            }
        }
        out.println(res % mod);
    }

    private void run() {
        try {
            in = new FastScanner(new File("A.in"));
            out = new PrintWriter(new File("A.out"));

            solve();

            out.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    private void runIO() {
        in = new FastScanner(System.in);
        out = new PrintWriter(System.out);

        solve();

        out.close();
    }

    private class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        FastScanner(File f) {
            try {
                br = new BufferedReader(new FileReader(f));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        FastScanner(InputStream f) {
            br = new BufferedReader(new InputStreamReader(f));
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                String s = null;
                try {
                    s = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (s == null)
                    return null;
                st = new StringTokenizer(s);
            }
            return st.nextToken();
        }

        boolean hasMoreTokens() {
            while (st == null || !st.hasMoreTokens()) {
                String s = null;
                try {
                    s = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (s == null)
                    return false;
                st = new StringTokenizer(s);
            }
            return true;
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }
    }

    public static void main(String[] args) {
        new A().runIO();
    }
}