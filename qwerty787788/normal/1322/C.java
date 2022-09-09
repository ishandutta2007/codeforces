import java.io.*;
import java.util.*;

public class A {
    FastScanner in;
    PrintWriter out;

    void solve() {
        int tc = in.nextInt();
        Random rnd = new Random(System.currentTimeMillis() * 787788);
        for (int t = 0; t < tc; t++) {
            int n = in.nextInt();
            int m = in.nextInt();
            long[] ci = new long[n];
            for (int i = 0; i < n; i++) {
                ci[i] = in.nextLong();
            }
            long[] colorLeft = new long[n];
            for (int i = 0; i < n; i++) {
                colorLeft[i] = rnd.nextLong();
            }
            long[] colorRight = new long[n];
            for (int i = 0; i < m; i++) {
                int left = in.nextInt() - 1;
                colorRight[in.nextInt() - 1] ^= colorLeft[left];
            }
            O[] a = new O[n];
            for (int i = 0; i < n; i++) {
                a[i] = new O(i, colorRight[i]);
            }
            Arrays.sort(a);
            long res = 0;
            for (int i = 0; i < n; ) {
                int j = i;
                long sum = 0;
                while (j != n && a[j].value == a[i].value) {
                    sum += ci[a[j].pos];
                    j++;
                }
                if (a[i].value != 0) {
                    res = gcd(res, sum);
                }
                i = j;
            }
            out.println(res);
        }
    }

    long gcd(long x, long y) {
        return x == 0 ? y : gcd(y % x, x);
    }

    class O implements Comparable<O> {
        int pos;
        long value;

        public O(int pos, long value) {
            this.pos = pos;
            this.value = value;
        }

        @Override
        public int compareTo(O o) {
            return Long.compare(value, o.value);
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