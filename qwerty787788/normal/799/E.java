import java.io.*;
import java.util.*;

public class E {
    private FastScanner in;
    private PrintWriter out;

    class O implements Comparable<O> {
        int cost;
        int id;

        public O(int cost, int id) {
            this.cost = cost;
            this.id = id;
        }

        @Override
        public int compareTo(O o) {
            if (cost != o.cost) {
                return Integer.compare(cost, o.cost);
            }
            return Integer.compare(id, o.id);
        }
    }

    class GiveMe {
        TreeSet<O> use = new TreeSet<>();
        TreeSet<O> notUse = new TreeSet<>();

        long sumCost;

        void add(O o) {
            if (use.size() == 0) {
                notUse.add(o);
            } else {
                if (o.cost > use.last().cost) {
                    notUse.add(o);
                } else {
                    sumCost += o.cost;
                    use.add(o);
                }
            }
        }


        long want(int x) {
            if (x < 0 || x > use.size() + notUse.size()) {
                return Long.MAX_VALUE;
            }
            int diff = x - use.size();
            if (diff > 0) {
                for (int i = 0; i < diff; i++) {
                    O first = notUse.pollFirst();
                    use.add(first);
                    sumCost += first.cost;
                }
            } else {
                for (int i = 0; i < -diff; i++) {
                    O last = use.pollLast();
                    notUse.add(last);
                    sumCost -= last.cost;
                }
            }
            return sumCost;
        }
    }

    private void solve() {
        int n = in.nextInt();
        int m = in.nextInt();
        int k = in.nextInt();
        int[] c = new int[n];
        for (int i = 0; i < n; i++) {
            c[i] = in.nextInt();
        }
        boolean[][] like = new boolean[2][n];
        for (int i = 0; i < 2; i++) {
            int cnt = in.nextInt();
            for (int j = 0; j < cnt; j++) {
                like[i][in.nextInt() - 1] = true;
            }
        }
        ArrayList<O> both = new ArrayList<>();
        ArrayList<O> first = new ArrayList<>();
        ArrayList<O> second = new ArrayList<>();
        ArrayList<O>[] lists = new ArrayList[]{first, second};
        GiveMe give = new GiveMe();
        for (int i = 0; i < n; i++) {
            O o = new O(c[i], i);
            if (like[0][i] && like[1][i]) {
                both.add(o);
            } else {
                if (like[0][i]) {
                    first.add(o);
                } else if (like[1][i]) {
                    second.add(o);
                } else {
                    give.add(o);
                }
            }
        }
        Collections.sort(first);
        Collections.sort(second);
        Collections.sort(both);
        long result = Long.MAX_VALUE;
        long nowCost = 0;
        int[] it = new int[2];
        for (int i = 0; i < 2; i++) {
            ArrayList<O> list = lists[i];
            while (it[i] < list.size()) {
                nowCost += list.get(it[i]).cost;
                it[i]++;
            }
        }
        for (int useBoth = 0; useBoth <= both.size() && useBoth <= m; useBoth++) {
            for (int z = 0; z < 2; z++) {
                while (useBoth + it[z] > k && it[z] != 0) {
                    it[z]--;
                    give.add(lists[z].get(it[z]));
                    nowCost -= lists[z].get(it[z]).cost;
                }
            }
            if (useBoth + it[0] >= k && useBoth + it[1] >= k) {
                int need = m - useBoth - it[0] - it[1];
                long add = give.want(need);
                if (add != Long.MAX_VALUE) {
                    result = Math.min(result, add + nowCost);
                }
            }
            if (useBoth != both.size()) {
                nowCost += both.get(useBoth).cost;
            }
        }
        out.println(result == Long.MAX_VALUE ? -1 : result);
    }

    private void run() {
        try {
            in = new FastScanner(new File("E.in"));
            out = new PrintWriter(new File("E.out"));

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
        new E().runIO();
    }
}