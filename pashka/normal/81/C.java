import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

/**
 * To be documented..
 * Date: May 4, 2011
 * Time: 8:57:59 AM
 *
 * @author Pavel Mavrin
 */
public class C {

    private void solve() throws IOException {
        int n = nextInt();
        final int n1 = nextInt();
        final int n2 = nextInt();
        final int[] points = new int[n];
        for (int i = 0; i < n; i++) points[i] = nextInt();
        Integer[] p = new Integer[n];
        for (int i = 0; i < n; i++) p[i] = i;
        Arrays.sort(p, new Comparator<Integer>() {
            public int compare(Integer a, Integer b) {
                int d = -(points[a] * n2 + points[b] * n1 - points[a] * n1 - points[b] * n2);
                if (d != 0) return d;
                return a - b;
            }
        });
//        System.out.println(Arrays.toString(p));
        int[] res = new int[n];
        for (int i = 0; i < n; i++) {
            if (i < n1) res[p[i]] = 1; else res[p[i]] = 2;
        }
        for (int i = 0; i < n; i++) {
            out.print(res[i] + " ");
        }
        out.println();
        //To change body of created methods use File | Settings | File Templates.
    }

    BufferedReader br;
    StringTokenizer st;
    PrintWriter out;

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
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        solve();
        out.close();
        br.close();
    }

}