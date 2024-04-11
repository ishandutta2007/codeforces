import java.io.*;
import java.util.*;

public class Main {
    static int inf = (int) 1e9 + 7;

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        int n = nextInt();
        char h[] = next().toCharArray();
        int cnt[][] = new int [2][n];
        cnt[h[0] - 'A'][0] = 1;
        for(int i = 1;i < n;i++) {
            cnt[0][i] = cnt[0][i - 1];
            cnt[1][i] = cnt[1][i - 1];
            cnt[h[i] - 'A'][i]++;
        }

        long ans = 0;
        for(int i = 0;i < n - 1;i++) {
            if (h[i] == h[i + 1]) {
                ans += n - i - 2;
                if (cnt[1 - (h[i] - 'A')][n - 1] == cnt[1 - (h[i] - 'A')][i]) ans++;
            }else{
                int l = -1;
                int r = n;
                while(r - l > 1) {
                    int m =((l + r) >> 1);
                    if (cnt[h[i] - 'A'][m] > cnt[h[i] - 'A'][i]) r = m;
                    else l = m;
                }

                ans += Math.min(n - i - 2, n - r);
            }
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