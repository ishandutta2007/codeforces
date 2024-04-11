
import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;


public class Main {
    static int inf = (int) 1e9 + 7;

    public static void main(String[] args) throws IOException {
        sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        for (int test = sc.nextInt(); test > 0; test--) {
            char a[] = sc.next().toCharArray();
            char b[] = sc.next().toCharArray();
            boolean good = false;
            for (int size = 0; size < b.length; size++) {
                int dp[][] = new int[size + 1][b.length - size + 1];
                int n = a.length;
                int next[][] = new int[n][26];
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < 26; j++) next[i][j] = n;
                }
                for (int i = 0; i < n; i++) next[i][a[i] - 'a'] = i;

                for (int j = 0; j < 26; j++) {
                    int first = n;
                    for (int i = n - 1; i >= 0; i--) {
                        first = Math.min(first, next[i][j]);
                        next[i][j] = first;
                    }
                }

                for (int i = 0; i <= size; i++) {
                    for (int j = 0; j <= b.length - size; j++) {
                        int ans = inf;
                        if (i != 0 && dp[i - 1][j] + 1 < n) {
                            ans = next[dp[i - 1][j] + 1][b[i - 1] - 'a'];
                        }
                        if (j != 0 && dp[i][j - 1] + 1 < n) {
                            ans = Math.min(ans, next[dp[i][j - 1] + 1][b[size + j - 1] - 'a']);
                        }
                        if (i == 0 && j == 0) ans = -1;

                        dp[i][j] = ans;
                    }
                }
                if (dp[size][b.length - size] < n) good = true;
            }
            pw.println(good ? "YES" : "NO");
        }
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