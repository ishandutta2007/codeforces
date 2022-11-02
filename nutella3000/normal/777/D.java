import java.io.*;
import java.util.*;
public class Main {
    static int inf = (int) 1e9 + 7;

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        int n = nextInt() - 1;

        char starter_pack[][] = new char[n + 1][];
        int ans_id[][] = new int [n + 1][];

        char last[] = next().toCharArray();
        int dp[] = new int [last.length];
        for(int i = 0;i < last.length;i++) {
            dp[i] = last.length - i - 1;
        }

        starter_pack[0] = last;

        while(n-- > 0) {
            char v[] = next().toCharArray();
            int sz1 = last.length;
            int sz2 = v.length;
            int new_dp[] = new int [sz2];

            starter_pack[starter_pack.length - n - 1] = v;
            ans_id[ans_id.length - n - 1] = new int [sz2];

            int id = 1;
            int min = dp[0];
            int min_id = 0;
            for(int i = 0;i < sz2;i++) {
                if (id != sz1) {
                    if (id == i && v[i] == last[id]) {
                        if (min > dp[id]) {
                            min_id = id;
                            min = dp[id++];
                        }
                    }

                    if (id == i && last[id] < v[i]) {
                        while(id != sz1) {
                            if (min > dp[id]) {
                                min_id = id;
                                min = dp[id++];
                            }
                        }
                    }
                }

                new_dp[i] = sz2 - i - 1 + min;
                ans_id[ans_id.length - n - 1][i] = min_id;
            }

            dp = new_dp;
            last = v;
        }

        int ans = inf;
        int v = 0;
        for(int i = 0;i < dp.length;i++) {
            if (ans > dp[i]) {
                ans = dp[i];
                v = i;
            }
        }
        //pw.println(ans);

        int id[] = new int [ans_id.length];
        int x = ans_id.length - 1;
        while(x != 0) {
            id[x] = v;
            v = ans_id[x--][v];
        }
        id[0] = v;

        for(int i = 0;i < ans_id.length;i++) {
            for(int j = 0;j <= id[i];j++) {
                pw.print(starter_pack[i][j]);
            }
            pw.println();
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