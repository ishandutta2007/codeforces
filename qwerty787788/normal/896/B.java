import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class B {
    private FastScanner in;
    private PrintWriter out;

    boolean ok(int[] a) {
        for (int i = 0; i < a.length; i++) {
            if (a[i] == -1) {
                return false;
            }
        }
        for (int i = 1; i < a.length; i++) {
            if (a[i] < a[i - 1]) {
                return false;
            }
        }
        return true;
    }

    private void solve() {
        int n = in.nextInt();
        int m = in.nextInt();
        int c = in.nextInt();
        int[] a = new int[n];
        Arrays.fill(a, -1);
        int mid = (c + 1) / 2;
        for (int i = 0; i < m; i++) {
            int x = in.nextInt();
            int pos = -1;
            if (x <= mid) {
                pos = n - 1;
                for (int j = 0; j < n; j++) {
                    if (a[j] == -1 || a[j] > x) {
                        pos = j;
                        break;
                    }
                }
            } else {
                pos = 0;
                for (int j = n - 1; j >= 0; j--) {
                    if (a[j] == -1 || a[j] < x) {
                        pos = j;
                        break;
                    }
                }
            }
            out.println(pos + 1);
            out.flush();
            a[pos] = x;
            if (ok(a)) {
                return;
            }
        }
    }

    private void run() {
        try {
            in = new FastScanner(new File("A.in"));
            out = new PrintWriter(new File("A.out"));

            solve();

            out.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    private void runIO() {
        in = new FastScanner(System.in);
        out = new PrintWriter(System.out);

        solve();

        out.close();
    }

    private class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        FastScanner(File f) {
            try {
                br = new BufferedReader(new FileReader(f));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        FastScanner(InputStream f) {
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
        new B().runIO();
    }
}