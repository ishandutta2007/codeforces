import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

/**
 * @author Pavel Mavrin
 */
public class A {

    private void solve() throws IOException {
        int n = nextInt();
        int d = nextInt();
        int h = nextInt();
        if (d == 1 && n > 2 || d > h * 2) {
            out.println(-1);
        } else {
            int k = 2;
            int last = 1;
            for (int i = 0; i < h; i++) {
                out.println(last + " " + k);
                last = k;
                k++;
            }
            last = 1;
            for (int i = 0; i < d - h; i++) {
                out.println(last + " " + k);
                last = k;
                k++;
            }
            if (d > h) {
                last = 1;
            } else {
                last = 2;
            }
            while (k <= n) {
                out.println(last + " " + k);
                k++;
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