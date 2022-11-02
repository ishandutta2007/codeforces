import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;


public class Main {
    static int inf = (int) 1e9 + 7;
    static int n, log_n = 20;
    static ArrayList<Integer> gr[];
    static int dist[], size[], predki[][];

    static void scan() throws IOException {
        n = sc.nextInt();
        dist = new int [n];
        size = new int [n];
        predki = new int [log_n][n];
        gr = new ArrayList[n];
        for(int i = 0;i < n;i++) gr[i] = new ArrayList<>();
        for(int i = 0;i < n - 1;i++) {
            int v1 = sc.nextInt() - 1;
            int v2 = sc.nextInt() - 1;
            gr[v1].add(v2);
            gr[v2].add(v1);
        }
    }

    static void dfs(int v, int pr) {
        dist[v] = dist[pr] + 1;

        predki[0][v] = pr;
        for(int i = 1;i < log_n;i++)
            predki[i][v] = predki[i - 1][predki[i - 1][v]];

        size[v] = 1;


        for(int i = 0;i < gr[v].size();i++) {
            if (gr[v].get(i) == pr) {
                gr[v].remove(i);
                break;
            }
        }

        for(int to : gr[v]) {
            dfs(to, v);
            size[v] += size[to];
        }
    }

    static int up(int v, int dist) {
        for(int k = log_n - 1;k >= 0;k--) {
            if ((1 << k) < dist) {
                dist -= (1 << k);
                v = predki[k][v];
            }
        }

        int c = v;
        v = predki[0][v];

        int ans = size[v] - size[c];
        return ans;
    }


    static int solve(int v1, int v2) {
        int to1 = v1, to2 = v2;

        for(int k = log_n - 1;k >= 0;k--) {
            if (dist[to1] - (1 << k) >= dist[to2]) {
                to1 = predki[k][to1];
            }
        }

        for(int k = log_n - 1;k >= 0;k--) {
            if (dist[to2] - (1 << k) >= dist[to1]) {
                to2 = predki[k][to2];
            }
        }

        for(int k = log_n - 1;k >= 0;k--) {
            if (predki[k][to1] != predki[k][to2]) {
                to1 = predki[k][to1];
                to2 = predki[k][to2];
            }
        }
        int lca = to1;
        if (to1 != to2) lca = predki[0][to1];
        if (dist[v1] == dist[v2]) {
            int ans = n - size[to1] - size[to2];
            if (to1 == to2) ans = n;

            return ans;
        }


        if (dist[v1] % 2 != dist[v2] % 2) return 0;

        int temp = Math.abs(dist[v1] - dist[v2]) / 2 + Math.min(dist[v1], dist[v2]) - dist[lca];

        if (dist[v1] > dist[v2]) return up(v1, temp);
        return up(v2, temp);
    }

    static void solve() throws IOException {
        scan();
        dist[0] = -1;
        dfs(0, 0);

        for(int q = sc.nextInt();q > 0;q--) {
            int v1 = sc.nextInt() - 1;
            int v2 = sc.nextInt() - 1;
            pw.println(solve(v1, v2));
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

class pair {
    int l, r, id;
    pair(int l, int r, int id) {
        this.l = l;
        this.r = r;
        this.id = id;
    }
    pair() {}
}