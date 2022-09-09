import java.io.*;
import java.util.*;

public class C {
    FastScanner in;
    PrintWriter out;

    long gcd(long x, long y) {
        return x == 0 ? y : gcd(y % x, x);
    }

    final int MAX = 20;

    int[][] up;
    long[][] g;

    void solve() {
        int n = in.nextInt();
        up = new int[MAX][n];
        g = new long[MAX][n];
        for (int i = 0; i < n; i++) {
            g[0][i] = in.nextLong();
        }
        graph = new List[n];
        for (int i = 0; i < n; i++) {
            graph[i] = new ArrayList<>();
        }
        for (int i = 0; i + 1 < n; i++) {
            int fr = in.nextInt() - 1;
            int to = in.nextInt() - 1;
            graph[fr].add(to);
            graph[to].add(fr);
        }
        go(0, 0);
        out.println(res);
    }

    final int mod = (int) 1e9 + 7;
    int res;

    int mul(int x, int y) {
        return (int) ((x * 1L * y % mod));
    }

    int add(int x, int y) {
        x += y;
        return x >= mod ? (x - mod) : x;
    }

    void go(int v, int p) {
        up[0][v] = p;
        for (int i = 1; i < MAX; i++) {
            int curup = up[i - 1][v];
            up[i][v] = up[i - 1][curup];
            g[i][v] = gcd(g[i - 1][v], g[i - 1][curup]);
        }
        {
            int nowVertex = v;
            long curGCD = g[0][nowVertex];
            while (up[0][nowVertex] != 0) {
                for (int i = MAX - 1; i >= 0; i--) {
                    int nextVertex = up[i][nowVertex];
                    if (nextVertex == 0) {
                        continue;
                    }
                    if ((curGCD == 0 && g[i][nowVertex] == 0) || (curGCD != 0 && g[i][nowVertex] % curGCD == 0)) {
                        res = add(res, mul(1 << i, (int) (curGCD % mod)));
                        nowVertex = nextVertex;
                    }
                }
                curGCD = gcd(curGCD, g[0][nowVertex]);
            }
            res = add(res, (int) (curGCD % mod));
            if (nowVertex != 0) {
                res = add(res, (int) (gcd(curGCD, g[1][nowVertex]) % mod));
            }
        }
//        System.err.println("After vertex " + v + ", ans is = " + res);
        for (int i = 0; i < graph[v].size(); i++) {
            int to = graph[v].get(i);
            if (to == p) {
                continue;
            }
            go(to, v);
        }
    }

    List<Integer>[] graph;

    void run() {
        try {
            in = new FastScanner(new File("C.in"));
            out = new PrintWriter(new File("C.out"));

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
        new C().runIO();
    }
}