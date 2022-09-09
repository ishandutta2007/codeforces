import java.io.*;
import java.util.*;

public class CF {
    FastScanner in;
    PrintWriter out;

    long mod = (long) 1e9 + 7;

    long getV(int n) {
        if (n <= 4) {
            return new long[]{ 1, 1, 2, 4, 10, 26, 76, 232 }[n];
        }
        long[] res = new long[n + 1];
        res[0] = res[1] = 1;
        for (int i = 2; i <= n; i++) {
            res[i] = (res[i - 1] + (i - 1) * res[i - 2]) % mod;
        }
        return res[n];
    }

    long getAns2(int x, int y) {
        long res = getV(x);
        for (int i = 0; i < y; i++) {
            res = (res * (x + i + 1)) % mod;
        }
        return res;
    }

    void solve() {
        int n = in.nextInt();
        int f = 0;
        for (int i = 0; i < n; i++) {
            if (in.nextInt() == 1) {
                f++;
            }
        }
        out.println(getAns2(f, n - f));

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