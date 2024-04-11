import java.io.*;
import java.util.*;

public class Main {
    static int inf = (int) 1e9 + 7;

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        int n = nextInt();
        int m = nextInt();
        int fib[] = new int [100005];
        fib[0] = 1;
        fib[1] = 1;
        for(int i = 2;i < 100005;i++) fib[i] = (fib[i - 1] + fib[i - 2]) % inf;

        long ans1 = 0;
        for(int i = 0;i < n - 1;i++) {
            ans1 = (ans1 + fib[i]) % inf;
        }
        long ans2 = 0;

        for(int i = 0;i < m - 1;i++) {
            ans2 = (ans2 + fib[i]) % inf;
        }


        long ans3 = (ans1 + ans2 + 1) % inf;
        pw.println(ans3 * 2 % inf);
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

}