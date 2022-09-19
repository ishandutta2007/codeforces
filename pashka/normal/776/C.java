import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

/**
 * @author Pavel Mavrin
 */
public class C {

    private void solve() throws IOException {
        int n = nextInt();
        int k = nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) a[i] = nextInt();
        Map<Long, Integer> pr = new HashMap<>();
        pr.put(0L, 1);
        long max = n * 1000000000L;
        long s = 0;
        long res = 0;
        for (int i = 0; i < n; i++) {
            s += a[i];
            for (long kk = 1; Math.abs(kk) <= max; kk *= k) {
                res += get(pr, s - kk);
                if (Math.abs(k) == 1 && kk == k) break;
            }
            add(pr, s);
        }
        out.println(res);
    }

    private void add(Map<Long, Integer> pr, long x) {
        Integer res = pr.get(x);
        if (res == null) pr.put(x, 1); else pr.put(x, res + 1);
    }

    private long get(Map<Long, Integer> pr, long x) {
        Integer res = pr.get(x);
        if (res == null) return 0; else return res;
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
        new C().run();
    }

    private void run() throws IOException {
        solve();
        out.close();
    }

}