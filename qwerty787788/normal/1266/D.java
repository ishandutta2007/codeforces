import java.io.*;
import java.util.*;

public class D {
    FastScanner in;
    PrintWriter out;

    void solve() {
        int n = in.nextInt();
        int m = in.nextInt();
        long[] balance = new long[n];
        for (int i = 0; i < m; i++) {
            int fr = in.nextInt() - 1;
            int to = in.nextInt() - 1;
            int cost = in.nextInt();
            balance[fr] -= cost;
            balance[to] += cost;
        }
        int itPlus = 0, itMinus = 0;
        List<long[]> ans = new ArrayList<>();
        while (true) {
            while (itPlus != balance.length && balance[itPlus] <= 0) {
                itPlus++;
            }
            while (itMinus != balance.length && balance[itMinus] >= 0) {
                itMinus++;
            }
            if (itPlus == balance.length) {
                if (itMinus != balance.length) {
                    throw new AssertionError();
                }
                break;
            }
            long mx = Math.min(balance[itPlus], -balance[itMinus]);
            ans.add(new long[]{itMinus + 1, itPlus + 1, mx});
            balance[itPlus] -= mx;
            balance[itMinus] += mx;
        }
        out.println(ans.size());
        for (long[] t : ans) {
            out.println(t[0] + " " + t[1] + " " + t[2]);
        }
    }

    void run() {
        try {
            in = new FastScanner(new File("D.in"));
            out = new PrintWriter(new File("D.out"));

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
        new D().runIO();
    }
}