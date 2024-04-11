import java.io.*;
import java.util.*;

/**
 * @author Pavel Mavrin
 */
public class D {

    private static final int BUBEN = 500;
    private static final int SIZE = 10000000;
    private int mapSize;

    public D() throws FileNotFoundException {
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
//        br = new BufferedReader(new FileReader("input.txt"));
//        out = new PrintWriter("output.txt");
    }

    private void solve() throws IOException {
        int n = nextInt();
        int m = nextInt();
        List<Edge>[] byCol = new List[m];
        for (int i = 0; i < m; i++) {
            int x = nextInt() - 1;
            int y = nextInt() - 1;
            int c = nextInt() - 1;
            if (byCol[c] == null) {
                byCol[c] = new ArrayList<Edge>();
            }
            byCol[c].add(new Edge(x, y));
        }
        Arrays.sort(byCol, new Comparator<List<Edge>>() {
            public int compare(List<Edge> o1, List<Edge> o2) {
                int a = o1 == null ? 0 : o1.size();
                int b = o2 == null ? 0 : o2.size();
                return Integer.compare(a, b);
            }
        });
        init(n, BUBEN);
        int[] r = new int[2 * BUBEN];
        int rn;
        Map<Pair, Integer> small = new HashMap<Pair, Integer>();
        List<int[]> big = new ArrayList<int[]>();
        int cc = 0;
        for (List<Edge> edges : byCol) {
            if (edges == null) continue;
            if (edges.size() < BUBEN) {
                rn = 0;
                for (Edge edge : edges) {
                    r[rn++] = edge.x;
                    r[rn++] = edge.y;
                }
                reinit(r, rn);
                for (Edge edge : edges) {
                    addEdge(edge.x, edge.y);
                }
                for (int i = 0; i < rn; i++) {
                    int x = r[i];
                    if (!z[x]) {
                        pn = 0;
                        dfs(x);
                        for (int ii = 0; ii < pn; ii++) {
                            for (int jj = ii + 1; jj < pn; jj++) {
//                                Pair pair = new Pair(p[ii], p[jj]);
                                cc++;
                                add(p[ii], p[jj]);
//                                Integer q = small.get(pair);
//                                if (q == null) {
//                                    small.put(pair, 1);
//                                } else {
//                                    small.put(pair, q + 1);
//                                }
                            }
                        }
                    }
                }
            } else {
                int[] p = new int[n];
                for (int i = 0; i < n; i++) {
                    p[i] = i;
                }
                for (Edge edge : edges) {
                    join(p, edge.x, edge.y);
                }
                big.add(p);
            }
        }
        int q = nextInt();
        for (int i = 0; i < q; i++) {
            int u = nextInt() - 1;
            int v = nextInt() - 1;
            int res = get(u, v);
            for (int[] p : big) {
                if (get(p, u) == get(p, v)) {
                    res++;
                }
            }
            out.println(res);
        }
//        System.out.println(cc);
//        System.out.println(big.size() + " " + small.size());
//        System.out.println(MemoryUsage.);
    }

    Random random = new Random();

    private void join(int[] p, int x, int y) {
        x = get(p, x);
        y = get(p, y);
        if (random.nextBoolean()) p[x] = y;
        else p[y] = x;
    }

    private int get(int[] p, int x) {
        if (p[x] == x) return x;
        p[x] = get(p, p[x]);
        return p[x];
    }

    int[] ww = new int[SIZE];
    int[] zz = new int[SIZE];

    void add(int u, int v) {
        if (u > v) {
            int t = u; u = v; v = t;
        }
        int h = hash(u, v);
        int h2 = hash2(u, v);
        while (ww[h] != 0) {
            if (ww[h] == h2) {
                zz[h]++;
                return;
            }
            h++;
            if (h == SIZE) h = 0;
        }
        ww[h] = h2;
        mapSize++;
        if (mapSize > SIZE * 0.8) throw new RuntimeException();

        zz[h] = 1;
    }

    int get(int u, int v) {
        if (u > v) {
            int t = u; u = v; v = t;
        }
        int h = hash(u, v);
        int h2 = hash2(u, v);
        while (ww[h] != 0) {
            if (ww[h] == h2) {
                return zz[h];
            }
            h++;
            if (h == SIZE) h = 0;
        }
        return 0;
    }

    private int hash(int u, int v) {
        return ((u * 239 + v) * 239) % SIZE;
    }

    private int hash2(int u, int v) {
        return ((u * 239239 + v) * 239239);
    }


    class Pair {
        int x, y;

        public Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;

            Pair pair = (Pair) o;

            if (x != pair.x) return false;
            if (y != pair.y) return false;

            return true;
        }

        @Override
        public int hashCode() {
            int result = x;
            result = 31 * result + y;
            return result;
        }
    }

    class Edge {
        int x, y;

        public Edge(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    void init(int n, int m) {
        m *= 2;
        this.n = n;
        this.m = m;
        last = 0;
        head = new int[n];
        nx = new int[m];
        dst = new int[m];
        Arrays.fill(head, -1);
        z = new boolean[n];
        p = new int[n];
    }

    void reinit(int[] r, int rn) {
        for (int i = 0; i < rn; i++) {
            head[r[i]] = -1;
            z[r[i]] = false;
        }
        last = 0;
    }

    void addEdge(int x, int y) {
        nx[last] = head[x];
        dst[last] = y;
        head[x] = last;
        last++;
        nx[last] = head[y];
        dst[last] = x;
        head[y] = last;
        last++;
    }


    private void dfs(int x) {
        if (z[x]) return;
        p[pn++] = x;
        z[x] = true;
        int j = head[x];
        while (j >= 0) {
            int y = dst[j];
            dfs(y);
            j = nx[j];
        }
    }


    int n, m;
    int[] head;
    int[] nx;
    int[] dst;
    boolean[] z;
    int last;
    int[] p;
    int pn;

    BufferedReader br;
    PrintWriter out;

    StringTokenizer st;

    String next() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return st.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    public static void main(String[] args) throws IOException {
        new D().run();
    }

    private void run() throws IOException {
        solve();
        out.close();
    }

}