
import java.io.*;
import java.util.Arrays;
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
        int[] a = new int[n];
        for (int i = 0; i < n; i++) a[i] = nextInt();
        Arrays.sort(a);
        int res = 0;
        for (int i = 1; i < n; i++) if (a[i] > 0) {
            if (a[i] == a[i - 1]) {
                res++;
            }
            if (i > 1 && a[i] == a[i - 2]) {
                out.println(-1);
                return;
            }
        }
        out.println(res);
    }
}