import java.io.*;
import java.lang.reflect.Array;
import java.math.BigInteger;
import java.util.*;
public class Main {
    static int inf = (int) 1e9 + 7;
    static int n, k;
    static ArrayList<pair> gr[];
    static long dp_f[], dp[];

    static void dfs(int v, int pr) {
        long sum = 0;
        ArrayList<Long> r = new ArrayList<>();
        for(pair i : gr[v]) {
            if (i.to == pr) continue;
            dfs(i.to, v);
            sum += dp_f[i.to];
            r.add(dp[i.to] + i.x - dp_f[i.to]);
        }
        Collections.sort(r);
        int cnt = 0;

        dp[v] = sum;
        dp_f[v] = sum;

        for(int i = r.size() - 1;i >= 0;i--) {
            if (r.get(i) < 0) break;
            sum += r.get(i);
            cnt++;
            if (cnt < k) dp[v] = sum;
            if (cnt <= k) dp_f[v] = sum;
        }
    }

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        int q = nextInt();
        while(q-- > 0) {
            n = nextInt();
            k = nextInt();
            gr = new ArrayList[n];
            dp_f = new long[n];
            dp = new long[n];
            for(int i = 0;i < n;i++) gr[i] = new ArrayList<>();
            for(int i = 0;i < n - 1;i++) {
                int v1 = nextInt() - 1;
                int v2 = nextInt() - 1;
                int w = nextInt();
                gr[v1].add(new pair(v2, w));
                gr[v2].add(new pair(v1, w));
            }
            dfs(0, -1);
            pw.println(dp_f[0]);
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

class pair {
    int to, x;
    pair(int to, int x) {
        this.to = to;
        this.x = x;
    }

    pair() {}
}