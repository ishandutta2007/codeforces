import java.io.*;
import java.util.*;

public class A {
    FastScanner in;
    PrintWriter out;

    void dfs(int v, int curDist, int[] dist, List<Integer>[] g) {
        dist[v] = curDist;
        for (int i = 0; i < g[v].size(); i++) {
            int to = g[v].get(i);
            if (dist[to] == -1) {
                dfs(to, curDist + 1, dist, g);
            }
        }
    }

    int[] getDists(int v, List<Integer>[] g) {
        int[] res = new int[g.length];
        Arrays.fill(res, -1);
        dfs(v, 0, res, g);
        return res;
    }

    boolean doesAliceWin(int a, int b, int da, int db, List<Integer>[] g) {
        int[] dFromAlice = getDists(a, g);
        if (dFromAlice[b] <= da) {
            return true;
        }
        if (db <= 2 * da) {
            return true;
        }
        int maxDistId = 0;
        for(int i = 1; i < dFromAlice.length; i++) {
            if (dFromAlice[i] > dFromAlice[maxDistId]) {
                maxDistId = i;
            }
        }
        int[] d = getDists(maxDistId, g);
        int diam = 0;
        for (int len : d) {
            diam = Math.max(diam, len);
        }
        return diam <= 2 * da;
    }

    void solve() {
        int tc = in.nextInt();
        for (int t = 0; t < tc; t++) {
            int n = in.nextInt();
            int a = in.nextInt() - 1;
            int b = in.nextInt() - 1;
            int da = in.nextInt();
            int db = in.nextInt();
            List<Integer>[] g = new List[n];
            for (int i = 0; i < n; i++) {
                g[i] = new ArrayList<>();
            }
            for (int i = 0; i + 1 < n; i++) {
                int fr = in.nextInt() - 1;
                int to = in.nextInt() - 1;
                g[fr].add(to);
                g[to].add(fr);
            }
            boolean aliceWin = doesAliceWin(a, b, da, db, g);
            out.println(aliceWin ? "Alice" : "Bob");
        }
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