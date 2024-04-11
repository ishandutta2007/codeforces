import java.io.*;
import java.util.*;

public class CF {
    FastScanner in;
    PrintWriter out;

    boolean canFit(int[] a, int[] b, int fr, int max) {
        if (fr == max) {
            return true;
        } else {
            int nextVal = 1 << b[fr];
            for (int i = 0; i < a.length; i++) {
                if (a[i] >= nextVal) {
                    a[i] -= nextVal;
                    if (canFit(a, b, fr + 1, max)) {
                        a[i] += nextVal;
                        return true;
                    }
                    a[i] += nextVal;
                }
            }
        }
        return false;
    }

    int stupid(int[] a, int[] b) {
        Arrays.sort(b);
        int l = 0, r = b.length + 1;
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (canFit(a, b, 0, m)) {
                l = m;
            } else {
                r = m;
            }
        }
        return l;
    }

    int MAX = 31;

    boolean can(int[] ask, int[] have) {
        int[] ask2 = new int[MAX + 1];
        for (int i = 0; i < MAX; i++) {
            ask2[i] = ask[i];
        }
        for (int i = 0; i < MAX; i++) {
            int cc = Math.min(ask2[i], have[i]);
            ask2[i] -= cc;
            if (ask2[i] != 0) {
                ask2[i + 1] += 1 + (ask2[i] - 1) / 2;
            }
        }
        return ask2[ask2.length - 1] == 0;
    }

    int solve2(int[] a, int[] b) {
        int n = a.length;
        int m = b.length;
        int[] ask = new int[MAX];
        for (int i = 0; i < m; i++) {
            ask[b[i]]++;
        }
        int[] have = new int[MAX];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < MAX; j++) {
                if (((1 << j) & a[i]) != 0) {
                    have[j]++;
                }
            }
        }
        int l = 0, r = m + 1;
        while (r - l > 1) {
            int med = (l + r) / 2;
            int[] askMed = new int[MAX];
            int alr = 0;
            for (int i = 0; i < MAX; i++) {
                askMed[i] = Math.min(med - alr, ask[i]);
                alr += askMed[i];
            }
            if (can(askMed, have)) {
                l = med;
            } else {
                r = med;
            }
        }
        return l;
    }

    void solve() {
        int n = in.nextInt();
        int m = in.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
        }
        int[] b = new int[m];
        for (int i = 0; i < m; i++) {
            b[i] = in.nextInt();
        }
        out.println(solve2(a, b));
    }

    Random rnd = new Random(123);

    void solve1() {
        for (int test = 0;; test++) {
            System.err.println(test);
            int n = 1 + rnd.nextInt(10);
            int m = 1 + rnd.nextInt(10);
            int[] a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = rnd.nextInt(100);
            }
            int[] b = new int[m];
            for (int i = 0; i < m; i++) {
                b[i] = rnd.nextInt(7);
            }
            int v2 = solve2(a, b);
            int v1 = stupid(a, b);
            System.err.println(v1 + " " + v2);
            if (v1 != v2) {
                System.err.println(Arrays.toString(a));
                System.err.println(Arrays.toString(b));
                solve2(a, b);
                throw new AssertionError();
            }
        }
    }

    void run() {
        try {
            in = new FastScanner(new File("test.in"));
            out = new PrintWriter(new File("test.out"));

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