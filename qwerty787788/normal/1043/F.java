import java.io.*;
import java.util.*;

public class A {
    FastScanner in;
    PrintWriter out;

    int[] prime;
    int[] divs = new int[7];
    int dCnt;

    void go(int value) {
        dCnt = 0;
        while (value != 1) {
            int p = prime[value];
            divs[dCnt++] = p;
            while (value % p == 0) {
                value /= p;
            }
        }
    }

    void solve() {
        long START = System.currentTimeMillis();
        int n = in.nextInt();
        final int MAX = (int) 3e5 + 10;
        prime = new int[MAX];
        Arrays.fill(prime, -1);
        for (int i = 2; i < MAX; i++) {
            if (prime[i] == -1) {
                prime[i] = i;
                for (int j = i + i; j < MAX; j += i) {
                    prime[j] = i;
                }
            }
        }
        boolean[] has = new boolean[MAX];
        for (int i = 0; i < n; i++) {
            has[in.nextInt()] = true;
        }
        if (has[1]) {
            out.println(1);
            return;
        }
        int g = 0;
        for (int i = 0; i < MAX; i++) {
            if (has[i]) {
                g = gcd(g, i);
            }
        }
        if (g != 1) {
            out.println(-1);
            return;
        }
        int[] cntPrimes = new int[MAX];
        for (int i = 2; i < MAX; i++) {
            if (has[i]) {
                go(i);
                for (int j = 0; j < dCnt; j++) {
                    cntPrimes[divs[j]]++;
                }
            }
        }
        int bestPrime = -1, cntIn = -1;
        for (int i = 0; i < MAX; i++) {
            if (cntPrimes[i] > cntIn) {
                cntIn = cntPrimes[i];
                bestPrime = i;
            }
        }
        List<Integer> check = new ArrayList<>();
        for (int i = 0; i < MAX; i++) {
            if (has[i] && i % bestPrime != 0) {
                check.add(i);
            }
        }
        Collections.shuffle(check);
        int res = 7;
        int allCnt = 0;
        for (boolean b : has) {
            if (b) {
                allCnt++;
            }
        }
        int[] allNumbers = new int[allCnt];
        for (int i = 0; i < MAX; i++) {
            if (has[i]) {
                allCnt--;
                allNumbers[allCnt] = i;
            }
        }
        int[] cost = new int[MAX];
        for (int i = 1; i < MAX; i++) {
            go(i);
            for (int j = 0; j < dCnt; j++) {
                cost[i] += cntPrimes[divs[j]];
            }
        }
        for (int c : check) {
            go(c);
            int primes = dCnt;
            int[] usePrimes = new int[primes];
            for (int i = 0; i < primes; i++) {
                usePrimes[i] = divs[i];
            }
            int[] minCost = new int[1 << primes];
            int[] bestGCD = new int[1 << primes];
            Arrays.fill(minCost, Integer.MAX_VALUE);
            for (int num : allNumbers) {
                int mask = 0;
                for (int i = 0; i < primes; i++) {
                    if (num % usePrimes[i] == 0) {
                        while (num % usePrimes[i] == 0) {
                            num /= usePrimes[i];
                        }
                        mask |= 1 << i;
                    }
                }
                if (minCost[mask] > 1 || minCost[mask] == 1 && cost[bestGCD[mask]] > cost[num]) {
                    minCost[mask] = 1;
                    bestGCD[mask] = num;
                }
            }
            for (int mask1 = (1 << primes) - 1; mask1 >= 1; mask1--) {
                if (minCost[mask1] == Integer.MAX_VALUE) {
                    continue;
                }
                for (int mask2 = mask1 - 1; mask2 >= 1; mask2--) {
                    if (minCost[mask2] != Integer.MAX_VALUE) {
                        int nmask = mask1 & mask2;
                        int ncost = minCost[mask1] + minCost[mask2];
                        int ngcd = gcd(bestGCD[mask1], bestGCD[mask2]);
                        if (minCost[nmask] > ncost || minCost[nmask] == ncost && cost[bestGCD[nmask]] > cost[ngcd]) {
                            minCost[nmask] = ncost;
                            bestGCD[nmask] = ngcd;
                        }
                    }
                }
            }
            if (minCost[0] != Integer.MAX_VALUE) {
                int curRes = minCost[0] + (bestGCD[0] == 1 ? 0 : 1);
                res = Math.min(res, curRes);
            }

            if (System.currentTimeMillis() - START > 2000) {
                break;
            }
        }
        out.println(res);
    }

    int gcd(int x, int y) {
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