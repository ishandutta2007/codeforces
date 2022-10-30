import java.io.*;
import java.util.*;
public class Main {
    static int inf = (int) 1e9 + 7;

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        int t = nextInt();
        while(t-- > 0) {
            long n = nextLong();
            long m = nextLong();
            long ans = 0;
            long p[] = new long [10];
            for(int i = 1;i < 10;i++) p[i] = (i * m) % 10;
            long u = 0;
            for(int i = 1;i < 10;i++) u += p[i];
            ans += u * (n / m / 10);
            for(int i = 1;i <= n / m % 10;i++) ans += p[i];
            pw.println(ans);
        }
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