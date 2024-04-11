import java.io.*;
import java.util.*;

public class Main {
    static long inf = (long) 1e9;

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        int n = nextInt();
        int k = nextInt();
        long a[] = new long [n];
        for(int i = 0;i < n;i++) a[i] = nextInt();
        Arrays.sort(a);
        long ans = a[n / 2];
        if (k != 0) {
            int s = n / 2;
            for(int i = s;i < n - 1;i++) {
                if (a[i + 1] == a[i]) continue;
                if (k < (a[i + 1] - a[i]) * (i - s + 1)) {
                    ans += k / (i - s + 1);
                    k = 0;
                    break;
                }
                ans += a[i + 1] - a[i];
                k -= (a[i + 1] - a[i]) * (i - s + 1);
                a[i] = a[i + 1];
            }
            ans += k / (n - s);
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