import java.io.*;
import java.util.*;

public class D {
    private FastScanner in;
    private PrintWriter out;

    private void solve() {
        int n = in.nextInt();
        int edges = in.nextInt();
        int teams = in.nextInt();
        int need = in.nextInt();
        int[][] g = new int[n][n];
        for (int i = 0; i < n; i++) {
            Arrays.fill(g[i], Integer.MAX_VALUE / 2);
            g[i][i] = 0;
        }
        int[] start = new int[teams];
        for (int i = 0; i < teams; i++) {
            start[i] = in.nextInt() - 1;
        }
        for (int i = 0; i < edges; i++) {
            int fr = in.nextInt() - 1;
            int to = in.nextInt() - 1;
            int cost = in.nextInt();
            g[fr][to] = g[to][fr] = Math.min(g[fr][to], cost);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    g[j][k] = Math.min(g[j][k], g[j][i] + g[i][k]);
                }
            }
        }
        Flow f = new Flow(1 + teams + n + 1);
        for (int i = 0; i < teams; i++) {
            f.addEdge(0, 1 + i, 1);
        }
        for (int i = 0; i < n; i++) {
            f.addEdge(1 + teams + i, f.n - 1, 1);
        }
        Edge[][] e = new Edge[teams][n];
        for (int i = 0; i < teams; i++) {
            for (int j = 0; j < n; j++) {
                e[i][j] = f.addEdge(1 + i, 1 + teams + j, 0);
            }
        }
//        System.err.println("teams = " + teams + ", n = " + n + " , need = " + need);
        final int MAX = 1731313;
        int l = -1, r = MAX;
        while (r - l > 1) {
            int m = (l + r) >> 1;
            f.clear();
            for (int i = 0; i < teams; i++) {
                for (int j = 0; j < n; j++) {
                    if (g[start[i]][j] <= m) {
                        e[i][j].cap = 1;
                    } else {
                        e[i][j].cap = 0;
                    }
                }
            }
            long ff = f.flow();
//            System.err.println("flow = " + ff);
            if (ff >= need) {
                r = m;
            } else {
                l = m;
            }
        }
        out.println(r == MAX ? -1 : r);
    }

    class Edge {
        int fr, to;
        long flow, cap;
        Edge rev;

        Edge(int fr, int to, long cap) {
            this.fr = fr;
            this.to = to;
            this.cap = cap;
        }
    }

    class Flow {
        int n;
        ArrayList<Edge>[] g;

        Flow(int n) {
            this.n = n;
            g = new ArrayList[n];
            for (int i = 0; i < n; i++) {
                g[i] = new ArrayList<>();
            }
            q = new int[n];
            h = new int[n];
            cur = new int[n];
        }

        Edge addEdge(int fr, int to, long cap) {
            Edge e1 = new Edge(fr, to, cap);
            Edge e2 = new Edge(to, fr, 0);
            e1.rev = e2;
            e2.rev = e1;
            g[fr].add(e1);
            g[to].add(e2);
            return e1;
        }

        int[] h;
        int[] cur;
        int[] q;

        boolean bfs() {
            int qIt = 0, qSz = 0;
            q[qSz++] = 0;
            Arrays.fill(h, -1);
            h[0] = 0;
            while (qIt < qSz) {
                int v = q[qIt++];
                for (Edge e : g[v]) {
                    if (e.flow == e.cap)
                        continue;
                    if (h[e.to] == -1) {
                        h[e.to] = h[e.fr] + 1;
                        q[qSz++] = e.to;
                    }
                }
            }
            return h[n - 1] != -1;
        }

        long dfs(int v, long flow) {
            if (v == n - 1 || flow == 0)
                return flow;
            for (; cur[v] < g[v].size(); cur[v]++) {
                Edge e = g[v].get(cur[v]);
                if (h[e.to] != h[e.fr] + 1 || e.flow == e.cap)
                    continue;
                long add = dfs(e.to, Math.min(flow, e.cap - e.flow));
                if (add == 0)
                    continue;
                e.flow += add;
                e.rev.flow -= add;
                return add;
            }
            return 0;
        }

        long flow() {
            long res = 0;
            while (bfs()) {
                Arrays.fill(cur, 0);
                while (true) {
                    long add = dfs(0, Long.MAX_VALUE);
                    if (add == 0)
                        break;
                    res += add;
                }
            }
            return res;
        }

        void clear() {
            for (int i = 0; i < g.length; i++) {
                for (Edge e : g[i]) {
                    e.flow = 0;
                }
            }
        }
    }


    private void run() {
        try {
            in = new FastScanner(new File("D.in"));
            out = new PrintWriter(new File("D.out"));

            solve();

            out.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    private void runIO() {
        in = new FastScanner(System.in);
        out = new PrintWriter(System.out);

        solve();

        out.close();
    }

    private class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        FastScanner(File f) {
            try {
                br = new BufferedReader(new FileReader(f));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        FastScanner(InputStream f) {
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