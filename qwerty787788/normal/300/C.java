import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class CF {
    FastScanner in;
    PrintWriter out;

    int a, b, n;
    long ans;
    long mod = (long) 1e9 + 7;
    long[] fact;

    long c(int n, int k) {
        long res = fact[n];
        long v1 = BigInteger.valueOf(fact[k]).modInverse(BigInteger.valueOf(mod)).longValue();
        long v2 = BigInteger.valueOf(fact[n - k]).modInverse(BigInteger.valueOf(mod)).longValue();
        res = (res * v1) % mod;
        res = (res * v2) % mod;
        return res;
    }
    
    void go(int curSum) {
        if (curSum > n * 10)
            return;
        go(curSum * 10 + a);
        go(curSum * 10 + b);
        int l = 0, r = n + 1;
        while (r - l > 1) {
            int m = (l + r) / 2;
            int cntB = n - m;
            long sum = a * m + b * cntB;
            if (sum >= curSum)
                l = m; else
                    r = m;
        }
        int cntA = l;
        int cntB = n - cntA;
        long sum = a * cntA + b * cntB;
        if (sum == curSum) {
            ans += c(n, cntA);
            ans %= mod;
        }
    }

    void solve() throws IOException {
        a = in.nextInt();
        b = in.nextInt();
        n = in.nextInt();
        int MAX = (int) 1e6;
        fact = new long[MAX + 1];
        fact[0] = 1;
        for (int i = 1; i <= MAX; i++) {
            fact[i] = (fact[i - 1] * i) % mod;
        }
        go(0);
        out.println(ans);
    }

    void run() throws IOException {
        try {
            in = new FastScanner(new File("test.in"));
            out = new PrintWriter(new File("test.out"));

            solve();

            out.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    void runIO() throws IOException {
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

        long nextLong() {
            return Long.parseLong(next());
        }
    }

    public static void main(String[] args) throws IOException {
        new CF().runIO();
    }
}