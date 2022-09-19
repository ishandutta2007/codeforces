import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class A {

    private void solve() throws IOException {
        String a = next();
        int n = a.length();
        char[] res = new char[n];
        int m = 0;
        for (int i = 0; i < a.length(); i++) {
            res[m++] = a.charAt(i);
            if (m > 1 && res[m - 1] == res[m - 2]) {
                m -= 2;
            }
        }
        for (int i = 0; i < m; i++) out.print(res[i]);
        out.println();
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
        new A().run();
    }

    private void run() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        solve();
        out.close();
        br.close();
    }

}