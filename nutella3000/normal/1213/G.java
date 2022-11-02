import java.io.*;
import java.util.*;


public class Main {
    static int inf = (int) (1e9 + 7);
    static int n;
    static ArrayList<edge> gr[];
    static boolean killed[];
    static int sz[];
    static long pair_cnt[];

    static void build_sz(int v, int pr) {
        sz[v] = 1;
        for(edge to : gr[v]) {
            if (to.to != pr && !killed[to.to]) {
                build_sz(to.to, v);
                sz[v] += sz[to.to];
            }
        }
    }

    static int find_centroid(int v, int pr, int size) {
        for(edge to : gr[v]) {
            if (to.to == pr || killed[to.to]) continue;
            if (sz[to.to] > size / 2) return find_centroid(to.to, v, size);
        }
        return v;
    }


    static int comp[];
    static int cnt[];
    static int max[];

    static ArrayList<Integer> all = new ArrayList<>();

    static void dfs(int v, int pr, int ma, int com) {
        if (com != -1) {
            comp[v] = com;
            max[v] = ma;
            cnt[com]++;
            all.add(v);
        }

        for(edge to : gr[v]) {
            if (to.to == pr || killed[to.to]) continue;
            dfs(to.to, v, Math.max(ma, to.cost), (com == -1 ? to.to : com));
        }
    }



    static void centre(int start) {
        build_sz(start, -1);
        int root = find_centroid(start, -1, sz[start]);

        //
        dfs(root, -1, 0, -1);

        for(int i : all) {
            pair_cnt[max[i]]++;
        }

        int all_cnt = 0;
        for(edge i : gr[root]) {
            if (!killed[i.to]) all_cnt += cnt[i.to];
        }

        Collections.sort(all, new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                return -Integer.compare(max[o1], max[o2]);
            }
        });

        for(int i : all) {
            pair_cnt[max[i]] += (all_cnt - cnt[comp[i]]);
            cnt[comp[i]]--;
            all_cnt--;
        }

        all.clear();
        //

        killed[root] = true;
        for(edge to : gr[root]) {
            if (!killed[to.to]) centre(to.to);
        }
    }

    static void solve() throws IOException {
        n = sc.nextInt();
        int m = sc.nextInt();


        gr = new ArrayList[n];
        for(int i = 0;i < n;i++) gr[i] = new ArrayList<>();
        killed = new boolean[n];
        sz = new int [n];
        pair_cnt = new long[200001];
        comp = new int [n];
        cnt = new int [n];
        max = new int [n];

        for(int i = 0;i < n - 1;i++) {
            int v1 = sc.nextInt() - 1;
            int v2 = sc.nextInt() - 1;
            int w = sc.nextInt();

            gr[v1].add(new edge(v2, w));
            gr[v2].add(new edge(v1, w));
        }

        centre(0);

        for(int i = 1;i <= 200000;i++) pair_cnt[i] += pair_cnt[i - 1];

        for(int i = 0;i < m;i++) {
            pw.print(pair_cnt[sc.nextInt()] + " ");
        }
    }

    public static void main(String[] args) throws IOException {
        sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        solve();
        pw.close();
    }

    static Scanner sc;
    static PrintWriter pw;

    static class Scanner {
        BufferedReader br;
        StringTokenizer st = new StringTokenizer("");

        Scanner(InputStream in) throws FileNotFoundException {
            br = new BufferedReader(new InputStreamReader(in));
        }

        Scanner(String in) throws FileNotFoundException {
            br = new BufferedReader(new FileReader(in));
        }

        String next() throws IOException {
            while (!st.hasMoreTokens()) st = new StringTokenizer(br.readLine());
            return st.nextToken();
        }

        int nextInt() throws IOException {
            return Integer.parseInt(next());
        }

        long nextLong() throws IOException {
            return Long.parseLong(next());
        }

        double nextDouble() throws IOException {
            return Double.parseDouble(next());
        }
    }

}

class edge {
    int to, cost;
    edge(int to, int cost) {
        this.to = to;
        this.cost = cost;
    }

    edge() {}
}