import java.io.*;
import java.util.*;

public class CF {
    FastScanner in;
    PrintWriter out;

    class SegmentTree {
        int n;
        int[] val;

        SegmentTree(int n) {
            this.n = n;
            val = new int[n * 4];
            Arrays.fill(val, -1);
        }

        int get(int v, int l, int r, int need) {
            if (val[v] != -1 || l == r)
                return val[v];
            int m = (l + r) / 2;
            if (need <= m) {
                return get(v * 2 + 1, l, m, need);
            }
            return get(v * 2 + 2, m + 1, r, need);
        }

        void set(int v, int l, int r, int needL, int needR, int value) {
            if (needL > needR)
                return;
            if (val[v] != -1 && l != r) {
                update(v);
            }
            if (l == needL && r == needR) {
                val[v] = value;
                return;
            }
            int m = (l + r) / 2;
            set(v * 2 + 1, l, m, needL, Math.min(needR, m), value);
            set(v * 2 + 2, m + 1, r, Math.max(needL, m + 1), needR, value);
        }

        int get(int pos) {
            return get(0, 0, n - 1, pos);
        }

        void set(int l, int r, int value) {
            set(0, 0, n - 1, l, r, value);
        }

        void update(int v) {
            val[v * 2 + 1] = val[v];
            val[v * 2 + 2] = val[v];
            val[v] = -1;
        }
    }

    void solve() throws IOException {
        int n = in.nextInt();
        int m = in.nextInt();
        int[] a = new int[n];
        int[] b = new int[n];
        for (int i = 0; i < n; i++)
            a[i] = in.nextInt();
        for (int i = 0; i < n; i++) {
            b[i] = in.nextInt();
        }
        int[] opX = new int[m];
        int[] opY = new int[m];
        int[] opK = new int[m];
        SegmentTree st = new SegmentTree(n);
        for (int i = 0; i < m; i++) {
            int type = in.nextInt();
            if (type == 1) {
                opX[i] = in.nextInt() - 1;
                opY[i] = in.nextInt() - 1;
                opK[i] = in.nextInt();
                st.set(opY[i], opY[i] + opK[i] - 1, i);
            } else {
                int pos = in.nextInt() - 1;
                int xx = st.get(pos);
                int ans = b[pos];
                if (xx != -1) {
                    ans = a[opX[xx] + (pos - opY[xx])];
                }
                out.println(ans);
            }
        }
    }

    void run() throws IOException {
        try {
            in = new FastScanner(new File("test.in"));
            out = new PrintWriter(new File("test.out"));

            solve();

            out.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    void runIO() throws IOException {
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
    }

    public static void main(String[] args) throws IOException {
        new CF().runIO();
    }
}