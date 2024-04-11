import java.io.*;
import java.util.*;

public class CFD {
    FastScanner in;
    PrintWriter out;

    class SegmentTree {
        long[] sum;
        long[] max;
        int n;

        SegmentTree(int n, int[] a) {
            this.n = n;
            sum = new long[n * 4];
            max = new long[n * 4];
            build(0, 0, n - 1, a);
        }

        long get(int v, int l, int r, int needL, int needR) {
            if (needR < needL)
                return 0;
            if (l == needL && r == needR)
                return sum[v];
            int m = (l + r) >>> 1;
            return get(v * 2 + 1, l, m, needL, Math.min(needR, m))
                    + get(v * 2 + 2, m + 1, r, Math.max(needL, m + 1), needR);
        }

        void mod(int v, int l, int r, int needL, int needR, int mod) {
            if (needL > needR)
                return;
            if (needL == l && needR == r) {
                if (l == r) {
                    max[v] = sum[v] %= mod;
                } else {
                    if (max[v] < mod)
                        return;
                    int m = (l + r) >>> 1;
                    mod(v * 2 + 1, l, m, l, m, mod);
                    mod(v * 2 + 2, m + 1, r, m + 1, r, mod);
                    upd(v);
                }
            } else {
                int m = (l + r) >>> 1;
                mod(v * 2 + 1, l, m, needL, Math.min(needR, m), mod);
                mod(v * 2 + 2, m + 1, r, Math.max(needL, m + 1), needR, mod);
                upd(v);
            }
        }

        void set(int v, int l, int r, int need, int val) {
            if (l == r) {
                max[v] = sum[v] = val;
            } else {
                int m = (l + r) >>> 1;
                if (m >= need) {
                    set(v * 2 + 1, l, m, need, val);
                } else {
                    set(v * 2 + 2, m + 1, r, need, val);
                }
                upd(v);
            }
        }

        void build(int v, int l, int r, int[] a) {
            if (l == r) {
                sum[v] = max[v] = a[l];
            } else {
                int m = (l + r) >>> 1;
                build(v * 2 + 1, l, m, a);
                build(v * 2 + 2, m + 1, r, a);
                upd(v);
            }
        }

        void upd(int v) {
            sum[v] = sum[v * 2 + 1] + sum[v * 2 + 2];
            max[v] = Math.max(max[v * 2 + 1], max[v * 2 + 2]);
        }
    }

    void solve() {
        int n = in.nextInt();
        int m = in.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
        }
        SegmentTree st = new SegmentTree(n, a);
        for (int i = 0; i < m; i++) {
            int type = in.nextInt();
            if (type == 1) {
                int l = in.nextInt() - 1;
                int r = in.nextInt() - 1;
                out.println(st.get(0, 0, n - 1, l, r));
            } else {
                if (type == 2) {
                    int l = in.nextInt() - 1, r = in.nextInt() - 1, x = in.nextInt();
                    st.mod(0, 0, n - 1, l, r, x);
                } else {
                    st.set(0, 0,n - 1  , in.nextInt() - 1, in.nextInt());
                }
            }
        }

    }

    void run() {
        try {
            in = new FastScanner(new File("object.in"));
            out = new PrintWriter(new File("object.out"));

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
    }

    public static void main(String[] args) {
        new CFD().runIO();
    }
}