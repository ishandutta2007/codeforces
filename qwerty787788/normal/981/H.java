import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class H {
    FastScanner in;
    PrintWriter out;

    int n, k;

    List<Integer>[] g;

    final int mod = 998244353;

    int add(int x, int y) {
        x += y;
        return x >= mod ? (x - mod) : x;
    }

    int mul(int x, int y) {
        return (int) (x * 1L * y % mod);
    }

    int sub(int x, int y) {
        x -= y;
        return x >= 0 ? x : (x + mod);
    }

    int res = 0;
    int[] sizes;
    int[] dp;

    final static int LOG = 18;
    static NTT[] ntts = new NTT[LOG];
    static {
        for (int i = 0; i < ntts.length; i++) {
            ntts[i] = new NTT(1 << i);
        }
    }

    int[] mulFast(int[] a, int[] b) {
        for (int i = 0; i < ntts.length; i++) {
            int len = 1 << i;
            if (a.length + b.length + 2 < len) {
                int[] r = ntts[i].multiply(a, b);
                int lastNotZero = 0;
                for (int j = 0; j < r.length; j++) {
                    if (r[j] != 0) {
                        lastNotZero = j;
                    }
                }
                return Arrays.copyOf(r, lastNotZero + 1);
            }
        }
        throw new AssertionError();
    }

    int[] mulSlow(int[] a, int[] b) {
        int[] c = new int[a.length + b.length - 1];
        for (int i = 0; i < a.length; i++) {
            for (int j = 0; j < b.length; j++) {
                c[i + j] = add(c[i + j], mul(a[i], b[j]));
            }
        }
        return c;
    }

    int[] calc(List<Integer> list, int fr, int to) {
        if (to == -1) {
            return new int[]{1};
        }
        if (fr == to) {
            return new int[]{1, list.get(fr)};
        } else {
            int mid = (fr + to) >> 1;
            int[] left = calc(list, fr, mid);
            int[] right = calc(list, mid + 1, to);
            return mulFast(left, right);
        }
    }

    int globalIter = 0;

    int[] cachedIter;
    int[] cachedRes;
    int[] inv;
    int[] buf;

    int realDivide(int[] vals, int divSub) {
        int n = vals.length;
        for (int i =0 ; i < n; i++) {
            buf[i] = vals[i];
        }
        int in = inv[divSub];
        int sum = 0;
        for (int i = n - 1; i > 0; i--) {
            int cur = mul(buf[i], in);
            buf[i - 1] = sub(buf[i - 1], cur);
            if (i <= k + 1) {
                sum = add(sum, mul(mulCoef[i - 1], cur));
            }
        }
        if (n > 0 && buf[0] != 0) {
            throw new AssertionError();
        }
        return sum;
    }

    int divide(int[] vals, int divSub) {
        if (cachedIter[divSub] == globalIter) {
            return cachedRes[divSub];
        }
        cachedIter[divSub] = globalIter;
        return cachedRes[divSub] = realDivide(vals, divSub);
    }

    void go(int v, int p) {
        sizes[v] = 1;
        List<Integer> childSizes = new ArrayList<>();
        int chSum = 0;
        for (int to : g[v]) {
            if (to == p) {
                continue;
            }
            go(to, v);
            childSizes.add(sizes[to]);
            sizes[v] += sizes[to];
            dp[v] = add(dp[v], dp[to]);
            res = add(res, mul(chSum, dp[to]));
            chSum = add(chSum, dp[to]);
        }
        int[] total = calc(childSizes, 0, childSizes.size() - 1);
        int sum = 0;
        for (int pos = 0; pos <= k && pos < total.length; pos++) {
            sum = add(sum, mul(mulCoef[pos], total[pos]));
        }
        dp[v] = add(dp[v], sum);
        total = mulSlow(total, new int[]{1, n - sizes[v]});
        globalIter++;
        for (int to : g[v]) {
            if (to == p) {
                continue;
            }
            res = add(res, mul(dp[to], divide(total, sizes[to])));
        }
    }

    int[] fact, factInv;
    int[] mulCoef;

    int c(int n ,int k) {
        return mul(fact[n], mul(factInv[k], factInv[n - k]));
    }

    void solve123() {
        Random rnd =new Random(12);
        for (int it = 0; it < 123123; it++) {
            int n = 1 + rnd.nextInt(100);
            int m = 1 + rnd.nextInt(100);
            int[] a = new int[n];
            for(int i =0 ; i < n; i++) {
                a[i] = rnd.nextInt(mod);
            }
            int[] b = new int[m];
            for (int i = 0; i < m; i++) {
                b[i] = rnd.nextInt(mod);
            }
            int[] c = mulSlow(a, b);
            int[] d = mulFast(a, b);
            for (int i =0 ; i < Math.max(c.length, d.length); i++) {
                int v1 =i < c.length ? c[i] : 0;
                int v2 =i < d.length ? d[i] : 0;
                if (v1 != v2) {
                    throw new AssertionError();
                }
            }
            System.err.println("iter = " + it);
        }
    }

    void solve() {
        n = in.nextInt();
        k = in.nextInt();
        inv = new int[n + 3];
        BigInteger MOD = BigInteger.valueOf(mod);
        for (int i = 1; i < inv.length; i++) {
            inv[i] = BigInteger.valueOf(i).modInverse(MOD).intValue();
        }
        if (k == 1) {
            res = mul(n, mul(n - 1, inv[2]));
            out.println(res);
            return;
        }
        final int MAX =Math.max(n, k) + 1;
        fact = new int[MAX];
        factInv = new int[MAX];
        fact[0] = 1;
        for (int i = 1; i < fact.length; i++) {
            fact[i] = mul(fact[i - 1], i);
        }
        factInv[factInv.length - 1] = BigInteger.valueOf(fact[fact.length - 1]).modInverse(MOD).intValue();
        for (int i = factInv.length - 1; i > 0; i--) {
            factInv[i - 1] = mul(factInv[i], i);
        }
        mulCoef = new int[k + 1];
        for (int sz = 0; sz < mulCoef.length; sz++) {
            mulCoef[sz] = mul(c(k, sz), fact[sz]);
        }
        g = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            g[i] = new ArrayList<>();
        }
        for (int i = 0; i + 1 < n; i++) {
            int fr = in.nextInt() - 1;
            int to = in.nextInt() - 1;
            g[fr].add(to);
            g[to].add(fr);
        }
        sizes = new int[n];
        dp = new int[n];
        cachedRes = new int[n + 1];
        cachedIter = new int[n + 1];
        buf = new int[MAX + 1];
        go(0, 0);
        out.println(res);
    }

    public static class NTT {
        public int MOD = 7 * 17 * (1 << 23) + 1;
        public int G = 3;

        private int[] omegas;
        private int[] tail;
        private int len, log, lenInv;

        public NTT(int size) {
            len = 1;
            log = 0;
            while (len < size) {
                len *= 2;
                log++;
            }
            int OMEGA = (int) modPow(G, (MOD - 1) / len, MOD);
            omegas = new int[len];
            tail = new int[len];
            omegas[0] = 1;
            tail[0] = 0;
            for (int i = 1; i < len; i++) {
                omegas[i] = (int) ((long) omegas[i - 1] * OMEGA % MOD);
                tail[i] = (tail[i >> 1] >> 1) | ((i & 1) << (log - 1));
            }
            lenInv = (int) inv(len, MOD);
            tmp1 = new int[len];
            tmp2 = new int[len];
        }

        int[] tmp1, tmp2;

        public int[] multiply(int[] a, int[] b) {
            for (int i = 0; i < len; i++) {
                tmp1[i] = i < a.length ? a[i] : 0;
                tmp2[i] = i < b.length ? b[i] : 0;
            }
            ntt(tmp1);
            ntt(tmp2);
            for (int i = 0; i < len; i++) {
                tmp1[i] = (int) ((long) tmp1[i] * tmp2[i] % MOD * lenInv % MOD);
            }
            ntt(tmp1);
            for (int i = 1, j = len - 1; i < j; i++, j--) {
                int swap = tmp1[i];
                tmp1[i] = tmp1[j];
                tmp1[j] = swap;
            }
            return tmp1;
        }

        void ntt(int[] a) {
            for (int i = 1; i < len; i++) {
                if (i < tail[i]) {
                    int tmp = a[i];
                    a[i] = a[tail[i]];
                    a[tail[i]] = tmp;
                }
            }
            for (int len = 1; len < a.length; len *= 2) {
                int step = a.length / len / 2;
                for (int i = 0; i < a.length; i += len << 1) {
                    int pos = 0;
                    for (int j = i, k = j + len; j < i + len; j++, k++) {
                        int u = a[j], v = (int) ((long) a[k] * omegas[pos] % MOD);
                        a[j] = u + v;
                        a[k] = u - v;
                        if (a[j] >= MOD) {
                            a[j] -= MOD;
                        }
                        if (a[k] < 0) {
                            a[k] += MOD;
                        }
                        pos += step;
                    }
                }
            }
        }
    }


    public static int modPow(int a, long b, int mod) {
        while (a < 0) {
            a += mod;
        }
        int res = 1;
        while (b > 0) {
            if ((b & 1) != 0) {
                res = (int) ((long) res * a % mod);
            }
            a = (int) ((long) a * a % mod);
            b >>>= 1;
        }
        return res;
    }

    public static long modPow(long a, long b, long mod) {
        while (a < 0) {
            a += mod;
        }
        long res = 1;
        while (b > 0) {
            if ((b & 1) != 0) {
                res = res * a % mod;
            }
            a = a * a % mod;
            b >>>= 1;
        }
        return res;
    }

    public static long inv(long a, long mod) {
        return modPow(a, mod - 2, mod);
    }



    void run() {
        try {
            in = new FastScanner(new File("H.in"));
            out = new PrintWriter(new File("H.out"));

            solve();

            out.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    void runIO() {

        in = new FastScanner(System.in);
        out = new PrintWriter(System.out);

        solve();

        out.close();
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(File f) {
            try {
                br = new BufferedReader(new FileReader(f));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        public FastScanner(InputStream f) {
            br = new BufferedReader(new InputStreamReader(f));
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                String s = null;
                try {
                    s = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (s == null)
                    return null;
                st = new StringTokenizer(s);
            }
            return st.nextToken();
        }

        boolean hasMoreTokens() {
            while (st == null || !st.hasMoreTokens()) {
                String s = null;
                try {
                    s = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (s == null)
                    return false;
                st = new StringTokenizer(s);
            }
            return true;
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }
    }

    public static void main(String[] args) {
        new H().runIO();
    }
}