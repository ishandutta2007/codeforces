import java.io.*;
import java.util.*;

public class Main {
    static long inf = (long) 1e12;
    static int n;
    static polygon region[];
    static ArrayList<Integer> gr[];
    static int ans[];

    static class solve1 {
        static int sz;
        static point edge[];

        static int compare(point o1, point o2) {
            return Integer.compare((o1.r - o1.l + sz) % sz, (o2.r - o2.l + sz) % sz);
        }

        static void scan() throws IOException {
            sz = nextInt();
            n = nextInt();
            edge = new point[n];
            for(int i = 0;i < n;i++) {
                int v1 = nextInt() - 1;
                int v2 = nextInt() - 1;
                int var1 = (v2 - v1 + sz) % sz;
                int var2 = (v1 - v2 + sz) % sz;
                if (var2 < var1) {
                    int t = v1;
                    v1 = v2;
                    v2 = t;
                }
                edge[i] = new point(v1, v2);
            }
            Arrays.sort(edge, solve1::compare);
        }

        static void build_reg1() {
            region = new polygon[n + 1];

            dsu out = new dsu(sz);

            ArrayList<Integer> dis = new ArrayList<>();

            for(int i = 0;i < n;i++) {
                int l = edge[i].l;
                int r = edge[i].r;
                dis.add(l);

                int v = out.get((l + 1) % sz);

                while(v < r || (l > r && v >= l)) {
                    dis.add(v);
                    out.union(v, (v + 1) % sz);
                    v = out.get(v);
                }
                dis.add(v);
                region[i] = new polygon(0, dis);
                dis.clear();
            }

            int v = 0;
            while(true) {
                if (out.get(v) < v) break;
                v = out.get(v);

                dis.add(v);
                v = (v + 1) % sz;
                if (v == 0) break;
            }

            region[n] = new polygon(0, dis);

        }

        static void build_reg2() {
            n++;
            triple a[] = new triple[n];

            for(int i = 0;i < n;i++) {
                a[i] = new triple(0, 0, 0, i);
                for(int j : region[i].x) {
                    if (a[i].x < j) {
                        a[i].z = a[i].y;
                        a[i].y = a[i].x;
                        a[i].x = j;

                    }else if (a[i].y < j) {
                        a[i].z = a[i].y;
                        a[i].y = j;

                     }else{
                        a[i].z = j;
                    }
                }
            }

            Arrays.sort(a, new triple());

            for(int i = 0;i < n;i++)
                region[a[i].id].id = i;

        }

    }

    static class solve2 {
        static void build_gr() {
            gr = new ArrayList[n];
            for(int i = 0;i < n;i++) gr[i] = new ArrayList<>();
            TreeMap<point, Integer> var = new TreeMap<>(new point());

            for(int i = 0;i < n;i++) {
                for(int j = 0;j < region[i].n;j++) {
                    int v = region[i].x[j];
                    int to = region[i].x[(j + 1) % region[i].n];

                    if (v > to) {
                        int t = v;
                        v = to;
                        to = t;
                    }

                    int id = region[i].id;

                    point var1 = new point(v, to);

                    if (var.containsKey(var1)) {
                        gr[id].add(var.get(var1));
                        gr[var.get(var1)].add(id);
                    }else{
                        var.put(var1, id);
                    }
                }
            }
        }
    }

    static class solve3 {
        static boolean used[];
        static int sz[];

        static void build_sz(int v, int pr) {
            sz[v] = 1;
            for(int i : gr[v]) {
                if (i != pr && !used[i]) {
                    build_sz(i, v);
                    sz[v] += sz[i];
                }
            }
        }

        static int find_dec(int v, int pr, int size) {
            for(int i : gr[v]) {
                if (i == pr || used[i]) continue;
                if (sz[i] * 2 > size) return find_dec(i, v, size);
            }
            return v;
        }

        static void solve() {
            ans = new int [n];
            sz = new int [n];
            used = new boolean[n];
            all_dec(0, 1);
        }

        static void all_dec(int st, int col) {
            build_sz(st, -1);
            int mid = find_dec(st, -1, sz[st]);

            ans[mid] = col;
            used[mid] = true;

            for(int i : gr[mid]) {
                if (!used[i]) {
                    all_dec(i, col + 1);
                }
            }
        }

    }

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        solve1.scan();
        solve1.build_reg1();
        solve1.build_reg2();
        solve2.build_gr();
        solve3.solve();

        for(int i : ans) pw.print(i + " ");
        pw.close();
    }

    static BufferedReader br;
    static StringTokenizer st = new StringTokenizer("");
    static PrintWriter pw;

    static String next() throws IOException {
        while (!st.hasMoreTokens()) st = new StringTokenizer(br.readLine());
        return st.nextToken();
    }

    static int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    static long nextLong() throws IOException {
        return Long.parseLong(next());
    }

}

class point implements Comparator<point>{
    int l, r;
    point(int x, int y) {
        this.l = x;
        this.r = y;
    }

    point() {}

    @Override
    public int compare(point o1, point o2) {
        return Integer.compare(o1.l, o2.l) * 2 + Integer.compare(o1.r, o2.r);
    }
}

class dsu {
    int parent[];

    dsu(int n) {
        parent = new int [n];
        for(int i = 0;i < n;i++) parent[i] = i;
    }

    int get(int v) {
        if (v == parent[v]) return v;
        return parent[v] = get(parent[v]);
    }

    void union(int a, int b) {
        parent[get(a)] = get(b);
    }
}

class polygon {
    int id, n, x[];
    polygon (int id, ArrayList<Integer> a) {
        n = a.size();
        x = new int [n];
        for(int i = 0;i < n;i++) x[i] = a.get(i);
        this.id = id;
    }

    polygon() {}
}

class triple implements Comparator<triple>{
    int x, y, z, id;
    triple (int x, int y, int z, int id) {
        this.x = x;
        this.y = y;
        this.z = z;
        this.id = id;
    }

    triple() {}

    @Override
    public int compare(triple o1, triple o2) {
        return Integer.compare(o1.x, o2.x) * 4 + Integer.compare(o1.y, o2.y) * 2 + Integer.compare(o1.z, o2.z);
    }
}