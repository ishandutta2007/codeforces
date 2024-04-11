import java.io.*;
import java.util.*;

public class CF {
    FastScanner in;
    PrintWriter out;

    int sqrt(int x) {
        int t = (int) Math.round(Math.sqrt(x));
        if (t * t == x)
            return t;
        return -1;
    }

    Random rnd = new Random(123);

    int[] gen(int n) {
        int[] a = new int[n];
        int sum = 0;
        for (int i = 0; i < n - 1; i++) {
            a[i] = 1 + rnd.nextInt(5);
            sum += a[i] * a[i];
        }
        int sq = (int) Math.sqrt(sum) + 1;
        int tmp = 0;
        while (sqrt(sq * sq - sum) == -1) {
            sq++;
            tmp++;
            if (tmp == 40)
                return gen(n);
        }
        a[n - 1] = sqrt(sq * sq - sum);
        return a;
    }

    int[][] ans(int n, int m) {
        int[] a = gen(n);
        int[] b = gen(m);
        int[][] res = new int[n][m];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                res[i][j] = a[i] * b[j];
        return res;
    }

    void print(int[][] a) {
        for (int i = 0; i < a.length; i++) {
            for (int j = 0; j < a[0].length; j++) {
                System.err.print(a[i][j] + " ");
            }
            System.err.println();
        }
    }

    void solve() {
        // for (int i = 1; i <= 100; i++) {
        // for (int j = 1; j <= 100; j++) {
        // int[][] a = ans(i, j);
        // for (int k = 0; k < i; k++) {
        // int su = 0;
        // for (int l = 0; l < j; l++)
        // su += a[k][l] * a[k][l];
        // if (sqrt(su) == -1) {
        // print(a);
        // throw new AssertionError(i + " " + j);
        // }
        // }
        // for (int k = 0; k < j; k++) {
        // int su = 0;
        // for (int l = 0; l < i; l++)
        // su += a[l][k] * a[l][k];
        // if (sqrt(su) == -1) {
        // print(a);
        // throw new AssertionError(i + " " + j);
        // }
        // }
        // }
        // // System.err.println(i + ":" + Arrays.toString(gen(i)));
        // }
        int n = in.nextInt();
        int m = in.nextInt();
        int[][] res = ans(n, m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                out.print(res[i][j] + " ");
            out.println();
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

        double nextDouble() {
            return Double.parseDouble(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }
    }

    public static void main(String[] args) {
        new CF().runIO();
    }
}