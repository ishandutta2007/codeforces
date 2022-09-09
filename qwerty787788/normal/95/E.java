import java.io.*;
import java.util.*;

public class CF {
    FastScanner in;
    PrintWriter out;

    class Dsu {
        int[] p;
        int[] sz;

        Dsu(int n) {
            p = new int[n];
            for (int i = 0; i < n; i++)
                p[i] = i;
            sz = new int[n];
            Arrays.fill(sz, 1);
        }

        int get(int v) {
            return p[v] == v ? v : (p[v] = get(p[v]));
        }

        void union(int v, int u) {
            v = get(v);
            u = get(u);
            if (v == u)
                return;
            p[v] = u;
            sz[u] += sz[v];
        }
    }

    class Number {
        int count, value;

        public Number(int count, int value) {
            super();
            this.count = count;
            this.value = value;
        }

        @Override
        public String toString() {
            return "Number [count=" + count + ", value=" + value + "]";
        }
        
        

    }

    class Knapsack {
        int sz;
        int[] cost;
        int n;
        int[] qPos, qCost;

        Knapsack(int n) {
            this.n = n;
            cost = new int[n + 1];
            Arrays.fill(cost, Integer.MAX_VALUE / 2);
            qPos = new int[n + 1];
            qCost = new int[n + 1];
            cost[0] = 0;
        }

        void addNumber(int count, int value) {
            for (int startPos = 0; startPos < value; startPos++) {
                if (startPos > n)
                    break;
                int qIt = 0, qSz = 0;
                int qAddAll = 0;
                for (int pos = startPos, rPos = 0; pos <= n; pos += value, rPos++) {
                    if (cost[pos] != Integer.MAX_VALUE / 2) {
                        int nCost = -qAddAll + cost[pos];
                        while (qIt < qSz && qCost[qSz - 1] > nCost)
                            qSz--;
                        qCost[qSz] = nCost;
                        qPos[qSz++] = rPos;
                    }
                    while (qIt < qSz && rPos - qPos[qIt] > count)
                        qIt++;
                    if (qIt < qSz) {
                        int realCost = qAddAll + qCost[qIt];
                        cost[pos] = Math.min(cost[pos], realCost);
                    }
                    qAddAll++;
                }
            }
        }
    }

    int getAnswer(Knapsack knapsack, int cur, int max) {
        if (cur > max)
            return Integer.MAX_VALUE;
        int res = Integer.MAX_VALUE;
        if (cur != 0) {
            res = knapsack.cost[cur];
        }
        res = Math.min(res, getAnswer(knapsack, cur * 10 + 4, max));
        res = Math.min(res, getAnswer(knapsack, cur * 10 + 7, max));
        return res;
    }

    void solve() {
        int n = in.nextInt();
        int m = in.nextInt();
        Dsu d = new Dsu(n);
        for (int i = 0; i < m; i++) {
            d.union(in.nextInt() - 1, in.nextInt() - 1);
        }
        ArrayList<Integer> sizes = new ArrayList<>();
        boolean[] was = new boolean[n];
        for (int i = 0; i < n; i++) {
            int v = d.get(i);
            if (was[v])
                continue;
            was[v] = true;
            sizes.add(d.sz[v]);
        }
        Collections.sort(sizes);
        ArrayList<Number> numbers = new ArrayList<>();
        for (int i = 0; i < sizes.size();) {
            int j = i;
            while (j != sizes.size() && sizes.get(j) == sizes.get(i))
                j++;
            numbers.add(new Number(j - i, sizes.get(i)));
            i = j;
        }
        Knapsack knapsack = new Knapsack(n);
        for (Number number : numbers) {
            knapsack.addNumber(number.count, number.value);
        }
        int res = getAnswer(knapsack, 0, n);
        out.println(res >= Integer.MAX_VALUE / 2 ? -1 : res - 1);
    }

    void run() {
        try {
            in = new FastScanner(new File("test.in"));
            out = new PrintWriter(new File("test.out"));

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

        double nextDouble() {
            return Double.parseDouble(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }
    }

    public static void main(String[] args) {
        new CF().runIO();
    }
}