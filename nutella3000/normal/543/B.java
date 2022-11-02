import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;


public class Main {
    static int inf = (int) 1e9 + 7;
    static int n, m, dist[][];
    static int s[], t[], l[];
    static ArrayList<Integer> gr[];

    static void scan() throws IOException {
        n = sc.nextInt();
        m = sc.nextInt();
        gr = new ArrayList[n];
        for(int i = 0;i < n;i++) gr[i] = new ArrayList<>();
        for(int i = 0;i < m;i++) {
            int v1 = sc.nextInt() - 1;
            int v2 = sc.nextInt() - 1;
            gr[v1].add(v2);
            gr[v2].add(v1);
        }
        s = new int [2];
        t = new int [2];
        l = new int [2];
        for(int i = 0;i < 2;i++) {
            s[i] = sc.nextInt() - 1;
            t[i] = sc.nextInt() - 1;
            l[i] = sc.nextInt();
        }


        dist = new int [n][n];

        for(int start = 0;start < n;start++) {
            ArrayDeque<Integer> bfs = new ArrayDeque<>();
            bfs.add(start);
            for(int i = 0;i < n;i++) dist[start][i] = inf;
            dist[start][start] = 0;
            while(!bfs.isEmpty()) {
                int v = bfs.pollFirst();
                for(int to : gr[v]) {
                    if (dist[start][to] > dist[start][v] + 1) {
                        dist[start][to] = dist[start][v] + 1;
                        bfs.add(to);
                    }
                }
            }
        }
    }

    static int solve1() {
        int ans = 0;

        for(int i = 0;i < 2;i++) {
            if (dist[s[i]][t[i]] > l[i]) ans = inf;
            else ans += dist[s[i]][t[i]];
        }

        for(int i = 0;i < n;i++) {
            for(int j = 0;j < n;j++) {
                int new_ans = 0;
                for(int k = 0;k < 2;k++) {
                    int temp = dist[s[k]][i] + dist[i][j] + dist[j][t[k]];
                    if (temp > l[k]) new_ans += inf;
                    else new_ans += temp;
                }
                new_ans -= dist[i][j];
                ans = Math.min(ans, new_ans);
            }
        }
        return ans;
    }

    static int solve2() {
        int ans = solve1();
        int t1 = s[0];
        s[0] = t[0];
        t[0] = t1;
        ans = Math.min(ans, solve1());
        return ans;
    }

    static void solve() throws IOException {
        scan();
        int ans = solve2();
        if (ans == inf) pw.println(-1);
        else pw.println(m - ans);
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