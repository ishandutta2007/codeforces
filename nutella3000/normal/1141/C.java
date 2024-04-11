import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {
    static int inf = (int) 1e9;

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        int n = nextInt();
        boolean a[] = new boolean[2 * n + 5];
        int down = inf;
        int b[] = new int [n - 1];
        int last = n + 2;
        a[last] = true;
        for(int i = 0;i < n - 1;i++) {
            b[i] = nextInt();
            last += b[i];
            if (last < 0 || last >= 2 * n + 5 || a[last]) {
                pw.print(-1);
                pw.close();
                return;
            }
            a[last] = true;
        }
        boolean ans = true;
        int cnt = 0;
        for(int i = 0;i < 2 * n + 5;i++) {
            if (a[i]) {
                if (down == inf) down = i - 1;
                cnt++;
            }else{
                if (cnt != 0 && cnt != n) ans = false;
            }
        }
        if (cnt != n) ans = false;
        if (!ans) pw.print(-1);
        else{
            int first = n + 2 - down;
            for(int i = 0;i < n;i++) {
                if (i != 0) first = b[i - 1] + first;
                pw.print(first + " ");
            }
        }
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