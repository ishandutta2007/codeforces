import java.io.*;
import java.util.*;

public class A {
    private FastScanner in;
    private PrintWriter out;

    int n, m;
    char[][] a;

    int xs, ys;

    int[] dx = new int[]{-1, 0, 0, 1};
    int[] dy = new int[]{0, -1, 1, 0};

    String rr;

    int go(boolean[] used, int[] idx, int r) {
        if (r == used.length) {
            int x = xs, y = ys;
            for (char c : rr.toCharArray()) {
                int id = idx[c - '0'];
                int ddx = dx[id], ddy = dy[id];
                x += ddx;
                y += ddy;
                if (x < 0 || x >= n || y < 0 || y >= m || a[x][y] == '#') {
                    return 0;
                }
                if (a[x][y] == 'E') {
                    return 1;
                }
            }
            return 0;
        } else {
            int res = 0;
            for (int i = 0; i < 4; i++) {
                if (!used[i]) {
                    used[i] = true;
                    idx[r] = i;
                    res += go(used, idx, r + 1);
                    used[i] = false;
                }
            }
            return res;
        }
    }

    private void solve() {
        n = in.nextInt();
        m = in.nextInt();
        a = new char[n][];
        for (int i = 0; i < n; i++) {
            a[i] = in.next().toCharArray();
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == 'S') {
                    xs = i;
                    ys = j;
                    a[i][j] = '.';
                }
            }
        }
        rr = in.next();
        out.println(go(new boolean[4], new int[4], 0));
    }

    private void run() {
        try {
            in = new FastScanner(new File("A.in"));
            out = new PrintWriter(new File("A.out"));

            solve();

            out.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    private void runIO() {
        in = new FastScanner(System.in);
        out = new PrintWriter(System.out);

        solve();

        out.close();
    }

    private class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        FastScanner(File f) {
            try {
                br = new BufferedReader(new FileReader(f));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        FastScanner(InputStream f) {
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

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }
    }

    public static void main(String[] args) {
        new A().runIO();
    }
}