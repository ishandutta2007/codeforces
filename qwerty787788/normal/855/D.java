import java.io.*;
import java.util.*;

public class A {
    private FastScanner in;
    private PrintWriter out;

    enum PARENT_TYPE {
        SPECIAL_CASE,
        PART
    }

    private void solve() {
        int n = in.nextInt();
        int[] parent = new int[n];
        PARENT_TYPE[] type = new PARENT_TYPE[n];
        for (int i = 0; i < n; i++) {
            parent[i] = in.nextInt() - 1;
            type[i] = in.nextInt() == 0 ? PARENT_TYPE.SPECIAL_CASE : PARENT_TYPE.PART;
        }
        int[] globalH = new int[n];
        int[] localH = new int[n];
        for (int i = 0; i < n; i++) {
            if (parent[i] == -2) {
                parent[i] = i;
                globalH[i] = 0;
                localH[i] = 0;
            } else {
                if (type[i] == PARENT_TYPE.SPECIAL_CASE) {
                    globalH[i] = globalH[parent[i]];
                    localH[i] = localH[parent[i]] + 1;
                } else {
                    globalH[i] = globalH[parent[i]] + 1;
                    localH[i] = 0;
                }
            }
        }
        M = 18;
        globalUp = new int[M][n];
        localUp = new int[M][n];
        for (int i = 0; i < n; i++) {
            if (type[i] == PARENT_TYPE.PART) {
                localUp[0][i] = i;
            } else {
                localUp[0][i] = parent[i];
            }
        }
        for (int j = 1; j < M; j++) {
            for (int i = 0; i < n; i++) {
                localUp[j][i] = localUp[j - 1][localUp[j - 1][i]];
            }
        }
        for (int i = 0; i < n; i++) {
            globalUp[0][i] = type[i] == PARENT_TYPE.SPECIAL_CASE ? i : parent[i];
        }
        for (int j = 1; j < M; j++) {
            for (int i = 0; i < n; i++) {
                globalUp[j][i] = globalUp[j - 1][globalUp[j - 1][i]];
            }
        }
        int queries = in.nextInt();
        for (int q = 0; q < queries; q++) {
            int t = in.nextInt();
            int u = in.nextInt() - 1;
            int v = in.nextInt() - 1;
            if (u == v) {out.println("NO"); continue;}
            if (t == 1) {
                // is v - special case of u?
                v = goLocal(v, localH[v] - localH[u]);
            } else {
                // v - part of u?
                int nv = goGlobal(v, globalH[v] - globalH[u]);
                if (nv == v) {out.println("NO"); continue;}
                v = nv;
                u = goLocal(u, localH[u] - localH[v]);
            }
            out.println(v == u ? "YES" : "NO");
        }
    }

    int goLocal(int v, int dh) {
        for (int i = 0; i < M; i++) {
            if (((1 << i) & dh) != 0) {
                v = localUp[i][v];
            }
        }
        return v;
    }

    int goGlobal(int v, int dh) {
        for (int i = 0; i < M; i++) {
            if (((1 << i) & dh) != 0) {
                v = globalUp[i][v];
            }
        }
        return v;
    }

    int[][] globalUp, localUp;
    int M;


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