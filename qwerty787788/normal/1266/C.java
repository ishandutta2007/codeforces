import java.io.*;
import java.util.*;

public class A {
    FastScanner in;
    PrintWriter out;

    void solve() {
        int r = in.nextInt();
        int c = in.nextInt();
        if (r == 1 && c == 1) {
            out.println(0);
            return;
        }
        int[][] a = new int[r][c];
        int max = r + c;
        boolean[] used = new boolean[max + 1];
        used[0] = used[1] = true;
        if (r < c) {
            for (int i = 0; i < r; i++) {
                a[i][0] = i * 2 + 2;
                used[a[i][0]] = true;
            }
            int it = 0;
            for (int j = 1; j < c; j++) {
                while (used[it]) {
                    it++;
                }
                used[it] = true;
                a[0][j] = it;
            }
        } else {
            for (int i = 0; i < c; i++) {
                a[0][i] = i * 2 + 2;
                used[a[0][i]] = true;
            }
            int it = 0;
            for (int j = 1; j < r; j++) {
                while (used[it]) {
                    it++;
                }
                used[it] = true;
                a[j][0] = it;
            }
        }
        for (int i = 1; i < r; i++) {
            for (int j = 1; j < c; j++) {
                a[i][j] = a[i][0] * a[0][j];
            }
        }
        for (int[] ar : a) {
            for (int x : ar) {
                out.print(x + " ");
            }
            out.println();
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