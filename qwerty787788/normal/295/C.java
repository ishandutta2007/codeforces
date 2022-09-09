import java.io.*;
import java.util.*;

public class CF {
    FastScanner in;
    PrintWriter out;

    long mod = (long) 1e9 + 7;

    void solve() {
        int n = in.nextInt();
        int k = in.nextInt();
        int moves = 200;
        int f = 0;
        for (int i = 0; i < n; i++) {
            if (in.nextInt() == 50)
                f++;
        }
        int s = n - f;
        long[][][][] dp = new long[2][moves][f + 1][s + 1];
        dp[0][0][f][s] = 1;
        long[][] c = new long[100][100];
        for (int i = 0; i < 100; i++) {
            c[i][0] = 1;
            if (i != 0)
                for (int j = 1; j < 100; j++)
                    c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
        }
        for (int move = 0; move < moves - 1; move++)
            for (int curS = 0; curS < 2; curS++)
                for (int fi = 0; fi <= f; fi++)
                    for (int se = 0; se <= s; se++) {
                        if (dp[curS][move][fi][se] != 0) {
                            int curFi = curS == 0 ? fi : f - fi;
                            int curSe = curS == 0 ? se : s - se;
                            for (int fi2 = 0; fi2 <= curFi; fi2++)
                                for (int se2 = 0; se2 <= curSe; se2++) {
                                    if (fi2 != 0 || se2 != 0)
                                        if (fi2 * 50 + se2 * 100 <= k) {
                                            int nextF = curS == 0 ? fi - fi2
                                                    : fi + fi2;
                                            int nextS = curS == 0 ? se - se2
                                                    : se + se2;
                                            long curAdd = (((dp[curS][move][fi][se] * c[curFi][fi2]) % mod) * c[curSe][se2])
                                                    % mod;
                                            dp[1 - curS][move + 1][nextF][nextS] = (dp[1 - curS][move + 1][nextF][nextS] + curAdd)
                                                    % mod;
                                        }
                                }
                        }
                    }
        int bestMove = Integer.MAX_VALUE;
        for (int move = 0; move < moves; move++)
            if (dp[1][move][0][0] != 0) {
                bestMove = Math.min(move, bestMove);
            }
        if (bestMove == Integer.MAX_VALUE) {
            out.println(-1);
            out.println(0);
            return;
        }
        out.println(bestMove);
        out.println(dp[1][bestMove][0][0]);
    }

    void run() {
        try {
            in = new FastScanner(new File("test.in"));
            out = new PrintWriter(new File("test.out"));

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
        new CF().runIO();
    }
}