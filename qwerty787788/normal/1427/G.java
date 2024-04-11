import java.io.*;
import java.util.*;

public class GFlow {
    FastScanner in;
    PrintWriter out;

    class Edge {
        int fr, to;
        int flow, cap;
        Edge rev;

        Edge(int fr, int to, int cap) {
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
            was = new boolean[n];
        }

        Edge addEdge(int fr, int to, int cap) {
            Edge e1 = new Edge(fr, to, cap);
            Edge e2 = new Edge(to, fr, cap);
            e1.rev = e2;
            e2.rev = e1;
            g[fr].add(e1);
            g[to].add(e2);
            return e1;
        }

        boolean[] was;

        int dfs(int v, int flow) {
            if (v == n - 1 || flow == 0)
                return flow;
            if (was[v]) {
                return 0;
            }
            was[v] = true;
            for (int curE = 0; curE < g[v].size(); curE++) {
                Edge e = g[v].get(curE);
                if (e.flow == e.cap)
                    continue;
                int add = dfs(e.to, Math.min(flow, e.cap - e.flow));
                if (add == 0)
                    continue;
                e.flow += add;
                e.rev.flow -= add;
                return add;
            }
            return 0;
        }

        long res = 0;

        boolean undo(int v, boolean[] was) {
            if (v == n - 1) {
                return true;
            }
            if (was[v]) {
                return false;
            }
            was[v] = true;
            for (Edge e : g[v]) {
                if (e.flow > 0 && undo(e.to, was)) {
                    e.flow--;
                    e.rev.flow++;
                    return true;
                }
            }
            return false;
        }

        void undo(Edge startEdge) {
            Arrays.fill(was, false);
            while (startEdge.flow > 0 && undo(startEdge.to, was)) {
                startEdge.flow--;
                startEdge.rev.flow++;
                res--;
                Arrays.fill(was, false);
            }
        }

        long flow() {
            while (true) {
                Arrays.fill(was, false);
                int add = dfs(0, Integer.MAX_VALUE);
                if (add == 0)
                    break;
                res += add;
            }
            return res;
        }
    }

    void solve() {
        int n = in.nextInt();
        int[][] a = new int[n][n];
        int[][] id = new int[n][n];
        for (int i = 0; i < n; i++) {
            Arrays.fill(id[i], -1);
        }
        int it = 0;
        List<Integer> allColors = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                a[i][j] = in.nextInt();
                if (a[i][j] == -1) {
                    continue;
                }
                id[i][j] = it++;
                if (a[i][j] != 0) {
                    allColors.add(a[i][j]);
                }
            }
        }
        Collections.sort(allColors);
        long res = 0;
        Flow f = new Flow(it + 2);
        Edge[][] startEdge = new Edge[n][n];
        Edge[][] endEdge = new Edge[n][n];
        List<Pos> inter = new ArrayList<>();
        {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (a[i][j] > 0) {
                        startEdge[i][j] = f.addEdge(0, id[i][j] + 1, 0);
                        endEdge[i][j] = f.addEdge(id[i][j] + 1, f.n - 1, 0);
                        inter.add(new Pos(i, j));
                    }
                }
            }
            int[] dx = new int[]{0, -1, 1, 0};
            int[] dy = new int[]{1, 0, 0, -1};
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    int id1 = id[i][j];
                    if (id1 == -1) {
                        continue;
                    }
                    for (int itDir = 0; itDir < dx.length; itDir++) {
                        int ni = i + dx[itDir], nj = j + dy[itDir];
                        if (ni >= 0 && ni < n && nj >= 0 && nj < n) {
                            int id2 = id[ni][nj];
                            if (id2 != -1 && id2 > id1) {
                                f.addEdge(id1 + 1, id2 + 1, 1);
                            }
                        }
                    }
                }
            }
        }
        for (int iter = allColors.size() - 2; iter >= 0; iter--) {
            int c1 = allColors.get(iter), c2 = allColors.get(iter + 1);
            if (c1 == c2) {
                continue;
            }
            for (Pos p : inter) {
                int i = p.x, j = p.y;
                if (a[i][j] > 0) {
                    if (a[i][j] <= c1) {
                        startEdge[i][j].cap = Integer.MAX_VALUE;
                    } else {
                        if (startEdge[i][j].flow > 0) {
                            f.undo(startEdge[i][j]);
                        }
                        startEdge[i][j].cap = 0;
                    }
                    if (a[i][j] >= c2) {
                        endEdge[i][j].cap = Integer.MAX_VALUE;
                    } else {
                        if (endEdge[i][j].flow > 0) {
                            throw new AssertionError();
                        }
                        endEdge[i][j].cap = 0;
                    }
                }
            }
            long flow = f.flow();
            res += flow * (long) (c2 - c1);
        }
        out.println(res);
    }

    class Pos {
        int x, y;

        public Pos(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    void run() {
        try {
            in = new FastScanner(new File("G.in"));
            out = new PrintWriter(new File("G.out"));

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
        new GFlow().runIO();
    }
}