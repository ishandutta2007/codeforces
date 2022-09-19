import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

/**
 * @author Pavel Mavrin
 */
public class B {

    private void solve() throws IOException {
        int n = nextInt();
        int[] a = new int[n + 1];
        for (int i = 0; i < n; i++) {
            a[i + 1] = a[i] + nextInt() - 1;
        }
        List<int[]> res = new ArrayList<int[]>();
        for (int t = 1; t <= n; t++) {
            int k = 0;
            int w0 = 0;
            int w1 = 0;
            while (k < n) {
                int l = k;
                int r = n;
                while (r > l + 1) {
                    int m = (l + r) / 2;
                    int c = a[m] - a[k];
                    c = Math.max(c, m - k - c);
                    if (c >= t) {
                        r = m;
                    } else {
                        l = m;
                    }
                }
                int c1 = a[r] - a[k];
                int c0 = r - k - c1;
                if (c1 == t) {
                    w1++;
                } else if (c0 == t) {
                    w0++;
                } else {
                    break;
                }
                if (r == n) {
                    if (w1 > w0 && c1 == t) {
                        res.add(new int[]{w1, t});
                    }
                    if (w0 > w1 && c0 == t) {
                        res.add(new int[]{w0, t});
                    }
                }
                k = r;
            }
        }
        Collections.sort(res, new Comparator<int[]>() {
            public int compare(int[] o1, int[] o2) {
                int res = Integer.compare(o1[0], o2[0]);
                if (res == 0) {
                    res = Integer.compare(o1[1], o2[1]);
                }
                return res;
            }
        });
        out.println(res.size());
        for (int[] re : res) {
            out.println(re[0] + " " + re[1]);
        }
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