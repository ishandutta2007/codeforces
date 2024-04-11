import java.io.*;
import java.util.*;

public class D {
    FastScanner in;
    PrintWriter out;

    List<Integer>[] g;

    int[] sz;

    void go(int v, int p) {
        sz[v] = 1;
        for (int to : g[v]) {
            if (to == p) {
                continue;
            }
            go(to, v);
            sz[v] += sz[to];
        }
    }

    void solve() {
        int n = in.nextInt();
        g = new List[n];
        for (int i = 0; i < n; i++) {
            g[i] = new ArrayList<>();
        }
        for (int i = 0; i + 1 < n; i++) {
            int fr = in.nextInt() - 1;
            int to = in.nextInt() - 1;
            g[fr].add(to);
            g[to].add(fr);
        }
        sz = new int[n];
        go(0, 0);
        int root = 0;
        int prev = 0;
        while (true) {
            boolean found = false;
            for (int to : g[root]) {
                if (to == prev) {
                    continue;
                }
                if (sz[to] * 2 > n) {
                    prev = root;
                    root = to;
                    found = true;
                    break;
                }
            }
            if (!found) {
                break;
            }
//            System.err.println(root);
        }
        go(root, root);
        int more = n - 1;
        boolean bigPart = false;
        while (n != 1) {
            Collections.shuffle(g[root]);
            boolean ok = false;
            int size = 0;
            for (int to : g[root]) {
                size += sz[to];
                int max = (size + 1) * (n - size) - 1;
                if (2 * n * n / 9 <= max) {
                    ok = true;
                    break;
                }
            }
            if (ok) {
                break;
            }
        }
        for (int to : g[root]) {
            long biggest = (curMaxValue + 1) * 1L * (more + 1) - 1;
            if (2 * n * n / 9 <= biggest) {
                bigPart = true;
            }
            if (!bigPart) {
                goValsSmall(to, root, 0);
            } else {
                goValsBig(to, root, 0);
            }
            more -= sz[to];
        }
        if (!bigPart && n != 1) {
            throw new AssertionError();
        }
    }

    void goValsBig(int v, int prev, int prevSum) {
        curBig += (curMaxValue + 1);
        out.println((v + 1) + " " + (prev + 1) + " " + (curBig - prevSum));
        int currentValue = curBig;
        for (int to : g[v]) {
            if (to == prev) {
                continue;
            }
            goValsBig(to, v, currentValue);
        }
    }

    void goValsSmall(int v, int prev, int prevSum) {
        curMaxValue++;
        out.println((v + 1) + " " + (prev + 1) + " " + (curMaxValue - prevSum));
        int currentValue = curMaxValue;
        for (int to : g[v]) {
            if (to == prev) {
                continue;
            }
            goValsSmall(to, v, currentValue);
        }
    }

    int curMaxValue = 0;
    int curBig = 0;

    void run() {
        try {
            in = new FastScanner(new File("D.in"));
            out = new PrintWriter(new File("D.out"));

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
        new D().runIO();
    }
}