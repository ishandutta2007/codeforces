import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;


public class Main {
    static int mod = (int) 1e9 + 7;
    static int base = (int)1e4 + 1;
    static int max_m = base * 2;
    static int n, a[];

    static void solve() throws IOException {
        n = sc.nextInt();
        a = new int [n];
        for(int i = 0;i < n;i++) a[i] = sc.nextInt();
        long ans = 0;
        long dp[][] = new long [n][max_m];
        dp[0][base + a[0]] = 1;
        dp[0][base - a[0]] = 1;
        for(int i = 0;i < n;i++) {
            ans += dp[i][base];
            dp[i][base]++;

            if (i == n - 1) break;

            for(int j = 0;j < max_m;j++) {
                if (j - a[i + 1] >= 0) dp[i + 1][j - a[i + 1]] += dp[i][j];
                if (j + a[i + 1] < max_m) dp[i + 1][j + a[i + 1]] += dp[i][j];
            }

            for(int j = 0;j < max_m;j++) {
                dp[i + 1][j] %= mod;
            }
        }

        pw.println(ans % mod);
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
    int x, y, id;
    pair(int x, int y, int id) {
        this.x = x;
        this.y = y;
        this.id = id;
    }

    pair() {}
}