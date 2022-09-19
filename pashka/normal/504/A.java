import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;
import java.util.TreeSet;

/**
 * @author Pavel Mavrin
 */
public class A {

    private void solve() throws IOException {
        int n = nextInt();
        final int[] d = new int[n];
        int[] s = new int[n];
        int m = 0;
        for (int i = 0; i < n; i++) {
            d[i] = nextInt();
            s[i] = nextInt();
            m += d[i];
        }
        m /= 2;
        TreeSet<Integer> h = new TreeSet<Integer>(new Comparator<Integer>() {
            public int compare(Integer o1, Integer o2) {
                int res = Integer.compare(d[o1], d[o2]);
                if (res == 0) {
                    return Integer.compare(o1, o2);
                } else {
                    return res;
                }
            }
        });
        for (int i = 0; i < n; i++) {
            h.add(i);
        }

        int[][] res = new int[m][2];
        int j = 0;
        while (!h.isEmpty()) {
            int i = h.pollFirst();
            if (d[i] == 1) {
                res[j][0] = i;
                res[j][1] = s[i];
                j++;
                h.remove(s[i]);
                d[s[i]]--;
                s[s[i]] ^= i;
                h.add(s[i]);
            }
        }
        out.println(m);
        for (int i = 0; i < m; i++) {
            out.println(res[i][0] + " " + res[i][1]);
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
        new A().run();
    }

    private void run() throws IOException {
        solve();
        out.close();
    }

}