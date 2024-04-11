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

    void solve() {
        int n = in.nextInt();
        int m = in.nextInt();
        V[] a = new V[n];
        int[]c = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = new V(i, in.nextInt());
            c[i]= a[i].cost;
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
        boolean[] alive =new boolean[n];
        Arrays.fill(alive, true);
        int cost  = 0;
        for (int i = 0; i < n; i++) {
            int v = a[i].v;
            for (int to : g[v]) {
                if (alive[to])
                    cost += c[to];
            }
            alive[v] = false;
        }
        out.println(cost);
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