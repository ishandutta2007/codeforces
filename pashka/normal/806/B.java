import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.text.RuleBasedCollator;
import java.util.Arrays;
import java.util.StringTokenizer;

/**
 * @author Pavel Mavrin
 */
public class B {

    public static final int LEV = 6;
    private int n;
    private int m;

    private void solve() throws IOException {
        n = nextInt();
        m = 5;
        int[] sol = new int[m];
        int[] a = new int[m];
        for (int i = 0; i < m; i++) {
            a[i]= nextInt();
            if (a[i] >= 0) sol[i]++;
        }
        int[]b = new int[m];
        for (int i = 0; i < m; i++) {
            b[i] = nextInt();
            if (b[i] >= 0) sol[i]++;
        }
        for (int i = 0; i < n - 2; i++) {
            for (int j = 0; j < m; j++) {
                if (nextInt() >= 0) sol[j]++;
            }
        }


//        System.out.println(Arrays.toString(sol));
        for (int add = 0; add < n * 32; add++) {
            int ds = 0;
            for (int i = 0; i < m; i++) {
                int level = 0;
                int dd = calcScoreByLev(a[i], level) - calcScoreByLev(b[i], level);
                if (dd > 0) {
                    level = getLevel(sol[i], n + add);
                    ds += calcScoreByLev(a[i], level) - calcScoreByLev(b[i], level);
                } else if (dd < 0) {
                    if (a[i] >= 0) {
                        level = getLevel(sol[i] + add, n + add);
                        ds += calcScoreByLev(a[i], level) - calcScoreByLev(b[i], level);
                    } else {
                        level = getLevel(sol[i], n + add);
                        ds += calcScoreByLev(a[i], level) - calcScoreByLev(b[i], level);
                    }
                }
//                System.out.println(i + "-> " + level + " " + calcScoreByLev(a[i], level) + " " + calcScoreByLev(b[i], level));
            }
//            System.out.println(add + " " + ds);
            if (ds > 0) {
                out.println(add);
                return;
            }
        }
        out.println(-1);
    }

    private int calcScoreByLev(int i, int lev) {
        if (i < 0) return 0;
        int maxScore = (lev + 1) * 500;
        return maxScore - maxScore / 250 * i;
    }

    private int getLevel(int x, int n) {
        if (x <= n / 32) return 5;
        if (x <= n / 16) return 4;
        if (x <= n / 8) return 3;
        if (x <= n / 4) return 2;
        if (x <= n / 2) return 1;
        return 0;
    }


    // ------------------

    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st;
    PrintWriter out = new PrintWriter(System.out);

    String next() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return st.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    public static void main(String[] args) throws IOException {
        new B().run();
    }

    private void run() throws IOException {
        solve();
        out.close();
    }

}