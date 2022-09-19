import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

/**
 * @author Pavel Mavrin
 */
public class G {

    private void solve() throws IOException {
        int q = nextInt();
        for (int i = 0; i < q; i++) {
            solveTest();
        }
    }

    private void solveTest() throws IOException {
        long l = nextLong();
        long r = nextLong();
        out.println(calc(r + 1) - calc(l));
    }

    private long calc(long r) {
        int[] dd = new int[16];
        for (int i = 0; i < dd.length; i++) {
            dd[i] = (int) (r % 16);
            r /= 16;
        }
//        System.out.println(Arrays.toString(dd));
        long ans = 0;
        for (int d = 0; d < 16; d++) {
            long ls = 0;
            long eq = 1;
            long als = 0;
            long aeq = 0;
            for (int i = dd.length - 1; i >= 0; i--) {
                long ls1 = 0;
                long eq1 = 0;
                long als1 = 0;
                long aeq1 = 0;
                for (int j = 0; j <= d; j++) {
                    if (d >= i * 4 && d < i * 4 + 4) {
                        if ((j & (1 << (d - i * 4))) == 0) {
                            continue;
                        }
                    }
                    if (j == d) {
                        if (j < dd[i]) {
                            als1 += als + aeq + ls + eq;
                        } else if (j == dd[i]) {
                            als1 += als + ls;
                            aeq1 += aeq + eq;
                        } else {
                            als1 += als + ls;
                        }
                    } else {
                        if (j < dd[i]) {
                            ls1 += ls + eq;
                            als1 += als + aeq;
                        } else if (j == dd[i]) {
                            ls1 += ls;
                            eq1 += eq;
                            als1 += als;
                            aeq1 += aeq;
                        } else {
                            ls1 += ls;
                            als1 += als;
                        }
                    }
                }
                ls = ls1;
                eq = eq1;
                als = als1;
                aeq = aeq1;
            }
//            if (als > 0) System.out.println(d + " " + als);
            ans += als;
        }
        return ans;
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

    long nextLong() throws IOException {
        return Long.parseLong(next(), 16);
    }

    public static void main(String[] args) throws IOException {
        new G().run();
    }

    private void run() throws IOException {
        solve();
        out.close();
    }

}