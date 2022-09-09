import java.io.*;
import java.util.*;

public class CF {
    FastScanner in;
    PrintWriter out;

    class Query {
        int id;
        int fr, to;

        public Query(int id, int fr, int to) {
            super();
            this.id = id;
            this.fr = fr;
            this.to = to;
        }

    }

    class SegmentTree {
        int n;
        int[] t;

        public SegmentTree(int n) {
            this.n = n;
            t = new int[n];
        }

        int sum(int r) {
            int result = 0;
            for (; r >= 0; r = (r & (r + 1)) - 1)
                result += t[r];
            return result;
        }

        void inc(int i, int delta) {
            for (; i < n; i = (i | (i + 1)))
                t[i] += delta;
        }
    }

    ArrayList<Query>[] queries;

    void solve() throws IOException {
        int n = in.nextInt();
        int m = in.nextInt();
        int[] pos = new int[n + 1];
        int[] a = new int[n];
        Arrays.fill(pos, -1);
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
            pos[a[i]] = i;
        }
        queries = new ArrayList[n + 1];
        for (int i = 0; i < n + 1; i++)
            queries[i] = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            Query q = new Query(i, in.nextInt() - 1, in.nextInt() - 1);
            queries[q.fr].add(q);
        }
        SegmentTree segTree = new SegmentTree(n);
        int[] ans = new int[m];
        ArrayList<Integer>[] add = new ArrayList[n + 1];
        for (int i = 0; i <= n; i++)
            add[i] = new ArrayList<>();
        for (int st = n - 1; st >= 0; st--) {
            int x = a[st];
            for (int val : add[st])
                segTree.inc(val, 1);
            for (int val = x; val <= n; val += x)
                if (pos[val] != -1) {
                    if (pos[val] >= st)
                        segTree.inc(pos[val], 1); else
                            add[pos[val]].add(st);
                }
            for (Query q : queries[st]) {
                ans[q.id] = segTree.sum(q.to);
            }
        }
        for (int i = 0; i < m; i++) {
            out.println(ans[i]);
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