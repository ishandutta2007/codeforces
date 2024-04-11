import java.io.*;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

/**
 * @author Pavel Mavrin
 */
public class C {

    private void solve() throws IOException {
        int n = nextInt();
        int k = nextInt();
        int b = nextInt();
        int c = nextInt();
        if (c * 5 < b) {
            b = c * 5;
        }
        long[] a = new long[n];
        for (int i = 0; i < n; i++) {
            a[i] = nextInt();
        }
        Arrays.sort(a);

        long[] rr = new long[5];
        for (int i = 0; i < 5; i++) {
            rr[i] = (long) 1e9 + 10 + i;
        }

        long[][] cost = new long[5][n];
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < n; j++) {
                long d = rr[i] - a[j];
                cost[i][j] = b * (d / 5) + c * (d % 5);
            }
        }

        PriorityQueue<Long>[] best = new PriorityQueue[5];
        long[] s = new long[5];
        for (int i = 0; i < 5; i++) {
            best[i] = new PriorityQueue<>();
        }

        long min = Long.MAX_VALUE;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 5; j++) {
                best[j].add(-cost[j][i]);
                s[j] += cost[j][i];
                if (best[j].size() > k) {
                    s[j] += best[j].remove();
                }
            }
            for (long t = a[i]; t < a[i] + 5; t++) {
                int r = (int) (t % 5);
                if (r < 0) r += 5;
                if (best[r].size() >= k) {
                    long ccc = s[r] - ((rr[r] - t) / 5) * b * k;
                    if (ccc < min) {
                        min = ccc;
                    }
                }
            }
        }

        out.println(min);

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
//        long start = System.currentTimeMillis();
//        System.setIn(new FileInputStream("input.txt"));
        new C().run();
//        System.err.println(System.currentTimeMillis() - start);
    }

    private void run() throws IOException {
        solve();
        out.close();
    }

}