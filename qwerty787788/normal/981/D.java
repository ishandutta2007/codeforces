import java.io.*;
import java.util.*;

public class A {
    FastScanner in;
    PrintWriter out;


    void solve() {
        int n = in.nextInt();
        int k = in.nextInt();
        long[] a = new long[n];
        for (int i =0 ; i <n ; i++) {
            a[i] = in.nextLong();
        }
        long ans = 0;
        for (int bit = 60; bit >=0 ; bit--) {
            if (can(ans | (1L << bit), a, k)) {
                ans |= 1L << bit;
            }
        }
        out.println(ans);
    }

    boolean can(long ans, long[] a, int k) {
        boolean[] can = new boolean[a.length + 1];
        can[0] = true;
        for (int i = 0; i < k; i++) {
            boolean[] nextCan = new boolean[a.length + 1];
            for (int j = 0; j < a.length; j++) {
                if (can[j]) {
                    long s = 0;
                    for (int last = j; last < a.length; last++) {
                        s += a[last];
                        if ((s&ans) == ans) {
                            nextCan[last + 1] = true;
                        }
                    }
                }
            }
            can = nextCan;
        }
        return can[can.length - 1];
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