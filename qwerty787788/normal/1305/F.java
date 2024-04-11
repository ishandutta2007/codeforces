import java.io.*;
import java.util.*;

public class A {
    FastScanner in;
    PrintWriter out;

    long findAns(long[] a, long prime) {
        long res = 0;
        for (long x : a) {
            long z = x / prime * prime;
            long diff = z == 0 ? prime - x : Math.min(x - z, z + prime - x);
            res += diff;
        }
        return res;
    }

    void solve() {
        int n = in.nextInt();
        long[] a = new long[n];
        Random rnd = new Random(123);
        for (int i = 0; i < n; i++) {
            a[i] = in.nextLong();
        }
        long ans = n * 2;
        boolean[] checked = new boolean[n];
        long START = System.currentTimeMillis();
        HashSet<Long> primes = new HashSet<>();
        while (System.currentTimeMillis() - START < 1500) {
            int id = rnd.nextInt(n);
            if (checked[id]) {
                continue;
            }
            checked[id] = true;
            for (long val = a[id] - 3; val <= a[id] + 3; val++) {
                if (val < 2) {
                    continue;
                }
                long tmp = val;
                for (long x = 2; x * x <= tmp; x++) {
                    if (tmp % x == 0) {
                        if (!primes.contains(x)) {
                            primes.add(x);
                            ans = Math.min(ans, findAns(a, x));
                        }
                        while (tmp % x == 0) {
                            tmp /= x;
                        }
                    }
                }
                if (tmp != 1) {
                    if (!primes.contains(tmp)) {
                        primes.add(tmp);
                        ans = Math.min(ans, findAns(a, tmp));
                    }
                }
            }
        }
        out.println(ans);
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