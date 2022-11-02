import java.io.*;
import java.lang.reflect.Array;
import java.util.*;

public class Main {
    static int inf = (int) 1e9 + 7;

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        int n = nextInt();
        int m = 200002;
        int a[] = new int[m];
        int pref[] = new int[m];
        int pref1[] = new int[m];
        for (int i = 0; i < n; i++) a[nextInt()]++;
        pref1[0] = 1;
        for (int i = 1; i < m; i++) {
            pref[i] = pref[i - 1] + a[i];
            pref1[i] = pref1[i - 1];
            if (a[i] < 2) pref1[i]++;
        }
        int ans = 0;
        int left = 0;
        int right = 0;
        for (int i = 1; i < m - 1; i++) {
            if (a[i] == 0) continue;
            int l = i;
            int r = m;
            while (l != r - 1) {
                int mid = (l + r) / 2;
                if (pref1[mid] == pref1[i]) l = mid;
                else r = mid;
            }
            r = l;
            if (a[r + 1] == 1) r++;
            if (pref[r] - pref[i - 1] > ans) {
                ans = pref[r] - pref[i - 1];
                left = i;
                right = r;
            }
        }
        pw.println(ans);
        pw.print(left + " ");
        for (int i = left + 1; i <= right; i++) {
            for (int j = 0; j < a[i] - 1; j++)
                pw.print(i + " ");
            if (i == right) pw.print(right + " ");
        }
        for(int i = right - 1;i > left;i--) pw.print(i + " ");
        for(int i = 0;i < a[left] - 1;i++) pw.print(left + " ");
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