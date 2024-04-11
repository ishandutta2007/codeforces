import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;


public class Main {
    static int inf = (int) 1e9 + 7;
    static int n, k, a[];

    static boolean solve(long d) {
        int dp[] = new int[n];
        dp[0] = 0;

        for(int i = 1;i < n;i++) {
            dp[i] = i;

            for(int j = 0;j < i;j++) {
                if (d * (i - j) >= Math.abs(a[i] - a[j])) dp[i] = Math.min(dp[i], dp[j] + (i - j -1));
            }
        }

        boolean ans = false;
        for(int i = 0;i < n;i++) if (dp[i] + n - i - 1 <= k) ans = true;
        return ans;
    }

    static void solve() throws IOException {
        n = sc.nextInt();
        k = sc.nextInt();
        a = new int [n];
        for(int i = 0;i < n;i++) a[i] = sc.nextInt();

        long l = -1;
        long r = (long) 2e9 + 2;
        while(r - l > 1) {
            long mid = ((l + r) >> 1);

            if (solve(mid)) r = mid;
            else l = mid;
        }

        pw.println(r);
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