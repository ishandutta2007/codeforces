import java.io.*;
import java.util.*;

public class CF {
    FastScanner in;
    PrintWriter out;

    ArrayList<Integer>[] g;
    int[] from;
    int[] to;

    ArrayList<Integer> res = new ArrayList<>();

    void go(int v, int p, int xorCur, int xorPrev) {
        from[v] ^= xorCur;
        if (from[v] != to[v]) {
            xorCur ^= 1;
            res.add(v);
        }
        for (int to : g[v]) {
            if (to != p) {
                go(to, v, xorPrev, xorCur);
            }
        }
    }

    void solve() {
        int n = in.nextInt();
        g = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            g[i] = new ArrayList<>();
        }
        for (int i = 0; i < n - 1; i++) {
            int fr = in.nextInt() - 1;
            int to = in.nextInt() - 1;
            g[fr].add(to);
            g[to].add(fr);
        }
        from = new int[n];
        to = new int[n];
        for (int i = 0; i < n; i++)
            from[i] = in.nextInt();
        for (int i = 0; i < n; i++) {
            to[i] = in.nextInt();
        }
        go(0, -1, 0, 0);
        out.println(res.size());
        for (int x : res) {
            out.println(x + 1);
        }
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