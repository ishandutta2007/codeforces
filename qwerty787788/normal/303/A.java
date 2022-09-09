import java.io.*;
import java.util.*;

public class CF {
    FastScanner in;
    PrintWriter out;

    void solve() throws IOException {
        int n = in.nextInt();
        if (n % 2 == 0) {
            out.println(-1);
        } else {
            for (int i = 0; i < n; i++) {
                out.print(i + " ");
            }
            out.println();
            for (int i = 0; i < n; i++) {
                out.print(i + " ");
            }
            out.println();
            for (int i = 0; i < n; i++) {
                out.print((2 * i) % n + " ");
            }
            out.println();
        }
        // for (int n = 1; n <= 10; n++) {
        // int[] a = new int[n];
        // int[] b = new int[n];
        // boolean[] c = new boolean[n];
        // for (int i = 0; i < n; i++) {
        // a[i] = i;
        // b[i] = i;
        // }
        // for (int i = 0; i < n; i++) {
        // c[(a[i] + b[i]) % n] = true;
        // }
        // boolean ok = true;
        // for (int i = 0; i < n; i++)
        // if (!c[i])
        // ok = false;
        // System.err.println(n + ": " + ok);
        // }
    }

    void run() throws IOException {
        try {
            in = new FastScanner(new File("test.in"));
            out = new PrintWriter(new File("test.out"));

            solve();

            out.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    void runIO() throws IOException {
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

    public static void main(String[] args) throws IOException {
        new CF().runIO();
    }
}