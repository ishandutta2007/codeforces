import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class CF {
    FastScanner in;
    PrintWriter out;

    final int MAX = (int) 1e5 + 10;
    final int MOD = (int) 1e9 + 7;
    int[] fact = new int[MAX];
    int[] factInv = new int[MAX];

    int c(int n, int k) {
        if (k < 0 || k > n)
            return 0;
        if (k == 0)
            return 1;
        int res = (int) ((fact[n] * 1L * factInv[k]) % MOD);
        res = (int) ((res * 1L * factInv[n - k]) % MOD);
        return res;
    }

    int findWays(int n, int friends) {
        if (n < friends)
            return 0;
        return c(n - 1, friends - 1);
    }

    void solve() {
        BigInteger MODBI = BigInteger.valueOf(MOD);
        fact[0] = factInv[0] = 1;
        for (int i = 1; i < MAX; i++) {
            fact[i] = (int) ((fact[i - 1] * 1L * i) % MOD);
            factInv[i] = BigInteger.valueOf(fact[i]).modInverse(MODBI)
                    .intValue();
        }
        int[] cnt = new int[MAX];
        Arrays.fill(cnt, -1);
        boolean[] prime = new boolean[MAX];
        Arrays.fill(prime, true);
        for (int i = 2; i < MAX; i++)
            if (prime[i])
                for (int j = i + i; j < MAX; j += i)
                    prime[j] = false;
        for (int i = 2; i < MAX; i++)
            if (cnt[i] == -1 && prime[i])
                for (int j = i + i; j < MAX; j += i) {
                    if ((j / i) % i == 0) {
                        cnt[j] = 0;
                    } else {
                        if (cnt[j] != 0) {
                            if (cnt[j / i] == 1) {
                                cnt[j] = -1;
                            } else {
                                cnt[j] = 1;
                            }
                        }
                    }
                }
        int q = in.nextInt();
        for (int i = 0; i < q; i++) {
            int n = in.nextInt();
            int f = in.nextInt();
            int res = findWays(n, f);
            for (int another = 1; another * 1L * another <= n; another++) {
                if (n % another == 0) {
                    if (another != 1) {
                        int tryIt = another;
                        int mul = cnt[tryIt];
                        if (mul != 0) {
                            res += mul * findWays(n / tryIt, f);
                            if (res < 0)
                                res += MOD;
                            if (res >= MOD)
                                res -= MOD;
                        }
                    }
                    if (another * another != n) {
                        int tryIt = n / another;
                        int mul = cnt[tryIt];
                        if (mul != 0) {
                            res += mul * findWays(n / tryIt, f);
                            if (res < 0)
                                res += MOD;
                            if (res >= MOD)
                                res -= MOD;
                        }
                    }

                }
            }
            out.println(res);
        }
    }

    void run() {
        try {
            in = new FastScanner(new File("test.in"));
            out = new PrintWriter(new File("test.out"));

            solve();

            out.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    void runIO() {

        in = new FastScanner(System.in);
        out = new PrintWriter(System.out);

        solve();

        out.close();
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(File f) {
            try {
                br = new BufferedReader(new FileReader(f));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        public FastScanner(InputStream f) {
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

        double nextDouble() {
            return Double.parseDouble(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }
    }

    public static void main(String[] args) {
        new CF().runIO();
    }
}