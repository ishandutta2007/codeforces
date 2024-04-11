import java.io.*;
import java.util.*;

public class A {
    FastScanner in;
    PrintWriter out;

    List<Integer>[] g;
    int[] parent;

    void go(int v, int p) {
        parent[v] = p;
        for (int to : g[v]) {
            if (to == p) {
                continue;
            }
            go(to, v);
        }
    }

    // 0 - unknown
    // 1 - up
    // -1 down
    int[] isEdgeUp;

    void solve() {
        // 21:47
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
        parent = new int[n];
        go(0, -1);
        isEdgeUp = new int[n];
        while (true) {
            List<Integer> vertices = new ArrayList<>();
            for (int i = 1; i < n; i++) {
                if (isEdgeUp[i] == 0) {
                    vertices.add(i);
                    vertices.add(parent[i]);
                    if (vertices.size() == 4) {
                        break;
                    }
                }
            }
            if (vertices.isEmpty()) {
                break;
            }
            int[] toAsk = null;
            for (int v1 : vertices) {
                for (int v2 : vertices) {
                    List<Integer> path = new ArrayList<>();
                    findPath(v1, v2, v1, path);
                    boolean ok = true;
                    for (int v : vertices) {
                        if (!path.contains(v)) {
                            ok = false;
                            break;
                        }
                    }
                    if (ok) {
                        toAsk = new int[]{v1, v2};
                    }
                }
            }
            int root = ask(toAsk[0], toAsk[1]);
            markPath(toAsk[0], root);
            markPath(toAsk[1], root);
        }
        int root = 0;
        while (true) {
            boolean changed = false;
            for (int v = 0; v < n; v++) {
                if (parent[v] == root && isEdgeUp[v] == -1) {
                    root = v;
                    changed = true;
                    break;
                }
            }
            if (!changed) {
                break;
            }
        }
        out.println("! " + (1 + root));
    }

    void markPath(int from, int to) {
        List<Integer> path = new ArrayList<>();
        findPath(from, to, from, path);
        for (int i = 0; i + 1 < path.size(); i++) {
            int v = path.get(i), u = path.get(i + 1);
            if (parent[v] == u) {
                isEdgeUp[v] = 1;
            } else {
                isEdgeUp[u] = -1;
            }
        }
    }

    int ask(int x, int y) {
        out.println("? " + (x + 1) + " " + (y + 1));
        out.flush();
        return in.nextInt() - 1;
    }

    boolean findPath(int v, int need, int p, List<Integer> path) {
        path.add(v);
        if (v == need) {
            return true;
        }
        for (int to : g[v]) {
            if (to == p) {
                continue;
            }
            if (findPath(to, need, v, path)) {
                return true;
            }
        }
        path.remove(path.size() - 1);
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