import java.io.*;
import java.util.*;

public class CF333 {
    FastScanner in;
    PrintWriter out;

    void solve() {
        int n = in.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
        }
        int cntLeaves = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == 1)
                cntLeaves++;
        }
        if (n == 1) {
            if (cntLeaves == 1) {
                out.println("YES");
            } else {
                out.println("NO");
            }
            return;
        }
        if (cntLeaves * 2 < n) {
            out.println("NO");
            return;
        }
        {
            int m = n - cntLeaves;
            int[] tmp = new int[m];
            int it = 0;
            for (int i = 0; i < n; i++)
                if (a[i] != 1) {
                    tmp[it++] = a[i];
                }
            a = tmp;
            n = m;
        }
        if (n == 0) {
            out.println("NO");
            return;
        }
        Arrays.sort(a);
        if (a[n - 1] != cntLeaves + n) {
            out.println("NO");
            return;
        }
        for (int i = 0; i < n; i++) {
            a[i]--;
        }
        for (int i = 0; i < n; i++) {
            if (a[i] == 1) {
                out.println("NO");
                return;
            }
        }
        boolean[][][] dp = new boolean[n + 1][cntLeaves + 1][1 << n];
        dp[0][0][1 << (n - 1)] = true;
        for (int lastId = 0; lastId < n; lastId++)
            for (int st = 1; st < 1 << n; st++)
                for (int cntL = 0; cntL <= cntLeaves; cntL++) {
                    for (int nst = st;; nst = (nst - 1) & st) {
                        if (((1 << lastId) & nst) != 0)
                            continue;
                        int sum = 0;
                        for (int i = 0; i < n; i++)
                            if (((1 << i) & nst) != 0)
                                sum += a[i] + 1;
                        if (sum <= a[lastId]) {
                            int needOnes = a[lastId] - sum;
                            if (needOnes <= cntL) {
                                int cnt = Integer.bitCount(nst) + needOnes;
                                if (cnt > 1) {
                                    dp[lastId + 1][cntL][st] |= dp[lastId][cntL
                                            - needOnes][st ^ nst];
                                }
                            }
                        }
                        if (nst == 0)
                            break;
                    }
                }
        out.println(dp[n][cntLeaves][(1 << n) - 1] ? "YES" : "NO");
    }

    void run() {
        try {
            in = new FastScanner(new File("object.in"));
            out = new PrintWriter(new File("object.out"));

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
    }

    public static void main(String[] args) {
        new CF333().runIO();
    }
}