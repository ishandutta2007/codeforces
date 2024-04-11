
import java.io.*;
import java.util.Arrays;
import java.util.Random;
import java.util.StringTokenizer;

public class D {

    BufferedReader br;
    StringTokenizer st;
    PrintStream out = System.out;
    private int[] p;
    private int res;

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
        new D().run();
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
        int[] x = new int[m];
        int[] y = new int[m];
        for (int i = 0; i < m; i++) {
            x[i] = nextInt() - 1;
            y[i] = nextInt() - 1;
        }
        int[][] z1 = new int[m + 1][n];
        int[][] z2 = new int[m + 1][n];
        for (int i = 0; i < n; i++) {
            z1[0][i] = i;
            z2[m][i] = i;
        }
        for (int i = 0; i < m; i++) {
            addEdge(z1[i], x[i], y[i], z1[i + 1]);
            addEdge(z2[m - i], x[m - 1 - i], y[m - 1 - i], z2[m - 1 - i]);
        }

        int k = nextInt();
        p = new int[n];
        for (int i = 0; i < k; i++) {
            int l = nextInt();
            int r = nextInt();
            int[][] a = new int[][]{z1[l - 1], z2[r]};
//            System.out.println(Arrays.toString(a[0]));
//            System.out.println(Arrays.toString(a[1]));
            for (int j = 0; j < n; j++) p[j] = j;
            res = n;
            int[] t = new int[n];
            for (int s = 0; s < 2; s++) {
                Arrays.fill(t, -1);
                for (int j = 0; j < n; j++) {
                    if (t[a[s][j]] == -1) {
                        t[a[s][j]] = j;
                    } else {
                        join(j, t[a[s][j]]);
                    }
                }
            }
            out.println(res);
        }

    }

    Random random = new Random(4545675686L);

    private void join(int x, int y) {
        x = get(x);
        y = get(y);
        if (x != y) {
            res--;
            if (random.nextBoolean()) {
                p[x] = y;
            } else {
                p[y] = x;
            }
        }

        //To change body of created methods use File | Settings | File Templates.
    }

    private int get(int x) {
        if (p[x] != x) {
            p[x] = get(p[x]);
        }
        return p[x];
    }

    private void addEdge(int[] a, int x, int y, int[] b) {
        for (int i = 0; i < a.length; i++) {
            if (a[i] == a[x]) {
                b[i] = a[y];
            } else {
                b[i] = a[i];
            }
        }
    }
}