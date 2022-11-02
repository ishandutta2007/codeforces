import java.io.*;
import java.math.BigDecimal;
import java.math.MathContext;
import java.math.RoundingMode;
import java.util.*;


public class Main {
    static int inf = (int) 1e9 + 7;

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        int q = nextInt();
        while(q-- > 0) {
            int c = nextInt();
            int m = nextInt();
            int x = nextInt();
            int t = Math.min(c, Math.min(m, x));
            int ans = t;
            c -= t;
            m -= t;
            x -= t;
            if (m < c) {
                t = m;
                m = c;
                c = t;
            }
            int u = m - c;
            t = Math.min(u, c);

            ans += t;
            m -= 2 * t;
            c -= t;

            ans += c / 3 * 2;
            c %= 3;
            m %= 3;

            if (c == 2) ans++;

            pw.println(ans);
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
}