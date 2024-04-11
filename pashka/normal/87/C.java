import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

/**
 * Created by IntelliJ IDEA.
 * User: pashka
 * Date: 05.06.2011
 * Time: 14:02:47
 * To change this template use File | Settings | File Templates.
 */
public class C {
    BufferedReader br;
    StringTokenizer st;
    PrintWriter out;


    public static void main(String[] args) throws IOException {
        new C().run();
    }

    private void run() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        solve();
        out.close();
    }

    String next() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return st.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    private void solve() throws IOException {
        int n = nextInt();
        int[] g = new int[n + 1];
        int[] p = new int[n + 1];
        for (int k = 1; k <= n; k++) {
            Set<Integer> set = new HashSet<Integer>();
            for (int z = 2; z * (z + 1) / 2 <= k; z++) {
                int w = k - z * (z + 1) / 2;
                if (w % z == 0) {
                    w /= z;
                    int gg = 0;
                    for (int i = 0; i < z; i++) {
                        gg ^= g[w + i + 1];
                    }
                    if (gg == 0 && p[k] == 0) {
                        p[k] = z;
                    }
                    set.add(gg);
                }
            }
            while (set.contains(g[k])) g[k]++;
        }
        if (g[n] == 0) {
            out.println(-1);
        } else {
            out.println(p[n]);
        }
    }
}