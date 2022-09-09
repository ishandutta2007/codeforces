import java.io.*;
import java.util.*;

public class A {
    FastScanner in;
    PrintWriter out;

    int gcd(int x, int y) {
        return x == 0 ? y : gcd(y % x, x);
    }

    int getCost(int n, boolean[] already) {
        boolean[] z = new boolean[n];
        for (int x = 3; x < n; x++) {
            if (!already[x]) {
                continue;
            }
            int g = gcd(n, x);
            int add = n / g;
            for (int i = 0; i < n; i += add) {
                z[i] = true;
            }
        }
        int cost = 0;
        for (int i = 0; i < n; i++) {
            cost += z[i] ? 0 : 1;
        }
        return cost;
    }

    int getAns(int maxN, int k) {
        int res = 0;
        boolean[] already = new boolean[maxN + 1];
        int[] costA = new int[maxN + 1];
        for (int it = 0; it < k; it++) {
            int mincost = Integer.MAX_VALUE;
            int minVal = -1;
            for (int n = 3; n <= maxN; n++) {
                if (already[n]) {
                    continue;
                }
                int cost = getCost(n, already);
                if (cost < mincost) {
                    mincost = cost;
                    minVal = n;
                }
            }
            already[minVal] = true;
            res += mincost;
//            System.err.println("! " + minVal + " " + mincost);
            costA[minVal] = mincost;
        }
//        System.err.println(Arrays.toString(costA));
        return res;
    }

    void solve() {
        int n = in.nextInt();
        int k = in.nextInt();
        out.println(solve(n, k));
    }

    void solvesd() {
        for (int n = 10; n <= 15; n++) {
            System.err.println("n = " + n);
            for (int k = 1; k + 2 <= n; k++) {
                long correct = getAns(n, k);
                long my = solve(n, k);
                if (correct != my) {
                    throw new AssertionError(n + " " + k + " " + correct + " " + my);
                }
            }
        }
    }

    long solve(int maxN, int k) {
        final int MAX = (int) 1e6 + 10;
        int[] prime = new int[MAX];
        Arrays.fill(prime, -1);
        for (int i = 2; i < MAX; i++) {
            if (prime[i] == -1) {
                for (int j = i; j < MAX; j += i) {
                    prime[j] = i;
                }
            }
        }
        int[] phi = new int[MAX];
        for (int i = 2; i < MAX; i++) {
            int n = i;
            int result = n;
            while (n != 1) {
                int pr = prime[n];
                while (n % pr == 0) {
                    n /= pr;
                }
                result -= result / pr;
            }
            phi[i] = result;
        }
        long cost = 1;
        if (k >= 2) {
            cost++;
        }
        List<Integer>[] where = new ArrayList[MAX + 1];
        for (int i = 0; i < where.length; i++) {
            where[i] = new ArrayList<>();
        }
//        System.err.println("NEED " + k);
        for (int i = 3; i <= maxN; i++) {
            where[phi[i]].add(i);
//            System.err.println("!" + phi[i]);
        }
        for (int c = 2; k != 0; c++) {
            int sz = where[c].size();
            int use = Math.min(k, sz);
            k -= use;
            cost += c * 1L * use;
        }
        return cost;
    }

    void solve22() {
//        for (int n = 3; n <= 40; n++) {
//            for (int k = 1; k <= n - 3; k++) {
//                System.err.print(getAns(n, k) + " ");
//            }
//            System.err.println();
//        }
        getAns(60, 50);
//        out.println(getAns(in.nextInt(), in.nextInt()));
    }

    void solve123() {
        for (int n = 3; n <= 50; n++) {
            boolean[] z = new boolean[n];
            for (int x = 3; x < n; x++) {
                int g = gcd(n, x);
                int add = n / g;
                for (int i = 0; i < n; i += add) {
                    z[i] = true;
                }
            }
            int cost = 0;
            for (int i = 0; i < n; i++) {
                cost += z[i] ? 0 : 1;
            }
            System.err.println(n + " -> " + cost);
        }
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