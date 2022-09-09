import java.io.*;
import java.util.*;

public class CF {
    FastScanner in;
    PrintWriter out;

    long mod = (long) 1e9 + 7;

    class Fenwick {
        int n;
        long[] t;

        public Fenwick(int n) {
            this.n = n;
            t = new long[n];
        }

        long sum(int r) {
            long result = 0;
            for (; r >= 0; r = (r & (r + 1)) - 1) {
                result += t[r];
                if (result >= mod)
                    result -= mod;
            }
            return result;
        }

        void inc(int i, long delta) {
            for (; i < n; i = (i | (i + 1))) {
                t[i] += delta;
                if (t[i] >= mod)
                    t[i] -= mod;
            }
        }

        long sum(int l, int r) {
            return (sum(r) - sum(l - 1) + mod) % mod;
        }
    }

    long hh(ArrayList<Integer> aa) {
        long res = 0;
        for (int x : aa) {
            res = res * mod + x;
        }
        return res;
    }

    long stupid(int[] a) {
        long res = 0;
        int n = a.length;
        ArrayList<Integer> aa = new ArrayList<>();
        HashSet<Long> hs = new HashSet<>();
        for (int st = 1; st < 1 << n; st++) {
            aa.clear();
            for (int i = 0; i < n; i++) {
                if (((1 << i) & st) != 0)
                    aa.add(a[i]);
            }
            boolean ok = true;
            for (int i = 0; i < aa.size() - 1; i++) {
                if (aa.get(i) > aa.get(i + 1))
                    ok = false;
            }
            if (!ok)
                continue;
            long h = hh(aa);
            if (hs.contains(h))
                continue;
            hs.add(h);
            long res1 = 1;
            for (int x : aa)
                res1 = (res1 * x) % mod;
            res = (res + res1) % mod;
        }
        return res;
    }

    Random rnd = new Random(123);

    int[] gen(int n) {
        int[] res = new int[n];
        for (int i = 0; i < n; i++) {
            res[i] = rnd.nextInt(10) + 1;
        }
        return res;
    }

    void solve() {
        // for (int test = 0;; test++) {
        // System.err.println(test);
        int n = in.nextInt();
        int[] a = new int[n];

        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
        }
        // int n = 10;
        // int[] a = gen(n);
        int MAX = (int) 1e6 + 1;
        Fenwick tree = new Fenwick(MAX + 1);
        for (int i = n - 1; i >= 0; i--) {
            long was = tree.sum(a[i], MAX) + 1;
            was = (was * a[i]) % mod;
            long w1 = tree.sum(a[i], a[i]);
            tree.inc(a[i], (was - w1 + mod) % mod);
        }
        long ans = tree.sum(1, MAX);
        out.println(ans);
        // if (ans != stupid(a))
        // throw new AssertionError();
        // }
    }

    void run() {
        try {
            in = new FastScanner(new File("test.in"));
            out = new PrintWriter(new File("test.out"));

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
    }

    public static void main(String[] args) {
        new CF().runIO();
    }
}