import java.io.IOException;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author niyaznigmatul 
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		FastScanner in = new FastScanner(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskE solver = new TaskE();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskE {

    static int MOD;

    public void solve(int testNumber, FastScanner in, PrintWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        MOD = in.nextInt();
        int[] a = new int[n];
        int maxSet = 0;
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
            maxSet = Math.max(maxSet, a[i]);
        }
//        int[] primes;
//        int[] where;
//        {
//            boolean[] isNotPrime = new boolean[maxSet + 1];
//            for (int i = 2; i * i < isNotPrime.length; i++) {
//                if (isNotPrime[i]) {
//                    continue;
//                }
//                for (int j = i * i; j < isNotPrime.length; j += i) {
//                    isNotPrime[j] = true;
//                }
//            }
//            int count = 0;
//            for (int i = 2; i < isNotPrime.length; i++) {
//                if (isNotPrime[i]) {
//                    continue;
//                }
//                count++;
//            }
//            primes = new int[count];
//            where = new int[isNotPrime.length];
//            count = 0;
//            for (int i = 2; i < isNotPrime.length; i++) {
//                if (isNotPrime[i]) {
//                    continue;
//                }
//                primes[count] = i;
//                where[i] = count++;
//            }
//        }
//        int[][] all = new int[maxSet + 1][];
//        int[] pows = new int[maxSet + 1];
//        int[] c = new int[maxSet + 1];
//        c[0] = 1;
//        int[] primePows = new int[primes.length];
//        int currentC = 1;
//        for (int i = 1; i <= maxSet && i <= m; i++) {
//            int z = m - i + 1;
//            int y = i;
//            for (int j = 0; (y > 1 || z > 1) && j < primes.length; j++) {
//                int prime = primes[j];
//                while (z % prime == 0) {
//                    z /= prime;
//                    primePows[j]++;
//                }
//                while (y % prime == 0) {
//                    y /= prime;
//                    primePows[j]--;
//                }
//            }
//            currentC = (int) ((long) currentC * z % MOD);
//            c[i] = currentC;
//            for (int j = 0; j < primes.length; j++) {
//                for (int k = 0; k < primePows[j]; k++) {
//                    c[i] = (int) ((long) c[i] * primes[j] % MOD);
//                }
//            }
//        }
//        for (int i = 1; i < all.length; i++) {
//            all[i] = new int[i + 1];
//            int current = 1;
//            for (int j = 1; j <= i; j++) {
//                current = (int) ((long) current * (i - j + 1) % MOD);
//                if (j == i) {
//                    pows[j] = 1;
//                } else {
//                    pows[j] = (int) ((long) pows[j] * j % MOD);
//                }
//                all[i][j] = (int) ((long) current * pows[j] % MOD);
//            }
//        }
        int[][] all = new int[maxSet + 1][];
        int[][] all2 = new int[maxSet + 1][];
        all[0] = new int[1];
        all2[0] = new int[1];
        all[0][0] = 1;
        all2[0][0] = 1;
        for (int i = 0; i <= maxSet; i++) {
            if (i < maxSet) {
                all[i + 1] = new int[Math.min(i + 2, m) + 1];
                all2[i + 1] = new int[Math.min(i + 2, m) + 1];
            }
            int[] alli = all[i];
            int[] all2i = all2[i];
            int[] alli1 = i + 1 <= maxSet ? all[i + 1] : null;
            int[] all2i1 = i + 1 <= maxSet ? all2[i + 1] : null;
            for (int j = 0; j < alli.length; j++) {
                if (alli[j] == 0 && all2i[j] == 0) {
                    continue;
                }
                if (i == maxSet) {
                    continue;
                }
                if (j + 1 < alli1.length) {
                    alli1[j + 1] = (int) ((alli1[j + 1] + (long) alli[j] * (m - j)) % MOD);
                    all2i1[j + 1] += all2i[j];
                    if (all2i1[j + 1] >= MOD) {
                        all2i1[j + 1] -= MOD;
                    }
                }
                if (j > 0) {
                    alli1[j] = (int) ((alli1[j] + (long) alli[j] * (j - 1)) % MOD);
                    all2i1[j] = (int) ((all2i1[j] + (long) all2i[j] * (j - 1)) % MOD);
                }
            }
        }
        for (int i = 0; i <= maxSet; i++) {
            int fact = 1;
            for (int j = 0; j < all[i].length; j++) {
                if (j > 0) {
                    fact = (int) ((long) fact * j % MOD);
                }
                all2[i][j] = (int) ((long) all2[i][j] * fact % MOD);
            }
        }
        int[] dp = new int[0];
        int before = 1;
        for (int i = 0; i < n; i++) {
            int[] allai = all[a[i]];
            int[] all2ai = all2[a[i]];
            int[] next = new int[Math.min(a[i], m) + 1];
            int after = 0;
            for (int j = 1; j < next.length; j++) {
                int current = before;
                int current2 = 0;
                if (j < dp.length) {
                    current -= dp[j];
                    current2 = dp[j];
                    if (current < 0) {
                        current += MOD;
                    }
                }
                int good = allai[j] - all2ai[j];
                if (good < 0) {
                    good += MOD;
                }
                long add1 = (long) allai[j] * current;
                long add2 = (long) good * current2;
                next[j] = (int) ((add1 + add2) % MOD);
                after += next[j];
                if (after >= MOD) {
                    after -= MOD;
                }
            }
            before = after;
            dp = next;
        }
        out.println(before % MOD);
    }
}

class FastScanner {
    BufferedReader br;
    StringTokenizer st;
    IOException happened;

    public FastScanner(InputStream is) {
        br = new BufferedReader(new InputStreamReader(is));
    }

    public String next() {
        while (st == null || !st.hasMoreTokens()) {
            try {
                String line = br.readLine();
                st = new StringTokenizer(line);
            } catch (IOException e) {
                happened = e;
                return null;
            }
        }
        return st.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

    }