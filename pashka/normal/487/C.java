import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.StringTokenizer;

/**
 * @author Pavel Mavrin
 */
public class C {

    private void solve() throws IOException {
        int n = nextInt();
        int[] a = new int[n];
        a[0] = 1;
        a[n - 1] = n;
        int[] b = new int[n];
        if (n == 4) {
            a[1] = 3;
            a[2] = 2;
        } else {
            BigInteger nn = BigInteger.valueOf(n);
            try {
                for (int i = 1; i < n - 1; i++) {
                    a[i] = (int) BigInteger.valueOf(i).modInverse(nn).multiply(BigInteger.valueOf(i + 1)).mod(nn).longValue();
                }
            } catch (Exception e) {
                out.println("NO");
                return;
            }
        }
        b[0] = 1;
        for (int i = 1; i < n - 1; i++) {
            b[i] = (b[i - 1] * a[i]) % n;
        }
        out.println("YES");
        for (int i = 0; i < n; i++) {
            out.println(a[i]);
        }
//        System.out.println(Arrays.toString(a));
//        System.out.println(Arrays.toString(b));
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
        new C().run();
    }

    private void run() throws IOException {
        solve();
        out.close();
    }

}