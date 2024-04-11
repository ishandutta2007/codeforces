import java.io.*;
import java.util.*;

public class A {
    FastScanner in;
    PrintWriter out;

    void solve() {
        int tc = in.nextInt();
        for (int t = 0; t < tc; t++) {
            int n = in.nextInt();
            int m = in.nextInt();
            O[] a = new O[n * m];
            int[][] cols = new int[m][n + n];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    cols[j][i] = cols[j][i + n] = in.nextInt();
                    a[i * m + j] = new O(i, j, cols[j][i]);
                }
            }
            Arrays.sort(a);
            boolean[] used = new boolean[m];
            int cntUsed = 0;
            for (O o : a) {
                if (!used[o.y]) {
                    used[o.y] = true;
                    cntUsed++;
                    if (cntUsed == n) {
                        break;
                    }
                }
            }
            int[] dp = new int[1 << n];
            int[] ndp = new int[1 << n];
            int[] maxndp = new int[1 << n];
            for (int col = 0; col < m; col++) {
                if (!used[col]) {
                    continue;
                }
                int[] curColumn = cols[col];
                for (int shift = 0; shift < n; shift++) {
                    System.arraycopy(dp, 0, ndp, 0, ndp.length);
                    for (int mask = 0; mask < 1 << n; mask++) {
                        for (int bit = 0; bit < n; bit++) {
                            if (((1 << bit) & mask) == 0) {
                                int nmask = mask | (1 << bit);
                                ndp[nmask] = Math.max(ndp[nmask], ndp[mask] + curColumn[bit + shift]);
                            }
                        }
                    }
                    for (int i = 0; i < ndp.length; i++) {
                        maxndp[i] = Math.max(maxndp[i], ndp[i]);
                    }
                }
                int[] tmp = dp;
                dp = maxndp;
                maxndp = tmp;
            }
            out.println(dp[dp.length - 1]);
        }
    }

    class O implements Comparable<O> {
        int x, y, value;

        public O(int x, int y, int value) {
            this.x = x;
            this.y = y;
            this.value = value;
        }

        @Override
        public int compareTo(O o) {
            return -Integer.compare(value, o.value);
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