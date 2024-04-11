import java.io.*;
import java.util.*;

public class Main {
    static int inf = (int) 1e9 + 7;

    static int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        int n = nextInt();
        int a[] = new int [n];
        for(int i = 0;i < n;i++) {
            a[i] = nextInt();
        }
        boolean good[][] = new boolean[n][n];
        boolean dp[][][] = new boolean[2][n][n];
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < i;j++) {
                dp[0][i][j] = true;
                dp[1][i][j] = true;
            }
        }

        for(int i = 0;i < n;i++) {
            for(int j = 0;j < n;j++) {
                good[i][j] = gcd(a[i], a[j]) > 1;
            }
        }

        for(int len = 1;len <= n;len++) {
            for(int l = 0;l < n;l++) {
                int r = l + len - 1;
                if (r >= n) continue;
                if (len == 1) {
                    if (l == 0 || good[l - 1][l]) dp[0][l][l] = true;
                    if (r == n - 1 || good[l][l + 1]) dp[1][l][l] = true;
                    continue;
                }

                for(int i = l;i <= r;i++) {
                    if (l == 0 || good[l - 1][i]) {
                        boolean u = true;
                        if (i != l) u &= dp[1][l][i - 1];
                        if (i != r) u &= dp[0][i + 1][r];
                        if (u) dp[0][l][r] = true;
                    }
                }

                for(int i = l;i <= r;i++) {
                    if (r == n - 1 || good[r + 1][i]) {
                        boolean u = true;
                        if (i != l) u &= dp[1][l][i - 1];
                        if (i != r) u &= dp[0][i + 1][r];
                        if (u) dp[1][l][r] = true;
                    }
                }
            }
        }

        if (dp[0][0][n - 1] || dp[1][0][n - 1]) pw.println("Yes");
        else pw.println("No");
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