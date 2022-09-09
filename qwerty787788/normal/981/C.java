import java.io.*;
import java.util.*;

public class A {
    FastScanner in;
    PrintWriter out;


    void solve() {
        int n = in.nextInt();
        int[] sz = new int[n];
        for (int i =0; i + 1 < n; i++) {
            sz[in.nextInt() - 1]++;
            sz[in.nextInt() - 1]++;
        }
        if (n == 2) {
            out.println("Yes");
            out.println(1);
            out.println("1 2");
            return;
        }
        int cntLeafs = 0;
        for (int i =0 ; i < n; i++) {
            if (sz[i] == 1) {
                cntLeafs++;
            }
        }
        for (int i = 0; i < n; i++) {
            if (sz[i] == cntLeafs) {
                out.println("Yes");
                out.println(cntLeafs);
                for (int j = 0; j < n; j++) {
                    if (sz[j] == 1) {
                        out.println((i + 1) +" " + (j + 1));
                    }
                }
                return;
            }
        }
        out.println("No");
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