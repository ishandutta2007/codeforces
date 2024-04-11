import java.io.*;
import java.util.*;

public class Main {
    static int inf = (int) 1e9 + 7;
    static int n;
    static ArrayList<Integer> gr[], num[], dp1[];
    static int dp2[];
    static int dp[];

    static void scan() throws IOException {
        n = nextInt();
        gr = new ArrayList[n];
        num = new ArrayList[n];
        dp1 = new ArrayList[n];
        dp2 = new int [n];
        dp = new int [n];
        for(int i = 0;i < n;i++) {
            gr[i] = new ArrayList<>();
            num[i] = new ArrayList<>();
            dp1[i] = new ArrayList<>();
            int v = nextInt();
            for(int d = 2;d <=  Math.sqrt(v);d++) {
                while(v % d == 0) {
                    num[i].add(d);
                    v /= d;
                }
            }
            if (v != 1) num[i].add(v);
        }

        for(int i = 0;i < n - 1;i++) {
            int v1 = nextInt() - 1;
            int v2 = nextInt() - 1;
            gr[v1].add(v2);
            gr[v2].add(v1);
        }
    }

    static int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    static void dfs(int v, int pr) {
        if (v == 0) {
            for (int i = 0; i < num[0].size(); i++) dp1[v].add(-1);
        }else{
            for(int i : dp1[pr]) dp1[v].add(i);
            int id1 = 0;
            int id2 = 0;
            while(id1 < num[0].size()) {
                if (id2 < num[v].size() && num[0].get(id1).equals(num[v].get(id2))) {
                    id1++;
                    id2++;
                }else if (id2 < num[v].size() && num[v].get(id2).compareTo(num[0].get(id1)) < 0) {
                    id2++;
                }else{
                    if (dp1[v].get(id1) == -1) {
                        dp1[v].set(id1, v);
                    }else dp1[v].set(id1, inf);
                    id1++;
                }
            }
        }

        int ans = 1;
        for(int i = 0;i < dp1[v].size();i++) {
            if (dp1[v].get(i) == -1) ans *= num[0].get(i);
        }

        for(int i = 0;i < dp1[v].size();i++) {
            if (dp1[v].get(i) != -1 && !dp1[v].get(i).equals(inf)) {
                int var = ans;
                for(int j = i;j < dp1[v].size();j++) if (dp1[v].get(j).equals(dp1[v].get(i))) var *= num[0].get(j);
                dp[v] = Math.max(var, dp[v]);
            }
        }
        dp[v] = Math.max(dp[v], ans);

        if (pr == 0) {
            dp2[v] = 1;
            for(int i : num[v]) dp2[v] *= i;
        }else if (v != 0) {
            dp2[v] = 1;
            for(int i : num[v]) dp2[v] *= i;
            dp2[v] = gcd(dp2[pr], dp2[v]);
        }

        for(int i : gr[v]) {
            if (i != pr) dfs(i, v);
        }
    }

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        scan();
        dfs(0, -1);

        for(int i = 0;i < n;i++) {
            pw.print(Math.max(dp[i], dp2[i]) + " ");
        }
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

    static double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }
}