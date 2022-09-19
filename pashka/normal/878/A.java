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
        int[] st = new int[10];
        for (int i = 0; i < n; i++) {
            String c = next();
            int x = nextInt();
            switch (c) {
                case "|":
                    for (int j = 0; j < 10; j++) {
                        if ((x & (1 << j)) > 0) {
                            st[j] = 1;
                        }
                    }
                    break;
                case "&":
                    for (int j = 0; j < 10; j++) {
                        if ((x & (1 << j)) == 0) {
                            st[j] = 2;
                        }
                    }
                    break;
                case "^":
                    for (int j = 0; j < 10; j++) {
                        if ((x & (1 << j)) > 0) {
                            st[j] = 3 - st[j];
                        }
                    }
                    break;
            }
        }

        out.println(3);

        int x = 0;
        for (int j = 0; j < 10; j++) {
            if (st[j] == 1) {
                x |= (1 << j);
            }
        }
        out.println("| " + x);

        x = 0;
        for (int j = 0; j < 10; j++) {
            if (st[j] != 2) {
                x |= (1 << j);
            }
        }
        out.println("& " + x);

        x = 0;
        for (int j = 0; j < 10; j++) {
            if (st[j] == 3) {
                x |= (1 << j);
            }
        }
        out.println("^ " + x);

    }

    // ------------------

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