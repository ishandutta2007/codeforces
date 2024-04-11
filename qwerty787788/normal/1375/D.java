import java.io.*;
import java.util.*;

public class A {
    FastScanner in;
    PrintWriter out;

    void solve() {
        int tc = in.nextInt();
        for (int t = 0; t < tc; t++) {
            int n = in.nextInt();
            int[] a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = in.nextInt();
            }
            List<Integer> res = new ArrayList<>();
            boolean[] used = new boolean[n + 1];
            while (true) {
                Arrays.fill(used, false);
                while (n > 0 && a[n - 1] == n) {
                    n--;
                }
                if (n == 0) {
                    break;
                }
                boolean ok = true;
                for (int i = 0; i + 1 < a.length; i++) {
                    if (a[i] > a[i + 1]) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    break;
                }
                for (int i = 0; i < n; i++) {
                    used[a[i]] = true;
                }
                int mex = 0;
                while (used[mex]) {
                    mex++;
                }
                int pos = Math.min(n - 1, mex);
                res.add(pos + 1);
                a[pos] = mex;
            }
            if (res.size() > 2 * a.length) {
                throw new AssertionError();
            }
            out.println(res.size());
            for (int x : res) {
                out.print(x + " ");
            }
            out.println();
        }
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