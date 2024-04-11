
import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class D {

    BufferedReader br;
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

    public static void main(String[] args) throws FileNotFoundException {
        new D().run();
    }

    private void run() {
        br = new BufferedReader(new InputStreamReader(System.in));
        try {
            solve();
        } catch (IOException e) {
            e.printStackTrace();
        }
        out.close();
    }

    private void solve() throws IOException {
        int n = nextInt();
        int k = nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n - 1; i++) a[i] = 1;
        int[] c = new int[n];
        int[] aa = new int[n];
        for (int j = 0; j < k; j++) {
            for (int i = 0; i < n; i++) {
                int l = -1;
                int r = n;
                while (r > l + 1) {
                    int m = (l + r) / 2;
                    if (a[i] + a[m] > (n - 1 - i))
                        l = m;
                    else
                        r = m;
                }
                c[i] = r;
            }
            for (int i = 0; i < n; i++) {
                out.print((c[i] + 1) + " ");
                aa[i] = a[i] + a[c[i]];
            }
            System.arraycopy(aa, 0, a, 0, n);
            out.println();
        }


//        int n = nextInt();

        //To change body of created methods use File | Settings | File Templates.
    }
}