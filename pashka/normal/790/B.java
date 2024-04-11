import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

/**
 * @author Pavel Mavrin
 */
public class B {

    private int k;

    private void solve() throws IOException {
        n = nextInt();
        k = nextInt();
        init(n);
        for (int i = 0; i < n - 1; i++) {
            int x = nextInt() - 1;
            int y = nextInt() - 1;
            addEdge(x, y);
        }
        dfs(0, -1);
        dfs2(0, -1);
        long res = 0;
        for (int j = 0; j < k; j++) {
            for (int i = 0; i < n; i++) {
//                System.out.println(i + " " + j + " " + numDown[j][i] + " " + sumDown[j][i] + " " + numUp[j][i] + " " + sumUp[j][i]);
                res += sumDown[j][i] + sumUp[j][i];
            }
        }
        res /= 2;
        out.println(res);
    }

    void init(int n) {
        this.n = n;
        this.m = (n - 1) * 2;
        last = 0;
        head = new int[n];
        nx = new int[m];
        dst = new int[m];
        numUp = new long[k][n];
        sumUp = new long[k][n];
        numDown = new long[k][n];
        sumDown = new long[k][n];
        Arrays.fill(head, -1);
    }


    void addEdge(int x, int y) {
        nx[last] = head[x];
        dst[last] = y;
        head[x] = last;
        last++;
        nx[last] = head[y];
        dst[last] = x;
        head[y] = last;
        last++;
    }

    private int dfs(int x, int p) {
        int j = head[x];
        numDown[0][x] = 1;
        while (j >= 0) {
            int y = dst[j];
            if (y != p) {
                dfs(y, x);
                for (int i = 0; i < k; i++) {
                    int ii = (i + 1) % k;
                    numDown[ii][x] += numDown[i][y];
                    sumDown[ii][x] += sumDown[i][y] + (i == 0 ? numDown[0][y] : 0);
                }
            }
            j = nx[j];
        }
        return 0;
    }

    private int dfs2(int x, int p) {
        if (p >= 0) {
            for (int i = 0; i < k; i++) {
                int ii = (i + 1) % k;
                int iii = (i + k - 1) % k;
                numUp[ii][x] = numUp[i][p] + numDown[i][p] - numDown[iii][x];
                sumUp[ii][x] = sumUp[i][p] + sumDown[i][p] - (sumDown[iii][x] + (iii == 0 ? numDown[iii][x] : 0)) + (i == 0 ? numUp[ii][x] : 0);
            }
        }
        int j = head[x];
        while (j >= 0) {
            int y = dst[j];
            if (y != p) {
                dfs2(y, x);
            }
            j = nx[j];
        }
        return 0;
    }

    int n, m;
    int[] head;
    int[] nx;
    int[] dst;
    long[][] numUp;
    long[][] sumUp;
    long[][] numDown;
    long[][] sumDown;
    int last;

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
        new B().run();
    }

    private void run() throws IOException {
        solve();
        out.close();
    }

}