import java.io.*;
import java.util.*;

public class CF {
    FastScanner in;
    PrintWriter out;

    int MAX = 65;

    int[] dx = { 0, -1, 0, 0, 1 };
    int[] dy = { 0, 0, -1, 1, 0 };

    void relax(int[][] a) {
        int n = a.length;
        for (;;) {
            boolean ch = false;
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    if (a[i][j] >= 4) {
                        int cnt = a[i][j] / 4;
                        a[i][j] -= 4 * cnt;
                        for (int k = 1; k < 5; k++)
                            a[i + dx[k]][j + dy[k]] += cnt;
                        ch = true;
                    }
            if (!ch) {
                break;
            }
        }
    }

    int[][] sum(int[][] a, int[][] b) {
        int[][] res = new int[a.length][a.length];
        int n = a.length;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                res[i][j] = a[i][j] + b[i][j];
        return res;
    }

    int[][] get(int n) {
        int[][] cur = new int[MAX * 2][MAX * 2];
        cur[MAX][MAX] = 1;
        int[][] ans = new int[MAX * 2][MAX * 2];
        for (int i = 0; i < 15; i++) {
            
            if (((1 << i) & n) != 0) {
                ans = sum(ans, cur);
                relax(ans);
            }
            if ((1 << (i + 1)) > n)
                break;
            cur = sum(cur, cur);
            relax(cur);
        }
        return ans;
    }

    void solve() {
        int n = in.nextInt();
        int[][] cnt  = get(n);
        int t = in.nextInt();
        for (int i = 0; i < t; i++) {
            int x = in.nextInt() + MAX;
            int y = in.nextInt() + MAX;
            boolean f = false;
            if (x >= 0 && x < MAX * 2) {
                if (y >= 0 && y < MAX * 2) {
                    out.println(cnt[x][y]);
                    f = true;
                }
            }
            if (!f) {
                out.println(0);
            }
        }

    }

    void run() {
        try {
            in = new FastScanner(new File("object.in"));
            out = new PrintWriter(new File("object.out"));

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

        long nextLong() {
            return Long.parseLong(next());
        }
    }

    public static void main(String[] args) {
        new CF().runIO();
    }
}