import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

/**
 * Created by IntelliJ IDEA.
 * User: pashka
 * Date: 05.06.2011
 * Time: 14:02:47
 * To change this template use File | Settings | File Templates.
 */
public class A {
    BufferedReader br;
    StringTokenizer st;
    PrintWriter out;


    public static void main(String[] args) throws IOException {
        new A().run();
    }

    private void run() throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        out = new PrintWriter(System.out);
        solve();
        out.close();
    }

    String next() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return st.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    private void solve() throws IOException {
        int a = nextInt();
        int b = nextInt();
        boolean inv = false;
        if (a > b) {
            int t = a;
            a = b;
            b = t;
            inv = true;
        }
        long aa = 0;
        long bb = 0;
        long t = 0;
        while (t + a != b) {
            if (t + a < b) {
                aa += a;
                t = t + a;
            } else {
                bb += (b - t);
                aa += t + a - b;
                t = t + a - b;
            }
        }
        bb += a;
        if (inv) {
            long tt = aa;
            aa = bb;
            bb = tt;
        }
        if (aa < bb) {
            out.println("Masha");
        } else if (aa > bb) {
            out.println("Dasha");
        } else {
            out.println("Equal");
        }
    }
}