import java.io.*;
import java.util.*;

public class A {
    FastScanner in;
    PrintWriter out;

    ArrayList<Integer>[] g;
    ArrayList<Integer>[] gBack;

    void solve() {
        int n = in.nextInt();
        int m = in.nextInt();
        g = new ArrayList[n];
        gBack = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            g[i] = new ArrayList<>();
            gBack[i] = new ArrayList<>();
        }
        for (int i = 0; i < n; i++) {
            int cnt = in.nextInt();
            for (int j = 0; j < cnt; j++) {
                int to = in.nextInt() - 1;
                g[i].add(to);
                gBack[to].add(i);
            }
        }
        int start = in.nextInt() - 1;
        boolean[][] was = new boolean[2][n];
        int[][] q = new int[2][2 * n];
        int[][] next = new int[2][n];
        int qIt = 0;
        int qSz = 0;
        for (int i = 0; i < n; i++) {
            if (g[i].size() == 0) {
                q[0][qSz] = 0;
                q[1][qSz++] = i;
                was[0][i] = true;
                next[0][i] = -1;
            }
        }
        while (qIt < qSz) {
            int par = q[0][qIt];
            int v = q[1][qIt++];
            for (int to : gBack[v]) {
                if (!was[1 - par][to]) {
                    was[1 - par][to] = true;
                    q[0][qSz] = 1 - par;
                    q[1][qSz++] = to;
                    next[1 - par][to] = v;
                }
            }
        }
        if (was[1][start]) {
            out.println("Win");
            int par = 1;
            while (start != -1) {
                out.print((start + 1) + " ");
                start = next[par][start];
                par = 1 - par;
            }
            return;
        }

        if (!go(start, new int[n])) {
            out.println("Lose");
        } else {
            out.println("Draw");
        }
    }

    boolean go(int v, int[] was) {
        was[v] = 1;
        for (int to : g[v]) {
            if (was[to] == 1) {
                return true;
            }
            if (was[to] == 2) {
                continue;
            }
            if (go(to, was)) {
                return true;
            }
        }
        was[v] = 2;
        return false;
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