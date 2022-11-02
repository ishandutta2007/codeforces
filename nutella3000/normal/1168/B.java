import java.io.*;
import java.lang.reflect.Array;
import java.math.BigInteger;
import java.util.*;

public class Main {
    static int inf = (int) 1e9 + 7;

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        char h[] = next().toCharArray();
        long ans = 0;
        int n = h.length;
        int l = 0;
        int r = 0;
        while(r != n) {
            for(int k = 1;r - 2 * k >= l;k++) {
                if (h[r] == h[r - k] && h[r] == h[r - 2 * k]) {
                    while (l <= r - 2 * k) {
                        ans += n - r;
                        l++;
                    }
                    break;
                }
            }
            r++;
        }
        pw.print(ans);
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