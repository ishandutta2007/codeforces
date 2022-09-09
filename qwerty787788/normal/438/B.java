import java.io.*;
import java.util.*;

public class CF {
    FastScanner in;
    PrintWriter out;

    class V implements Comparable<V> {
        int v, cost;

        V(int v, int cost) {
            this.v = v;
            this.cost = cost;
        }

        @Override
        public int compareTo(V o) {
            return Integer.compare(o.cost, cost);
        }
    }

    class Dsu {
        int[] p;
        int[] sz;

        Dsu(int n) {
            p = new int[n];
            sz = new int[n];
            for (int i = 0; i < n; i++)
                p[i] = i;
            Arrays.fill(sz, 1);
        }

        int get(int v) {
            return p[v] == v ? v : (p[v] = get(p[v]));
        }

        void union(int v, int u) {
            v = get(v);
            u = get(u);
            if (v == u)
                return;
            p[v] = u;
            sz[u] += sz[v];
        }
    }

    void solve() {
        int n = in.nextInt();
        int m = in.nextInt();
        V[] a = new V[n];
        int[] c = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = new V(i, in.nextInt());
            c[i] = a[i].cost;
        }
        Arrays.sort(a);
        ArrayList<Integer>[] g = new ArrayList[n];
        for (int i = 0; i < n; i++)
            g[i] = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            int fr = in.nextInt() - 1;
            int to = in.nextInt() - 1;
            g[fr].add(to);
            g[to].add(fr);
        }
        Dsu dsu = new Dsu(n);
        boolean[] alive = new boolean[n];
        long up = 0, down = n * 1L * (n - 1) / 2;
        for (int i = 0; i < n; i++) {
            int v = a[i].v;
            for (int to : g[v]) {
                if (alive[to]) {
                    if (dsu.get(v) != dsu.get(to)) {
                        up += a[i].cost * 1L * dsu.sz[dsu.get(v)] * 1L
                                * dsu.sz[dsu.get(to)];
                        dsu.union(v, to);
                    }
                }
            }
            alive[v] = true;
        }
        Locale.setDefault(Locale.US);
        out.println(up / (1.0 * down));
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

        double nextDouble() {
            return Double.parseDouble(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }
    }

    public static void main(String[] args) {
        new CF().runIO();
    }
}