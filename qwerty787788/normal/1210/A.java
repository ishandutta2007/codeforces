import java.io.*;
import java.util.*;

public class A {
    FastScanner in;
    PrintWriter out;

    boolean[][] g;
    int[] id;
    boolean[][] used = new boolean[7][7];

    int go(int curVertex) {
        if (curVertex == g.length) {
            int curRes = 0;
            for (int i = 0; i < curVertex; i++) {
                for (int j = i + 1; j < curVertex; j++) {
                    int u = Math.min(id[i], id[j]);
                    int v = Math.max(id[i], id[j]);
                    if (g[i][j] && !used[u][v]) {
                        used[u][v] = true;
                        curRes++;
                    }
                }
            }
            for (int i = 0; i < 6; i++) {
                Arrays.fill(used[i], false);
            }
            return curRes;
        }
        int r = 0;
        for (int i = 0; i < 6; i++) {
            id[curVertex] = i;
            r = Math.max(r, go(curVertex + 1));
        }
        return r;
    }

    void solve() {
        int n = in.nextInt();
        int m = in.nextInt();
        g = new boolean[n][n];
        id = new int[n];
        for (int i = 0; i < m; i++) {
            int fr = in.nextInt() - 1;
            int to = in.nextInt() - 1;
            g[fr][to] = g[to][fr] = true;
        }

        out.println(go(0));
    }

    void run() {
        try {
            in = new FastScanner(new File("A.in"));
            out = new PrintWriter(new File("A.out"));

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

        double nextDouble() {
            return Double.parseDouble(next());
        }
    }

    public static void main(String[] args) {
        new A().runIO();
    }
}