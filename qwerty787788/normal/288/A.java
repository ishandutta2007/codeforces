import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class CF {
    FastScanner in;
    PrintWriter out;

    void solve() {
        int n = in.nextInt();
        int k = in.nextInt();
        if (k == 1) {
            if (n == 1) {
                out.println('a');
                return;
            }
            out.println(-1);
            return;
        }
        if (n < k) {
            out.println(-1);
            return;
        }
        if (n == k) {
            for (int i = 0; i < n; i++) {
                out.print((char)('a' + i));
            }
            return;
        }
        k -= 2;
        for (int i = 0; i < n - k; i++) {
            if (i % 2 == 0) {
                out.print('a');
            } else {
                out.print('b');
            }
        }
        for (int i = 0; i < k; i++) {
            out.print((char)('c' + i));
        }
    }

    void run() {
        try {
            in = new FastScanner(new File("cap.sol"));
            out = new PrintWriter(new File("cap.dat"));

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