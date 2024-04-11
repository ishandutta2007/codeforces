import java.io.*;
import java.util.*;

public class F {
    private FastScanner in;
    private PrintWriter out;

    class SegmentTree {
        Node[] a;

        SegmentTree(int[] array) {
            a = new Node[array.length * 4];
            build(0, 0, array.length - 1, array);
        }

        void build(int v, int l, int r, int[] array) {
            if (l == r) {
                a[v] = new Node(array[l]);
            } else {
                a[v] = new Node();
                int m = (l + r) >> 1;
                build(v * 2 + 1, l, m, array);
                build(v * 2 + 2, m + 1, r, array);
                a[v].join(a[v * 2 + 1], a[v * 2 + 2]);
            }
        }

        long sum(int v, int l, int r, int needL, int needR) {
            if (needL > needR) {
                return 0;
            }
            if (needL == l && needR == r) {
                long res = 0;
                for (int i = 1; i < 10; i++) {
                    res += i * a[v].sum[i];
                }
                return res;
            }
            a[v * 2 + 1].relax(a[v]);
            a[v * 2 + 2].relax(a[v]);
            int m = (l + r) >> 1;
            long res = sum(v * 2 + 1, l, m, needL, Math.min(m, needR)) + sum(v * 2 + 2, m + 1, r, Math.max(m + 1, needL), needR);
            a[v].join(a[v * 2 + 1], a[v * 2 + 2]);
            return res;
        }

        void change(int v, int l, int r, int needL, int needR, int from, int to) {
            if (from == to) {
                return;
            }
            if (needL > r || needR < l) {
                return;
            }
            if (needL <= l && needR >= r) {
                for (int i = 0; i < 10; i++) {
                    if (a[v].perm[i] == from) {
                        a[v].perm[i] = to;
                    }
                }
                a[v].sum[to] += a[v].sum[from];
                a[v].sum[from] = 0;
            } else {
                a[v * 2 + 1].relax(a[v]);
                a[v * 2 + 2].relax(a[v]);
                int m = (l + r) >> 1;
                change(v * 2 + 1, l, m, needL, needR, from, to);
                change(v * 2 + 2, m + 1, r, needL, needR, from, to);
                a[v].join(a[v * 2 + 1], a[v * 2 + 2]);
            }
        }
    }

    class Node {
        int[] perm;
        long[] sum;

        Node(int v) {
            perm = new int[10];
            for (int i = 0; i < perm.length; i++) {
                perm[i] = i;
            }
            sum = new long[10];
            int pow10 = 1;
            while (v > 0) {
                sum[v % 10] += pow10;
                pow10 *= 10;
                v /= 10;
            }
        }

        Node() {
            perm = new int[10];
            sum = new long[10];
        }

        void join(Node left, Node right) {
            for (int i = 0; i < 10; i++) {
                sum[i] = left.sum[i] + right.sum[i];
                perm[i] = i;
            }
        }

        void relax(Node parent) {
            for (int i = 0; i < 10; i++) {
                int to = parent.perm[perm[i]];
                perm[i] = to;
            }
            for (int i =0; i < 10; i++) {
                tmp[i] =0;
            }
            for (int i = 0; i < 10; i++) {
                tmp[parent.perm[i]] += sum[i];
            }
            for (int i = 0; i < 10; i++) {
                sum[i] =tmp[i];
            }
        }
    }

    long[] tmp = new long[10];

    private void solve() {
        int n = in.nextInt();
        int q = in.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
        }
        SegmentTree st = new SegmentTree(a);
        for (int i = 0; i < q; i++) {
            if (in.nextInt() == 1) {
                int l = in.nextInt() - 1, r = in.nextInt() - 1;
                int fr = in.nextInt(), to = in.nextInt();
                st.change(0, 0, n - 1, l, r, fr, to);
            } else {
                int l = in.nextInt() - 1, r = in.nextInt() - 1;
                out.println(st.sum(0, 0, n - 1, l, r));
            }
        }
    }

    private void run() {
        try {
            in = new FastScanner(new File("F.in"));
            out = new PrintWriter(new File("F.out"));

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
        new F().runIO();
    }
}