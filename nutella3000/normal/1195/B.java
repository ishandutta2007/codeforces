import java.io.*;
import java.math.BigInteger;
import java.util.*;
public class Main {
    static int inf = (int) 1e9;
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        int n = nextInt();
        int k = nextInt();
        long l = -1;
        long r = 100000;
        while(l != r - 1) {
            long mid = (l + r) / 2;
            if (mid * (mid + 1) / 2 - (n - mid) > k) r = mid;
            else l = mid;
        }
        pw.println(n - l);
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