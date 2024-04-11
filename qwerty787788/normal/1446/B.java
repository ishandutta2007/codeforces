import java.io.*;
import java.util.*;

public class A {
    FastScanner in;
    PrintWriter out;

    int getMax(int[] a) {
        int r = 0;
        for (int x : a) {
            r = Math.max(r, x);
        }
        return r;
    }

    void solve() {
        int n = in.nextInt();
        int m = in.nextInt();
        char[] s = in.next().toCharArray();
        char[] t = in.next().toCharArray();
        int[] dp = new int[m + 1];
        int[] ndp = new int[m + 1];
        int res = 0;
        for (char c : s) {
            Arrays.fill(ndp, 0);
            for (int pos = 0; pos <= m; pos++) {
                int cur = dp[pos];
                if (pos < m) {
                    dp[pos + 1] = Math.max(dp[pos + 1], cur - 1);
                    if (t[pos] == c) {
                        ndp[pos + 1] = Math.max(ndp[pos + 1], cur + 2);
                    }
                }
                ndp[pos] = Math.max(ndp[pos], cur - 1);
            }
            int[] tmp = dp;
            dp = ndp;
            ndp = tmp;
            res = Math.max(res, getMax(dp));
        }
        out.println(res);
    }

    void run() {
        try {
            in = new FastScanner(new File("A.in"));
            out = new PrintWriter(new File("A.out"));

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