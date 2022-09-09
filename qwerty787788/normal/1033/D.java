import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class A {
    FastScanner in;
    PrintWriter out;

    void solve() {
        int max = (int) (Math.pow(2e18, 1 / 3.0) + 5);
        boolean[] isPrime = new boolean[max];
        Arrays.fill(isPrime, true);
        int cnt = 0;
        final int TOTAL_CNT = 97177;
        int[] allPrimes = new int[TOTAL_CNT];
        for (int v = 2; v < isPrime.length; v++) {
            if (!isPrime[v]) {
                continue;
            }
            allPrimes[cnt++] = v;
            for (int x = v + v; x < isPrime.length; x += v) {
                isPrime[x] = false;
            }
        }
        int n = in.nextInt();
        int[] used = new int[allPrimes.length];
        List<Long> bigVals = new ArrayList<>();
        Set<Long> interPrimes = new HashSet<>();
        for (int i = 0; i < n; i++) {
            long value = in.nextLong();
            for (int j = allPrimes.length - 1; j >= 0; j--) {
                int prime = allPrimes[j];
                while (value % prime == 0) {
                    used[j]++;
                    value /= prime;
                }
            }
            if (value > 1) {
                long tmp = Math.round(Math.sqrt(value));
                if (tmp * tmp == value) {
                    interPrimes.add(tmp);
                }
                bigVals.add(value);
            }
        }
        for (long x : bigVals) {
            for (long y : bigVals) {
                long g = gcd(x, y);
                if (g != 1 && g != x && g != y) {
                    interPrimes.add(g);
                }
            }
        }
        final long mod = 998244353;
        long res = 1;
        for (int i : used) {
            res = res * (i + 1) % mod;
        }
//        System.err.println("?? " + res);
        boolean[] wasDivided = new boolean[bigVals.size()];
        for (long p : interPrimes) {
//            if (!BigInteger.valueOf(p).isProbablePrime(30)) {
//                throw new AssertionError();
//            }
            int cc = 0;
            for (int i = 0; i < bigVals.size(); i++) {
                while (bigVals.get(i) % p == 0) {
                    wasDivided[i] = true;
//                    System.err.println("prime " + p);
                    cc++;
                    bigVals.set(i, bigVals.get(i) / p);
                }
            }
//            System.err.println(p + "---> " + cc);
            res = res * (cc + 1) % mod;
        }
        Collections.sort(bigVals);
if (bigVals.size() > 555) throw new AssertionError();
        for (int i = 0; i < bigVals.size(); ) {
            int j = i;
            while (j != bigVals.size() && bigVals.get(i).equals(bigVals.get(j))) {
                j++;
            }
            int cc = j - i;

//            System.err.println("cc = " + cc + ", res = " + res + " , " + bigVals.get(i));

            if (bigVals.get(i) != 1) {
                res = res * (cc + 1) % mod;
//                if (!wasDivided[i]) {
                if (!BigInteger.valueOf(bigVals.get(i)).isProbablePrime(15)) {
                    res = res * (cc + 1) % mod;
                }
            }

            i = j;
        }
        out.println(res);
    }

    long gcd(long x, long y) {
        return x == 0 ? y : gcd(y % x, x);
    }

    void run() {
        try {
            in = new FastScanner(new File("A.in"));
            out = new PrintWriter(new File("A.out"));

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
        new A().runIO();
    }
}