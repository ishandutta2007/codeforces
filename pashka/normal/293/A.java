
import java.io.*;
import java.util.StringTokenizer;

public class A {

    BufferedReader br;
    StringTokenizer st;
    PrintStream out = System.out;

    String next() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return st.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    public static void main(String[] args) throws FileNotFoundException {
        new A().run();
    }

    private void run() {
        br = new BufferedReader(new InputStreamReader(System.in));
        try {
            solve();
        } catch (IOException e) {
            e.printStackTrace();
        }
        out.close();
    }

    private void solve() throws IOException {
        int n = nextInt();
        String s = next();
        String t = next();
        int n01 = 0;
        int n10 = 0;
        int n11 = 0;
        int n00 = 0;
        for (int i = 0; i < 2 * n; i++) {
            char c1 = s.charAt(i);
            char c2 = t.charAt(i);
            if (c1 == '0' && c2 == '0') n00++;
            if (c1 == '0' && c2 == '1') n01++;
            if (c1 == '1' && c2 == '0') n10++;
            if (c1 == '1' && c2 == '1') n11++;
        }

        int fs = 0;
        int ss = 0;
        for (int i = 0; i < n; i++) {
            if (n11 > 0) {
                n11--;
                fs++;
            } else if (n10 > 0) {
                n10--;
                fs++;
            } else if (n01 > 0) {
                n01--;
            } else {
                n00--;
            }
            if (n11 > 0) {
                n11--;
                ss++;
            } else if (n01 > 0) {
                n01--;
                ss++;
            } else if (n10 > 0) {
                n10--;
            } else {
                n00--;
            }
        }
        if (fs > ss) {
            out.println("First");
        } else if (ss > fs) {
            out.println("Second");
        } else {
            out.println("Draw");
        }

        //To change body of created methods use File | Settings | File Templates.
    }
}