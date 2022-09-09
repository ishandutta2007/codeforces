import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class CF {
    FastScanner in;
    PrintWriter out;

    void solve() {
        int n = in.nextInt();
        int m = in.nextInt();
        char[][] a = new char[n][];
        for (int i = 0; i < n; i++)
            a[i] = in.next().toCharArray();
        int[][] down = new int[n][m];
        for (int i = n - 1; i >= 0; i--)
            for (int j = 0; j < m; j++) {
                if (a[i][j] == '1') {
                    down[i][j] = i;
                } else {
                    if (i == n - 1) {
                        down[i][j] = i + 1;
                    } else {
                        down[i][j] = down[i + 1][j];
                    }
                }
            }
        int[][] left = new int[n][m];
        for (int i = n - 1; i >= 0; i--)
            for (int j = 0; j < m; j++) {
                if (a[i][j] == '1') {
                    left[i][j] = j;
                } else {
                    if (j == 0) {
                        left[i][j] = -1;
                    } else {
                        left[i][j] = left[i][j - 1];
                    }
                }
            }
        int[][] dr = new int[n][m];
        for (int i = n - 1; i >= 0; i--)
            for (int j = 0; j < m; j++) {
                if (a[i][j] == '1') {
                    dr[i][j] = i;
                } else {
                    if (i == n - 1 || j == m - 1) {
                        dr[i][j] = i + 1;
                    } else {
                        dr[i][j] = dr[i + 1][j + 1];
                    }
                }
            }
        int[][] dl = new int[n][m];
        for (int i = n - 1; i >= 0; i--)
            for (int j = 0; j < m; j++) {
                if (a[i][j] == '1') {
                    dl[i][j] = i;
                } else {
                    if (i == n - 1 || j == 0) {
                        dl[i][j] = i + 1;
                    } else {
                        dl[i][j] = dl[i + 1][j - 1];
                    }
                }
            }
        long ans = 0;
        for (int x1 = 0; x1 < n; x1++)
            for (int y1 = 0; y1 < m; y1++)
                if (a[x1][y1] == '0') {
                    for (int y2 = y1 + 1; y2 < m; y2++) {
                        if (a[x1][y2] == '1')
                            break;
                        int d = y2 - y1;
                        if (down[x1][y2] - x1 > d) {
                            if (dr[x1][y1] - x1 > d) {
                                ans++;
                            }
                        }
                        if (down[x1][y1] - x1 > d) {
                            if (dl[x1][y2] - x1 > d) {
                                ans++;
                            }
                        }
                        if (d % 2 == 0) {
                            if (dl[x1][y2] - x1 > d / 2)
                                if (dr[x1][y1] - x1 > d / 2)
                                    ans++;
                        }
                    }
                    for (int y2 = y1 + 1, x2 = x1 + 1; y2 < m && x2 < n; y2++, x2++) {
                        if (a[x2][y2] == '1')
                            break;
                        int d = x2 - x1;
                        if (down[x1][y1] - x1 > d)
                            if (y2 - left[x2][y2] > d)
                                ans++;
                        if (dl[x1][y1] - x1 > d)
                            if (y2 - left[x2][y2] > 2 * d)
                                ans++;
                        if (down[x1][y1] - x1 > d * 2)
                            if (dl[x2][y2] - x2 > d)
                                ans++;
                    }
                    for (int x2 = x1 + 1; x2 < n; x2++) {
                        if (a[x2][y1] == '1')
                            break;
                        int d = x2 - x1;
                        if (y1 - left[x2][y1] > d)
                            if (dl[x1][y1] - x1 > d)
                                ans++;
                        if (d % 2 == 0) {
                            if (dl[x1][y1] - x1 > d / 2)
                                if (dr[x1 + d / 2][y1 - d / 2] - (x1 + d / 2) > d / 2)
                                    ans++;
                        }
                    }
                }
        out.println(ans);
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