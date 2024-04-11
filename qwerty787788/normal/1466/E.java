import java.io.*;
import java.util.*;

public class E {
    FastScanner in;
    PrintWriter out;

    final int mod = (int) 1e9 + 7;

    int add(int x, int y) {
        x += y;
        return x >= mod ? (x - mod) : x;
    }

    int mul(int x, int y) {
        return (int) ((x * 1L * y) % mod);
    }

    void solve() {
        int tc = in.nextInt();
        for (int t = 0; t < tc; t++) {
            int n = in.nextInt();
            long[] a = new long[n];
            for (int i = 0; i < n; i++) {
                a[i] = in.nextLong();
            }
            int res = 0;
            final int MAX = 60;
            int[] cnt = new int[MAX];
            int[] precPw = new int[MAX];
            int[] precPwN = new int[MAX];
            for (int bit = 0; bit < MAX; bit++) {
                precPw[bit] = (int) ((1L << bit) % mod);
                precPwN[bit] = mul(precPw[bit], n);
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < MAX; j++) {
                    if (((1L << j) & a[i]) != 0) {
                        cnt[j]++;
                    }
                }
            }
            for (int j = 0; j < n; j++) {
                int sumLeft = 0;
                int sumRight = 0;
                for (int bit = 0; bit < MAX; bit++) {
                    int mul = precPw[bit];
                    if (((1L << bit) & a[j]) != 0) {
                        sumLeft = add(sumLeft, mul(mul, cnt[bit]));
                        sumRight = add(sumRight, precPwN[bit]);
                    } else {
                        sumRight = add(sumRight, mul(mul, cnt[bit]));
                    }
                }
                res = add(res, mul(sumLeft, sumRight));
            }
            out.println(res);
        }
    }

    void run() {
        try {
            in = new FastScanner(new File("E.in"));
            out = new PrintWriter(new File("E.out"));

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
        new E().runIO();
    }
}