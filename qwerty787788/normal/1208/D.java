import java.io.*;
import java.util.*;

public class A {
    FastScanner in;
    PrintWriter out;

    class ST {
        int[] minPos;
        long[] minValue;
        long[] add;

        ST(long[] vals) {
            int n = vals.length;
            minPos = new int[n * 4];
            minValue = new long[n * 4];
            add = new long[n * 4];
            build(0, 0, n - 1, vals);
        }

        void build(int v, int l, int r, long[] vals) {
            if (l == r) {
                minPos[v] = l;
                minValue[v] = vals[l];
                add[v] = vals[l];
            } else {
                int m = (l + r) >> 1;
                build(v * 2 + 1, l, m, vals);
                build(v * 2 + 2, m + 1, r, vals);
                relax(v);
            }
        }

        void relax(int v) {
            if (minValue[v * 2 + 1] < minValue[v * 2 + 2]) {
                minValue[v] = minValue[v * 2 + 1] + add[v];
                minPos[v] = minPos[v * 2 + 1];
            } else {
                minValue[v] = minValue[v * 2 + 2] + add[v];
                minPos[v] = minPos[v * 2 + 2];
            }
        }

        void add(int v, int l, int r, int needL, int needR, long delta) {
            if (needL > r || needR < l) {
                return;
            }
            if (needL <= l && needR >= r) {
                add[v] += delta;
                minValue[v] += delta;
            } else {
                int m = (l + r) >> 1;
                add(v * 2 + 1, l, m, needL, needR, delta);
                add(v * 2 + 2, m + 1, r, needL, needR, delta);
                relax(v);
            }
        }

        long[] t = new long[]{-1, Long.MAX_VALUE / 10};

        long[] getMin(int v, int l, int r, int needL, int needR) {
            if (needL > r || needR < l) {
                return t;
            }
            if (needL <= l && needR >= r) {
                return new long[]{minPos[v], minValue[v]};
            } else {
                int m = (l + r) >> 1;
                long[] t1 = getMin(v * 2 + 1, l, m, needL, needR);
                long[] t2 = getMin(v * 2 + 2, m + 1, r, needL, needR);
                if (t1[1] < t2[1]) {
                    return new long[]{t1[0], t1[1] + add[v]};
                } else {
                    return new long[]{t2[0], t2[1] + add[v]};
                }
            }
        }
    }

    void solve() {
        int n = in.nextInt();
        long[] sum = new long[n];
        for (int i = 0; i < n; i++) {
            sum[i] = in.nextLong();
        }
        ST st = new ST(sum);
        int[] res = new int[n];
        for (int i = 0; i < n; i++) {
            long[] f = st.getMin(0, 0, n - 1, 0, n - 1);
            int pos = (int) f[0];
            res[pos] = i + 1;
            st.add(0, 0, n - 1, pos + 1, n - 1, -(i + 1));
            st.add(0, 0, n - 1, pos, pos, Long.MAX_VALUE / 10);
        }
        for (int i : res) {
            out.print(i + " ");
        }
        out.println();
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