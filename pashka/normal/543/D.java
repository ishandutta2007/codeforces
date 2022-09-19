import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.StringTokenizer;

/**
 * @author Pavel Mavrin
 */
public class D {

    private static final long MOD = (long) (1e9 + 7);
    private static final BigInteger BI_MOD = BigInteger.valueOf(MOD);

    private void solve() throws IOException {
        int n = nextInt();
        init(n, n - 1);
        for (int i = 0; i < n - 1; i++) {
            addEdge(nextInt() - 1, i + 1);
        }
        dd = new long[m];
        mm = new long[n];
        mp = new long[m];
        ms = new long[m];
        pp = new long[n];
        cc = new int[n];
        dfs1(0, -1);
        dfs2(0, -1, -1);
        for (int i = 0; i < n; i++) {
            System.out.println(mm[i] * pp[i] % MOD);
        }
    }

    void init(int n, int m) {
        m *= 2;
        this.n = n;
        this.m = m;
        last = 0;
        head = new int[n];
        nx = new int[m];
        dst = new int[m];
        Arrays.fill(head, -1);
    }

    void addEdge(int x, int y) {
        nx[last] = head[x];
        dst[last] = y;
        head[x] = last;
        last++;
        nx[last] = head[y];
        dst[last] = x;
        head[y] = last;
        last++;
    }

    int[] cc;

    private int dfs1(int x, int p) {
        int j = head[x];
        mm[x] = 1;
        while (j >= 0) {
            int y = dst[j];
            if (y != p) {
                dfs1(y, x);
                dd[j] = (1 + mm[y]) % MOD;
                mm[x] = (mm[x] * dd[j]) % MOD;
            }
            j = nx[j];
        }
        j = head[x];
        int n = 0;
        while (j >= 0) {
            int y = dst[j];
            if (y != p) {
                cc[n++] = j;
            }
            j = nx[j];
        }
        if (n > 0) {
            mp[cc[0]] = 1;
            for (int i = 0; i < n - 1; i++) {
                mp[cc[i + 1]] = mp[cc[i]] * dd[cc[i]] % MOD;
            }
            ms[cc[n - 1]] = 1;
            for (int i = n - 1; i >= 1; i--) {
                ms[cc[i - 1]] = ms[cc[i]] * dd[cc[i]] % MOD;
            }
//            for (int i = 0; i < n; i++) {
//                System.out.println(mp[cc[i]] + " " + ms[cc[i]]);
//            }
        }
        return 0;
    }


    private int dfs2(int x, int p, int e) {
        pp[x] = 1;
        if (p >= 0) {
            int j = head[x];
            while (j >= 0) {
                int y = dst[j];
                if (y == p) {
                    dd[j] = mp[e] * ms[e];
                    dd[j] %= MOD;
                    dd[j] *= pp[p];
                    dd[j] %= MOD;
                    dd[j]++;
                    dd[j] %= MOD;
                    pp[x] = dd[j];
                }
                j = nx[j];
            }
        }
        int j = head[x];
        while (j >= 0) {
            int y = dst[j];
            if (y != p) {
                dfs2(y, x, j);
            }
            j = nx[j];
        }
        return 0;
    }

    private long inv(long l) {
        return BigInteger.valueOf(l).modInverse(BI_MOD).longValue();
    }

    int n, m;
    int[] head;
    int[] nx;
    int[] dst;
    int last;
    long[] dd;
    long[] pp;
    long[] mm;
    long[] mp;
    long[] ms;

    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st;
    PrintWriter out = new PrintWriter(System.out);

    String next() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return st.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    public static void main(String[] args) throws IOException {
        new D().run();
    }

    private void run() throws IOException {
        solve();
        out.close();
    }

}