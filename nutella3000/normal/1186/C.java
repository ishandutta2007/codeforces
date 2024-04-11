import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {
    static int inf = (int) 1e9;

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        char a[] = next().toCharArray();
        char b[] = next().toCharArray();
        int k = 0;
        for(int i = 0;i < b.length;i++) {
            if (b[i] == '1') {
                k = (k + 1) % 2;
                b[i] = '0';
            }
        }
        int pref[] = new int [a.length];
        pref[0] = a[0] - '0';
        for(int i = 1;i < a.length;i++) pref[i] = pref[i - 1] + a[i] - '0';
        int ans = 0;
        if (pref[b.length - 1] % 2 == k) ans++;
        for(int i = b.length;i < a.length;i++) {
            if ((pref[i] - pref[i - b.length]) % 2 == k) ans++;
        }
        pw.print(ans);
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