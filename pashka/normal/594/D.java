import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

/**
 * @author Pavel Mavrin
 */
public class D {

    private static final long MOD = (long) (1e9 + 7);
    public static final BigInteger BMOD = BigInteger.valueOf(MOD);
    public static final int MAX = 1000002;

    private void solve() throws IOException {
        int n = nextInt();
        long[] a = new long[n];
        for (int i = 0; i < n; i++) {
            a[i] = nextInt();
        }
        int qn = nextInt();
        int[][] qq = new int[qn][3];
        for (int i = 0; i < qn; i++) {
            qq[i][0] = nextInt() - 1;
            qq[i][1] = nextInt() - 1;
            qq[i][2] = i;
        }
        Arrays.sort(qq, new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                return Integer.compare(o1[1], o2[1]);
            }
        });

        boolean[] p = new boolean[1000000];
        int[] primes = new int[1000000];
        int pn = 0;
        Arrays.fill(p, true);
        for (int i = 2; i < p.length; i++) {
            if (p[i]) {
                primes[pn++] = i;
                if (1l * i * i < p.length) {
                    for (int j = i * i; j < p.length; j += i) {
                        p[j] = false;
                    }
                }
            }
        }

        long[] pr = new long[n + 1];
        pr[0] = 1;
        for (int i = 0; i < n; i++) {
            pr[i + 1] = (pr[i] * a[i]) % MOD;
        }
        int[] last = new int[MAX];
        Arrays.fill(last, -1);

        long[] mm = new long[MAX];
        long[] invmm = new long[MAX];
        for (int i = 0; i < pn; i++) {
            mm[primes[i]] = (1l * (primes[i] - 1) * inv(primes[i])) % MOD;
            invmm[primes[i]] = inv(mm[primes[i]]);

        }

        int qc = 0;

        int[] res = new int[qn];

        SegmentTree st = new SegmentTree(n);
        for (int i = 0; i < n; i++) {
            long k = a[i];
            for (int j = 0; j < pn; j++) {
                int c = 0;
                while (true) {
                    long q = k / primes[j];
                    if (q * primes[j] != k) break;
                    k = q;
                    c++;
                }
                if (c > 0) {
                    if (last[primes[j]] != -1) {
                        st.add(last[primes[j]], invmm[primes[j]]);
                    }
                    last[primes[j]] = i;
                    st.add(i, mm[primes[j]]);
                }
                if (k == 1) break;
                if (p[((int) k)]) {
                    int pp = (int)k;
                    if (last[pp] != -1) {
                        st.add(last[pp], invmm[pp]);
                    }
                    last[pp] = i;
                    st.add(i, mm[pp]);
                    break;
                }
            }
            while (qc < qn && qq[qc][1] == i) {
                int l = qq[qc][0];
                int r = i + 1;
                long rr = pr[r] * inv(pr[l]) % MOD;
                rr = rr * st.prod(l, r) % MOD;
                res[qq[qc][2]] = (int) rr;
                qc++;
            }
        }

        for (int re : res) {
            out.println(re);
        }




    }

    private long inv(long q) {
        return BigInteger.valueOf(q).modInverse(BMOD).longValue();
    }

    class SegmentTree {

        private long[] a;
        private int size;
        private int m;

        public SegmentTree(int size) {
            m = 1;
            while (m < size) m *= 2;
            this.size = size;
            a = new long[2 * m];
            Arrays.fill(a, 1);
        }

        private void add(int i, long v) {
            if (v == 0) {
                System.out.println("!!!");
            }
            int t = i + m;
            while (t > 0) {
                a[t] = (a[t] * v) % MOD;
                t >>= 1;
            }
        }

        private long prod(int l, int r) {
            l = l + m;
            r = r + m - 1;
            long res = 1;
            while (r > l) {
                if ((l & 1) == 0) {
                    l = l >> 1;
                } else {
                    res = (res * a[l]) % MOD;
                    l = (l >> 1) + 1;
                }
                if ((r & 1) == 1) {
                    r = r >> 1;
                } else {
                    res = (res *a[r])  %MOD;
                    r = (r >> 1) - 1;
                }
            }
            if (l == r) {
                res = (res * a[l]) %MOD;
            }
            return res;
        }

    }


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