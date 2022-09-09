import java.io.*;
import java.util.*;

public class A {
    FastScanner in;
    PrintWriter out;

    void solve() {
        int n = in.nextInt();
        int m = in.nextInt();
        int k = in.nextInt();
        int startPos = readMask();
        int expectedPos = readMask();
        int[] ai = new int[n];
        int[] bi = new int[n];
        for (int i = 0; i < n; i++) {
            ai[i] = in.nextInt() - 1;
            bi[i] = in.nextInt() - 1;
        }
        int[][] perms = new int[n + 1][k];
        for (int i = 0; i < k; i++) {
            perms[n][i] = i;
        }
        for (int i = n - 1; i >= 0; i--) {
            System.arraycopy(perms[i + 1], 0, perms[i], 0, k);
            int tmp = perms[i][ai[i]];
            perms[i][ai[i]] = perms[i][bi[i]];
            perms[i][bi[i]] = tmp;
        }
        dp = new int[1 << k];
        dpFinish = new int[1 << k];
        queue = new int[1 << k];
        int res = 0;
        int resStart = 0;
        int resFinish = 0;
        for (int start = n - 1; start >= 0; start--) {
            int finishAtLeast = start + m;
            if (finishAtLeast <= n) {
                int finalMask = apply(expectedPos, perms[finishAtLeast]);
                update(finalMask, k, k, finishAtLeast);
            }
            int myMaskAfterApply = apply(startPos, perms[start]);
            int dpRes = dp[myMaskAfterApply];
            if (dpRes >= res) {
                res = dpRes;
                resStart = start;
                resFinish = dpFinish[myMaskAfterApply];
            }
        }
        out.println(res);
        out.println((resStart + 1) + " " + resFinish);
    }

    int[] dp;
    int[] dpFinish;
    int[] queue;

    void update(int mask, int cost, int k, int dpFinishVal) {
        if (dp[mask] >= cost) {
            return;
        }
        dp[mask] = cost;
        dpFinish[mask] = dpFinishVal;
        int qIt = 0, qSz = 0;
        queue[qSz++] = mask;
        while (qIt < qSz) {
            int curMask = queue[qIt++];
            int curCost = dp[curMask];
            for (int bit = 0; bit < k; bit++) {
                int nextMask = curMask ^ (1 << bit);
                if (dp[nextMask] < curCost - 1) {
                    dp[nextMask] = curCost - 1;
                    dpFinish[nextMask] = dpFinishVal;
                    queue[qSz++] = nextMask;
                }
            }
        }
    }

    int apply(int currentMask, int[] perm) {
        int res = 0;
        int k = perm.length;
        for (int i = 0; i < k; i++) {
            if (((1 << i) & currentMask) != 0) {
                res |= 1 << perm[i];
            }
        }
        return res;
    }

    int readMask() {
        char[] s = in.next().toCharArray();
        int res = 0;
        for (int i = 0; i < s.length; i++) {
            if (s[i] == '1') {
                res += 1 << i;
            }
        }
        return res;
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