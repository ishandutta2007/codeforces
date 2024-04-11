import java.io.*;
import java.util.*;

public class A {
    FastScanner in;
    PrintWriter out;

    void solve() {
        int n = in.nextInt();
        int m = in.nextInt();
        int[] x = new int[n + 1];
        for (int i = 0; i < n; i++) {
            x[i] = in.nextInt();
        }
        final int MAX = (int) 1e9;
        x[n] = MAX;
        Arrays.sort(x);
        List<Integer> all = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            int x1 = in.nextInt();
            int x2 = in.nextInt();
            int y = in.nextInt();
            if (x1 != 1) {
                continue;
            }
            all.add(x2);
        }
        Collections.sort(all);
        int res = Integer.MAX_VALUE;
        int it = 0;
        for (int rem = 0; rem <= n; rem++) {
            int nextX = x[rem];
            while (it != all.size() && all.get(it) < nextX) {
                it++;
            }
            res = Math.min(res, all.size() - it + rem);
        }
        out.println(res);
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