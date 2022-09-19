import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.Arrays;
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

    public static void main(String[] args) throws IOException {
        new A().solve();
    }

    private void solve() throws IOException {
        int n = nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) a[i] = nextInt();
        Arrays.sort(a);
        if (n == 1) {
            out.println(a[0]);
        } else {
            long s = 0;
            for (int i = 0; i < n; i++) {
                s += 1l * (i + 2) * a[i];
            }
            s -= a[n - 1];
            out.println(s);
        }
    }
}