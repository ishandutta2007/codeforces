import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;


public class Main {
    static int inf = (int) 1e9 + 7;



    static void solve() throws IOException {
        int n = sc.nextInt();
        int h = sc.nextInt();
        int a[] = new int [n];
        for(int i = 0;i < n;i++) a[i] = sc.nextInt();

        long dp[][] = new long [n][n + 1];

        if (a[0] == h) dp[0][0]++;
        if (a[0] + 1 == h) dp[0][0]++;
        if (a[0] + 1 == h) dp[0][1]++;

        for(int i = 1;i < n;i++) {
            for(int j = 0;j <= n;j++) {
                if (a[i] + j == h) {
                    dp[i][j] += dp[i - 1][j];
                    if (j != 0) dp[i][j] += dp[i - 1][j - 1];
                }

                if (a[i] + j + 1 == h) {
                    if (j != n) {
                        dp[i][j] += (j + 1) * dp[i - 1][j + 1];
                    }
                    dp[i][j] += (j + 1) * dp[i - 1][j];
                }

                dp[i][j] %= inf;
            }
        }

        pw.println(dp[n - 1][0]);
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
    long x, y;
    pair(long x, long y) {
        this.x = x;
        this.y = y;
    }

    pair() {}
}