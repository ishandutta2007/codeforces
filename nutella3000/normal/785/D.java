import java.io.*;
import java.lang.reflect.Array;
import java.util.*;

public class Main {
    static int inf = (int) 1e9 + 7;

    static long binpow(long a, long b) {
        long ans = 1;
        while (b > 0) {
            if ((b & 1) == 1) ans = (ans * a) % inf;
            a = (a * a) % inf;
            b /= 2;
        }
        return ans;
    }

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        long fact[] = new long[300000];
        fact[0] = 1;
        for (int i = 1; i < 300000; i++) fact[i] = (fact[i - 1] * i) % inf;
        char h[] = next().toCharArray();
        int n = h.length;
        int k1 = 0;
        int k2 = 0;
        long ans = 0;
        for (int i = 0; i < n; i++) if (h[i] == ')') k2++;
        for (int i = 0; i < n; i++) {
            if (h[i] == ')') k2--;
            else k1++;
            if (k1 > 0 && k2 > 0 && h[i] == '(') {
                k1--;
                long ans1 = fact[k1 + k2] * binpow(fact[k1 + 1], inf - 2) % inf *
                        binpow(fact[k2 - 1], inf - 2) % inf;
                k1++;
                ans += ans1;
            }
        }
        pw.println(ans % inf);
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