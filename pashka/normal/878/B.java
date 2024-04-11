import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

/**
 * @author Pavel Mavrin
 */
public class B {

    private void solve() throws IOException {
        int n = nextInt();
        int k = nextInt();
        int m = nextInt();
        long res = 1l * m * n;
        int[] sta = new int[n];
        long[] stb = new long[n];
        int sp = 0;
        for (int i = 0; i < n; i++) {
            int x = nextInt();
            if (sp > 0 && sta[sp - 1] == x) {
                stb[sp - 1]++;
                if (stb[sp - 1] == k) {
                    sp--;
                    res -= 1l * m * k;
                }
            } else {
                sta[sp] = x;
                stb[sp] = 1;
                sp++;
            }
        }
        int l = 0;
        int r = sp - 1;
        while (r > l && sta[l] == sta[r]) {
            long x = stb[l] + stb[r];
            res -= (m - 1) * (x / k * k);
            if (x % k == 0) {
                l++;
                r--;
            } else {
                break;
            }
        }
        if (l == r) {
            long x = stb[l] * m;
            res -= x / k * k;
            while (l > 0 && x % k == 0) {
                l--; r++;
                if (sta[l] == sta[r]) {
                    x = stb[l] + stb[r];
                    res -= x / k * k;
                } else {
                    break;
                }
            }
        }
        out.println(res);
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