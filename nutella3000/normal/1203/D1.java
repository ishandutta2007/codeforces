import java.io.*;
import java.util.*;

public class Main {
    static long inf = (long) 1e9;
    static char s[], t[];
    static int n, m, pref[], suf[];
    static void f() {
        int size = 0;
        for(int i = 0;i < n;i++) {
            if (size != m && t[size] == s[i]) {
                size++;
            }
            pref[i] = size;
        }
        size = m - 1;
        suf[n] = m + 1;
        for(int i = n - 1;i >= 0;i--) {
            if (size != -1 && t[size] == s[i]) {
                size--;
            }
            suf[i] = size + 2;
        }
    }
    static int m() {
        int ans = 0;
        for(int i = 0;i < n;i++) {
            int l = i - 1;
            int r = n + 1;
            while(r - l > 1) {
                int m = (l + r) / 2;
                if (suf[m] <= (i - 1 < 0 ? 0 : pref[i - 1]) + 1) l = m;
                else r = m;
            }
            ans = Math.max(ans, l - i);
        }
        return ans;
    }
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        s = next().toCharArray();
        t = next().toCharArray();
        n = s.length;
        m = t.length;
        pref = new int [n];
        suf = new int [n + 1];
        f();
        pw.println(m());
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