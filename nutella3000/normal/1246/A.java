import java.io.*;
import java.util.*;

public class Main {
    static int inf = (int) 1e9 + 7;

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        int n = nextInt();
        int p = nextInt();
        int ans = inf;
        for(int i = 0;i < 30000;i++) {
            int v = n - i * p;
            if (v < i) continue;
            int cnt = 0;
            for(int j = 0;j <= 30;j++) {
                if ((v & (1 << j)) != 0) cnt++;
            }
            if (cnt <= i)
            ans = Math.min(ans, i);
        }
        if (ans == inf) pw.println(-1);
        else pw.println(ans);
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