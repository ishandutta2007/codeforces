import java.io.*;
import java.util.*;

public class A {
    private FastScanner in;
    private PrintWriter out;

    final int mod = (int) 1e9 + 7;

    int m;

    int k, x;
    ArrayList<Integer>[] g;

    int[][] go(int v, int p) {
        int[][] res = new int[3][x + 1];
        res[0][0] = less;
        res[1][1] = 1;
        res[2][0] = more;
        for (int i = 0; i < g[v].size(); i++) {
            int to = g[v].get(i);
            if (to == p) {
                continue;
            }
            int[][] child = go(to, v);
            int[][] newRes = new int[3][x + 1];
            for (int id = 0; id < 3; id++) {
                for (int cnt = 0; cnt <= x; cnt++) {
                    for (int id2 = 0; id2 < 3; id2++) {
                        if (id == 1 && id2 >= 1) {
                            continue;
                        }
                        if (id2 == 1 && id >= 1) {
                            continue;
                        }
                        for (int cnt2 = 0; cnt2 + cnt <= x; cnt2++) {
                            newRes[id][cnt + cnt2] = (int) ((newRes[id][cnt + cnt2] + child[id2][cnt2] * 1L * res[id][cnt]) % mod);
                        }
                    }
                }
            }
            res = newRes;
        }
        return res;
    }

    private void solve() {
        int n = in.nextInt();
        m = in.nextInt();
        g = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            g[i] = new ArrayList<>();
        }
        for (int i = 0; i + 1 < n; i++) {
            int fr = in.nextInt() - 1;
            int to = in.nextInt() - 1;
            g[fr].add(to);
            g[to].add(fr);
        }
        k = in.nextInt();
        x = in.nextInt();
        less = k - 1;
        more = m - k;
        int[][] res = go(0, -1);
        long result = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j <= x; j++) {
                result += res[i][j];
            }
        }
        out.println(result % mod);
    }

    int less, more;

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