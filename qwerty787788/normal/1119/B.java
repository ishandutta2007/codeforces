import java.io.*;
import java.util.*;

public class Test {
    FastScanner in;
    PrintWriter out;

    void solve() {
        int n = in.nextInt();
        int h = in.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
        }
        int l = 0, r = n + 1;
        while (r - l > 1) {
            int mid = (l + r) >> 1;
            int[] all = new int[mid];
            for (int i = 0; i < mid; i++) {
                all[i] = a[i];
            }
            Arrays.sort(all);
            boolean ok = false;
            {
                long totalSum = 0;
                for (int i = 0; i < mid; i += 2) {
                    int cur = all[i];
                    if (i + 1 < mid) {
                        cur = all[i + 1];
                    }
                    totalSum += cur;
                }
                ok |= totalSum <= h;
            }
            if (mid % 2 == 1) {
                long totalSum = all[0];
                for (int i = 1; i < mid; i += 2) {
                    int cur = all[i];
                    if (i + 1 < mid) {
                        cur = all[i + 1];
                    }
                    totalSum += cur;
                }
                ok |= totalSum <= h;
            }
            if (ok) {
                l = mid;
            } else {
                r = mid;
            }
        }
        out.println(l);
    }

    void run() {
        try {
            in = new FastScanner(new File("Test.in"));
            out = new PrintWriter(new File("Test.out"));

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
        new Test().runIO();
    }
}