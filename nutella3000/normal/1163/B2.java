import java.io.*;
import java.lang.reflect.Array;
import java.util.*;
public class Main {
    static int inf = (int) 1e9 + 7;
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        int n = nextInt();
        int a[] = new int [200000];
        int cnt[] = new int [200000];
        int sz_cnt = 0;
        int ans = 0;
        for(int i = 0;i < n;i++) {
            int b = nextInt();
            a[b]++;
            if (a[b] != 1) {
                cnt[a[b] - 1]--;
                if (cnt[a[b] - 1] == 0) sz_cnt--;
            }
            cnt[a[b]]++;
            if (cnt[a[b]] == 1) sz_cnt++;
            if (sz_cnt == 1 && (a[b] == 1 || cnt[a[b]] == 1)) ans = i;
            if (sz_cnt == 2) {
                if (cnt[a[b] + 1] == 1) ans = i;
                if (cnt[a[b] - 1] > 0 && cnt[a[b]] == 1) ans = i;
                if (cnt[1] == 1) ans = i;
            }
        }
        pw.println(ans + 1);
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