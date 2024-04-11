import java.io.*;
import java.util.*;

public class I {
    private FastScanner in;
    private PrintWriter out;

    int[] p;

    int get(int x) {
        return p[x] == x ? x : (p[x] = get(p[x]));
    }

    void unite(int x, int y) {
        p[get(x)] = get(y);
    }

    private void solve() {
        int n = in.nextInt();
//        Random rnd = new Random(123);
//        p = new int[n];
//        for (int i = 0; i < n; i++) {
//            p[i] = i;
//        }
        men = new int[n];
        for (int i = 0; i < n; i++) {
            men[i] = in.nextInt();
        }
        f = new int[n];
        int[] all = new int[n];
        for (int i = 0; i < n; i++) {
            f[i] = all[i] = in.nextInt();
        }
        Arrays.sort(all);
        for (int i = 0; i < n; i++) {
            f[i] = Arrays.binarySearch(all, f[i]);
        }

        MoTree tree = new MoTree(n, new Solver());
        for (int i = 0; i + 1 < n; i++) {
            int fr = in.nextInt() - 1;
            int to = in.nextInt() - 1;
            tree.addEdge(fr, to);
        }
        int cnt = in.nextInt();
        for (int i = 0; i < cnt; i++) {
            Query q = new Query(in.nextInt() - 1, in.nextInt() - 1, i);
            tree.addQuery(q);
        }
        res = new long[cnt];
        curMens = new int[n];
        curWem = new int[n];
        tree.solve();
        for (long z : res) {
            out.println(z);
        }
    }

    long[] res;
    long curSum;
    int[] men;
    int[] f;
    int[] curMens;
    int[] curWem;

    class Solver {
        void addVertex(int v) {
            if (men[v] == 1) {
                curMens[f[v]]++;
                curSum += curWem[f[v]];
            } else {
                curWem[f[v]]++;
                curSum += curMens[f[v]];
            }
        }

        void removeVertex(int v) {
            if (men[v] == 1) {
                curMens[f[v]]--;
                curSum -= curWem[f[v]];
            } else {
                curWem[f[v]]--;
                curSum -= curMens[f[v]];
            }
        }

        void answerQuery(Query q) {
            res[q.id] = curSum;
        }
    }


    class Query {
        int v, u, id;

        public Query(int v, int u, int id) {
            this.v = v;
            this.u = u;
            this.id = id;
        }

        int arrayL, arrayR, needLCA;

        @Override
        public String toString() {
            return "Query{" +
                    "arrayL=" + arrayL +
                    ", arrayR=" + arrayR +
                    ", needLCA=" + needLCA +
                    '}';
        }
    }

    class MoTree {
        ArrayList<Integer>[] g;
        ArrayList<Query> queries;
        int n;
        Solver s;

        MoTree(int n, Solver s) {
            this.n = n;
            g = new ArrayList[n];
            for (int i = 0; i < n; i++) {
                g[i] = new ArrayList<>();
            }
            this.s = s;
            queries = new ArrayList<>();
        }

        void addEdge(int fr, int to) {
            g[fr].add(to);
            g[to].add(fr);
        }

        void addQuery(Query q) {
            queries.add(q);
        }

        final int LOG = 20;
        int[][] up;
        int time;
        int[] tin, tout;
        int[] array;
        int blockSize;

        void solve() {
            up = new int[LOG][n];
            time = 0;
            tin = new int[n];
            tout = new int[n];
            blockSize = 2 * (int) Math.sqrt(n);
            array = new int[2 * n];
            dfs(0, 0);
            for (int i = 1; i < LOG; i++) {
                for (int j = 0; j < n; j++) {
                    up[i][j] = up[i - 1][up[i - 1][j]];
                }
            }
            for (Query q : queries) {
                if (tin[q.v] > tin[q.u]) {
                    int tmp = q.v;
                    q.v = q.u;
                    q.u = tmp;
                }
                if (inside(q.v, q.u)) {
                    q.arrayL = tin[q.v];
                    q.needLCA = -1;
                } else {
                    q.arrayL = tout[q.v];
                    q.needLCA = lca(q.v, q.u);
                }
                q.arrayR = tin[q.u] + 1;
            }
            Collections.sort(queries, new Comparator<Query>() {
                @Override
                public int compare(Query o1, Query o2) {
                    int p1 = o1.arrayL / blockSize, p2 = o2.arrayL / blockSize;
                    if (p1 != p2) {
                        return Integer.compare(p1, p2);
                    }
                    int v = p1 % 2 == 0 ? 1 : -1;
                    return v * Integer.compare(o1.arrayR, o2.arrayR);
                }
            });
//            System.err.println("Array  = " + Arrays.toString(array));
//            for (Query q : queries) {
//                System.err.println(q);
//            }
            int it1 = 0, it2 = 0;
            use = new int[n];
            for (Query q : queries) {
                while (it1 < q.arrayL) {
                    changeUse(array[it1++]);
                }
                while (it1 > q.arrayL) {
                    changeUse(array[--it1]);
                }
                while (it2 < q.arrayR) {
                    changeUse(array[it2++]);
                }
                while (it2 > q.arrayR) {
                    changeUse(array[--it2]);
                }
                if (q.needLCA != -1) {
                    changeUse(q.needLCA);
                }
                s.answerQuery(q);
                if (q.needLCA != -1) {
                    changeUse(q.needLCA);
                }
            }
        }

        int[] use;

        void changeUse(int v) {
            use[v] ^= 1;
            if (use[v] == 1) {
                s.addVertex(v);
            } else {
                s.removeVertex(v);
            }
        }

        void dfs(int v, int p) {
            array[time] = v;
            tin[v] = time++;
            up[0][v] = p;
            for (int i = 0; i < g[v].size(); i++) {
                int to = g[v].get(i);
                if (to == p) {
                    continue;
                }
                dfs(to, v);
            }
            array[time] = v;
            tout[v] = time++;
        }

        boolean inside(int p, int v) {
            return tin[v] >= tin[p] && tout[v] <= tout[p];
        }

        int lca(int x, int y) {
            for (int i = LOG - 1; i >= 0; i--) {
                if (!inside(up[i][x], y)) {
                    x = up[i][x];
                }
            }
            return inside(x, y) ? x : up[0][x];
        }
    }

    private void run() {
        try {
            in = new FastScanner(new File("I.in"));
            out = new PrintWriter(new File("I.out"));

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
        new I().runIO();
    }
}