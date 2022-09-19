import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

/**
 * @author Pavel Mavrin
 */
public class A {

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
        new A().solve();
    }

    private void solve() throws IOException {
        int n = nextInt();
        int[] s = new int[n];
        for (int i = 0; i < n; i++) {
            s[i] = nextInt();
        }
        Arrays.sort(s);
        int l = 0;
        int r = n / 2 + 1;
        while (r > l + 1) {
            int m = (l + r) / 2;
            boolean ok = true;
            for (int i = 0; i < m; i++) {
                if (s[n - m + i] < s[i] * 2) {
                    ok = false;
                }
            }
            if (ok) {
                l = m;
            } else {
                r = m;
            }
        }
        out.println(n - l);
        out.close();
    }
}