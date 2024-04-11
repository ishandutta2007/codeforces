import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class A {
    private FastScanner in;
    private PrintWriter out;

    void solve() {
        int m = in.nextInt();
        int n = in.nextInt();
        String[] s = new String[n];
        for (int i = 0; i < n; i++) {
            s[i] = in.next();
        }
        HashMap<String, Integer> hm = new HashMap<>();
        for (int i = 0; i < m; i++) {
            char[] tmp = new char[n];
            for (int j = 0; j < n; j++) {
                tmp[j] = s[j].charAt(i);
            }
            String ss = new String(tmp);
            Integer was = hm.get(ss);
            if (was == null) {
                hm.put(ss, 1);
            } else {
                hm.put(ss, was + 1);
            }
        }
        long res = 1;
        final int mod = (int) 1e9 + 7;
        final int M = m + 4;
        int[][] c = new int[M][M];
        long[] bells = new long[M];
        bells[0] = 1;
        for (int i = 0; i < M; i++) {
            c[i][0] = 1;
            if (i != 0) {
                for (int j = 1; j < M; j++) {
                    c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
                    if (c[i][j] >= mod) {
                        c[i][j] -= mod;
                    }
                }
                for (int k = 0; k < i; k++) {
                    bells[i] += c[i - 1][k] * bells[k] % mod;
                }
                bells[i] %= mod;
            }
        }
        for (Map.Entry<String, Integer> entry : hm.entrySet()) {
            res = res * 1L * bells[entry.getValue()] % mod;
        }
        out.println(res);
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