import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

/**
 * @author Pavel Mavrin
 */
public class B {

    private void solve() throws IOException {
        int n = nextInt() + 1;
        long k = nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = nextInt();
        }
        long[] lf = new long[n];
        int maxL = n;
        for (int i = 0; i < n - 1; i++) {
            long cc = a[i] - lf[i];
            if (Math.abs(lf[i]) > 1e15 || cc % 2 != 0) {
                maxL = i + 1;
                break;
            }
            lf[i + 1] = - cc / 2;
        }
        long[] rf = new long[n];
        int minR = 0;
        for (int i = n - 1; i > 0; i--) {
            long cc = a[i] - rf[i];
            if (Math.abs(rf[i]) > 1e15) {
                minR = i;
                break;
            }
            rf[i - 1] = -cc * 2;
        }
//        System.out.println(Arrays.toString(lf));
//        System.out.println(Arrays.toString(rf));
        int res = 0;
        for (int i = minR; i < maxL; i++) {
            long vv = lf[i] + rf[i];
            if (Math.abs(vv) <= k && vv != a[i]) {
                if (i == n - 1 && vv == 0) continue;
                res++;
//                System.out.println(i + " " + vv);

//                long s = 0;
//                long pp = 1;
//                for (int j = 0; j < n; j++) {
//                    s += pp * (j == i ? vv : a[j]);
//                    pp *= 2;
//                }
//                System.out.println(s);

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
        new B().run();
    }

    private void run() throws IOException {
        solve();
        out.close();
    }

}