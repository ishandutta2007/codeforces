
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
        int[] t = new int[n];
        int[] c = new int[n];
        for (int i = 0; i < n; i++) {
            t[i] = nextInt();
            c[i] = nextInt();
        }
        int s = c[0];
        int max = s;
        for (int i = 1; i < n; i++) {
            s -= (t[i] - t[i - 1]);
            if (s < 0) s = 0;
            s += c[i];
            max = Math.max(max, s);
        }
        out.println((t[n - 1] + s) + " " + max);


        //To change body of created methods use File | Settings | File Templates.
    }
}