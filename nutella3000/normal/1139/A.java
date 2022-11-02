import java.io.*;
import java.util.*;
public class Main {
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        int n = nextInt();
        String s = next();
        long cnt = 0;
        for(int i = 0;i < n;i++) {
            if ((s.charAt(i) - '0') % 2 == 0) cnt += i + 1;
        }
        pw.println(cnt);
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

    public static long nextLong() throws IOException {
        if (!st.hasMoreTokens()) {
            st = new StringTokenizer((br.readLine()));
        }
        return Long.parseLong(st.nextToken());
    }

    public static double nextDouble() throws IOException {
        if (!st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return Double.parseDouble(st.nextToken());
    }

    public static String next() throws IOException {
        if (!st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return st.nextToken();
    }
}