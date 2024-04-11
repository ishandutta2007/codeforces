import java.io.*;
import java.util.*;

public class A {
    FastScanner in;
    PrintWriter out;

    int[] where;
    int[] a;

    List<int[]> res = new ArrayList<>();

    void swap(int p1, int p2) {
        if (p1 == p2) {
            return;
        }
        res.add(new int[]{p1, p2});
        int v1 = a[p1], v2 = a[p2];
        a[p1] = v2;
        a[p2] = v1;
        where[a[p1]] = p1;
        where[a[p2]] = p2;
    }

    void needSwap(int p1, int p2) {
        int n = a.length;
        if (Math.abs(p1 - p2) * 2 >= n) {
            swap(p1, p2);
        } else {
            if (p1 < n / 2) {
                swap(p1, n - 1);
                needSwap(p2, n - 1);
            } else {
                swap(p1, 0);
                needSwap(0, p2);
            }
        }
    }

    void solve() {
        int n = in.nextInt();
        a = new int[n];
        where = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt() - 1;
            where[a[i]] = i;
        }
        for (int value = 1; value + 1 < n; value++) {
            needSwap(where[value], value);
        }
        if (a[0] != 0) {
            swap(0, n - 1);
        }
        out.println(res.size());
        for (int[] z : res) {
            out.println((z[0] + 1) + " " + (z[1] + 1));
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