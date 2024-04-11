import java.io.*;
import java.math.BigInteger;
import java.util.*;
public class Main {
    static int inf = (int) 1e9;
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        int n = nextInt();
        int a[][] = new int [2][n];
        for(int i = 0;i < n;i++) a[0][i] = nextInt();
        for(int i = 0;i < n;i++) a[1][i] = nextInt();
        long dp[][] = new long [2][n];
        long max[] = new long[2];
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < 2;j++) {
                dp[j][i] = max[1 - j] + a[j][i];
            }
            for(int j = 0;j < 2;j++) {
                max[j] = Math.max(max[j], dp[j][i]);
            }
        }
        pw.println(Math.max(max[0], max[1]));
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
    static Double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }
}