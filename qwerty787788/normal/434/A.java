import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class CF {
    FastScanner in;
    PrintWriter out;

    void solve() {
        int n = in.nextInt();
        int m = in.nextInt();
        int[] a = new int[m];
        for (int i = 0; i < m; i++) {
            a[i] = in.nextInt();
        }
        if (m == 1) {
            out.println(0);
            return;
        }
        long ans = Long.MAX_VALUE;
        long cur = 0;
        for (int i = 0; i < m - 1; i++) {
            cur += Math.abs(a[i + 1] - a[i]);
        }
        ans = cur;
        ArrayList<Integer>[] g = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            g[i] = new ArrayList<>();
        }
        for (int i = 0; i < m - 1; i++) {
            int fr = a[i] - 1;
            int to = a[i + 1] - 1;
            if (fr == to)
                continue;
            g[fr].add(to);
            g[to].add(fr);
        }
        for (int i = 0; i < n; i++) {
            if (g[i].size() == 0)
                continue;
            Collections.sort(g[i]);
            long curSum = cur;
            for (int j = 0; j < g[i].size(); j++)
                curSum -= Math.abs(i - g[i].get(j));
            long start = g[i].get(0);
            long add = 0;
            int cntMore = g[i].size();
            int cntLess = 0;
            for (int j = 0; j < g[i].size(); j++) {
                add += g[i].get(j) - start;
            }
            for (int j = 0; j < g[i].size(); j++) {
                long curSub = g[i].get(j) - start;
                add -= cntMore * curSub;
                add += cntLess * curSub;
                cntMore--;
                cntLess++;
                ans = Math.min(ans, curSum + add);
                start += curSub;
            }
        }
        out.println(ans);
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