import java.io.*;
import java.lang.reflect.Array;
import java.util.*;

public class main {
    public static void main(String[] args) throws IOException {
        Locale.setDefault(Locale.US);
        br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        int n = nextInt();
        int d = nextInt();
        int ans = 2;
        int b[] = new int [n];
        Arrays.sort(b);
        for (int i = 0; i < n; i++) {
            b[i] = nextInt();
        }
        for (int i = 1; i < n; i++) {
            if (b[i] - b[i - 1] >= d * 2) {
                ans++;
            }
            if (b[i] - b[i - 1] > d * 2) {
                ans++;
            }
        }
        pw.println(ans);
        pw.close();
    }
    static BufferedReader br;
    static StringTokenizer st = new StringTokenizer("");

    public static int nextInt() throws IOException {
        if (!st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return Integer.parseInt(st.nextToken());
    }
    public static String next() throws IOException {
        if (!st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return st.nextToken();
    }
    public static double nextDouble() throws IOException {
        if (!st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return Double.parseDouble(st.nextToken());
    }
    public static long nextLong() throws IOException {
        if (!st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return Long.parseLong(st.nextToken());
    }
}