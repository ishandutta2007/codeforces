import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class A {
    FastScanner in;
    PrintWriter out;

    final int mod = (int) 1e9 + 7;

    int mul(int x, int y) {
        return (int) (x * 1L * y % mod);
    }

    int add(int x, int y) {
        x += y;
        return x >= mod ? (x - mod) : x;
    }

    int sub(int x, int y) {
        x -= y;
        return x < 0 ? (x + mod) : x;
    }

    void solve() {
        int n = in.nextInt();
        int m = n + 5;
        BigInteger MOD = BigInteger.valueOf(mod);
        int d = in.nextInt();
//        int[] inv = new int[n + 10];
//        inv[0] = 1;
//        for (int i = 1; i < inv.length; i++) {
//            inv[i] = BigInteger.valueOf(i).modInverse(BigInteger.valueOf(mod)).intValue();
//        }
        List<Integer>[] g = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            g[i] = new ArrayList<>();
        }
        for (int i = 1; i < n; i++) {
            g[in.nextInt() - 1].add(i);
        }
        int[][] f = new int[n][m];
        for (int i = n - 1; i >= 0; i--) {
            Arrays.fill(f[i], 1);
            for (int to : g[i]) {
                for (int j = 0; j < m; j++) {
                    f[i][j] = mul(f[i][j], f[to][j]);
                }
            }
            for (int j = 1; j < m; j++) {
                f[i][j] = add(f[i][j], f[i][j - 1]);
            }
        }
        int res = 0;
        for (int pt = 0; pt < m; pt++) {
            int coef = f[0][pt];
            int coefDown = 1;
            for (int i = 0; i < m; i++) {
                if (i != pt) {
                    coefDown = mul(coefDown, sub(pt, i));
                    coef = mul(coef, sub(d, 1 + i));
                }
            }
            res = add(res, mul(coef, BigInteger.valueOf(coefDown).modInverse(MOD).intValue()));
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