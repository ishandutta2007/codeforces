import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class D {
    FastScanner in;
    PrintWriter out;

    class MyPrime {
        int value;
        int cnt;

        public MyPrime(int value, int cnt) {
            this.value = value;
            this.cnt = cnt;
        }
    }

    final int mod = (int) 1e9 + 7;

    int add(int x, int y) {
        x += y;
        return x >= mod ? (x - mod) : x;
    }

    int sub(int x, int y) {
        x -= y;
        return x < 0 ? (x + mod) : x;
    }

    int mul(int x, int y) {
        return (int) (x * 1L * y % mod);
    }

    void solve() {
        List<MyPrime> primes = new ArrayList<>();
        long n = in.nextLong();
        int k = in.nextInt();
        for (int v = 2; v * 1L * v <= n; v++) {
            if (n % v == 0) {
                int cnt = 0;
                while (n % v == 0) {
                    cnt++;
                    n /= v;
                }
                primes.add(new MyPrime(v % mod, cnt));
            }
        }
        if (n != 1) {
            primes.add(new MyPrime((int) (n % mod), 1));
        }
        int res = 1;
        for (int i = 1; i < inv.length; i++) {
            inv[i] = BigInteger.valueOf(i).modInverse(BigInteger.valueOf(mod)).intValue();
        }
        for (MyPrime p : primes) {
            res = mul(res, calc(p, k));
        }
        out.println(res);
    }

    int[] inv = new int[100];

    private int calc(MyPrime p, int k) {
        int[] pr = new int[p.cnt + 1];
        pr[pr.length - 1] = 1;
        int[] npr = new int[pr.length];
        for (int i = 0; i < k; i++) {
            Arrays.fill(npr, 0);
            for (int j = 0; j < pr.length; j++) {
                int nv = mul(pr[j], inv[j + 1]);
                for (int l = 0; l <= j; l++) {
                    npr[l] = add(npr[l], nv);
                }
            }
            int[] tmp = pr;
            pr = npr;
            npr = tmp;
        }
        int res = 0;
        int cur = 1;
        for (int i = 0; i < pr.length; i++) {
            res = add(res, mul(cur, pr[i]));
            cur = mul(cur, p.value);
        }
        return res;
    }

    void run() {
        try {
            in = new FastScanner(new File("D.in"));
            out = new PrintWriter(new File("D.out"));

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
        new D().runIO();
    }
}