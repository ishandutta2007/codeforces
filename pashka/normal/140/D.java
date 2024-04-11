import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.StringTokenizer;

/**
 * @author Pavel Mavrin
 */
public class D {

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

    public static void main(String[] args) throws IOException {
        new D().solve();
    }

    private void solve() throws IOException {
        int n = nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = nextInt();
        }
        Arrays.sort(a);
        int t = -350;
        int solved = 0;
        int penalty = 0;
        for (int i = 0; i < n; i++) {
            t += a[i];
            if (t > 0) {
                if (t <= 360) {
                    solved++;
                    penalty += t;
                }
            } else {
                solved++;
            }
        }
        out.println(solved + " " + penalty);

        //To change body of created methods use File | Settings | File Templates.
    }


}