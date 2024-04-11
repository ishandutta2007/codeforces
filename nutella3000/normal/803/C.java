import java.io.*;
import java.util.*;

public class Main {
    static int inf = (int) 1e9 + 7;

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        long n = nextLong();
        long k = nextLong();
        ArrayList<Long> d = new ArrayList<>();

        if (k >= 2e5 || k * (k + 1) / 2 > n) {
            pw.println(-1);
        }else{
            long u = k * (k + 1) / 2;
            long ans = 0;
            for(long t = 1;t <= Math.sqrt(n);t++) {
                if (n % t == 0) {
                    if (n / t >= u) ans = Math.max(ans, t);
                    if (t >= u) ans = Math.max(ans, n / t);
                }
            }

            for(int i = 1;i < k;i++) {
                pw.print(i * ans + " ");
                n -= i * ans;
            }
            pw.println(n);
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

    static double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }
}