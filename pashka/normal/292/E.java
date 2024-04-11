
import java.io.*;
import java.util.StringTokenizer;

public class E {

    BufferedReader br;
    StringTokenizer st;
    PrintStream out = System.out;
    private int n;
    private boolean[] dd;
    private int nn;
    private int[] a;

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
        new E().run();
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

    int[] d;

    private void solve() throws IOException {
        n = nextInt();
        int m = nextInt();
        a = new int[2 * n];
        for (int i = 0; i < 2 * n; i++) {
            a[i] = nextInt();
        }
        nn = 1;
        while (nn < n) nn *= 2;

        d = new int[nn * 2];
        dd = new boolean[nn * 2];
        copy(n, 0, n);

        for (int i = 0; i < m; i++) {
            int t = nextInt();
            if (t == 1) {
                int x = nextInt() - 1;
                int y = nextInt() - 1;
                int k = nextInt();
                copy(x, y, k);
            } else {
                int x = nextInt();
                out.println(get(x - 1));
//                return;
            }
        }
    }

    private int get(int x) {
        return get(0, 0, n, x);
    }

    private int get(int i, int l, int r, int x) {
        if (dd[i]) {
            return a[d[i] + x - l];
        }
        if (r == l + 1) throw new RuntimeException();
        int m = (l + r) / 2;
        if (x < m) {
            return get(i * 2 + 1, l, m, x);
        } else {
            return get(i * 2 + 2, m, r, x);
        }
    }

    private void copy(int x, int y, int k) {
        copy(0, 0, n, x, y, k);
    }

    private void copy(int i, int l, int r, int x, int y, int k) {
        if (dd[i]) {
            relax(i, l, r);
        }
        if (y <= l && y + k >= r) {
            dd[i] = true;
            d[i] = l - y + x;
            return;
        }
        if (y >= r || y + k <= l) return;
        int m = (l + r) / 2;
        copy(i * 2 + 1, l, m, x, y, k);
        copy(i * 2 + 2, m, r, x, y, k);
    }

    private void relax(int i, int l, int r) {
        if (dd[i] && r > l + 1) {
            dd[i] = false;
            int m = (l + r) / 2;
            dd[2 * i + 1] = true;
            d[2 * i + 1] = d[i];
            dd[2 * i + 2] = true;
            d[2 * i + 2] = d[i] + (m - l);
        }
    }


}