import java.io.*;
import java.util.*;

public class A {
    FastScanner in;
    PrintWriter out;

    int[] p;

    int get(int x) {
        return p[x] == x ? x : (p[x] = get(p[x]));
    }

    void unit(int x, int y) {
        p[get(x)] = get(y);
    }

    int comps = 0;
    boolean[] alive;

    void add(int x) {
        alive[x] = true;
        comps++;
        if (x > 0 && alive[x - 1]) {
            unit(x - 1, x);
            comps--;
        }
        if (x + 1 < alive.length && alive[x + 1]) {
            unit(x, x + 1);
            comps--;
        }
    }

    void solve() {
        int n = in.nextInt();
        int m = in.nextInt();
        int l = in.nextInt();
        long[] len = new long[n];
        p = new int[n];
        for (int i = 0; i < n; i++) {
            p[i] = i;
        }
        alive = new boolean[n];
        for (int i = 0; i < n; i++) {
            len[i] = in.nextInt();
            if (len[i] > l) {
                add(i);
            }
        }
        for (int i = 0; i < m; i++) {
            if (in.nextInt() == 0) {
                out.println(comps);
            } else {
                int pos = in.nextInt() - 1;
                int d = in.nextInt();
                len[pos] += d;
                if (len[pos] > l && len[pos] - d <= l) {
                    add(pos);
                }
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