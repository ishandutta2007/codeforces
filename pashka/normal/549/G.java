import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

/**
 * @author Pavel Mavrin
 */
public class G {

    private void solve() throws IOException {
        int n = nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = nextInt();
        }
        int[] p = new int[n];
        for (int i = 0; i < n; i++) {
            p[i] = a[i] - (n - 1 - i);
        }
        Arrays.sort(p);
        int[] res = new int[n];
        for (int i = n - 1; i >= 0; i--) {
            res[i] = p[i] + (n - 1 - i);
        }
        for (int i = 0; i < n - 1; i++) {
            if (res[i] > res[i + 1]) {
                out.println(":(");
                return;
            }
        }
        for (int i = 0; i < n; i++) {
            out.print(res[i] + " ");
        }
        out.println();

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
        new G().run();
    }

    private void run() throws IOException {
        solve();
        out.close();
    }


}