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
        String t = "CODEFORCES";
        boolean res = false;
        if (s.length() >= t.length()) {
            for (int i = 0; i <= t.length(); i++) {
                if (s.startsWith(t.substring(0, i)) && s.endsWith(t.substring(i, t.length()))) {
                    res = true;
                }
            }
        }
        out.println(res ? "YES" : "NO");
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