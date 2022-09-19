import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Random;
import java.util.StringTokenizer;

/**
 * @author Pavel Mavrin
 */
public class E {

    private void solve() throws IOException {
        int n = nextInt();
        int q = nextInt();
        ArrayList<Integer> e[] = new ArrayList[n + 1];
        for (int i = 0; i < e.length; i++) {
            e[i] = new ArrayList<>();
        }
        for (int i = 0; i < q; i++) {
            int l = nextInt();
            int r = nextInt();
            int x = nextInt();
            e[l - 1].add(x);
            e[r].add(-x);
        }
        boolean[] res = new boolean[n + 1];
        long mod = BigInteger.probablePrime(60, new Random()).longValue();
        long[] c = new long[n + 1];
        c[0] = 1;
        for (int i = 0; i < n; i++) {
            for (int k : e[i]) {
                if (k > 0) {
                    for (int j = c.length - 1 - k; j >= 0; j--) {
                        c[j + k] += c[j];
                        if (c[j + k] >= mod) {
                            c[j + k] -= mod;
                        }
                    }
                } else {
                    k = -k;
                    for (int j = 0; j + k < c.length; j++) {
                        c[j + k] -= c[j];
                        if (c[j + k] < 0) {
                            c[j + k] += mod;
                        }
                    }
                }
            }
            for (int j = 0; j < c.length; j++) {
                if (c[j] != 0) res[j] = true;
            }
        }
        int k = 0;
        int[] r = new int[n];
        for (int i = 1; i <= n; i++) {
            if (res[i]) {
                r[k++] = i;
            }
        }
        out.println(k);
        for (int i = 0; i < k; i++) {
            out.print(r[i] + " ");
        }
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
        new E().run();
    }

    private void run() throws IOException {
        solve();
        out.close();
    }

}