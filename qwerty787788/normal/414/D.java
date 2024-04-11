import java.io.*;
import java.util.*;

public class CF {
    FastScanner in;
    PrintWriter out;

    ArrayList<Integer>[] g;
    int[] h;

    void go(int v, int hh) {
        h[v] = hh;
        for (int i = 0; i < g[v].size(); i++) {
            int to = g[v].get(i);
            if (h[to] == -1) {
                go(to, hh + 1);
            }
        }
    }

    void solve() {
        int m = in.nextInt();
        int k = in.nextInt();
        int p = in.nextInt();
        g = new ArrayList[m];
        for (int i = 0; i < m; i++)
            g[i] = new ArrayList<>();
        for (int i = 0; i < m - 1; i++) {
            int fr = in.nextInt() - 1;
            int to = in.nextInt() - 1;
            g[fr].add(to);
            g[to].add(fr);
        }
        h = new int[m];
        Arrays.fill(h, -1);
        go(0, 0);
        int maxH = 0;
        for (int i = 0; i < m; i++)
            maxH = Math.max(maxH, h[i]);
        int[] cntH = new int[maxH + 1];
        for (int i = 1; i < m; i++)
            cntH[h[i]]++;
        int res = 0;
        int[] use = new int[maxH + 1];
        int curSum = 0;
        long curNeed = 0;
        int it = 0;
        for (int curH = 0; curH <= maxH; curH++) {
            curNeed += curSum;
            int more = Math.min(k - curSum, cntH[curH]);
            curSum += more;
            use[curH] = more;
            while (it != curH && use[curH] < cntH[curH]) {
                int maxAdd = Math.min(cntH[curH] - use[curH], use[it]);
                curNeed -= (curH - it) * 1L * maxAdd;
                use[it] -= maxAdd;
                use[curH] += maxAdd;
                if (use[it] == 0)
                    it++;
            }
            while (curNeed > p) {
                int nowCost = curH - it;
                long needRem = 1 + (curNeed - p - 1) / nowCost;
                needRem = Math.min(needRem, use[it]);
                curNeed -= needRem * nowCost;
                use[it] -= (int) needRem;
                curSum -= (int) needRem;
                if (use[it] == 0)
                    it++;
            }
            res = Math.max(res, curSum);
        }
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