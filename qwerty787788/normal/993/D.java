import java.io.*;
import java.util.*;

public class A {
    FastScanner in;
    PrintWriter out;

    class O implements Comparable<O> {
        int power, proc;

        public O(int power, int proc) {
            this.power = power;
            this.proc = proc;
        }

        @Override
        public int compareTo(O o) {
            if (power == o.power) {
                return -Integer.compare(proc, o.proc);
            }
            return Integer.compare(o.power, power);
        }

        @Override
        public String toString() {
            return "O{" +
                    "power=" + power +
                    ", proc=" + proc +
                    '}';
        }
    }

    void solve() {
        int n = in.nextInt();
        O[] a = new O[n];
        int[] pw = new int[n];
        for (int i = 0; i < n; i++) {
            pw[i] = in.nextInt();
        }
        int[] pr = new int[n];
        for (int i = 0; i < n; i++) {
            pr[i] = in.nextInt();
        }
        for (int i = 0; i < n; i++) {
            a[i] = new O(pw[i], pr[i]);
        }
        Arrays.sort(a);
//        System.err.println(Arrays.toString(a));
        final int MAGIC = 101;
        long[][] dp = new long[n + 1][MAGIC * n + 1];
        long[][] ndp = new long[n + 1][MAGIC * n + 1];
        for (int x = 0; x <= n; x++) {
                Arrays.fill(dp[x], Long.MAX_VALUE);
                Arrays.fill(ndp[x], Long.MAX_VALUE);
        }
        dp[0][0] = 0;
        for (int i = 0; i < n; ) {
            int j = i;
            while (j != n && a[i].power == a[j].power) {
                j++;
            }
            int curLen = j - i;
            for (int canCover = 0; canCover <= n; canCover++) {
                for (int proc = 0; proc <= i * MAGIC; proc++) {
                    long val = dp[canCover][proc];
                    if (val == Long.MAX_VALUE) {
                        continue;
                    }
                    int must = Math.max(0, curLen - canCover);
                    long sumPower = val;
                    int sumProc =proc;
                    for (int use = 0; use <= curLen; use++) {
                        if (use != 0) {
                            sumPower += a[i + use - 1].power;
                            sumProc += a[i + use - 1].proc;
                        }
                        if (use >= must) {
                            int nextCanCover = canCover + use * 2 - curLen;
                            ndp[nextCanCover][sumProc] = Math.min(ndp[nextCanCover][sumProc], sumPower);
                        }
                    }
                }
            }
            swap(dp, ndp);
            i = j;
        }
        long ans = Long.MAX_VALUE;
        for (int can =0 ; can <= n;can++) {
            for (int proc = 1; proc <= n * MAGIC; proc++) {
                long pow =dp[can][proc];
                if (pow == Long.MAX_VALUE ) {
                    continue;
                }
                ans = Math.min(ans, (pow * 1000 + proc - 1) / proc);
            }
        }
        out.println(ans);
    }

    void swap(long[][] a, long[][] b) {
        for (int i =0 ; i < a.length; i++) {
                long[] tmp = a[i];
                a[i] = b[i];
                b[i] =tmp;
                Arrays.fill(b[i], Long.MAX_VALUE);
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