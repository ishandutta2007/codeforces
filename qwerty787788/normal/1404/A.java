import java.io.*;
import java.util.*;

public class A {
    FastScanner in;
    PrintWriter out;

    void solve() {
        int tc = in.nextInt();
        for (int t = 0; t < tc; t++) {
            int n = in.nextInt();
            int k = in.nextInt();
            char[] s = in.next().toCharArray();
            boolean[] mustBe0 = new boolean[k];
            boolean[] mustBe1 = new boolean[k];
            for (int i = 0; i < n; i++) {
                char c = s[i];
                int pos = i % k;
                if (c == '1') {
                    mustBe1[pos] = true;
                } else if (c == '0') {
                    mustBe0[pos] = true;
                }
            }
            boolean ok = true;
            int cnt0 = 0, cnt1 = 0;
            for (int i = 0; i < k; i++) {
                if (mustBe0[i] && mustBe1[i]) {
                    ok = false;
                }
                if (mustBe0[i]) {
                    cnt0++;
                }
                if (mustBe1[i]) {
                    cnt1++;
                }
            }
            if (cnt0 > k / 2 || cnt1 > k / 2) {
                ok = false;
            }
            out.println(ok ? "YES" : "NO");
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