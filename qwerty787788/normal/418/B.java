import java.io.*;
import java.util.*;

public class CF {
    FastScanner in;
    PrintWriter out;

    class Friend implements Comparable<Friend> {
        int can;
        int need;
        int cost;

        Friend() {
            cost = in.nextInt();
            need = in.nextInt();
            int t = in.nextInt();
            for (int i = 0; i < t; i++)
                can |= 1 << (in.nextInt() - 1);
        }

        @Override
        public int compareTo(Friend o) {
            return Integer.compare(need, o.need);
        }
    }

    void solve() {
        int n = in.nextInt();
        int m = in.nextInt();
        int b = in.nextInt();
        Friend[] a = new Friend[n];
        for (int i = 0; i < n; i++) {
            a[i] = new Friend();
        }
        Arrays.sort(a);
        int curMon = 0;
        long curCost = 0;
        long[] cost = new long[1 << m];
        Arrays.fill(cost, Long.MAX_VALUE);
        cost[0] = 0;
        long res = Long.MAX_VALUE;
        int need = (1 << m) - 1;
        for (int i = 0; i < n; i++) {
            curCost += (a[i].need - curMon) * 1L * b;
            curMon = a[i].need;
            for (int st = 0; st < 1 << m; st++)
                if (cost[st] != Long.MAX_VALUE) {
                    int nst = st | a[i].can;
                    cost[nst] = Math.min(cost[nst], cost[st] + a[i].cost);
                }
            if (cost[need] != Long.MAX_VALUE) {
                res = Math.min(res, cost[need] + curCost);
            }
        }
        if (res == Long.MAX_VALUE)
            res = -1;
        out.println(res);
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