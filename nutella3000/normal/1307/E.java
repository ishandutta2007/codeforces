import java.io.*;
import java.util.*;


public class Main {
    static int inf = (int)(1e9 + 7);
    static int n, m;
    static int a[];
    static int pref[][];
    static int max = 0;
    static long ans = 0;
    static int cnt1[], cnt2[];



    static void find_max() {
        for(int i = 0;i < n;i++) cnt2[a[i]]++;
        for(int i = 0;i <= n;i++) {
            int new_max = 0;
            for(int j = 0;j <= n;j++) {
                int v1 = Math.min(cnt1[j], cnt2[j]);
                int v2 = Math.max(cnt1[j], cnt2[j]);

                if (pref[j][v1] >= 1 && pref[j][v2] >= 2) new_max += 2;
                else if (pref[j][v2] == 0);
                else new_max++;
            }
            max = Math.max(max, new_max);

            if (i != n) {
                cnt2[a[i]]--;
                cnt1[a[i]]++;
            }
        }
    }



    static void scan() throws IOException {
        n = sc.nextInt();
        m = sc.nextInt();
        a = new int [n];
        cnt1 = new int [n + 1];
        cnt2 = new int [n + 1];
        pref = new int [n + 1][n + 1];
        for(int i = 0;i < n;i++) a[i] = sc.nextInt();
        for(int i = 0;i < m;i++) {
            int f = sc.nextInt();
            int h = sc.nextInt();
            pref[f][h]++;
        }
        for(int i = 0;i <= n;i++) {
            for(int j = 1;j <= n;j++) pref[i][j] += pref[i][j - 1];
        }

    }

    static void find_ans() {
        for(int i = 0;i <= n;i++) {
            cnt1[i] = 0;
            cnt2[i] = 0;
        }


        for(int i = 0;i < n;i++) cnt2[a[i]]++;
        for(int i = 0;i <= n;i++) {
            int new_max = 0;
            for(int j = 0;j <= n;j++) {
                // cnt1[j] cnt2[j]
                int v1 = Math.min(cnt1[j], cnt2[j]);
                int v2 = Math.max(cnt1[j], cnt2[j]);

                if (pref[j][v1] >= 1 && pref[j][v2] >= 2) new_max += 2;
                else if (pref[j][v2] == 0);
                else new_max++;
            }
            if (max == new_max) {
                long add_ans = 1;

                for(int j = 0;j <= n;j++) {
                    int v1 = Math.min(cnt1[j], cnt2[j]);
                    int v2 = Math.max(cnt1[j], cnt2[j]);

                    if (i == 0 || j != a[i - 1]) {
                        if (pref[j][v1] >= 1 && pref[j][v2] >= 2) {
                            add_ans = add_ans * pref[j][v1] % inf * (pref[j][v2] - 1) % inf;
                        } else if (pref[j][v2] == 0) ;
                        else {
                            add_ans = add_ans * (pref[j][v2] + pref[j][v1]) % inf;
                        }
                    }else{
                        boolean cal = true;
                        if (cnt1[j] == 0 && pref[j][0] >= 1) cal = false;
                        if (cnt1[j] != 0 && pref[j][cnt1[j]] - pref[j][cnt1[j] - 1] >= 1) cal = false;
                        if (cal) add_ans = 0;
                        long add = 1;
                        if (cnt2[j] < cnt1[j] && pref[j][cnt2[j]] != 0) add = pref[j][cnt2[j]];
                        else if (cnt2[j] >= cnt1[j] && pref[j][cnt2[j]] - 1 != 0) add = pref[j][cnt2[j]] - 1;

                        add_ans = add_ans * add % inf;
                    }
                }

                ans = (ans + add_ans) % inf;
            }

            if (i != n) {
                cnt2[a[i]]--;
                cnt1[a[i]]++;
            }
        }
    }

    static void solve() throws IOException {
        scan();
        find_max();
        find_ans();
        pw.println(max + " " + ans);
    }





    public static void main(String[] args) throws IOException {
        sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        solve();
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