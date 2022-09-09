import java.io.*;
import java.util.*;

public class A {
    FastScanner in;
    PrintWriter out;

    void solve() {
        int n = in.nextInt();
        g = new List[n];
        for (int i = 0; i < n; i++) {
            g[i] = new ArrayList<>();
        }
        for (int i = 0; i + 1 < n; i++) {
            int fr = in.nextInt() - 1;
            int to = in.nextInt() - 1;
            int val = in.nextInt();
            g[fr].add(new Edge(to, val));
            g[to].add(new Edge(fr, val));
        }
        int root = 0;
        while (root != n && g[root].size() <= 2) {
            root++;
        }
        if (root == n) {
            int sameCost = g[0].get(0).cost;
            for (int i = 0; i < n; i++) {
                for (Edge e : g[i]) {
                    if (e.cost != sameCost) {
                        out.println("NO");
                        return;
                    }
                }
            }
            List<Integer> ends = new ArrayList<>();
            for (int v = 0; v < n; v++) {
                if (g[v].size() == 1) {
                    ends.add(v);
                }
            }
            out.println("YES");
            out.println(1);
            out.println((ends.get(0) + 1) + " " + (ends.get(1) + 1) + " " + sameCost);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (g[i].size() == 2) {
                if (g[i].get(0).cost != g[i].get(1).cost) {
                    out.println("NO");
                    return;
                }
            }
        }
        parent = new int[n];
        anyLeaf = new int[n];
        fromParent = new Edge[n];
        anyChildUp = new int[n];
        h = new int[n];
        go(root, root, null, 0);
        for (int i = 0; i < n; i++) {
            if (i != root) {
                anyChildUp[i] = findAnyLeaf(parent[i], i);
            }
        }
        makeAns(root, root);
        out.println("YES");
        out.println(res.size());
        for (Ans a : res) {
            out.println((a.fr + 1) + " " + (a.to + 1) + " " + a.cost);
        }
    }

    int[] anyChildUp;

    void addPath(int c1, int root, int delta) {
        while (c1 != root) {
            Edge e = fromParent[c1];
            e.cost -= delta;
            c1 = parent[c1];
        }
    }

    void addPath(int root, int c1, int c2, int delta) {
        root = lca(c1, c2);
        res.add(new Ans(c1, c2, delta));
        addPath(c1, root, delta);
        addPath(c2, root, delta);
    }

    int[] h;

    int lca(int x, int y) {
        if (x == y) {
            return x;
        }
        if (h[x] > h[y]) {
            return lca(parent[x], y);
        }
        return lca(x, parent[y]);
    }

    void makeAns(int v, int p) {
        List<Edge> allEdges = new ArrayList<>();
        for (Edge e : g[v]) {
            if (e.to == p) {
                continue;
            }
            allEdges.add(e);
        }
        int sz = allEdges.size();
        for (int i = 0; i < allEdges.size(); i++) {
            Edge e1 = allEdges.get(i);
            Edge e2 = allEdges.get((i + 1) % sz);
            Edge e3 = allEdges.get((i + 2) % sz);
            if (e1.cost != 0) {
                int c1 = anyLeaf[e1.to];
                int c2 = anyLeaf[e2.to];
                int c3 = anyLeaf[e3.to];
                if (allEdges.size() == 2) {
                    c3 = anyChildUp[v];
                }
                int co = e1.cost / 2;
                addPath(v, c1, c2, co);
                addPath(v, c1, c3, co);
                addPath(v, c2, c3, -co);
            }
            if (e1.cost != 0) {
                throw new AssertionError();
            }
        }
        for (Edge e : allEdges) {
            makeAns(e.to, v);
        }
    }

    List<Ans> res = new ArrayList<>();

    class Ans {
        int fr, to, cost;

        public Ans(int fr, int to, int cost) {
            this.fr = fr;
            this.to = to;
            this.cost = cost;
        }
    }

    int findAnyLeaf(int v, int p) {
        for (Edge e : g[v]) {
            if (e.to == p) {
                continue;
            }
            return findAnyLeaf(e.to, v);
        }
        return v;
    }

    void go(int v, int p, Edge fro, int hh) {
        parent[v] = p;
        h[v] = hh;
        anyLeaf[v] = v;
        fromParent[v] = fro;
        for (Edge e : g[v]) {
            if (e.to == p) {
                continue;
            }
            go(e.to, v, e, hh + 1);
            anyLeaf[v] = anyLeaf[e.to];
        }
    }

    int[] parent;
    Edge[] fromParent;
    int[] anyLeaf;

    List<Edge>[] g;

    class Edge {
        int to, cost;

        public Edge(int to, int cost) {
            this.to = to;
            this.cost = cost;
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