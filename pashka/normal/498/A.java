import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

/**
 * @author Pavel Mavrin
 */
public class A {

    private void solve() throws IOException {
        long x1 = nextInt();
        long y1 = nextInt();
        long x2 = nextInt();
        long y2 = nextInt();
        int n = nextInt();
        int res = 0;
        for (int i = 0; i < n; i++) {
            long a = nextInt();
            long b = nextInt();
            long c = nextInt();
            long s1 = a * x1 + b * y1 + c;
            long s2 = a * x2 + b * y2 + c;
            if ((Long.signum(s1) > 0) ^ (Long.signum(s2) > 0)) {
                res++;
            }
        }
        out.println(res);

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
        new A().run();
    }

    private void run() throws IOException {
        solve();
        out.close();
    }

}