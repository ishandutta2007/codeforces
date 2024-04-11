import java.io.*;
import java.util.*;

public class H {
    FastScanner in;
    PrintWriter out;

    int calc(int size) {
        if (size <= 1) {
            return 0;
        }
        return size * (size - 1) / 2 + calc(size / 2) + calc((size + 1) / 2);
    }

    class Query {
        int fr, to;
        int id;

        public Query(int fr, int to, int id) {
            this.fr = fr;
            this.to = to;
            this.id = id;
        }
    }

    List<Integer> left = new ArrayList<>();
    List<Integer> right = new ArrayList<>();

    int first(int from, int to, int yFr, int yTo) {
        while (from != to + 1 && (a[from] < yFr || a[from] > yTo)) {
            from++;
        }
        return from;
    }

    int last(int from, int to, int yFr, int yTo) {
        while (to != from - 1 && (a[to] < yFr || a[to] > yTo)) {
            to--;
        }
        return to;
    }

    List<Integer> go(List<Integer> from, List<Integer> to, int yFr, int yTo) {
        for (int i : from) {
            if (i >= a.length) {
                throw new AssertionError();
            }
        }
        for (int i : to) {
            if (i >= a.length) {
                throw new AssertionError();
            }
        }
        if (from.size() == 0) {
            return new ArrayList<>();
        }
        if (yFr == yTo) {
            List<Integer> res = new ArrayList<>();
            for (int i = 0; i < from.size(); i++) {
                res.add(from.get(i));
            }
            return res;
        } else {
            int yMid = (yFr + yTo) / 2;
            List<Integer> join1 = new ArrayList<>();
            List<Integer> join2 = new ArrayList<>();
            List<Integer> askFr = new ArrayList<>();
            List<Integer> askTo = new ArrayList<>();
            cacheIt++;
            // [yFr.. yMid] [yMid + 1..tTo]
            for (int i = 0; i < from.size(); i++) {
                int f1 = first(from.get(i), to.get(i), yFr, yMid);
                int t1 = last(from.get(i), to.get(i), yFr, yMid);
                if (f1 > t1) {
                    join1.add(-1);
                } else {
                    if (cache[f1][t1] != cacheIt) {
                        cache[f1][t1] = cacheIt;
                        cacheVal[f1][t1] = askFr.size();
                        askFr.add(f1);
                        askTo.add(t1);
                    }
                    join1.add(cacheVal[f1][t1]);
                }
            }
            List<Integer> r1 = go(askFr, askTo, yFr, yMid);
            for (int i = 0; i < join1.size(); i++) {
                if (join1.get(i) != -1) {
//                    System.err.println(join1.get(i)+" " + askFr.size());
                    join1.set(i, r1.get(join1.get(i)));
                }
            }
            cacheIt++;
            askFr.clear();
            askTo.clear();
            for (int i = 0; i < from.size(); i++) {
                int f1 = first(from.get(i), to.get(i), yMid + 1, yTo);
                int t1 = last(from.get(i), to.get(i), yMid + 1, yTo);
                if (f1 > t1) {
                    join2.add(-1);
                } else {
                    if (cache[f1][t1] != cacheIt) {
                        cache[f1][t1] = cacheIt;
                        cacheVal[f1][t1] = askFr.size();
                        askFr.add(f1);
                        askTo.add(t1);
                    }
                    join2.add(cacheVal[f1][t1]);
                }
            }
            List<Integer> r2 = go(askFr, askTo, yMid + 1, yTo);
            for (int i = 0; i < join2.size(); i++) {
                if (join2.get(i) != -1) {
                    join2.set(i, r2.get(join2.get(i)));
                }
            }
            List<Integer> res = new ArrayList<>();
            for (int i = 0; i < from.size(); i++) {
                int x = join1.get(i), y = join2.get(i);
                if (x == -1 || y == -1) {
                    res.add(x + y + 1);
                } else {
                    left.add(x);
                    right.add(y);
                    res.add(left.size() - 1 + a.length);
                }
            }
            return res;
        }
    }


    int[][] cache;
    int[][] cacheVal;
    int cacheIt = 1;
    int[] a;

    void solve() {
        int n = in.nextInt();
        cache = new int[n][n];
        cacheVal = new int[n][n];
        int q = in.nextInt();
        a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt() - 1;
        }

        List<Integer> from = new ArrayList<>();
        List<Integer> to = new ArrayList<>();
        for (int i = 0; i < q; i++) {
            from.add(in.nextInt() - 1);
            to.add(in.nextInt() - 1);
        }
        List<Integer> res = go(from, to, 0, n - 1);
        out.println(n + left.size());
        for (int i = 0; i < left.size(); i++) {
            out.println((left.get(i) + 1) + " " + (right.get(i) + 1));
        }
        for (int i = 0; i < res.size(); i++) {
            out.print((res.get(i) + 1) + " ");
        }
        out.println();
    }

    void run() {
        try {
            in = new FastScanner(new File("H.in"));
            out = new PrintWriter(new File("H.out"));

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
        new H().runIO();
    }
}