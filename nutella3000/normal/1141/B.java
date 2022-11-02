import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {
    static int inf = (int) 1e9;

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        int n = nextInt();
        int a[] = new int [n * 2 - 1];
        for(int i = 0;i < n * 2 - 1;i++) {
            if (i < n) a[i] = nextInt();
            else a[i] = a[i - n];
        }
        int ans = 0;
        int cnt = 0;
        for(int i = 0;i < 2 * n - 1;i++) {
            if (a[i] == 1) cnt++;
            else{
                ans = Math.max(ans, cnt);
                cnt = 0;
            }
        }
        pw.print(ans);
        pw.close();
    }

    static BufferedReader br;
    static StringTokenizer st = new StringTokenizer("");

    public static int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    public static long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    public static double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }

    public static String next() throws IOException {
        if (!st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return st.nextToken();
    }
}