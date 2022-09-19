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
        long x = 0;
        long y = 0;
        long s = 0;
        int a = nextInt();
        x += a;
        a = nextInt();
        s -= (a * (y + y + a));
        x += a;
        y += a;
        a = nextInt();
        y += a;
        a = nextInt();
        s += (a * y * 2);
        x -= a;
        a = nextInt();
        s += (a * (y + y - a));
        x -= a;
        y -= a;
        a = nextInt();
        out.println(s);
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