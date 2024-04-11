import java.io.*;
import java.util.*;
public class Main {
    static int inf = (int) 1e9 + 7;

    static boolean have(char a[], char b[]) {
        int n = a.length;
        int m = b.length;
        int dp[] = new int [n];
        dp[0] = 0;
        if (a[0] == b[0]) dp[0] = 1;
        for(int i = 1;i < n;i++) {
            if (dp[i - 1] == b.length) dp[i] = b.length;
            else {
                dp[i] = dp[i - 1];
                if (a[i] == b[dp[i - 1]]) dp[i]++;
            }
        }
        return dp[n - 1] == b.length;
    }

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        char a[] = next().toCharArray();
        char b[] = next().toCharArray();
        int n = a.length;
        int c[] = new int [n];
        for(int i = 0;i < n;i++) c[i] = nextInt();
        int l = -1;
        int r = n - 1;
        while(r - l > 1) {
            int m = ((l + r) >> 1);

            char d[] = new char[n - m - 1];
            int id = 0;
            HashSet<Integer> t = new HashSet<>();
            for(int i = 0;i <= m;i++) t.add(c[i] - 1);
            for(int i = 0;i < n;i++) {
                if (t.contains(i)) continue;
                d[id++] = a[i];
            }

            if (have(d, b)) l = m;
            else r = m;
        }

        pw.println(l + 1);
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