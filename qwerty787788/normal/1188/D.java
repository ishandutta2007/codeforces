import java.io.*;
import java.util.*;

public class A {
    FastScanner in;
    PrintWriter out;

    int add(int x, int y) {
        if (y < 0) {
            throw new AssertionError()
                    ;
        }
        return x + y;
    }

    void solve() {
        int n = in.nextInt();
        long[] a = new long[n];
        for (int i = 0; i < n; i++) {
            a[i] = in.nextLong();
        }
        long[] lastVals = new long[n];
        long[] b = new long[n];
        int[] costs = new int[n + 1];
        Arrays.fill(costs, Integer.MAX_VALUE);
        costs[n] = 0;
        int[] ncost = new int[n + 1];

        for (int bit = 0; bit < 60; bit++) {
            int it = 0;
            int firstHalfCnt = 0;
            for (int j = 0; j < 2; j++) {
                long mask = 1L << bit;
                if (j == 0) {
                    mask = 0;
                }
                for (int i = 0; i < n; i++) {
                    if (((a[i] & (1L << bit)) == mask)) {
                        b[it++] = a[i];
                    }
                }
                if (j == 0) {
                    firstHalfCnt = it;
                }
            }
            System.arraycopy(b, 0, a, 0, n);

            Arrays.fill(ncost, Integer.MAX_VALUE);
            for (int i = 0; i <= n; i++) {
                int curCost = costs[i];
                if (curCost == Integer.MAX_VALUE) {
                    continue;
                }
                long need = 1L << bit;
                long curAdd = 0;
                if (i < n) {
                    curAdd = need - (lastVals[i] & (need - 1));
                }

                {
                    int l = -1, r = firstHalfCnt;
                    while (r - l > 1) {
                        int mid = (l + r) >> 1;
                        if (((a[mid] & (need - 1)) + curAdd) >= need) {
                            r = mid;
                        } else {
                            l = mid;
                        }
                    }
                    int myCost0 = add(curCost, firstHalfCnt - r);
                    int candToOverflow0 = (firstHalfCnt == r) ? -1 : r;

                    int myCost1 = add(curCost, r);
                    int candToOverflow1 = -1;

                    l = firstHalfCnt - 1;
                    r = n;
                    while (r - l > 1) {
                        int mid = (l + r) >> 1;
                        if (((a[mid] & (need - 1)) + curAdd) >= need) {
                            r = mid;
                        } else {
                            l = mid;
                        }
                    }
                    myCost1 = add(myCost1, n - r);
                    myCost0 = add(myCost0, (n - firstHalfCnt) - (n - r));
                    if (firstHalfCnt != n && candToOverflow0 == -1) {
                        candToOverflow0 = firstHalfCnt;
                    }
                    if (candToOverflow0 == -1) {
                        candToOverflow0 = n;
                    }
                    if (n != r) {
                        candToOverflow1 = r;
                    }
                    if (candToOverflow1 == -1) {
                        candToOverflow1 = n;
                    }
                    ncost[candToOverflow0] = Math.min(ncost[candToOverflow0], myCost0);
                    ncost[candToOverflow1] = Math.min(ncost[candToOverflow1], myCost1);
                }
            }

            System.arraycopy(a, 0, lastVals, 0, n);
            System.arraycopy(ncost, 0, costs, 0, n + 1);
//            System.err.println("ITER = " + bit);
//            for (int i =0 ; i <= n; i++) {
//                System.err.println("overflow " + (i == n ? 0 : a[i])+ " -> costs "  + costs[i]);
//            }
        }

        out.println(costs[n]);
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