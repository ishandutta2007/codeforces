import java.io.*;
import java.util.*;
public class Main {
    static int inf = (int) 1e9 + 7;

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        int n = nextInt();
        int a[] = new int [5];
        int b[] = new int [5];
        for(int i = 0;i < n;i++) a[nextInt() - 1]++;
        for(int i = 0;i < n;i++) b[nextInt() - 1]++;
        int ans = 0;
        for(int i = 0;i < 5;i++) {
            if ((a[i] + b[i]) % 2 == 1) ans = -inf;
            ans += Math.abs(a[i] - b[i]) / 2;
        }

        if (ans < 0) pw.println(-1);
        else pw.println(ans / 2);
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