import java.io.*;
import java.util.*;

public class Main {
    static PrintWriter pw;
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        String n = next();
        int ans = 0;
        int cnt = 1;
        for(int i = 0;i < n.length();i++) {
            int u = n.charAt(i) - '1';
            if (i == 0) u = Math.max(1, u);
            for(int j = 0;j < n.length() - i - 1;j++) u *= 9;
            ans = Math.max(u * cnt, ans);
            cnt *= n.charAt(i) - '0';
        }
        ans = Math.max(ans, cnt);
        pw.println(ans);
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