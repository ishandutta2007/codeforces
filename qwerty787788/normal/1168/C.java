import java.io.*;
import java.util.*;

public class A {
    FastScanner in;
    PrintWriter out;

    void solve() {
        int n = in.nextInt();
        int q = in.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
        }
        List<Query>[] all = new List[n];
        for (int i = 0; i < n; i++) {
            all[i] = new ArrayList<>();
        }
        for (int i = 0; i < q; i++) {
            Query qq = new Query(in.nextInt() - 1, in.nextInt() - 1, i);
            all[qq.l].add(qq);
        }
        final int MAX = 19;
        int[][] when = new int[MAX][MAX];
        for (int i = 0; i < MAX; i++) {
            Arrays.fill(when[i], Integer.MAX_VALUE);
        }
        int[] curMin = new int[MAX];
        boolean[] can = new boolean[q];
        for (int l = n - 1; l >= 0; l--) {
            Arrays.fill(curMin, Integer.MAX_VALUE);
            for (int bit = 0; bit < MAX; bit++) {
                if (((1 << bit) & a[l]) != 0) {
                    for (int j = 0; j < MAX; j++) {
                        curMin[j] = Math.min(curMin[j], when[bit][j]);
                    }
                }
            }
            for (int bit = 0; bit < MAX; bit++) {
                if (((1 << bit) & a[l]) != 0) {
                    curMin[bit] = l;
                }
            }
            for (int bit = 0; bit < MAX; bit++) {
                if (((1 << bit) & a[l]) != 0) {
                    for (int j = 0; j < MAX; j++) {
                        when[bit][j] = curMin[j];
                    }
                }
            }
            for (Query qq : all[l]) {
                boolean ok = false;
                for (int bit = 0; bit < MAX; bit++) {
                    if (((1 << bit) & a[qq.r]) != 0) {
                        ok |= curMin[bit] <= qq.r;
                    }
                }
                can[qq.id] = ok;
            }
        }
        for (boolean o : can) {
            out.println(o ? "Shi" : "Fou");
        }
    }

    class Query {
        int l, r, id;

        public Query(int l, int r, int id) {
            this.l = l;
            this.r = r;
            this.id = id;
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