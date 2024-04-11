import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class CF {
    FastScanner in;
    PrintWriter out;

    void solve() {
        int n = in.nextInt();
        int m = in.nextInt();
        int q = in.nextInt();
        int[][] a = new int[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                a[i][j] = in.nextInt();
        }
        int[][] up = new int[n][m];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                up[i][j] = a[i][j] == 0 ? i : (i == 0 ? -1 : up[i - 1][j]);
        int[][] down = new int[n][m];
        for (int i = n - 1; i >= 0; i--)
            for (int j = m - 1; j >= 0; j--)
                down[i][j] = a[i][j] == 0 ? i : (i == n - 1 ? n
                        : down[i + 1][j]);
        int[][] left = new int[n][m];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                left[i][j] = a[i][j] == 0 ? j : (j == 0 ? -1 : left[i][j - 1]);
        int[][] right = new int[n][m];
        for (int i = 0; i < n; i++)
            for (int j = m - 1; j >= 0; j--)
                right[i][j] = a[i][j] == 0 ? j : (j == m - 1 ? m
                        : right[i][j + 1]);
        int[] x1 = new int[q];
        int[] y1 = new int[q];
        int op = 0;
        int[] maxUp = new int[m];
        int[] maxDown = new int[m];
        int[] maxLeft = new int[n];
        int[] maxRight = new int[n];
        for (int i = 0; i < q; i++) {
            if (in.nextInt() == 1) {
                int x = in.nextInt() - 1;
                int y = in.nextInt() - 1;
                a[x][y] = 1 - a[x][y];
                x1[op] = x;
                y1[op++] = y;
            } else {
                int x = in.nextInt() - 1;
                int y = in.nextInt() - 1;
                for (int xx1 = 0; xx1 < n; xx1++) {
                    maxLeft[xx1] = left[xx1][y];
                    while (maxLeft[xx1] != -1 && a[xx1][maxLeft[xx1]] == 1) {
                        maxLeft[xx1]--;
                        if (maxLeft[xx1] != -1)
                            maxLeft[xx1] = left[xx1][maxLeft[xx1]];
                    }
                    maxRight[xx1] = right[xx1][y];
                    while (maxRight[xx1] != m && a[xx1][maxRight[xx1]] == 1) {
                        maxRight[xx1]++;
                        if (maxRight[xx1] != m)
                            maxRight[xx1] = right[xx1][maxRight[xx1]];
                    }
                }
                for (int yy1 = 0; yy1 < m; yy1++) {
                    maxUp[yy1] = up[x][yy1];
                    while (maxUp[yy1] != -1 && a[maxUp[yy1]][yy1] == 1) {
                        maxUp[yy1]--;
                        if (maxUp[yy1] != -1)
                            maxUp[yy1] = up[maxUp[yy1]][yy1];
                    }
                    maxDown[yy1] = down[x][yy1];
                    while (maxDown[yy1] != n && a[maxDown[yy1]][yy1] == 1) {
                        maxDown[yy1]++;
                        if (maxDown[yy1] != n)
                            maxDown[yy1] = down[maxDown[yy1]][yy1];
                    }
                }
                for (int qq = 0; qq < op; qq++) {
                    int xx1 = x1[qq], yy1 = y1[qq];
                    if (a[xx1][yy1] == 0) {
                        if (xx1 <= x) {
                            maxUp[yy1] = Math.max(maxUp[yy1], xx1);
                        }
                        if (xx1 >= x) {
                            maxDown[yy1] = Math.min(maxDown[yy1], xx1);
                        }
                        if (yy1 <= y) {
                            maxLeft[xx1] = Math.max(maxLeft[xx1], yy1);
                        }
                        if (yy1 >= y) {
                            maxRight[xx1] = Math.min(maxRight[xx1], yy1);
                        }
                    }
                }
                long ans = 0;
                {
                    int left1 = -1, right1 = m;
                    for (int xx1 = x; xx1 < n; xx1++) {
                        left1 = Math.max(left1, maxLeft[xx1]);
                        right1 = Math.min(right1, maxRight[xx1]);
                        if (left1 < y && right1 > y)
                            ans = Math.max(ans, (right1 - left1 - 1)
                                    * (xx1 - x + 1));
                    }
                }
                {
                    int left1 = -1, right1 = m;
                    for (int xx1 = x; xx1 >= 0; xx1--) {
                        left1 = Math.max(left1, maxLeft[xx1]);
                        right1 = Math.min(right1, maxRight[xx1]);
                        if (left1 < y && right1 > y)
                            ans = Math.max(ans, (right1 - left1 - 1)
                                    * (x - xx1 + 1));
                    }
                }
                {
                    int up1 = -1, down1 = n;
                    for (int yy1 = y; yy1 < m; yy1++) {
                        up1 = Math.max(up1, maxUp[yy1]);
                        down1 = Math.min(down1, maxDown[yy1]);
                        if (down1 > x && up1 < x)
                            ans = Math.max(ans, (down1 - up1 - 1)
                                    * (yy1 - y + 1));
                    }
                }
                {
                    int up1 = -1, down1 = n;
                    for (int yy1 = y; yy1 >= 0; yy1--) {
                        up1 = Math.max(up1, maxUp[yy1]);
                        down1 = Math.min(down1, maxDown[yy1]);
                        if (down1 > x && up1 < x)
                            ans = Math.max(ans, (down1 - up1 - 1)
                                    * (y - yy1 + 1));
                    }
                }
                out.println(ans);
            }
        }
    }

    void run() {
        try {
            in = new FastScanner(new File("test.in"));
            out = new PrintWriter(new File("test.out"));

            solve();

            out.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    void runIO() {

        in = new FastScanner(System.in);
        out = new PrintWriter(System.out);

        solve();

        out.close();
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(File f) {
            try {
                br = new BufferedReader(new FileReader(f));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        public FastScanner(InputStream f) {
            br = new BufferedReader(new InputStreamReader(f));
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                String s = null;
                try {
                    s = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (s == null)
                    return null;
                st = new StringTokenizer(s);
            }
            return st.nextToken();
        }

        boolean hasMoreTokens() {
            while (st == null || !st.hasMoreTokens()) {
                String s = null;
                try {
                    s = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (s == null)
                    return false;
                st = new StringTokenizer(s);
            }
            return true;
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }
    }

    public static void main(String[] args) {
        new CF().runIO();
    }
}