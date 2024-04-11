import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

/**
 * @author Pavel Mavrin
 */
public class A {

    int[] md = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    private void solve() throws IOException {
        int x = nextInt() - 1;
        next();
        String s = next();
        int res = 0;
        int wd = 3;
        for (int m = 0; m < 12; m++) {
            for (int d = 0; d < md[m]; d++) {
                wd = (wd + 1) % 7;
                if (s.equals("week")) {
                    if (wd == x) {
                        res++;
                    }
                } else {
                    if (d == x) {
                        res++;
                    }
                }
            }
        }
        out.println(res);

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