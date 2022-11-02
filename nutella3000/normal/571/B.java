import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;


public class Main {
    static int inf = (int) 1e9 + 7;
    static int n, k, a[];

    static void scan() throws IOException {
        n = sc.nextInt();
        k = sc.nextInt();
        a = new int [n];
        for(int i = 0;i < n;i++) a[i] = sc.nextInt();
        Arrays.sort(a);
    }

    static void solve() throws IOException {
        scan();

        long dp[][] = new long[k + 1][k + 1];
        for(int i = 1;i < k;i++) dp[0][i] = 2 * inf;

        for(int i = 1;i <= k;i++) {
            for(int j = 0;j < k;j++) {
                int fin = i * (n / k) + j - 1;
                if (fin >= n) continue;

                long ans1 = dp[i - 1][j] + a[fin] - a[fin - n / k + 1];
                long ans2 = 2 * inf;
                if (j != 0) ans2 = dp[i - 1][j - 1] + a[fin] - a[fin - n / k];

                dp[i][j] = Math.min(ans1, ans2);
            }
        }

        pw.println(dp[k][n % k]);
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