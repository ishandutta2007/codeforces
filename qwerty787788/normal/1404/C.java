import java.io.*;
import java.util.*;

public class A {
    FastScanner in;
    PrintWriter out;

    public class SegmentTreePush {
        // += on segment,
        // min on segment

        int[] pushAdd;
        int[][] min;
        final int NEUTRAL_ELEMENT = Integer.MAX_VALUE;
        final int START_ELEMENT = 0;
        final int NEUTRAL_PUSH = 0;

        int n;

        SegmentTreePush(int n) {
            this.n = n;
            pushAdd = new int[n * 4];
            min = new int[n * 4][2];
            init(0, 0, n - 1);
        }

        void init(int v, int l, int r) {
            if (l == r) {
                min[v] = new int[]{START_ELEMENT, l};
            } else {
                int m = (l + r) >> 1;
                init(v * 2 + 1, l, m);
                init(v * 2 + 2, m + 1, r);
                min[v] = join(min[v * 2 + 1], min[v * 2 + 2]);
            }
        }

        // TODO: change it
        int[] join(int[] leftValue, int[] rightValue) {
            if (leftValue[0] < rightValue[0]) {
                return leftValue;
            } else {
                return rightValue;
            }
        }

        // TODO: change it
        void apply(int v, int l, int r, int addValue) {
            pushAdd[v] += addValue;
            min[v][0] += addValue;
        }

        void push(int v, int l, int r) {
            if (pushAdd[v] == NEUTRAL_PUSH) {
                return;
            }
            int m = (l + r) >> 1;
            apply(v * 2 + 1, l, m, pushAdd[v]);
            apply(v * 2 + 2, m + 1, r, pushAdd[v]);
            pushAdd[v] = NEUTRAL_PUSH;
        }

        int[] get(int v, int l, int r, int needL, int needR) {
            if (needL > needR) {
                return new int[]{NEUTRAL_ELEMENT, -1};
            }
            if (l == needL && r == needR) {
                return min[v];
            }
            int m = (l + r) >> 1;
            push(v, l, r);
            int[] leftAns = get(v * 2 + 1, l, m, needL, Math.min(needR, m));
            int[] rightAns = get(v * 2 + 2, m + 1, r, Math.max(needL, m + 1), needR);
            return join(leftAns, rightAns);
        }

        int[] get(int l, int r) {
            return get(0, 0, n - 1, l, r);
        }

        void add(int v, int l, int r, int needL, int needR, int addValue) {
            if (needL > needR) {
                return;
            }
            if (l == needL && r == needR) {
                apply(v, l, r, addValue);
            } else {
                int m = (l + r) >> 1;
                push(v, l, r);
                add(v * 2 + 1, l, m, needL, Math.min(needR, m), addValue);
                add(v * 2 + 2, m + 1, r, Math.max(needL, m + 1), needR, addValue);
                min[v] = join(min[v * 2 + 1], min[v * 2 + 2]);
            }
        }

        void add(int l, int r, int addValue) {
            add(0, 0, n - 1, l, r, addValue);
        }
    }

    class Fenw {
        int[] s;

        Fenw(int n) {
            s = new int[n];
        }

        void add(int x, int val) {
            for (; x < s.length; x |= x + 1) {
                s[x] += val;
            }
        }

        int get(int pos) {
            int r = 0;
            for (; pos >= 0; pos = (pos & (pos + 1)) - 1) {
                r += s[pos];
            }
            return r;
        }
    }

    void solve() {
        int n = in.nextInt();
        int q = in.nextInt();
        int[] needDelete = new int[n];
        for (int i = 0; i < n; i++) {
            int val = in.nextInt();
            if (val > i + 1) {
                needDelete[i] = Integer.MAX_VALUE / 2;
            } else {
                needDelete[i] = i + 1 - val;
            }
        }
//        System.err.println(Arrays.toString(needDelete));
        SegmentTreePush st = new SegmentTreePush(n);
        for (int i = 0; i < n; i++) {
            st.add(i, i, needDelete[i]);
        }
        Query[] queries = new Query[q];
        for (int i = 0; i < q; i++) {
            int remLeft = in.nextInt();
            int remRight = in.nextInt();
            int stay = n - remLeft - remRight;
            queries[i] = new Query(i, remLeft, remLeft + stay - 1);
        }
        Arrays.sort(queries);
        int[] res = new int[queries.length];
        int qIt = 0;
        Fenw f = new Fenw(n);
        for (int from = n - 1; from >= 0; from--) {
            while (true) {
                int[] minPos = st.get(from, n - 1);
                if (minPos[0] <= 0) {
                    f.add(minPos[1], 1);
                    st.add(minPos[1], minPos[1], Integer.MAX_VALUE / 2);
                    st.add(minPos[1] + 1, n - 1, -1);
                } else {
                    break;
                }
            }
            while (qIt != queries.length && queries[qIt].from == from) {
                Query query = queries[qIt++];
                res[query.id] = f.get(query.to);
            }
        }
        for (int x : res) {
            out.println(x);
        }
    }

    class Query implements Comparable<Query> {
        int id;
        int from, to;

        public Query(int id, int from, int to) {
            this.id = id;
            this.from = from;
            this.to = to;
        }

        @Override
        public int compareTo(Query o) {
            return -Integer.compare(from, o.from);
        }
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