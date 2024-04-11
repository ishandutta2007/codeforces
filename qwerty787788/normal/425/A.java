import java.io.*;
import java.util.*;
import java.util.Map.Entry;
import java.util.concurrent.atomic.AtomicLong;

public class CF {
    FastScanner in;
    PrintWriter out;

    void solve() {
        int n = in.nextInt();
        int k = in.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
        }
        int max = Integer.MIN_VALUE;
        for (int l = 0; l < n; l++)
            for (int r = l; r < n; r++) {
                ArrayList<Integer> cur = new ArrayList<>();
                ArrayList<Integer> another = new ArrayList<>();
                for (int i = 0; i < n; i++) {
                    if (i >= l && i <= r) {
                        cur.add(a[i]);
                    } else {
                        another.add(a[i]);
                    }
                }
                Collections.sort(cur);
                Collections.sort(another);
                int it1 = cur.size() - 1;
                int it2 = another.size() - 1;
                int sum = 0, useSwaps = 0;
                for (int need = 0; need < r - l + 1; need++) {
                    if (it2 >= 0 && useSwaps < k
                            && another.get(it2) > cur.get(it1)) {
                        sum += another.get(it2--);
                        useSwaps++;
                    } else {
                        sum += cur.get(it1--);
                    }
                }
                max = Math.max(max, sum);
            }
        out.println(max);

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