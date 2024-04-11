import java.io.*;
import java.math.BigInteger;
import java.util.*;


public class Main {
    static int inf = (int) 1e9 + 7;
    static int n;
    static ArrayList<Integer> gr[];
    static ArrayList<Integer> c[];

    static int sz[];
    static long dp1[], dp2[], cnt[];

    static void dfs(int v, int pr) {
        sz[v] = 1;
        for(int to : gr[v]) {
            if (to == pr) continue;
            dfs(to, v);
            sz[v] += sz[to];
        }


        for(int u = 0;u < gr[v].size();u++) {
            int to = gr[v].get(u);
            int cost = c[v].get(u);
            if (to == pr) continue;
            if (sz[to] % 2 == 1) dp1[v] += cost;
            dp1[v] += dp1[to];
        }

        cnt[v]++;

        for(int u = 0;u < gr[v].size();u++) {
            int to = gr[v].get(u);
            int cost = c[v].get(u);
            if (to == pr) continue;

            cnt[v] += cnt[to];
            dp2[v] += dp2[to] + cnt[to] * cost;
        }

        int other = n - sz[v];
        cnt[v] = Math.min(cnt[v], other);
    }

    public static void main(String[] args) throws IOException {
        sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        for(int t = sc.nextInt();t > 0;t--) {
            n = 2 * sc.nextInt();
            gr = new ArrayList[n];
            c = new ArrayList[n];
            sz = new int [n];
            dp1 = new long [n];
            dp2 = new long [n];
            cnt = new long [n];
            for(int i = 0;i < n;i++) {
                gr[i] = new ArrayList<>();
                c[i] = new ArrayList<>();
            }

            for(int i = 0;i < n - 1;i++) {
                int v1 = sc.nextInt() - 1;
                int v2 = sc.nextInt() - 1;
                int cost = sc.nextInt();
                gr[v1].add(v2);
                gr[v2].add(v1);
                c[v1].add(cost);
                c[v2].add(cost);
            }

            dfs(0, -1);

            pw.println(dp1[0] + " " + dp2[0]);
        }

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