import java.io.*;
import java.util.*;

public class A {
    FastScanner in;
    PrintWriter out;

    long[] correct(long[] a) {
        final int n = a.length;
        while (true) {
            boolean[] changed = new boolean[n - 1];
            boolean stop = true;
            for (int i = 0; i + 1 < n; i++) {
                if (a[i] + 2 <= a[i + 1]) {
                    changed[i] = true;
                    stop = false;
                }
            }
            if (stop) {
                break;
            }
            for (int i = 0; i + 1 < n; i++) {
                if (changed[i]) {
                    a[i]++;
                    a[i + 1]--;
                }
            }
        }
        return a;
    }

    long[] fast(long[] a) {
        final int n = a.length;
        while (true) {
            boolean changed = false;
            for (int i = n - 2; i >= 0; i--) {
                if (a[i] + 2 <= a[i + 1]) {
                    changed = true;
                    long size = (a[i + 1] - a[i]) / 2;
                    a[i] += size;
                    a[i + 1] -= size;
                }
            }
            if (!changed) {
                break;
            }
        }
        return a;
    }

    long[] superFast(long[] a) {
        final int n = a.length;
        long sum = 0;
        for (long x : a) {
            sum += x;
        }
        long sq = n * 1L * (n - 1) / 2;
        sum -= sq;
        long full = sum / n;
        long more = sum % n;
        long[] res = new long[n];
        for (int i = 0; i < n; i++) {
            if (more > 0) {
                more--;
                res[i]++;
            }
            res[i] += i + full;
        }
        return res;
    }

    void solve33() {
        int n = (int) 1e6;
        long[] vals = new long[n];
        vals[n - 1] = (long) 1e12;
        fast(vals);
        for (long x : vals) {
            out.print(x + " ");
        }
        out.println();
    }

    void solve() {
        int n = in.nextInt();
        long[] a = new long[n];
        for (int i = 0; i < n; i++) {
            a[i] = in.nextLong();
        }
        long[] res = superFast(a);
        for (long z : res) {
            out.print(z + " ");
        }
        out.println();
    }

    void solve343() {
        Random rnd = new Random(123);
        for (int it = 0; it < 123123; it++) {
            System.err.println("it = " + it);
            int n = 1 + rnd.nextInt(10);
            long[] a = new long[n];
            int cnt = rnd.nextInt(20);
            for (int j = 0; j < cnt; j++) {
                int pos = rnd.nextInt(n);
                while (pos < n) {
                    a[pos]++;
                    pos++;
                }
            }
            for (int j = 1; j < n; j++) {
                while (a[j] <= a[j - 1]) {
                    a[j]++;
                }
            }
            long[] correct = correct(a.clone());
            long[] fast = fast(a.clone());
            long[] superfast = superFast(a.clone());
            int cntSame = 0;
            for (int i = 0; i + 1 < n; i++) {
                if (fast[i] == fast[i + 1]) {
                    cntSame++;
                }
            }
            if (cntSame > 1) {
                throw new AssertionError();
            }
            if (!Arrays.equals(correct, fast)) {
                throw new AssertionError("oops :(");
            }

            if (!Arrays.equals(superfast, fast)) {
                throw new AssertionError("oops :(");
            }
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