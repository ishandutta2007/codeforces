import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        int n = nextInt();
        int m = nextInt();
        int k = nextInt();
        int ans = 0;
        for (int i = 0; i < k; i++) {
            ans += 2 * m + 2 * n - 4;
            n-=4;
            m-=4;
        }
        pw.println(ans);
        pw.close();
    }
    static BufferedReader br;
    static StringTokenizer st = new StringTokenizer("");
    public static int nextInt() throws IOException {
        while (!st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return Integer.parseInt(st.nextToken());
    }
    public static String next() throws IOException {
        while (!st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return st.nextToken();
    }
    public static long nextLong() throws IOException {
        while (!st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return Long.parseLong(st.nextToken());
    }
    public static double nextDouble() throws IOException {
        while (!st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return Double.parseDouble(st.nextToken());
    }
}