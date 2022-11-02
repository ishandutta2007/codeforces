import java.io.*;
import java.lang.reflect.Array;
import java.util.*;


public class Main {
    static int inf = (int) 1e9 + 7;

    public static void main(String[] args) throws IOException {
        sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int a[] = new int [n];
        int r[] = new int [n];
        for(int i = 0;i < n;i++) {
            a[i] = sc.nextInt();
            r[i] = sc.nextInt();
        }
        int dp[] = new int [m + 1];
        dp[0] = 0;
        for(int i = 1;i <= m;i++) {
            dp[i] = inf;
            for(int j = 0;j < n;j++) {
                if (a[j] - r[j] > i) continue;
                dp[i] = Math.min(dp[i], dp[Math.max(a[j] - r[j] - Math.max(i - a[j] - r[j], 0) - 1, 0)] +
                        Math.max(i - a[j] - r[j], 0));
                dp[i] = Math.min(dp[i], Math.max(Math.max(i - a[j] - r[j], 0), Math.max(a[j] - r[j] - 1, 0)));
            }
        }
        //for(int i = 0;i <= m;i++) pw.println(i + " " + dp[i]);
        pw.println(dp[m]);
        pw.close();
    }

    static Scanner sc;
    static PrintWriter pw;

    static class Scanner {
        BufferedReader br;
        StringTokenizer st = new StringTokenizer("");

        Scanner(InputStream in) throws FileNotFoundException {
            br = new BufferedReader(new InputStreamReader(in));
        }

        Scanner(String in) throws FileNotFoundException {
            br = new BufferedReader(new FileReader(in));
        }

        String next() throws IOException {
            while (!st.hasMoreTokens()) st = new StringTokenizer(br.readLine());
            return st.nextToken();
        }

        int nextInt() throws IOException {
            return Integer.parseInt(next());
        }

        long nextLong() throws IOException {
            return Long.parseLong(next());
        }

        double nextDouble() throws IOException {
            return Double.parseDouble(next());
        }
    }
}

class pair implements Comparator<pair>{
    int a, b;
    pair(int a, int b) {
        this.a = a;
        this.b = b;
    }
    pair() {}

    @Override
    public int compare(pair o1, pair o2) {
        return Integer.compare(o1.a - o1.b, o2.a - o2.b);
    }
}