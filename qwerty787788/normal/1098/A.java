import java.io.*;
import java.util.*;

public class A {
    FastScanner in;
    PrintWriter out;

    void solve() {
        int n = in.nextInt();
        int[] p = new int[n];
        for (int i = 1; i < n; i++) {
            p[i] = in.nextInt() - 1;
        }
        int[] sum = new int[n];
        int[] startSum = new int[n];
        for (int i = 0; i < n; i++) {
            sum[i] = in.nextInt();
            startSum[i] = sum[i];
            if (sum[i] == -1) {
                sum[i] = Integer.MAX_VALUE;
            }
        }
        for (int i = n - 1; i > 0; i--) {
            if (sum[i] == Integer.MAX_VALUE) {
                sum[i] = sum[p[i]];
            }
            sum[p[i]] = Math.min(sum[p[i]], sum[i]);
        }
        for (int i = 0; i < n; i++) {
            if (startSum[i] != -1 && sum[i] != startSum[i]) {
                out.println(-1);
                return;
            }
        }
        long res = sum[0];
        for (int i = 1; i < n; i++) {
            res += sum[i] - sum[p[i]];
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