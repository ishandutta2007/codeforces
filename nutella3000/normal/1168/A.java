import java.io.*;
import java.lang.reflect.Array;
import java.math.BigInteger;
import java.util.*;

public class Main {
    static int inf = (int) 1e9 + 7;

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        int n = nextInt();
        int m = nextInt();
        int a[] = new int [n];
        for(int i = 0;i < n;i++) a[i] = nextInt();
        int l = -1;
        int r = m + 1;
        while(l != r - 1) {
            int mid = (l + r) / 2;
            int last = -1;
            boolean bad = false;
            for(int i = 0;i < n;i++) {
                if (a[i] + mid >= m && a[i] + mid - m >= last);
                else{
                    if (last > a[i] + mid) bad = true;
                    last = Math.max(last, a[i]);
                }
            }
            if (bad) l = mid;
            else r = mid;
        }
        pw.print(r);
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