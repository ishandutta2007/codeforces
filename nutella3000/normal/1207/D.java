import java.io.*;
import java.util.*;
public class Main {
    static int inf = (int) 1e9 + 7;
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        int n = nextInt();
        int mod =   998244353;
        long fact[] = new long [n + 1];
        fact[0] = 1;
        for(int i = 1;i <= n;i++) fact[i] = (fact[i - 1] * i) % mod;
        long ans = 0;
        pair a[] = new pair[n];
        for(int i = 0;i < n;i++) a[i] = new pair(nextInt(), nextInt());
        Arrays.sort(a, new pair());
        boolean bad = false;
        int last = 0;
        for(int i = 0;i < n;i++) {
            if (last > a[i].b) {
                bad = true;
            }
            last = a[i].b;
        }
        if (!bad) {
            int cnt = 1;
            long u = 1;
            for(int i = 1;i < n;i++) {
                if (a[i].a != a[i - 1].a || a[i].b != a[i - 1].b) {
                    u = (u * fact[cnt]) % mod;
                    cnt = 1;
                }else cnt++;
            }
            u = (u * fact[cnt]) % mod;
            ans += u;
        }
        long u = 1;
        int cnt = 1;
        for(int i = 1;i < n;i++) {
            if (a[i].a != a[i - 1].a) {
                u = (u * fact[cnt]) % mod;
                cnt = 1;
            }else cnt++;
        }
        u = (u * fact[cnt]) % mod;
        ans -= u;

        cnt = 1;
        u = 1;

        for(int i = 0;i < n;i++) {
            int t = a[i].a;
            a[i].a = a[i].b;
            a[i].b = t;
        }
        Arrays.sort(a, new pair());

        for(int i = 1;i < n;i++) {
            if (a[i].a != a[i - 1].a) {
                u = (u * fact[cnt]) % mod;
                cnt = 1;
            }else cnt++;
        }
        u = (u * fact[cnt]) % mod;
        ans -= u;
        ans += fact[n];
        ans = (ans % mod + mod) % mod;
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

class pair implements Comparator<pair>{
    int a, b;
    pair(int x, int y) {
        a = x;
        b = y;
    }

    pair() {}

    @Override
    public int compare(pair pair, pair t1) {
        return Integer.compare(pair.a, t1.a) * 2 + Integer.compare(pair.b, t1.b);
    }
}