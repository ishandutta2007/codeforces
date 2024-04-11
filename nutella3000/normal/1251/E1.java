
import java.io.*;
import java.util.*;

public class Main {
    static long inf = (long) 1e15 + 7;


    public static void main(String[] args) throws IOException {
        sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        for(int test = sc.nextInt();test > 0;test--) {
            int n = sc.nextInt();
            pair a[] = new pair[n];
            for(int i = 0;i < n;i++) a[i] = new pair(sc.nextInt(), sc.nextInt());
            Arrays.sort(a, new pair());

            long dp[][] = new long [n][n + 2];
            for(int i = 0;i < n;i++) {
                for(int j = 0;j < n;j++) {
                    if (i == 0) {
                        if (j >= a[0].m) dp[i][j] = 0;
                        else dp[i][j] = a[0].p;
                        continue;
                    }

                    dp[i][j] = dp[i - 1][j + 1] + a[i].p;
                    if (a[i].m <= i + j) dp[i][j] = Math.min(dp[i][j], dp[i - 1][j]);
                }
            }
            pw.println(dp[n - 1][0]);
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

class pair implements Comparator<pair>{
    int m, p;
    pair(int x, int y) {
        m = x;
        p = y;
    }

    pair() {}

    @Override
    public int compare(pair o1, pair o2) {
        return Integer.compare(o1.m, o2.m) * 2 + Integer.compare(o1.p, o2.p);
    }
}