import java.io.*;
import java.util.*;
public class Main {
    static int inf = (int) 1e9 + 7;

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        int n = nextInt();
        int k = nextInt();
        int a[] = new int [n];
        for(int i = 0;i < n;i++) a[i] = nextInt();
        int b[] = new int [n];
        for(int i = 0;i < n;i++) b[i] = nextInt();
        long ans = 0;
        for(int i = 0;i < n;i++) ans += b[i];
        for(int i = 0;i < n;i++) a[i] -= b[i];
        Arrays.sort(a);
        for(int i = 0;i < n;i++) {
            if (a[i] > 0 && i >= k) break;
            ans += a[i];
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