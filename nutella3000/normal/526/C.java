import java.io.*;
import java.util.*;

public class Main {
    static int inf = (int) 1e9 + 7;

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        int n = nextInt();
        int h1 = nextInt();
        int h2 = nextInt();
        int w1 = nextInt();
        int w2 = nextInt();
        boolean bad = true;
        if (w1 < 10000 && w2 < 10000) bad = false;

        if ((w1 < w2 && bad) || (!bad && (long) h1  * w2 < (long) h2 * w1)) {
            int t = h1;
            h1 = h2;
            h2 = t;
            t = w1;
            w1 = w2;
            w2 = t;
        }

        long ans = (long) h1 * (n / w1);
        long place = n % w1;
        ans += (long)h2 * (place / w2);
        place %= w2;
        int cnt = n / w1;
        long new_ans = ans;
        int u = Math.max(w1, w2) + 1;
        while(cnt > 0 && (u >= 0 || bad)) {
            u--;
            cnt--;
            new_ans -= h1;
            place += w1;
            new_ans += (long) h2 * (place / w2);
            place %= w2;
            ans = Math.max(ans, new_ans);
        }

        pw.println(ans);
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