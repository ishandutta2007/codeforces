import java.io.*;
import java.util.*;

public class Main {
    static int mod = (int) 1e9 + 7, p = 247;
    static int n, m = (int) 1e6 + 5;
    static char a[] = new char[m];
    static long hash[] = new long [m];
    static int size = 1;
    static long ste[] = new long [m];
    static void solve() throws IOException {
        ste[0] = 1;
        for(int i = 1;i < m;i++) ste[i] = (ste[i - 1] * p) % mod;
        n = nextInt();
        for(int i = 0;i < n;i++) {
            char b[] = next().toCharArray();
            long h[] = new long [b.length + 1];
            for(int j = 1;j <= b.length;j++) h[j] = (h[j - 1] * p + b[j - 1]) % mod;
            int l = 0;
            int r = Math.min(size, b.length + 1);
            for(m = 0;m < Math.min(size, b.length + 1);m++) {
                if (hs(hash, size - m, size - 1) == hs(h, 1, m)) l = m;
            }
            for(int j = size; j - size != b.length - l;j++) {
                a[j] = b[j - size + l];
                hash[j] = (hash[j - 1] * p + a[j]) % mod;
            }
            size += b.length - l;
        }
    }
    static long hs(long h[], int l, int r) {
        return ((h[r] - (l == 0 ? 0 : h[l - 1]) * ste[r - l + 1]) % mod + mod) % mod;
    }
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        solve();
        for(int i = 1;i < size;i++) pw.print(a[i]);
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