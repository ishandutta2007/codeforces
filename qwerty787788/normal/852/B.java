import java.io.*;
import java.util.*;

public class B {
    private FastScanner in;
    private PrintWriter out;

    int m;
    final int mod = (int) 1e9 + 7;

    int[] mul(int[] a, int[] b) {
        int[] res = new int[a.length];
        for (int i = 0; i < a.length; i++) {
            for (int j = 0; j < b.length; j++) {
                int c = i + j;
                if (c >= res.length) {
                    c -= res.length;
                }
                res[c] = (int) ((res[c] + a[i] * 1L * b[j]) % mod);
            }
        }
        return res;
    }

    int[] pow(int[] a, int pwr) {
        if (pwr == 0) {
            int[] res = new int[a.length];
            res[0] = 1;
            return res;
        }
        if (pwr == 1) {
            return a;
        }
        int[] xx = pow(a, pwr / 2);
        xx = mul(xx, xx);
        if (pwr % 2 == 1) {
            xx = mul(xx, a);
        }
        return xx;
    }

    private void solve() {
        int n = in.nextInt();
        int l = in.nextInt() - 2;
        m = in.nextInt();
        int[] a = new int[m];
        for (int i = 0; i < n; i++) {
            a[in.nextInt()]++;
        }
        int[] b = new int[n];
        int[] b1 = new int[m];
        for (int i = 0; i < n; i++) {
            b[i] = in.nextInt();
            b1[b[i]]++;
        }
        int[] c = new int[n];
        int[] c1 = new int[m];
        for (int i = 0; i < n; i++) {
            c[i] = (b[i] + in.nextInt()) % m;
            c1[c[i]]++;
        }
        b1 = pow(b1, l);
        long res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                for (int k = 0; k < m; k++) {
                    if ((i + j + k) % m != 0) {
                        continue;
                    }
                    long t = a[i] * 1L * b1[j] % mod * c1[k] % mod;
                    res += t;
                }
            }
        }
        out.println(res % mod);
    }

    private void run() {
        try {
            in = new FastScanner(new File("B.in"));
            out = new PrintWriter(new File("B.out"));

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
        new B().runIO();
    }
}