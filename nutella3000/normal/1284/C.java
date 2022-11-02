import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;


public class Main {
    static int inf = (int) 1e9;
    static int n, m;
    static long fact[];

    static void scan() throws IOException {
        n = sc.nextInt();
        m = sc.nextInt();
        fact = new long [n + 1];
        fact[0] = 1;
        for(int i = 1;i <= n;i++) fact[i] = fact[i - 1] * i % m;
    }

    static void solve() throws IOException {
        scan();
        long ans = 0;
        for(int len = 1;len <= n;len++) {
            long f1 = (long)(n - len + 1) * (n - len + 1) % m;
            long s2 = fact[n - len] * fact[len] % m;
            ans = (ans + f1 * s2) % m;
        }

        pw.println(ans);
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