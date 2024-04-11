import java.io.*;
import java.util.*;

public class A {
    FastScanner in;
    PrintWriter out;

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
        int root = 0;
        while (root < n && g[root].size() != 1) {
            root++;
        }
        if (root == n) {
            throw new AssertionError();
        }
        isLeaf = new boolean[n];
        go(root, root, 0);
        int min = existOdd ? 3 : 1;
        go2(root, root, 0);
        if (max < min) {
            throw new AssertionError();
        }
        out.println(min + " " + max);
    }

    List<Integer>[] g;

    int max = 0;

    void go2(int v, int p, int curD) {
        boolean hasLeafs = false;
        for (int to : g[v]) {
            if (to == p) {
                continue;
            }
            if (isLeaf[to]) {
                hasLeafs = true;
            } else {
                max++;
                go2(to, v, curD + 1);
            }
        }
        if (hasLeafs && curD != 1) {
            max++;
        }
    }

    void go(int v, int p, int curD) {
        boolean hasChild = false;
        for (int to : g[v]) {
            if (to == p) {
                continue;
            }
            go(to, v, curD + 1);
            hasChild = true;
        }
        if (!hasChild) {
            isLeaf[v] = true;
            if (curD % 2 == 1) {
                existOdd = true;
            }
        }
    }

    boolean existOdd;
    boolean[] isLeaf;

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