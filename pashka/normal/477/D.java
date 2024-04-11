import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

/**
 * @author Pavel Mavrin
 */
public class D {

    private static final long MOD = (long) (1e9 + 7);

    private void solve() throws IOException {
        String s = next();
        calc(s);
//        for (int i = 1; i < 1000; i++) {
//            calc(Integer.toBinaryString(i));
//        }
    }


    private void calc(String s) {
//        System.out.println(s);
        int n = s.length();
        s = s + "$";
        short[][] a = new short[n + 1][n + 1];
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                if (s.charAt(i) == s.charAt(j)) {
                    a[i][j] = (short) (a[i + 1][j + 1] + 1);
                } else {
                    a[i][j] = 0;
                }
            }
        }
        int[][] d = new int[n + 1][];
        int[][] d2 = new int[n + 1][];
        for (int i = 0; i <= n; i++) {
            d[i] = new int[i + 1];
            d2[i] = new int[i + 1];
        }
        for (int[] ints : d) {
            Arrays.fill(ints, Integer.MAX_VALUE);
        }
        d[1][1] = 1;
        d2[1][1] = 1;
        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= i; j++) if (d[i][j] < Integer.MAX_VALUE) {
                d[i + 1][j + 1] = Math.min(d[i + 1][j + 1], d[i][j]);
                d2[i + 1][j + 1] += d2[i][j];
                d2[i + 1][j + 1] %= MOD;
                int q = a[i - j][i];
                if (i + j <= n && (q >= j || s.charAt(i - j + q) < s.charAt(i + q))) {
                    d[i + j][j] = Math.min(d[i + j][j], d[i][j] + 1);
                    d2[i + j][j] += d2[i][j];
                    d2[i + j][j] %= MOD;
                } else {
                    if (s.charAt(i) == '1' && i + j + 1 <= n) {
                        d[i + j + 1][j + 1] = Math.min(d[i + j + 1][j + 1], d[i][j] + 1);
                        d2[i + j + 1][j + 1] += d2[i][j];
                        d2[i + j + 1][j + 1] %= MOD;
                    }
                }
            }
        }
        long best = -1;
        for (int j = 1; j <= n; j++) {
            if (d[n][j] < Integer.MAX_VALUE) {
                long res = 0;
                for (int i = n - j; i < n; i++) {
                    res *= 2;
                    res += s.charAt(i) - '0';
                    res %= MOD;
                }
                res += d[n][j];
                res %= MOD;
                if (best == -1 || best > res) {
                    best = res;
                }
                if (j > 30) {
                    break;
                }
            }
        }
        long ss = 0;
        for (int j = 1; j <= n; j++) {
            if (d[n][j] < Integer.MAX_VALUE) {
                ss += d2[n][j];
                ss %= MOD;
            }
        }
        System.out.println(ss);
        System.out.println(best);
    }


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
        new D().run();
    }

    private void run() throws IOException {
        solve();
        out.close();
    }

}