import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

/**
 * @author Pavel Mavrin
 */
public class A {

    private boolean[] z;
    private char[] p;
    private int t1, t2;
    private int n;
    private int m;
    private int res;

    private void solve() throws IOException {
        n = nextInt();
        m = nextInt();
        t1 = Integer.toString(n - 1, 7).length();
        t2 = Integer.toString(m - 1, 7).length();
        if (t1 + t2 > 7) {
            out.println(0);
            return;
        }
        z = new boolean[7];
        p = new char[t1 + t2];
        bt(0);
        out.println(res);
    }

    private void bt(int i) {
        if (i == t1 + t2) {
            String s1 = new String(p, 0, t1);
            String s2 = new String(p, t1, t2);
            if (Integer.parseInt(s1, 7) < n && Integer.parseInt(s2, 7) < m) {
//                System.out.println(s1 + " " + s2);
                res++;
            }
            return;
        }
        for (int j = 0; j < 7; j++) {
            if (!z[j]) {
                p[i] = (char) ('0' + j);
                z[j] = true;
                bt(i + 1);
                z[j] = false;
            }
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