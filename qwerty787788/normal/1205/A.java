import java.io.*;
import java.util.*;

public class RealA {
    FastScanner in;
    PrintWriter out;

    void solve() {
        int n = in.nextInt();
        if (n % 2 == 0) {
            out.println("NO");
            return;
        }
        out.println("YES");
        int[] res = new int[n * 2];
        boolean inv = false;
        for (int i = 0; i < n * 2; i += 2) {
            if (inv) {
                res[i / 2] = i;
                res[i / 2 + n] = i + 1;
            } else {
                res[i / 2] = i + 1;
                res[i / 2 + n] = i;
            }
            inv = !inv;
        }
        for (int x : res) {
            out.print((x + 1) + " ");
        }
    }

    void run() {
        try {
            in = new FastScanner(new File("RealA.in"));
            out = new PrintWriter(new File("RealA.out"));

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
        new RealA().runIO();
    }
}