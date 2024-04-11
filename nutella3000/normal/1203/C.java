import java.io.*;
import java.util.*;

public class Main {
    static long inf = (long) 1e9;
    static long gcd(long a, long b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        int n = nextInt();
        long a = nextLong();
        for(int i = 0;i < n - 1;i++) {
            long b = nextLong();
            a = gcd(a, b);
        }
        int cnt = 0;
        for(int i = 1;i < Math.sqrt(a);i++) {
            if (a % i == 0) {
                cnt += 2;
            }
        }
        long u = (long) Math.sqrt(a);
        if (u * u == a) cnt++;
        pw.println(cnt);
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