import java.io.*;
import java.lang.reflect.Array;
import java.util.*;

public class Main {
    static int inf = 998244353;
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        int n = nextInt();
        int m = nextInt();
        int mod = inf;
        int c[] = new int [n];
        for(int i = 0;i < n;i++) c[i] = nextInt();
        long dp[][] = new long [n][n];
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < n;j++) dp[i][j] = 1;
        }
        for(int len = 2;len <= n;len++) {
            for(int l = 0;l < n;l++) {
                int r = (l + len - 1);
                if (r >= n) break;
                int id = -1;
                int min = inf;
                for(int i = l;i <= r;i++) {
                    if (min > c[i]) {
                        min = c[i];
                        id = i;
                    }
                }
                long left = 0;
                for(int i = l;i <= id;i++) {
                    int i1 = Math.max(i - 1, l);
                    int id1 = Math.max(id - 1, i);
                    left += (dp[l][i1] * dp[i][id1]) % mod;
                }
                left %= mod;
                dp[l][r] = 0;
                for(int i = id;i <= r;i++) {
                    int i1 = Math.min(i + 1, r);
                    int id1 = Math.min(id + 1, i);
                    long right = (dp[id1][i] * dp[i1][r]) % mod;
                    dp[l][r] = (dp[l][r] + right * left) % mod;
                }
            }
        }
        pw.println(dp[0][n - 1]);
        pw.close();
    }

    static BufferedReader br;

    static StringTokenizer st = new StringTokenizer("");
    static PrintWriter pw;
    /*static String next() throws IOException {
        int c = br.read();
        while (Character.isWhitespace(c)) c = br.read();
        StringBuilder sb = new StringBuilder();
        while (!Character.isWhitespace(c)) {
            sb.appendCodePoint(c);
            c = br.read();
        }
        return sb.toString();
    }*/

    static String next() throws IOException {
        if (!st.hasMoreTokens()) st = new StringTokenizer(br.readLine());
        return st.nextToken();
    }

    static int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    static long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    static Double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }
}

class pair {
    int x, y;
    pair(int a, int b) {
        x = a;
        y = b;
    }
    pair() {}
}