import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Random;
import java.util.StringTokenizer;

/**
 * @author Pavel Mavrin
 */
public class B {

    private static final int BUBEN = 1000;

    private void solve() throws IOException {
        int n = nextInt();
        int start = nextInt();
        int x = nextInt();
        int max = -1;
        int maxi = -1;
        int min = 2000000000;

        Random random = new Random();

        for (int i = 0; i < BUBEN; i++) {
            int y = (i == 0) ? start : (random.nextInt(n) + 1);
            out.println("? " + y);
            out.flush();
            int v = nextInt();
            int nx = nextInt();
            if (v <= x && v > max) {
                max = v;
                maxi = y;
            }
            if (v < min) {
                min = v;
            }
        }
        if (max == -1) {
            out.println("! " + min);
        } else {
            int i = maxi;
            int cur = max;
            while (i != -1) {
                if (cur >= x) {
                    break;
                }
                out.println("? " + i);
                out.flush();
                int v = nextInt();
                int nx = nextInt();
                i = nx;
                cur = v;
            }
            if (cur >= x) {
                out.println("! " + cur);
            } else {
                out.println("! -1");
            }
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
        new B().run();
    }

    private void run() throws IOException {
        solve();
        out.close();
    }

}