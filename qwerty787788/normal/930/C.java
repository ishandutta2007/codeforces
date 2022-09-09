import java.io.*;
import java.util.*;

public class A {
    FastScanner in;
    PrintWriter out;

    class SegmentTree {
        int[] a;

        SegmentTree(int n) {
            a = new int[n * 4];
        }

        void upd(int v, int l, int r, int pos, int nv) {
            if (l == r) {
                a[v] = nv;
            } else {
                int m = (l + r) >> 1;
                if (m >= pos) {
                    upd(v * 2 + 1, l, m, pos, nv);
                } else {
                    upd(v * 2 + 2, m + 1, r, pos, nv);
                }
                a[v] = Math.max(a[v * 2 + 1], a[v * 2 + 2]);
            }
        }

        int get(int v, int l, int r, int needL, int needR) {
            if (needL > needR) {
                return 0;
            }
            if (l == needL && r == needR) {
                return a[v];
            }
            int m = (l + r) >> 1;
            return Math.max(get(v * 2 + 1, l, m, needL, Math.min(needR, m)), get(v * 2 + 2, m + 1, r, Math.max(needL, m + 1), needR));
        }
    }

    void solve() {
        int cnt = in.nextInt();
        int n = in.nextInt();
        int[] a = new int[n + 1];
        for (int i = 0; i < cnt; i++) {
            a[in.nextInt() - 1]++;
            a[in.nextInt()]--;
        }
        for (int i = 1; i < a.length; i++) {
            a[i] += a[i - 1];
        }
        final int MAX = (int) 1e5 + 10;
        SegmentTree st = new SegmentTree(MAX);
        int[] maxLeft = new int[n];
        for (int i = 0; i < n; i++) {
            int cur = st.get(0, 0, MAX - 1, 0, a[i]);
            st.upd(0, 0, MAX - 1, a[i], cur + 1);
            maxLeft[i] = cur;
        }
        st = new SegmentTree(MAX);
        int res = 0;
        for (int i = n - 1; i >= 0; i--) {
            int cur = st.get(0, 0, MAX - 1, 0, a[i]);
            st.upd(0, 0, MAX - 1, a[i], cur + 1);
            res = Math.max(res, maxLeft[i] + cur + 1);
        }
        out.println(res);
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