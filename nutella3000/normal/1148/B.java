import java.io.*;
import java.util.*;

public class Main {
    static int inf = (int) 1e9 + 7;
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        int n = nextInt();
        int m = nextInt();
        int ta = nextInt();
        int tb = nextInt();
        int k = nextInt();
        int a[] = new int [n];
        int b[] = new int [m];
        for(int i = 0;i < n;i++) a[i] = nextInt() + ta;
        for(int i = 0;i < m;i++) b[i] = nextInt();
        int l = 0;
        while (l < m && b[l] < a[0]) l++;
        int ans = inf;
        if (m > k + l) ans = b[k + l];
        for(int pref = 0;pref < Math.min(k, n - 1);pref++) {
            while(l < m && b[l] < a[pref + 1]) l++;
            if (l + k - pref - 1 >= m) ans = inf;
            else ans = Math.max(ans, b[l + k - pref - 1]);
        }
        if (k >= n) ans = inf;
        if (ans == inf) pw.println(-1);
        else pw.println(ans + tb);
        pw.close();
    }

    static BufferedReader br;
    static StringTokenizer st = new StringTokenizer("");

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