import java.io.*;
import java.util.*;

public class E {
    FastScanner in;
    PrintWriter out;

    void solve() {
        int n = in.nextInt();
        int segments = in.nextInt();
        int segChoose = in.nextInt();
        int k = in.nextInt();
        int[] a = new int[n];
        int[] allVals = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
            allVals[i] = a[i];
        }
        Arrays.sort(allVals);
//        System.err.println(Arrays.toString(allVals));
        int[] from = new int[segments];
        int[] to = new int[segments];
        for (int i = 0; i < segments; i++) {
            from[i] = in.nextInt() - 1;
            to[i] = in.nextInt() - 1;
        }
        int left = -1, right = n;
        int[] alive = new int[n];
        int[] alivePrefSum = new int[n + 1];
        int[] dp = new int[n + 1];
        int[] ndp = new int[n + 1];
        while (right - left > 1) {
            int mid = (left + right) >> 1;
//            mid = 1;
//            System.err.println("check " + allVals[mid]);
            for (int i = 0; i < n; i++) {
                if (a[i] <= allVals[mid]) {
                    alive[i] = 1;
                } else {
                    alive[i] = 0;
                }
                alivePrefSum[i + 1] = alivePrefSum[i] + alive[i];
            }
//            System.err.println(Arrays.toString(alive));
            Arrays.fill(dp, 0);
            for (int i = 0; i < segChoose; i++) {
                for (int j = 0; j <= n; j++) {
                    ndp[j] = dp[j];
                }
                for (int j = 0; j < segments; j++) {
                    int cntAlive = alivePrefSum[to[j] + 1] - alivePrefSum[from[j]];
//                    System.err.println("for " + from[j] + " " + to[j] + ", alive = " + cntAlive);
                    ndp[to[j] + 1] = Math.max(ndp[to[j] + 1], cntAlive + dp[from[j]]);
                }
//                System.err.println(Arrays.toString(ndp));


                int[] tmp = dp;
                dp = ndp;
                ndp = tmp;

                for (int j = 1; j < n; j++) {
                    dp[j + 1] = Math.max(dp[j + 1], dp[j]);
                }
                for (int j = n - 1; j >= 0; j--) {
                    dp[j] = Math.max(dp[j], dp[j + 1] - alive[j]);
                }
//                System.err.println(Arrays.toString(dp) + "!");
            }
//            System.err.println("dp[n] = " + dp[n] + ", k = " + k);
            if (dp[n] >= k) {
                right = mid;
            } else {
                left = mid;
            }
//            break;
        }
        out.println(right == n ? -1 : allVals[right]);
    }

    void run() {
        try {
            in = new FastScanner(new File("E.in"));
            out = new PrintWriter(new File("E.out"));

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
        new E().runIO();
    }
}