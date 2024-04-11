import java.io.*;
import java.util.*;

public class Main {
    static int inf = (int) 1e9 + 7;
    static long[] sort(long a[], int l, int r) {
        long ans[] = new long[r - l + 1];
        if (l == r) {
            ans[0] = a[l];
            return ans;
        }
        int m = (l + r) / 2;
        long left[] = sort(a, l, m);
        long right[] = sort(a, m + 1, r);
        int id1 = 0;
        int id2 = 0;
        while(id1 < left.length || id2 < right.length) {
            if (id1 < left.length && (id2 >= right.length || left[id1] < right[id2])) {
                ans[id1 + id2] = left[id1];
                id1++;
            }else{
                ans[id1 + id2] = right[id2];
                id2++;
            }
        }
        return ans;
    }
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        int n = nextInt();
        long a[] = new long[n];
        long b[] = new long[n];
        for (int i = 0; i < n; i++) a[i] = (i + 1l) * (n - i) * nextInt();
        for (int i = 0; i < n; i++) b[i] = nextInt();
        a = sort(a, 0, a.length - 1);
        b = sort(b, 0, b.length - 1);
        //Arrays.sort(a);
        //Arrays.sort(b);
        long ans = 0;
        int mod = 998244353;
        for (int i = 0; i < n; i++) a[i] %= mod;
        for (int i = 0; i < n; i++) {
            ans = (ans + a[i] * b[n - i - 1]) % mod;
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