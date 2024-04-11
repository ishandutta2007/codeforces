
import java.io.*;
import java.util.StringTokenizer;

public class B {

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
        new B().run();
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
        int m = nextInt();
        int[] d = new int[n];
        for (int i = 0; i < m; i++) {
            int x = nextInt();
            int y = nextInt();
            d[x - 1]++;
            d[y - 1]++;
        }
        int[] dd = new int[n];
        for (int i = 0; i < n; i++) {
            dd[d[i]]++;
        }
        if (dd[1] == 2 && dd[2] == n - 2) {
            out.println("bus topology");
        } else if (dd[2] == n) {
            out.println("ring topology");
        } else if (dd[1] == n - 1) {
            out.println("star topology");
        } else {
            out.println("unknown topology");
        }
    }
}