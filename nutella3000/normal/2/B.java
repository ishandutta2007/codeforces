import java.io.*;
import java.util.*;

public class Main {
    static int inf = (int) 1e9 + 7;
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        int n = nextInt();
        int t[][] = new int [n][n];
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < n;j++) t[i][j] = nextInt();
        }

        int a[][] = new int [n][n];
        int b[][] = new int [n][n];
        int c[][] = new int [n][n];
        int dp1[][] = new int [n][n];
        int dp2[][] = new int [n][n];
        int dp3[][] = new int [n][n];
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < n;j++) {
                int v = t[i][j];
                if (v == 0) {
                    c[i][j] = 1;
                    a[i][j] = 10000;
                    b[i][j] = 100;
                    continue;
                }

                while((v & 1) == 0) {
                    v >>= 1;
                    a[i][j]++;
                }

                while(v % 5 == 0) {
                    v /= 5;
                    b[i][j]++;
                }
            }
        }


        for(int i = 0;i < n;i++) {
            for(int j = 0;j < n;j++) {
                if (i == 0 && j == 0) {
                    dp1[i][j] = a[i][j];
                    dp2[i][j] = b[i][j];
                    dp3[i][j] = c[i][j];
                    continue;
                }

                int ans1 = inf;
                int ans2 = inf;
                int ans3 = 0;
                if (i != 0) {
                    ans1 = dp1[i - 1][j];
                    ans2 = dp2[i - 1][j];
                    ans3 = dp3[i - 1][j];
                }

                if (j != 0) {
                    ans1 = Math.min(ans1, dp1[i][j - 1]);
                    ans2 = Math.min(ans2, dp2[i][j - 1]);
                    ans3 = Math.max(ans3, dp3[i][j - 1]);
                }

                dp1[i][j] = a[i][j] + ans1;
                dp2[i][j] = b[i][j] + ans2;
                dp3[i][j] = Math.max(c[i][j], ans3);
            }
        }

        if (dp1[n - 1][n - 1] > dp2[n - 1][n - 1]) {
            for(int i = 0;i < n;i++) {
                for(int j = 0;j < n;j++) {
                    dp1[i][j] = dp2[i][j];
                    a[i][j] = b[i][j];
                }
            }
        }
        boolean swap = false;
        if (dp1[n - 1][n - 1] > 1 && dp3[n - 1][n - 1] == 1) {
            for(int i = 0;i < n;i++) {
                for(int j = 0;j < n;j++) {
                    dp1[i][j] = dp3[i][j];
                    a[i][j] = b[i][j];
                    swap = true;
                }
            }
        }

        int vx = n - 1;
        int vy = n - 1;
        ArrayList<Character> ans = new ArrayList<>();

        while(vx != 0 || vy != 0) {
            if (vx == 0) {
                vy--;
                ans.add('R');
                continue;
            }

            if (vy == 0) {
                vx--;
                ans.add('D');
                continue;
            }

            if (swap ^ dp1[vx - 1][vy] < dp1[vx][vy - 1]) {
                ans.add('D');
                vx--;
            }else{
                ans.add('R');
                vy--;
            }

        }
        pw.println(Math.max(dp1[n - 1][n - 1], 0));
        for(int i = ans.size() - 1;i >= 0;i--) pw.print(ans.get(i));
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

    static double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }
}