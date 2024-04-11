import java.io.*;
import java.util.*;

public class Main {
    static long inf = (long) 1e9;

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        int t = nextInt();
        while(t-- > 0) {
            int n = nextInt();
            int m = nextInt();
            int k = nextInt();
            int a[] = new int [n];
            boolean ans = true;
            for(int i = 0;i < n;i++) a[i] = nextInt();
            for(int i = 0;i < n - 1;i++) {
                if (a[i] + k >= a[i + 1]) {
                    m += Math.min((a[i] + k - a[i + 1]), a[i]);
                }else{
                    if (a[i + 1] - a[i] - k <= m) {
                        m -= (a[i + 1] - a[i] - k);
                    }else ans = false;
                }
            }
            if (ans) pw.println("YES");
            else pw.println("NO");
        }
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