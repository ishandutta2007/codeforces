import java.io.*;
import java.util.*;
import java.util.Map.Entry;
import java.util.concurrent.atomic.AtomicLong;

public class CF {
    FastScanner in;
    PrintWriter out;

    void solve() {
        int n = in.nextInt();
        final int MAX = (int) 1e5 + 123;
        HashSet<Integer>[] hs = new HashSet[MAX];
        ArrayList<Integer>[] x = new ArrayList[MAX];
        ArrayList<Integer>[] y = new ArrayList[MAX];
        for (int i = 0; i < MAX; i++) {
            hs[i] = new HashSet<>();
            x[i] = new ArrayList<>();
            y[i] = new ArrayList<>();
        }
        int[] ax = new int[n];
        int[] ay = new int[n];
        for (int i = 0; i < n; i++) {
            int xx = in.nextInt();
            int yy = in.nextInt();
            x[xx].add(yy);
            y[yy].add(xx);
            hs[xx].add(yy);
            ax[i] = xx;
            ay[i] = yy;
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int cx = ax[i], cy = ay[i];
            if (x[cx].size() < y[cy].size()) {
                for (int yy : x[cx]) {
                    if (yy > cy)
                        if (cx + yy - cy < MAX)
                            if (hs[cx + yy - cy].contains(yy))
                                if (hs[cx + yy - cy].contains(cy))
                                    ans++;
                }
            } else {
                for (int xx : y[cy]) {
                    if (xx > cx) {
                        if (hs[cx].contains(cy + xx - cx))
                            if (hs[xx].contains(cy + xx - cx))
                                ans++;
                    }
                }
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