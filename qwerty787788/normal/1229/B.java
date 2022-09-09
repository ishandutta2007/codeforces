import java.io.*;
import java.util.*;

public class A {
    FastScanner in;
    PrintWriter out;

    long[] x;
    List<Integer>[] graph;

    long gcd(long x, long y) {
        return x == 0 ? y : gcd(y % x, x);
    }

    void go(long[] g, int[] len, int sz, int v, int p) {
        long val = x[v];
        long[] ng = new long[sz + 1];
        int[] nlen = new int[sz + 1];
        for (int i = 0; i < sz; i++) {
            ng[i] = gcd(g[i], val);
            nlen[i] = len[i];
        }
        ng[sz] = val;
        nlen[sz] = 1;
        int iter = 0;
        for (int i = 1; i <= sz; i++) {
            if (ng[i] == ng[iter]) {
                nlen[iter] += nlen[i];
            } else {
                iter++;
                ng[iter] = ng[i];
                nlen[iter] = nlen[i];
            }
        }
        for (int i = 0; i <= iter; i++) {
            result = add(result, mul(ng[i], nlen[i]));
        }
        for (int to : graph[v]) {
            if (to == p) {
                continue;
            }
            go(ng, nlen, iter + 1, to, v);
        }
    }

    long mod = (long) 1e9 + 7;

    long mul(long x, long y) {
        return x * y % mod;
    }

    long add(long x, long y) {
        x += y;
        return x >= mod ? (x - mod) : x;
    }

    long result;

    void solve() {
        int n = in.nextInt();
        graph = new List[n];
        for (int i = 0; i < n; i++) {
            graph[i] = new ArrayList<>();
        }
        x = new long[n];
        for (int i = 0; i < n; i++) {
            x[i] = in.nextLong();
        }
        for (int i = 0; i + 1 < n; i++) {
            int fr = in.nextInt() - 1;
            int to = in.nextInt() - 1;
            graph[fr].add(to);
            graph[to].add(fr);
        }
        go(new long[]{}, new int[]{}, 0, 0, 0);
        out.println(result % mod);
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