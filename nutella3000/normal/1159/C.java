import java.io.*;
import java.lang.reflect.Array;
import java.util.*;
public class Main {
    static int inf = (int) 1e9 + 7;
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        int n = nextInt();
        int m = nextInt();
        int a[] = new int [n];
        int b[] = new int [m];
        for(int i = 0;i < n;i++) a[i] = nextInt();
        Arrays.sort(a);
        for(int i = 0;i < m;i++) b[i] = nextInt();
        Arrays.sort(b);
        long ans = 0;
        if (b[0] < a[n - 1]) {
            pw.println(-1);
            pw.close();
            return;
        }
        for(int i = 0;i < n;i++) ans += a[i];
        ans *= m;
        for(int i = 1;i < m;i++) ans += b[i] - a[n - 1];
        if (b[0] != a[n - 1]) {

            ans += b[0] - a[n - 2];
        }
        pw.println(ans);
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