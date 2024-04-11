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
public class A {

    private void solve() throws IOException {
        int n = nextInt();
        int[][] a = new int[n][2];
        for (int i = 0; i < n; i++) {
            a[i][0] = nextInt();
            a[i][1] = nextInt();
        }
        Arrays.sort(a, new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                return Integer.compare(o1[0], o2[0]);
            }
        });
        int res = 0;
        int[] q = new int[n];
        for (int i = 0; i < n; i++) {
            int l = -1;
            int r = i;
            while (r > l + 1) {
                int m = (l + r) >>> 1;
                if (a[m][0] < a[i][0] - a[i][1]) {
                    l = m;
                } else {
                    r = m;
                }
            }
            int d = 1 + (l == -1 ? 0 : q[l]);
            q[i] = d;
            res = Math.max(res, q[i]);
        }
        out.println(n - res);
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