import java.io.*;
import java.util.*;

public class A {
    FastScanner in;
    PrintWriter out;

    long[][] can;
    long[] tmp;

    void apply(long[] array, int shift) {
        int globalShift = shift / 64;
        int smallShift = shift & 63;
        for (int i =0 ; i < array.length; i++) {
            tmp[i] = array[i];
        }
        for (int i = 0; i < array.length; i++) {
            if (i + globalShift >= tmp.length) {
                break;
            }
            tmp[i + globalShift] |= (array[i] << smallShift);
            if (smallShift != 0 && i + globalShift + 1 < tmp.length) {
                tmp[i + globalShift + 1] |= (array[i] >>> (64 - smallShift));
            }
        }
        for (int i = 0; i < array.length; i++) {
            array[i] = tmp[i];
        }
    }

    void go(int fr, int to, List<Query> queries, int h) {
        for (int i = 0; i < allCan.length; i++) {
            can[h][i] = can[h - 1][i];
        }
        List<Query> next = new ArrayList<>();
        for (Query q : queries) {
            if (q.fr > to || q.to < fr) {
                continue;
            }
            if (q.fr <= fr && q.to >= to) {
                apply(can[h], q.x);
            } else {
                next.add(q);
            }
        }
        if (fr == to) {
            for (int i =0 ; i < allCan.length; i++) {
                allCan[i] |= can[h][i];
            }
        } else {
            int m=  (fr + to) >> 1;
            go(fr, m, next, h + 1);
            go(m + 1, to, next, h + 1);
        }
    }
    long[] allCan;

    void solve() {
        int n = in.nextInt();
        int q = in.nextInt();
        List<Query> queries = new ArrayList<>(q);
        for (int i =0 ; i <q; i++) {
            queries.add(new Query(in.nextInt() - 1, in.nextInt() - 1, in.nextInt()));
        }
        allCan = new long[n / 64 + 2];
        tmp = new long[allCan.length];
        can = new long[20][n / 64 + 2];
        can[0][0] = 1;
        go(0, n - 1, queries, 1);
        List<Integer> res = new ArrayList<>();
        for (int i = 1; i <= n; i++) {
            int p = i / 64;
            int j = i & 63;
            if ((allCan[p] & (1L << j)) != 0) {
                res.add(i);
            }
        }
        out.println(res.size());
        for (int x : res) {
            out.print(x + " ");
        }
    }

    class Query {
        int fr, to, x;

        public Query(int fr, int to, int x) {
            this.fr = fr;
            this.to = to;
            this.x = x;
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