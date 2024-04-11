import java.io.*;
import java.util.Random;
import java.util.StringTokenizer;

public class A {
    FastScanner in;
    PrintWriter out;

    public static void main(String[] args) {
        new A().runIO();
    }

    Random rnd = new Random(123);

    void solve123() {
        for (int it =0 ; it <123123; it++) {
            System.err.println("it = " + it);
            final int MAX = (int) 100;
            long[] r = solve(rnd.nextInt(MAX), rnd.nextInt(MAX));
            if (r == null) {
                throw new AssertionError();
            }
        }
    }

    void solve() {
        int tc = in.nextInt();
        for (int t = 0; t < tc; t++) {
            int n = in.nextInt();
            long sum = 0;
            long xor = 0;
            for (int i = 0; i < n; i++) {
                long val = in.nextLong();
                sum += val;
                xor ^= val;
            }
            while (true) {
                long[] r = solve(sum, xor);
                if (r != null) {
                    out.println(3);
                    for (long v : r) {
                        out.print(v + " ");
                    }
                    out.println();
                    break;
                }
            }
        }
    }

    long[] solve(long sum, long xor) {
        boolean lastInXor = false;
        long[] res = new long[3];
        for (int bit = 0; bit < 58; bit++) {
            boolean inSum = ((1L << bit) & sum) != 0;
            if (lastInXor != inSum) {
                int cnt = rnd.nextBoolean() ? 1 : 3;
                for (int i = 0; i < cnt; i++) {
                    res[i] ^= 1L << bit;
                    sum += 1L << bit;
                    xor ^= 1L << bit;
                }
            }
            lastInXor = ((1L << bit) & xor) != 0;
        }
        if (xor * 2 == sum) {
            return res;
        } else {
            return null;
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
}