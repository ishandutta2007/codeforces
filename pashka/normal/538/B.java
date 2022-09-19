import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

/**
 * @author Pavel Mavrin
 */
public class B {

    private void solve() throws IOException {
        int n = nextInt();
        String s = "" + n;
        List<Integer> res = new ArrayList<Integer>();
        for (int i = 0; i < 9; i++) {
            int q = 0;
            for (int j = 0; j < s.length(); j++) {
                q *= 10;
                if (s.charAt(j) > '0' + i) {
                    q++;
                }
            }
            if (q > 0) {
                res.add(q);
            }
        }
        out.println(res.size());
        for (Integer re : res) {
            out.print(re + " ");
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