import java.io.*;
import java.lang.reflect.Array;
import java.util.*;

public class Main {
    static int inf = (int) 1e9 + 7;

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        int n = nextInt();
        int m = nextInt();
        int k = nextInt();
        int a[] = new int [n];
        long dp[][] = new long [n][m];
        for(int i = 0;i < n;i++) a[i] = nextInt();
        for(int i = 0;i < m;i++) dp[0][i] = a[0];
        dp[0][0] -= k;
        for(int i = 1;i < n;i++) {
            for(int j = 1;j < m;j++) {
                dp[i][j] = Math.max(0, dp[i - 1][(j + 1) % m]) + a[i];
            }
            dp[i][0] = Math.max(0, dp[i - 1][1 % m]) + a[i] - k;
        }
        long ans = 0;
        for(int i = 0;i < n;i++) if (dp[i][0] > ans) ans = dp[i][0];
        pw.println(ans);
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