import java.io.*;
import java.lang.reflect.Array;
import java.util.*;


public class Main {
    static int inf = (int) 1e9 + 7;

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        int k1 = sc.nextInt();
        int k2 = sc.nextInt();
        int k3 = sc.nextInt();
        int a[] = new int [k1];
        int b[] = new int [k2];
        int c[] = new int [k3];
        for(int i = 0;i < k1;i++) a[i] = sc.nextInt();
        for(int i = 0;i < k2;i++) b[i] = sc.nextInt();
        for(int i = 0;i < k3;i++) c[i] = sc.nextInt();
        Arrays.sort(a);
        Arrays.sort(b);
        Arrays.sort(c);


        int dp1[] = new int [k3];
        for(int i = 0;i < k3;i++) {
            int l = -1;
            int r = k2;
            while(r - l > 1) {
                int mid = ((l + r) >> 1);
                if (b[mid] > c[i]) r = mid;
                else l = mid;
            }
            dp1[i] = k2 - r;
        }

        int min = inf;
        int id = -1;
        int dp[] = new int [k3];
        for(int i = k3 - 1;i >= 0;i--) {
            if (min > dp1[i] + i) {
                min = dp1[i] + i;
                id = i;
            }
            if (dp1[id] + id - i > k3 - i) dp[i] = k3 - i;
            else dp[i] = dp1[id] + id - i;
        }


        int ans = inf;

        int cnt1 = 0;
        int id3 = 0;
        for(int i = 0;i <= k1 + k2 + k3;i++) {
            while(cnt1 != k1 && a[cnt1] <= i) cnt1++;
            int ans1 = k1 - cnt1 + (i - cnt1);
            while(id3 != k3 && c[id3] <= i) id3++;
            int ans2 = 0;
            if (id3 != k3) {
                ans2 = dp[id3];
            }
            ans = Math.min(ans, ans1 + ans2);
        }

        pw.println(ans);
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