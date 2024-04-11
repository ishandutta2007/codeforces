import java.io.*;
import java.util.*;

public class CF {
    FastScanner in;
    PrintWriter out;

    class SegmentTree {
        int[] add;
        int[] minPos;
        int[] minValue;

        SegmentTree(int n) {
            add = new int[n * 4];
            minPos = new int[n * 4];
            minValue = new int[n * 4];
            init(0, 0, n - 1);
        }

        void init(int v, int l, int r) {
            if (l == r) {
                minPos[v] = l;
            } else {
                int m = (l + r) >> 1;
                init(v * 2 + 1, l, m);
                init(v * 2 + 2, m + 1, r);
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

        void add(int v, int l, int r, int needL, int needR, int diff) {
            if (needL > needR) {
                return;
            }
            if (l == needL && r == needR) {
                add[v] += diff;
                minValue[v] += diff;
            } else {
                int m = (l + r) >> 1;
                add(v * 2 + 1, l, m, needL, Math.min(m, needR), diff);
                add(v * 2 + 2, m + 1, r, Math.max(needL, m + 1), needR, diff);
                relax(v);
            }
        }
    }

    int[] solve(int[] next) {
        int n = next.length;
        SegmentTree st = new SegmentTree(n);
        List<Integer>[] prev = new List[n];
        for (int i = 0; i < n; i++) {
            prev[i] = new ArrayList<>();
        }
        for (int i = 0; i < n; i++) {
            int val = next[i];
            if (val == -1) {
                continue;
            }
            int start = i;
            int end = val - 1;
            if (val == n) {
                start++;
            } else {
                prev[val].add(i);
            }
            st.add(0, 0, n - 1, start, end, 1);
        }
        int[] res = new int[n];
        for (int val = n - 1; val >= 0; val--) {
            if (st.minValue[0] != 0) {
                return null;
            }
            int pos = st.minPos[0];
//            System.err.println("!! " + pos);
            res[pos] = val;
            st.add(0, 0, n - 1, pos, pos, Integer.MAX_VALUE / 2);
            st.add(0, 0, n - 1, pos + 1, next[pos] - 1, -1);
            for (int p : prev[pos]) {
                st.add(0, 0, n - 1, p, p, -1);
            }
        }
        return res;
    }

    void solve() {
        int tc = in.nextInt();
        for (int t = 0; t < tc; t++) {
            int n = in.nextInt();
            int[] next = new int[n];
            for (int i = 0; i < n; i++) {
                next[i] = in.nextInt();
                if (next[i] > 0) {
                    next[i]--;
                }
            }
            int[] r = solve(next);
            if (r == null) {
                out.println(-1);
            } else {
                for (int x : r) {
                    out.print((x + 1) + " ");
                }
                out.println();
            }
        }
    }

    void run() {
        try {
            in = new FastScanner(new File("CF.in"));
            out = new PrintWriter(new File("CF.out"));

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
        new CF().runIO();
    }
}