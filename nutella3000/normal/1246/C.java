import java.io.*;
import java.util.*;

public class Main {
    static int mod = (int) 1e9 + 7;
    static int n, m, pref[][];
    static long suf1[][], suf2[][];
    static char h[][];

    static int cnt(int x1, int y1, int x2, int y2) {
        int ans = pref[x2][y2];
        if (x1 != 0) ans -= pref[x1 - 1][y2];
        if (y1 != 0) ans -= pref[x2][y1 - 1];
        if (y1 != 0 && x1 != 0) ans += pref[x1 - 1][y1 - 1];
        return ans;
    }

    static long sum(int x1, int y1, int x2, int y2, long suf[][]) {
        long ans = suf[x1][y1];
        if (x2 != n - 1) ans -= suf[x2 + 1][y1];
        if (y2 != m - 1) ans -= suf[x1][y2 + 1];
        if (x2 != n - 1 && y2 != m - 1) ans += suf[x2 + 1][y2 + 1];
        return (ans + 2 * mod) % mod;
    }

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        n = nextInt();
        m = nextInt();
        h = new char[n][m];
        for(int i = 0;i < n;i++) h[i] = next().toCharArray();
        pref = new int [n][m];
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                if (h[i][j] == 'R') pref[i][j] = 1;
                if (i != 0) pref[i][j] += pref[i - 1][j];
                if (j != 0) pref[i][j] += pref[i][j - 1];
                if (i != 0 && j != 0) pref[i][j] -= pref[i - 1][j - 1];
            }
        }

        suf1 = new long[n + 1][m + 1];
        suf2 = new long[n + 1][m + 1];
        long dp[][][] = new long[2][n][m];
        for(int i = n - 1;i >= 0;i--) {
            for(int j = m - 1;j >= 0;j--) {

                if (i == n - 1 || j == m - 1) {
                    if (h[i][j] != 'R') {
                        if (i == n - 1 && j == m - 1) {
                            dp[0][i][j] = 1;
                            dp[1][i][j] = 1;
                        }else if (j == m - 1) {
                            dp[0][i][j] = dp[0][i + 1][j];
                            dp[1][i][j] = dp[0][i + 1][j];
                        }else {
                            dp[0][i][j] = dp[1][i][j + 1];
                            dp[1][i][j] = dp[1][i][j + 1];
                        }
                    }
                } else {
                int o1 = cnt(i, j, n - 1, j);
                int o2 = cnt(i, j + 1, i, m - 1);

                dp[0][i][j] = sum(i + 1, j + 1, n - o1 - 1, j + 1, suf2) +
                        sum(i + 1, j + 1, i + 1, m - o2 - 1, suf1);

                o1 = cnt(i + 1, j, n - 1, j);
                o2 = cnt(i, j, i, m - 1);

                dp[1][i][j] = sum(i + 1, j + 1, n - o1 - 1, j + 1, suf2) +
                        sum(i + 1, j + 1, i + 1, m - o2 - 1, suf1);

                dp[0][i][j] %= mod;
                dp[1][i][j] %= mod;
                }

                suf1[i][j] = dp[0][i][j];
                if (i != n - 1) suf1[i][j] += suf1[i + 1][j];
                if (j != m - 1) suf1[i][j] += suf1[i][j + 1];
                if (i != n - 1 && j != m - 1) suf1[i][j] -= suf1[i + 1][j + 1];
                suf1[i][j] = (suf1[i][j] + 2 * mod) % mod;

                suf2[i][j] = dp[1][i][j];
                if (i != n - 1) suf2[i][j] += suf2[i + 1][j];
                if (j != m - 1) suf2[i][j] += suf2[i][j + 1];
                if (i != n - 1 && j != m - 1) suf2[i][j] -= suf2[i + 1][j + 1];
                suf2[i][j] = (suf2[i][j] + 2 * mod) % mod;
            }
        }
        /*for(int k = 0;k < 2;k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    pw.print(dp[k][i][j] + " ");
                }
                pw.println();
            }
            pw.println();
        }*/
        pw.println((dp[0][0][0]) % mod);
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

}