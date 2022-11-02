import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {
    static int mod = (int) 1e9 + 7;
    static int fib[];
    static int f(int a) {
        return fib[a];
    }

    public static void main(String[] args) throws IOException {
        sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        char h[] = sc.next().toCharArray();
        int n = h.length;
        fib = new int [n + 1];

        fib[1] = 1;
        fib[0] = 1;
        for(int i = 2;i <= n;i++) fib[i] = (fib[i - 1] + fib[i - 2]) % mod;


        long ans = 1;
        int cnt = 0;

        boolean bad = false;
        for(int i = 0;i < n;i++) if (h[i] == 'm' || h[i] == 'w') bad = true;
        if (bad) {
            System.out.println(0);
            return;
        }

        for(int i = 0;i <= n;i++) {
            if (i < n && h[i] == 'u') cnt++;
            else{
                if (cnt > 1) ans = (ans * f(cnt)) % mod;
                cnt = 0;
            }
        }

        for(int i = 0;i <= n;i++) {
            if (i < n && h[i] == 'n') cnt++;
            else{
                if (cnt > 1) ans = (ans * f(cnt)) % mod;
                cnt = 0;
            }
        }
        pw.println(ans);
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