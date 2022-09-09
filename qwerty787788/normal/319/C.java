import java.io.*;
import java.util.*;

public class CF {
    FastScanner in;
    PrintWriter out;

    long[] cost;
    ArrayList<Integer> indexes = new ArrayList<>();
    int l;
    int[] b;

    void add(int r) {
        while (indexes.size() - 1 > l) {
            int i1 = indexes.get(indexes.size() - 2);
            int i2 = indexes.get(indexes.size() - 1);
            int i3 = r;
            double h1 = (cost[i2] - cost[i1]) / (0. + b[i1] - b[i2]);
            double h2 = (cost[i3] - cost[i2]) / (0. + b[i2] - b[i3]);
            if (h2 < h1) {
                indexes.remove(indexes.size() - 1);
            } else {
                break;
            }
        }
        indexes.add(r);
    }

    void solve() {
        int n = in.nextInt();
        int[] a = new int[n];
        b = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
        }
        for (int i = 0; i < n; i++) {
            b[i] = in.nextInt();
        }
        cost = new long[n];
        cost[0] = 0;
        l = 0;
        indexes.add(0);
        for (int r = 1; r < n; r++) {
            while (l < indexes.size() - 1) {
                int l1 = indexes.get(l);
                int l2 = indexes.get(l + 1);
                long c1 = cost[l1] + b[l1] * 1L * a[r];
                long c2 = cost[l2] + b[l2] * 1L * a[r];
                if (c2 < c1)
                    l++;
                else
                    break;
            }
            int l1 = indexes.get(l);
            cost[r] = cost[l1] + b[l1] * 1L * a[r];
            add(r);
        }
        out.println(cost[n - 1]);
    }

    void run() {
        try {
            in = new FastScanner(new File("object.in"));
            out = new PrintWriter(new File("object.out"));

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
    }

    public static void main(String[] args) {
        new CF().runIO();
    }
}