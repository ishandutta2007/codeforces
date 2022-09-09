import java.io.*;
import java.util.*;

public class F {
    FastScanner in;
    PrintWriter out;

//    List<Integer>[] vectors;

    int[][] g;
    int[] gSz;

//    void addVector(int id) {
//        for (int i = 0; i < gSz[id]; i++) {
//            vectors[g[id][i]].add(id);
//        }
//    }

//    void removeVector(int id) {
//        for (int coord : g[id]) {
//            vectors[coord].remove(id);
//        }
//    }

    boolean contains(int x, int y) {
        for (int i = 0; i < gSz[x]; i++) {
            if (g[x][i] == y) {
                return true;
            }
        }
        return false;
    }

    void addG(int i, int x) {
        g[i][gSz[i]++] = x;
    }

    void remove(int id, int x) {
        int nsz = 0;
        for (int i = 0; i < gSz[id]; i++) {
            if (g[id][i] != x) {
                g[id][nsz++] = g[id][i];
            }
        }
        gSz[id] = nsz;
    }

    void xor(int id, int idXor) {
        if (id == idXor) {
            throw new AssertionError();
        }
        for (int z : g[idXor]) {
            if (contains(id, z)) {
                remove(id, z);
            } else {
                addG(id, z);
            }
        }
    }

    int[] replace;

    int get(int x) {
        return (replace[x] == x || replace[x] == -1) ? replace[x] : (replace[x] = get(replace[x]));
    }

    void update(int id) {
        for (int i = 0; i < gSz[id]; i++) {
            int cur = g[id][i];
            cur = get(cur);
            if (cur == -1) {
                remove(id, g[id][i]);
                update(id);
                return;
            }
            g[id][i] = cur;
        }
        if (gSz[id] == 2 && g[id][0] == g[id][1]) {
            gSz[id] = 0;
        }
    }

    void solve() {
        int n = in.nextInt();
        int dim = in.nextInt();
//        vectors = new List[dim];
//        for (int i = 0; i < vectors.length; i++) {
//            vectors[i] = new ArrayList<>();
//        }
        replace = new int[dim];
        for (int i = 0; i < dim; i++) {
            replace[i] = i;
        }
        g = new int[n][2];
        gSz = new int[n];
        for (int i = 0; i < n; i++) {
            int cnt = in.nextInt();
            for (int j = 0; j < cnt; j++) {
                int x = in.nextInt() - 1;
                addG(i, x);
            }
//            addVector(i);
        }

        List<Integer> res = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            update(i);
            if (gSz[i] == 0) {
                continue;
            }
            int seted = g[i][0];
            if (gSz[i] == 1) {
                replace[seted] = -1;
            } else {
                replace[seted] = g[i][1];
            }
//            List<Integer> toXor = new ArrayList<>(vectors[seted]);
//            for (int another : toXor) {
//                if (another == i) {
//                    continue;
//                }
//                if (!contains(another, seted)) {
//                    continue;
//                }
//            removeVector(another);
//                xor(another, i);
//                addVector(another);
//            }
            res.add(i);
        }
        int ans = 1;
        for (int i = 0; i < res.size(); i++) {
            ans = add(ans, ans);
        }
        out.println(ans + " " + res.size());
        for (int x : res) {
            out.print((1 + x) + " ");
        }
        out.println();
    }


    final int mod = (int) 1e9 + 7;

    int add(int x, int y) {
        x += y;
        return x >= mod ? (x - mod) : x;
    }

    void run() {
        try {
            in = new FastScanner(new File("F.in"));
            out = new PrintWriter(new File("F.out"));

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
        new F().runIO();
    }
}