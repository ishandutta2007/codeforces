import java.io.*;
import java.util.*;

public class D {
    private FastScanner in;
    private PrintWriter out;

    boolean solve(int n, ArrayList<Integer>[] g) {
        HashSet<Long> edges = new HashSet<>();
        for (int i = 0; i < n; i++) {
            for (int j : g[i]) {
                if (j > i) {
                    long v = i;
                    edges.add((v << 20) + j);
                }
            }
        }
        int[] color = new int[n];
        Arrays.fill(color, Integer.MAX_VALUE);
        color[0] = 0;
        boolean[] near0 = new boolean[n];
        for (int to : g[0]) {
            near0[to]= true;
        }
        boolean used1 = false;
        for (int to : g[0]) {
            boolean allNear0 = true;
            for (int to2 :g[to]) {
                if (to2 != 0 && !near0[to2]) {
                    allNear0 = false;
                }
            }
            if (allNear0 && g[to].size() == g[0].size()) {
                color[to] = 0;
                continue;
            }
            int nColor = 2;
            for (int to2 : g[to]) {
                if (color[to2] != Integer.MAX_VALUE && color[to2] != 0) {
                    nColor = color[to2];
                }
            }
            if (nColor != 2) {
                color[to] = nColor;
            } else {
                if (used1) {
                    color[to] = -1;
                } else {
                    color[to] = 1;
                    used1 = true;
                }
            }
        }
//        System.err.println("!! " + Arrays.toString(color));
        int[] bfs = new int[n];
        int qIt = 0, qSz = 0;
        for (int i = 1; i < n; i++) {
            if (color[i] != Integer.MAX_VALUE) {
                bfs[qSz++] = i;
            }
        }
        while (qIt < qSz) {
            int v = bfs[qIt++];
            for (int to : g[v]) {
                if (color[to] == Integer.MAX_VALUE) {
                    color[to] = (color[v] < 0 ? (color[v] - 1) : (color[v] + 1));
                    bfs[qSz++] = to;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int to : g[i]) {
                if (Math.abs(color[i] - color[to]) > 1) {
                    out.println("NO");
                    return false;
                }
            }
        }
//        System.err.println(Arrays.toString(color));
        int minColor = 0;
        for (int i : color) {
            minColor = Math.min(minColor, i);
        }
        for (int i = 0; i < n; i++) {
            color[i] += -minColor + 1;
        }
        int maxColor = 0;
        for (int i : color) {
            maxColor = Math.max(maxColor, i);
        }
        ArrayList<Integer>[] ver = new ArrayList[maxColor + 1];
        for (int i = 0; i < ver.length; i++) {
            ver[i] = new ArrayList<>();
        }
        for (int i = 0; i < n; i++) {
            ver[color[i]].add(i);
        }
//        System.err.println(Arrays.toString(color));
        for (int i = 0; i <= maxColor; i++) {
            for (int v : ver[i]) {
                for (int j = i - 1; j <= i + 1; j++) {
                    if (j >= 0 && j < ver.length) {
                        for (int u : ver[j]) {
                            if (u == v) {
                                continue;
                            }
                            long edge = Math.min(u, v);
                            edge = (edge << 20) + Math.max(u, v);
                            if (!edges.contains(edge)) {
//                                System.err.println(v + " "+ u);
                                out.println("NO");
                                return false;
                            }
                        }
                    }
                }
            }
        }
        out.println("YES");
        for (int c : color) {
            out.print(c + " ");
        }
        out.println();
        return true;
    }

    void solve1233() {
        Random rnd = new Random(123);
        for (int it = 0; it < 123123; it++) {
            System.err.println("!" + it);
            int n = 1 + rnd.nextInt(100);
            int[] color = new int[n];
            int maxColor = 0;
            for (int i = 0; i < n; i++) {
                color[i] = rnd.nextInt(maxColor + 1);
                maxColor = Math.max(maxColor, color[i] + 1);
            }
            ArrayList<Integer>[] g = new ArrayList[n];
            for (int i = 0; i < n; i++) {
                g[i] = new ArrayList<>();
                for (int j = 0; j < n; j++) {
                    if (Math.abs(color[i] - color[j]) <= 1 && i != j) {
                        g[i].add(j);
                    }
                }
            }
            if (!solve(n, g)) {
                for (int i = 0; i < n; i++) {
                    System.err.println(i + ":" + g[i]);
                }
                throw new AssertionError();
            }
        }
    }

    private void solve() {
        int n = in.nextInt();
        int m = in.nextInt();
        ArrayList<Integer>[] g = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            g[i] = new ArrayList<>();
        }
        for (int i = 0; i < m; i++) {
            int fr = in.nextInt() - 1;
            int to = in.nextInt() - 1;
            g[fr].add(to);
            g[to].add(fr);
        }
        solve(n, g);
    }

    private void run() {
        try {
            in = new FastScanner(new File("D.in"));
            out = new PrintWriter(new File("D.out"));

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
        new D().runIO();
    }
}