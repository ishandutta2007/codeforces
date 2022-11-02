import java.io.*;
import java.util.*;


public class Main {
    static int inf = (int) (1e9 + 7);

    public static void main(String[] args) throws IOException {
        sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        for(int test = sc.nextInt();test > 0;test--) {
            int n = sc.nextInt();
            int a[] = new int [n];
            int b[] = new int [n];
            for(int i = 0;i < n;i++) {
                a[i] = sc.nextInt();
                b[i] = sc.nextInt();
            }

            long dp[][] = new long [n][3];
            for(int i = 0;i < n;i++) {
                if (i == 0) {
                    dp[i][0] = 0;
                    dp[i][1] = b[i];
                    dp[i][2] = 2 * b[i];
                }else{
                    for(int j = 0;j < 3;j++) {
                        dp[i][j] = (long) 1e15;
                        for(int q = 0;q < 3;q++) {
                            if (a[i - 1] + q != a[i] + j) {
                                dp[i][j] = Math.min(dp[i][j], dp[i - 1][q] + j * b[i]);
                            }
                        }
                    }
                }
            }

            pw.println(Math.min(dp[n - 1][0], Math.min(dp[n - 1][1], dp[n - 1][2])));
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