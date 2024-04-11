import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class F {
    private FastScanner in;
    private PrintWriter out;

    int phi (int n) {
        int result = n;
        for (int i=2; i*i<=n; ++i)
            if (n % i == 0) {
                while (n % i == 0)
                    n /= i;
                result -= result / i;
            }
        if (n > 1)
            result -= result / n;
        return result;
    }

    private void solve() {
        int n = in.nextInt();
        int m = in.nextInt();
        int a = in.nextInt();
        int q = in.nextInt();
        int phi = phi(q);
        int mod = phi;
        for (int i = 2; i * i <= phi; i++) {
            if (phi % i == 0) {
                if (pow(a, i, q) == 1) {
                    mod = Math.min(mod, i);
                }
                if (pow(a, phi / i, q) == 1) {
                    mod = Math.min(mod, phi / i);
                }
            }
        }
//        System.err.println("mod = " + mod);
        final int max = Math.max(n, m) + 1;
        int[] fact = new int[max];
        fact[0] = 1;
        for (int i = 1; i < max; i++) {
            fact[i] = (int) ((fact[i - 1] * 1L * i) % mod);
        }
        int[] factInv = new int[max];
        factInv[max - 1] = BigInteger.valueOf(fact[max - 1]).modInverse(BigInteger.valueOf(mod)).intValue();
        for (int i = max - 2; i >= 0; i--) {
            factInv[i] = (int) (factInv[i + 1] * 1L * (i + 1) % mod);
        }
        int[] vals = new int[n];
        for (int pos = n - 1; pos >= 0; pos--) {
            if (pos != n - 1) {
                vals[pos] = vals[pos + 1];
            }
            int k = (n - 1) - pos;
            if (k <= m) {
                int add = (int) (fact[m] * 1L * factInv[k] % mod * factInv[m - k] % mod);
                vals[pos] += add;
                if (vals[pos] >= mod) {
                    vals[pos] -= mod;
                }
            }
        }
//        System.err.println(Arrays.toString(vals));
        for (int i = 0; i < n; i++) {
            vals[i] = pow(a, vals[i], q);
            out.print(vals[i] + " ");
        }
        out.println();
    }

    int pow(int x, int y, int mod) {
        if (y == 0) {
            return 1;
        }
        if (y == 1) {
            return x;
        }
        int f = pow(x, y / 2, mod);
        f = (int) (f * 1L * f % mod);
        if (y % 2 == 1) {
            f = (int) (f * 1L * x % mod);
        }
        return f;
    }

    private void run() {
        try {
            in = new FastScanner(new File("F.in"));
            out = new PrintWriter(new File("F.out"));

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
        new F().runIO();
    }
}