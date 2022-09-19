import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.lang.management.RuntimeMXBean;
import java.util.StringTokenizer;

/**
 * @author Pavel Mavrin
 */
public class A {

    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st;
    PrintStream out = System.out;

    String next() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return st.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    public static void main(String[] args) {
        try {
            new A().solve();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private void solve() throws IOException {
        int n = nextInt();
        int R = nextInt();
        int r = nextInt();
        int k = howMany(R, r);
        if (n <= k) {
            out.println("YES");
        } else {
            out.println("NO");
        }
        out.close();
    }

    private int howMany(int R, int r) {
        if (r > R) return 0;
        if (r * 2 > R) return 1;
        if (r * 2 == R) return 2;
        double lo = 0;
        double hi = Math.PI;
        while (hi > lo + 1e-15) {
            double m = (lo + hi) / 2;
            double x1 = R - r;
            double y1 = 0;
            double x2 = (R - r) * Math.cos(m);
            double y2 = (R - r) * Math.sin(m);
            double dx = x1 - x2;
            double dy = y1 - y2;
            if (dx * dx + dy * dy < 4 * r * r) lo = m; else hi = m;
        }
        return (int) Math.floor(2 * Math.PI / lo);
    }


}