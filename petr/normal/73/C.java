import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class LionAge implements Runnable {
    static final int INF = 1000000000;

    private void solve() throws IOException {
        String s = nextToken();
        int k = nextInt();
        int[][] bonus = new int[26][26];
        int nBonus = nextInt();
        for (int i = 0; i < nBonus; ++i) {
            char c1 = nextToken().charAt(0);
            char c2 = nextToken().charAt(0);
            bonus[c1 - 'a'][c2 - 'a'] = nextInt();
        }
        int[][] best = new int[k + 1][26];
        for (int i = 0; i < best.length; ++i) Arrays.fill(best[i], -INF);
        for (int i = 0; i < 26; ++i) {
            int nop = (s.charAt(0) - 'a' == i) ? 0 : 1;
            if (nop <= k)
                best[nop][i] = 0;
        }
        for (int pos = 1; pos < s.length(); ++pos) {
            int curCh = s.charAt(pos) - 'a';
            int[][] nbest = new int[k + 1][26];
            for (int i = 0; i < nbest.length; ++i) Arrays.fill(nbest[i], -INF);
            for (int pnum = 0; pnum <= k; ++pnum)
                for (int plast = 0; plast < 26; ++plast) {
                    if (best[pnum][plast] <= -INF) continue;
                    for (int nlast = 0; nlast < 26; ++nlast) {
                        int nnum = pnum;
                        if (curCh != nlast) ++nnum;
                        if (nnum > k) continue;
                        nbest[nnum][nlast] = Math.max(nbest[nnum][nlast], best[pnum][plast] + bonus[plast][nlast]);
                    }
                }
            best = nbest;
        }
        int res = -INF;
        for (int i = 0; i < best.length; ++i)
            for (int j = 0; j < 26; ++j)
                res = Math.max(res, best[i][j]);
        writer.println(res);
    }


    public static void main(String[] args) {
        new LionAge().run();
    }

    BufferedReader reader;
    StringTokenizer tokenizer;
    PrintWriter writer;

    public void run() {
        try {
            reader = new BufferedReader(new InputStreamReader(System.in));
            tokenizer = null;
            writer = new PrintWriter(System.out);
            solve();
            reader.close();
            writer.close();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

    int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    String nextToken() throws IOException {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(reader.readLine());
        }
        return tokenizer.nextToken();
    }
}