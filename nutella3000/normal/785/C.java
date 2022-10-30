import java.io.*;
import java.lang.reflect.Array;
import java.util.*;

public class Main {
    static int inf = (int) 1e9 + 7;
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        long n = nextLong();
        long m = nextLong();
        long ans = n;
        long l = -1;
        long r = (long)2e9;
        while(r - l > 1) {
            long mid = ((l + r) >> 1);
            if (mid * (mid + 1) / 2 >= n - m) r = mid;
            else l = mid;
        }
        ans = Math.min(ans, r + m);
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
}

class point {
    int l, r;
    point(int l, int r) {
        this.l = l;
        this.r = r;
    }

}