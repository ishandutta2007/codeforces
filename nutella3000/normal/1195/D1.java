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
        power = new long [20];
        power[0] = 1;
        for(int i = 1;i < 20;i++) power[i] = (power[i - 1] * 10) % mod;
        n = nextInt();
        a = new int [n][];
        for(int i = 0;i < n;i++) {
            char h[] = next().toCharArray();
            a[i] = new int [h.length];
            for(int j = 0;j < h.length;j++) a[i][j] = h[j] - '0';
        }
        long ans = 0;
        for(int i = 0;i < a[0].length;i++) {
            int u =  (a[0].length - i - 1) * 2;
            long p = (power[u] + power[u + 1]) % mod;
            long sum = 0;
            for(int j = 0;j < n;j++) sum += a[j][i];
            ans = (ans + sum * p % mod * n) % mod;
        }
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