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
        long n[] = new long [2];
        n[0] = nextLong();
        n[1] = nextLong();
        int q = nextInt();
        long c[] = new long [2];
        c[0] = n[0] / gcd(n[0], n[1]);
        c[1] = n[1] / gcd(n[0], n[1]);
        while(q-- > 0) {
            int a = nextInt() - 1;
            long b = nextLong() - 1;
            int x = nextInt() - 1;
            long y = nextLong() - 1;
            long num1 = b / c[a];
            long num2 = y / c[x];
            if (num1 == num2) pw.println("YES");
            else pw.println("NO");
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