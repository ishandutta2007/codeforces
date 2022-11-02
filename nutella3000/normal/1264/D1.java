import java.io.*;
import java.math.BigDecimal;
import java.math.MathContext;
import java.math.RoundingMode;
import java.util.*;


public class Main {
    static char h[];
    static int n;
    static int mod = 998244353;
    static long cnt[][], dp[][];

    static void f(int l, int r) {
        if (r - l + 1 <= 2) {
            if (h[l] != ')' && h[r] != '(') dp[l][r]++;
        }else {
            if (h[l] != '(') dp[l][r] += dp[l + 1][r];
            if (h[r] != ')') dp[l][r] += dp[l][r - 1];
            if (h[l] != '(' && h[r] != ')') dp[l][r] -= dp[l + 1][r - 1];
            if (h[l] != ')' && h[r] != '(') dp[l][r] += dp[l + 1][r - 1] + cnt[l + 1][r - 1];
        }
        dp[l][r] %= mod;
    }

    static void build_cnt() {
        cnt = new long [n][n];

        for(int len = 1;len <= n;len++) {
            for(int l = 0;l < n;l++) {
                int r = l + len - 1;
                if (r >= n) continue;

                if (len == 1) {
                    cnt[l][r] = (h[l] == '?' ? 2 : 1);
                }else{
                    if (h[l] == '?') cnt[l][r] = (cnt[l + 1][r] * 2) % mod;
                    else cnt[l][r] = cnt[l + 1][r];
                }
            }
        }
    }

    static void build_dp() {
        dp = new long [n][n];
        for(int len = 1;len <= n;len++) {
            for(int l = 0;l < n;l++) {
                int r = l + len - 1;
                if (r >= n) continue;

                if (len == 1) continue;

                f(l, r);
            }
        }

    }




    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        h = next().toCharArray();
        n = h.length;

        build_cnt();

        build_dp();

            /*for(int i = 0;i < n;i++) {
                for(int j = i;j < n;j++) {
                    pw.println(i + 1 + " " + (j + 1) + ": " + dp[i][j]);
                }
            }
    */
        pw.println(dp[0][n - 1]);

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


// ((( 0
// (() 1
// ()( 1
// ()) 1
// )(( 0
// )() 1
// ))( 0
// )))

// ( (