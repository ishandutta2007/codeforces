import java.io.*;
import java.lang.reflect.Array;
import java.util.*;

public class main {
    public static void main(String[] args) throws IOException {
        Locale.setDefault(Locale.US);
        br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        int n = nextInt();
        int x = nextInt();
        int y = nextInt();
        long ans = 0;
        int count = 0;
        int b[] = new int [n + 1];
        b[0] = 1;
        String s = next();
        for (int i = 1; i < n + 1; i++) {
            b[i] = s.charAt(i - 1) - '0';
            if (b[i] == 0 && b[i - 1] == 1) {
                count++;
            }
        }
        if (y <= x || count == 0) {
            pw.print((long)y * count);
        }else{
            pw.print((long) x * (count - 1) + y);
        }
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