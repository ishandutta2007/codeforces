import java.io.*;
import java.util.*;

public class A {
    FastScanner in;
    PrintWriter out;


    List<Integer>[] g;

    void solve() {
        int n = in.nextInt();
        int q = in.nextInt();
        g = new List[n];
        for (int i = 0; i < n; i++) {
            g[i] = new ArrayList<>();
        }
        for (int i = 0; i + 1 < n; i++) {
            int fr = in.nextInt() - 1;
            int to = in.nextInt() - 1;
            g[fr].add(to);
            g[to].add(fr);
        }
        up = new int[LOG][n];
        time = 0;
        tin = new int[n];
        tout = new int[n];
        h = new int[n];

        dfs(0, 0, 0);
        for (int i = 1; i < LOG; i++) {
            for (int j = 0; j < n; j++) {
                up[i][j] = up[i - 1][up[i - 1][j]];
            }
        }

        HashSet<Long> edges = new HashSet<>();
        st = new SegmentTree(time);
//        System.err.println(Arrays.toString(tin));
        for (int i = 0; i < q; i++) {
            int u = in.nextInt() - 1;
            int v = in.nextInt() - 1;
            long edge = makeEdge(u, v);
            if (edges.contains(edge)) {
                edges.remove(edge);
                addEdge(u, v, -1);
            } else {
                edges.add(edge);
                addEdge(u, v, 1);
            }
            int[] r = st.getMin(0, 0, time - 1, 0, time - 1);
            if (r[0] == 0) {
                out.println(r[1]);
            } else {
                out.println(0);
            }
        }
    }

    void addEdgeInsde(int pare, int ch, int mul) {
        int first = ch;
        for (int i = LOG - 1; i >= 0; i--) {
            if (up[i][first] != pare && inside(pare, up[i][first])) {
                first = up[i][first];
            }
        }
        st.add(0, 0, time - 1, tin[first], tout[first], mul);
        st.add(0, 0, time - 1, tin[ch], tout[ch], -mul);
    }

    void addEdge(int u, int v, int mul) {
        if (inside(u, v)) {
            addEdgeInsde(u, v, mul);
        } else if (inside(v, u)) {
            addEdgeInsde(v, u, mul);
        } else {
//            System.err.println("here " + u + " " + v + " " + mul);
//            System.err.println("+ " + 0 + " " + (time - 1) + " " + mul);
            st.add(0, 0, time - 1, 0, time - 1, mul);
//            System.err.println("+ " + tin[v] + " " + tout[v] + " " + (-mul));
            st.add(0, 0, time - 1, tin[v], tout[v], -mul);
//            System.err.println("+ " + tin[u] + " " + tout[u] + " " + (-mul));
            st.add(0, 0, time - 1, tin[u], tout[u], -mul);
        }
    }

    class SegmentTree {
        int[] add;
        int[] numMins;
        int[] min;

        SegmentTree(int n) {
            add = new int[n * 4];
            numMins = new int[n * 4];
            min = new int[n * 4];
            build(0, 0, n - 1);
        }

        void build(int v, int l, int r) {
            numMins[v] = (r - l + 1);
            if (l != r) {
                int m = (l + r) >> 1;
                build(v * 2 + 1, l, m);
                build(v * 2 + 2, m + 1, r);
            }
        }

        int[] fake = new int[]{Integer.MAX_VALUE, 0};

        // min, cnt
        int[] getMin(int v, int l, int r, int needL, int needR) {
            if (needL == l && needR == r) {
                return new int[]{min[v] + add[v], numMins[v]};
            }
            if (needL > needR) {
                return fake;
            }
            int m = (l + r) >> 1;
            int[] left = getMin(v * 2 + 1, l, m, needL, Math.min(needR, m));
            int[] right = getMin(v * 2 + 2, m + 1, r, Math.max(needL, m + 1), needR);
            int newMin = Math.min(left[0], right[0]);
            int newCnt = 0;
            if (left[0] == newMin) {
                newCnt += left[1];
            }
            if (right[0] == newMin) {
                newCnt += right[1];
            }
            return new int[]{newMin, newCnt};
        }

        void add(int v, int l, int r, int needL, int needR, int addV) {
//            System.err.println("ADD " + needL + " " + needR + " " + addV);
            if (needL == l && needR == r) {
                add[v] += addV;
                return;
            }
            if (needL > needR) {
                return;
            }
            int m = (l + r) >> 1;
            add(v * 2 + 1, l, m, needL, Math.min(needR, m), addV);
            add(v * 2 + 2, m + 1, r, Math.max(needL, m + 1), needR, addV);
            min[v] = Math.min(min[v * 2 + 1] + add[v * 2 + 1], min[v * 2 + 2] + add[v * 2 + 2]);
            numMins[v] = 0;
            for (int it = 1; it < 3; it++) {
                if (min[v * 2 + it] + add[v * 2 + it] == min[v]) {
                    numMins[v] += numMins[v * 2 + it];
                }
            }
//            System.err.println(l + " " + r + ", min =  " + (min[v] + add[v]) + ", numMins = " + numMins[v]);
        }
    }


    final long MAGIC = (long) 1e9 + 7;

    long makeEdge(int u, int v) {
        return Math.min(u, v) * MAGIC + Math.max(u, v);
    }

    int time = 0;
    int[] tin, tout;
    int[][] up;
    int[] h;
    final int LOG = 20;

    SegmentTree st;

    void dfs(int v, int p, int curH) {
        h[v] = curH;
        tin[v] = time++;
        up[0][v] = p;
        for (int i = 0; i < g[v].size(); i++) {
            int to = g[v].get(i);
            if (to == p) {
                continue;
            }
            dfs(to, v, curH + 1);
        }
        tout[v] = time - 1;
    }

    boolean inside(int p, int v) {
        return tin[v] >= tin[p] && tout[v] <= tout[p];
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