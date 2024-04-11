import java.io.*;
import java.util.*;

public class E {
    private FastScanner in;
    private PrintWriter out;

    final int mod = (int) 1e9 + 7;

    private void solve() {
        int n = in.nextInt();
        int[] cnt = new int[n];
        for (int i = 0; i + 1 < n; i++) {
            cnt[in.nextInt() - 1]++;
            cnt[in.nextInt() - 1]++;
        }
        if (n == 1) {
            out.println(1);
            return;
        }
        long res;
        final int mod = (int) 1e9 + 7;
        long mul = 1;
        long cntInside = 0;
        for (int i = 0; i < n; i++) {
            if (cnt[i] > 1) {
                mul = mul * 2 % mod;
                cntInside++;
            }
        }
        res = cntInside * mul % mod;
        long outSide = n - cntInside;
        res = (res + outSide * mul % mod * 2) % mod;
        out.println(res);
    }

    private void run() {
        try {
            in = new FastScanner(new File("E.in"));
            out = new PrintWriter(new File("E.out"));

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
        new E().runIO();
    }
}