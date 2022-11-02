import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;


public class Main {
    static int inf = (int) 1e9 + 7;
    static int n;
    static ArrayList<Integer> gr[];
    static int predki[][], dist[];

    static void build(int v, int pr) {
        dist[v] = dist[pr] + 1;
        predki[v][0] = pr;
        for(int i = 1;i < 20;i++) predki[v][i] = predki[predki[v][i - 1]][i - 1];

        for(int i : gr[v]) {
            if (i != pr) build(i, v);
        }
    }

    static void scan() throws IOException {
        n = sc.nextInt();
        gr = new ArrayList[n];
        for(int i = 0;i < n;i++) gr[i] = new ArrayList<>();
        predki = new int[n][20];
        dist = new int [n];
        for(int i = 0;i < n - 1;i++) {
            int v = sc.nextInt() - 1;
            int u = sc.nextInt() - 1;
            gr[v].add(u);
            gr[u].add(v);
        }
        dist[0] = -1;
        build(0, 0);
    }

    static int lca(int v, int u) {
        for(int k = 19;k >= 0;k--) {
            if (dist[v] - (1 << k) >= dist[u]) v = predki[v][k];
            if (dist[u] - (1 << k) >= dist[v]) u = predki[u][k];
        }

        for(int k = 19;k >= 0;k--) {
            if (predki[v][k] != predki[u][k]) {
                v = predki[v][k];
                u = predki[u][k];
            }
        }
        if (v == u) return v;
        return predki[v][0];
    }

    static int dist(int v, int u) {
        int lca = lca(v, u);
        return dist[v] + dist[u] - 2 * dist[lca];
    }

    static boolean get(int x, int y, int a, int b, int time) {
        int first = dist(a, x) + 1 + dist(y, b);
        int second = dist(a, y) + 1 + dist(x, b);
        int third = dist(a, b);
        if (first % 2 == time % 2 && first <= time) return true;
        if (second % 2 == time % 2 && second <= time) return true;
        if (third % 2 == time % 2 && third <= time) return true;
        return false;
    }
    static void solve() throws IOException {
        scan();

        for(int q = sc.nextInt();q > 0;q--) {
            int x = sc.nextInt() - 1;
            int y = sc.nextInt() - 1;
            int a = sc.nextInt() - 1;
            int b = sc.nextInt() - 1;
            int time = sc.nextInt();
            if (get(x, y, a, b, time)) pw.println("YES");
            else pw.println("NO");
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

class pair implements Comparator<pair>{
    int t, l, r;
    pair(int t, int l, int r) {
        this.t = t;
        this.l = l;
        this.r = r;
    }
    pair() {}
    @Override
    public int compare(pair pair, pair t1) {
        return Integer.compare(pair.t, t1.t);
    }
}