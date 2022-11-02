import java.io.*;
import java.math.BigInteger;
import java.util.*;
public class Main {
    static int inf = (int) 1e9;
    static int n;
    static int a[][];
    static long power[];
    static int mod = 998244353;
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        power = new long [21];
        power[0] = 1;
        for(int i = 1;i < 21;i++) power[i] = (power[i - 1] * 10) % mod;
        n = nextInt();
        a = new int [n][10];
        for(int i = 0;i < n;i++) {
            StringBuilder t = new StringBuilder(next());
            while (t.length() != 10) {
                t.insert(0, '0');
            }
            char h[] = String.valueOf(t).toCharArray();
            for(int j = 0;j < h.length;j++) a[i][j] = h[j] - '0';
        }
        long ans = 0;
        boolean cal[] = new boolean[n];
        for(int i = 0;i < a[0].length;i++) {
            int u =  (a[0].length - i - 1) * 2;
            long p = (power[u] + power[u + 1]) % mod;
            long sum = 0;
            long cnt = 0;
            for(int j = 0;j < n;j++) {
                sum += a[j][i];
                if (a[j][i] != 0) {
                    cal[j] = true;
                }
                if (cal[j]) cnt++;
            }
            ans = (ans + sum * p % mod * cnt) % mod;
        }
        //
        long b[] = new long[n];
        long sum_b = 0;
        for(int len = 10; len >= 1;len--) {
            boolean god[] = new boolean[n];
            for(int k = 0;k < n;k++) {
                boolean good = true;
                for (int i = 0; i < 10 - len; i++) {
                    if (a[k][i] != 0) good = false;
                }
                if (!good) {
                    sum_b = (sum_b - b[k] + mod) % mod;
                    b[k] = ((b[k] * power[1] + 2 * a[k][10 - len - 1])) % mod;
                    sum_b = (sum_b + b[k]) % mod;
                }

                if (a[k][10 - len] == 0) good = false;
                if (!good) continue;
                god[k] = true;
            }
            for(int k = 0;k < n;k++) {
                if (god[k]) {
                    ans = (ans + sum_b % mod * power[2 * len]) % mod;
                }
            }
        }
        //
        pw.println(ans);
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