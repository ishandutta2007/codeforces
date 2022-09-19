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
        String s = next();
        int b = 0;
        int c = 0;
        int lb = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(') {
                b++;
            } else if (s.charAt(i) == ')') {
                b--;
            } else {
                b--;
                c++;
                lb = b;
            }
            lb = Math.min(b, lb);
            if (b < 0) {
                out.println(-1);
                return;
            }
        }
//        System.out.println(lb + " " + b);
        if (lb - b < 0) {
            out.println(-1);
            return;
        }
        for (int i = 0; i < c - 1; i++) {
            out.println(1);
        }
        out.println(1 + b);
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