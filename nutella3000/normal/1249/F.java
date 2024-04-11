
import java.io.*;
import java.util.*;

public class Main {
    static long inf = (long) 1e15 + 7;
    static int n, k;
    static int dp[][], a[];
    static ArrayList<Integer> gr[];

    static void dfs(int v, int pr) {
        for (int i : gr[v]) if (i != pr) dfs(i, v);

        for (int i = k + 1; i > 0; i--) {
            for (int main : gr[v]) {
                int sum = 0;
                for (int j : gr[v]) {
                    if (j == pr) continue;
                    if (main == j) sum += dp[j][i - 1];
                    else sum += dp[j][Math.max(k - i, i - 1)];
                    //sum += dp[j][i - 1];
                }
                dp[v][i] = Math.max(dp[v][i], sum);
            }
            // k - i + 1;
            dp[v][i] = Math.max(dp[v][i], dp[v][i + 1]);
        }

        int sum = 0;
        for (int i : gr[v]) {
            if (i == pr) continue;
            sum += dp[i][k];
        }

        dp[v][0] = Math.max(dp[v][1], sum + a[v]);
    }

    public static void main(String[] args) throws IOException {
        sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        n = sc.nextInt();
        k = sc.nextInt();
        dp = new int[n][k + 3];
        gr = new ArrayList[n];
        for (int i = 0; i < n; i++) gr[i] = new ArrayList<>();
        a = new int[n];
        for (int i = 0; i < n; i++) a[i] = sc.nextInt();
        for (int i = 0; i < n - 1; i++) {
            int v1 = sc.nextInt() - 1;
            int v2 = sc.nextInt() - 1;
            gr[v1].add(v2);
            gr[v2].add(v1);
        }
        dfs(0, -1);

        pw.println(dp[0][0]);
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