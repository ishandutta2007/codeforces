import java.io.*;
import java.util.*;

public class Main {
    static int max(int a[]) {
        int ans = Integer.MIN_VALUE;
        for (int i : a) ans = Math.max(ans, i);
        return ans;
    }

    static int max(ArrayList<Integer> a) {
        int ans = Integer.MIN_VALUE;
        for (int i : a) ans = Math.max(ans, i);
        return ans;
    }

    static int min(int a[]) {
        int ans = Integer.MAX_VALUE;
        for (int i : a) ans = Math.min(ans, i);
        return ans;
    }

    static int min(ArrayList<Integer> a) {
        int ans = Integer.MAX_VALUE;
        for (int i : a) ans = Math.min(ans, i);
        return ans;
    }

    static int cnt(int a[], int num) {
        int ans = 0;
        for (int i : a) if (i == num) ans++;
        return ans;
    }

    static int cnt(ArrayList<Integer> a, int num) {
        int ans = 0;
        for (int i : a) if (i == num) ans++;
        return ans;
    }

    static int cnt(boolean a[]) {
        int ans = 0;
        for (int i = 0; i < a.length; i++) if (a[i]) ans++;
        return ans;
    }

    static void fill(int a[], int num) {
        for (int i = 0; i < a.length; i++) a[i] = num;
    }


    static int inf = (int) 1e9 + 7;


    public static void main(String[] args) throws IOException {
        sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        int n = sc.nextInt();
        int a[] = new int [n];
        for(int i = 0;i < n;i++) a[i] = sc.nextInt();
        long dp[] = new long [n];
        for(int i = n - 1;i >= 0;i--) {
            if (i + 2 < n) {
                dp[i] = Math.max(Math.max(dp[i + 2], 0) + Math.abs(a[i] - a[i + 1]) - Math.abs(a[i + 1] - a[i + 2]), Math.abs(a[i] - a[i + 1]));
            }else if (i == n - 1) dp[i] = 0;
            else dp[i] = Math.abs(a[i] - a[i + 1]);
        }
        long ans = -inf;
        for(int i = 0;i < n;i++) ans = Math.max(ans, dp[i]);
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