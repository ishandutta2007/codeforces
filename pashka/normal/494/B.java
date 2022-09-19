import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

/**
 * @author Pavel Mavrin
 */
public class B {

    private static final long MOD = (long) (1e9 + 7);

    private void solve() throws IOException {
        String s = next();
        String t = next();
        String ss = t + "#" + s;
        int[] p = new int[ss.length() + 1];
        for (int i = 2; i <= ss.length(); i++) {
            int k = p[i - 1];
            while (k > 0 && ss.charAt(k) != ss.charAt(i - 1)) {
                k = p[k];
            }
            if (ss.charAt(k) == ss.charAt(i - 1)) {
                p[i] = k + 1;
            }
        }
//        System.out.println(ss + Arrays.toString(p));
        long[] a = new long[s.length() + 1];
        long[] sa = new long[s.length() + 1];
        int ii = 0;
        a[0] = 1;
        sa[0] = 1;
        for (int i = 1; i <= s.length(); i++) {
            a[i] = a[i - 1];
            if (p[t.length() + 1 + i] == t.length()) {
                ii = i;
            }
            if (ii > 0) {
                a[i] += sa[ii - t.length()];
            }
            a[i] %= MOD;
            sa[i] = sa[i - 1] + a[i];
            sa[i] %= MOD;
        }
//        System.out.println(Arrays.toString(a));
        out.println((a[s.length()] - 1 + MOD) % MOD);
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
        new B().run();
    }

    private void run() throws IOException {
        solve();
        out.close();
    }

}