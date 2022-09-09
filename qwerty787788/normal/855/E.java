import java.io.*;
import java.util.*;

public class A {
    private FastScanner in;
    private PrintWriter out;

    long[][][] dp;
    int[] val = new int[66];

    long getAnswer(int base, long value) {
        if (value == 0) {
            return 0;
        }
//        long pValue = value;
        int valSz = 0;
        while (value != 0) {
            val[valSz++] = (int) (value % base);
            value /= base;
        }
        long result = 0;
        for (int len = 1; len < valSz; len++) {
            result += dp[base][len][0] - dp[base][len - 1][1];
        }
        int xor = 0;
        for (int next = 1; next < val[valSz - 1]; next++) {
            result += dp[base][valSz - 1][xor ^ (1 << next)];
        }
        for (int sameLen = 1; sameLen <= valSz; sameLen++) {
            xor ^= 1 << val[valSz - sameLen];
            if (sameLen == valSz) {
                if (xor == 0) {
                    result++;
                }
            } else {
                for (int next = 0; next < val[valSz - sameLen - 1]; next++) {
                    result += dp[base][valSz - sameLen - 1][xor ^ (1 << next)];
                }
            }
        }
//        System.err.println("answer for " + base + " " + pValue + " is " + result);
        return result;
    }

    private void solve() {
        // base, len, mask
        dp = new long[11][][];
        for (int base = 2; base <= 10; base++) {
            long[][] cur = new long[62][1 << base];
            cur[0][0] = 1;
            for (int len = 0; len + 1 < cur.length; len++) {
                for (int mask = 0; mask < cur[0].length; mask++) {
                    long now = cur[len][mask];
                    if (now == 0) {
                        continue;
                    }
                    for (int use = 0; use < base; use++) {
                        cur[len + 1][mask ^ (1 << use)] += now;
                    }
                }
            }
            dp[base] = cur;
        }
        int q = in.nextInt();
        for (int i = 0; i < q; i++) {
            int base = in.nextInt();
            long left = in.nextLong();
            long right = in.nextLong();
            out.println(getAnswer(base, right) - getAnswer(base, left - 1));
        }
    }


    private void run() {
        try {
            in = new FastScanner(new File("A.in"));
            out = new PrintWriter(new File("A.out"));

            solve();

            out.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    private void runIO() {
        in = new FastScanner(System.in);
        out = new PrintWriter(System.out);

        solve();

        out.close();
    }

    private class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        FastScanner(File f) {
            try {
                br = new BufferedReader(new FileReader(f));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        FastScanner(InputStream f) {
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