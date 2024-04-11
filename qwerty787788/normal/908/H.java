import java.io.*;
import java.util.*;

public class A {
    private FastScanner in;
    private PrintWriter out;

    int[] p;

    int get(int x) {
        return p[x] == x ? x : (p[x] = get(p[x]));
    }

    void unite(int x, int y) {
        p[get(x)] = get(y);
    }

    int f(int n, char[][] a) {
        p = new int[n];
        for (int i = 0; i < n; i++) {
            p[i] = i;
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (a[i][j] == 'A') {
                    unite(i, j);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    continue;
                }
                if (a[i][j] == 'X' && get(i) == get(j)) {
                    return -1;
                }
            }
        }
        ArrayList<Integer>[] g = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            g[i] = new ArrayList<>();
        }
        for (int i = 0; i < n; i++) {
            g[get(i)].add(i);
        }
        int res = n - 1;
        for (int i = 0; i < n; i++) {
            if (g[i].size() >= 2) {
                res++;
            }
        }
        int[] nid = new int[n];
        int it = 0;
        for (int i = 0; i < n; i++) {
            if (g[i].size() >= 2) {
                nid[i] = it++;
            } else {
                nid[i] = -1;
            }
        }
        boolean[][] ok = new boolean[it][it];
        for (int i = 0; i < it; i++) {
            Arrays.fill(ok[i], true);
        }
        for (int i = 0; i < n; i++) {
            if (nid[i] == -1) {
                continue;
            }
            for (int j = 0; j < n; j++) {
                if (nid[j] == -1) {
                    continue;
                }
                if (i == j) {
                    continue;
                }
                for (int xx : g[i]) {
                    for (int yy : g[j]) {
                        if (a[xx][yy] == 'X') {
                            ok[nid[i]][nid[j]] = false;
                        }
                    }
                }
            }
        }
        return res - go(ok);
    }

    int go(boolean[][] ok) {
        int n = ok.length;
        ArrayList<Integer> ids = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            ids.add(i);
        }
        int[] okM = new int[n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (ok[i][j]) {
                    okM[i] |= 1 << j;
                }
            }
        }
        long START = System.currentTimeMillis();
        boolean[] used = new boolean[n];
        int res = 0;
        while (System.currentTimeMillis() - START < 4000) {
            for (int it = 0; it < 100; it++) {
                Arrays.fill(used, false);
                int curRes = 0;
                for (int i = 0; i < n; i++) {
                    int curId = ids.get(i);
                    if (used[curId]) {
                        continue;
                    }
                    int mask = 1 << curId;
                    for (int j = i + 1; j < n; j++) {
                        int nextId = ids.get(j);
                        if (!used[nextId]) {
                            if ((okM[nextId] & mask) == mask) {
                                mask |= 1 << nextId;
                            }
                        }
                    }
                    int tot = Integer.bitCount(mask);
                    if (tot != 1) {
                        for (int j = 0; j < n; j++) {
                            if (((1 << j) & mask) != 0) {
                                used[j] = true;
                            }
                        }
                        curRes += tot - 1;
                    }
                }
                res = Math.max(res, curRes);
                Collections.shuffle(ids);
            }
        }
        return res;
    }

    void solve() {
        int n = in.nextInt();
        char[][] a = new char[n][];
        for (int i = 0; i < n; i++) {
            a[i] = in.next().toCharArray();
        }
        out.println(f(n, a));
    }

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