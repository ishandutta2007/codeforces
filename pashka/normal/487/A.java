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
        int hp1 = nextInt();
        int at1 = nextInt();
        int df1 = nextInt();
        int hp2 = nextInt();
        int at2 = nextInt();
        int df2 = nextInt();
        int h = nextInt();
        int a = nextInt();
        int d = nextInt();
        int min = Integer.MAX_VALUE;
        for (int aa = 0; aa < 300; aa++) {
            for (int dd = 0; dd < 100; dd++) {
                int q = at1 + aa - df2;
                if (q <= 0) continue;
                int n = (hp2 + q - 1) / q;
                int w = Math.max(0, at2 - df1 - dd);
                int hh = Math.max(0, w * n + 1 - hp1);
                int s = h * hh + a * aa + d * dd;
                if (s < min) {
                    min = s;
                }
            }
        }
        out.println(min);
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