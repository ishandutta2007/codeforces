import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        int n = nextInt() - 1;
        int a[] = new int [n];
        int b[] = new int [n];
        for (int i = 0; i < n; i++) {
            a[i] = nextInt();
        }
        for (int i = 0; i < n; i++) {
            b[i] = nextInt();
        }
        int t[] = new int [n + 1];
        boolean u = false;
        for (int i = 0; i < 4; i++) {
            if (u) {
                break;
            }
            t[0] = i;
            for (int j = 1; j < n + 1; j++) {
                int y = -1;
                for (int k = 0; k < 4; k++) {
                    if ((k | t[j - 1]) == a[j - 1] && (k & t[j - 1]) == b[j - 1]) {
                        y = k;
                    }
                }
                if (y == -1) break;
                t[j] = y;
                if (j == n) u = true;
            }
        }
        if (u) {
            pw.println("YES");
            for (int i = 0; i < n + 1; i++) {
                pw.print(t[i] + " ");
            }
        }else{
            pw.println("NO");
        }
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