import java.io.*;
import java.lang.reflect.Array;
import java.math.BigInteger;
import java.util.*;
public class Main {
    static long inf = (long) 1e15 + 7;
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        int n = nextInt();
        int k = nextInt();
        int ans[] = new int [k];
        int sz = 0;
        for(int i = 0;i < n;i++) {
            int v = nextInt();
            boolean bad = false;
            for(int j = 0;j < sz;j++) {
                if (ans[j] == v) bad = true;
            }

            if (bad) continue;

            if (sz == k) {
                sz--;
            }
            for(int j = k - 1;j > 0;j--) ans[j] = ans[j - 1];
            ans[0] = v;
            sz++;
        }

        pw.println(sz);
        for(int i = 0;i < sz;i++) pw.print(ans[i] + " ");
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