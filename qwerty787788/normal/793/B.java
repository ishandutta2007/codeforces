import java.io.*;
import java.util.*;

public class B {
    private FastScanner in;
    private PrintWriter out;

    private void solve() {
        int n = in.nextInt();
        int m = in.nextInt();
        char[][] a = new char[n][];
        for (int i = 0; i < n; i++) {
            a[i] = in.next().toCharArray();
        }
        boolean[][] can = new boolean[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == 'S') {
                    can[i][j] = true;
                }
            }
        }
        for (int moves = 0; moves < 3; moves++) {
            boolean[][] next = new boolean[n][m];
            for (int i = 0; i < n; i++) {
                boolean ok = false;
                for (int j =0; j < m; j++) {
                    ok |= can[i][j];
                    ok &= (a[i][j] != '*');
                    next[i][j] |= ok;
                }
            }
            for (int i = 0; i < m; i++) {
                boolean ok = false;
                for (int j =0; j < n; j++) {
                    ok |= can[j][i];
                    ok &= (a[j][i] != '*');
                    next[j][i] |= ok;
                }
            }
            for (int i = 0; i < n; i++) {
                boolean ok = false;
                for (int j = m - 1; j >= 0; j--) {
                    ok |= can[i][j];
                    ok &= (a[i][j] != '*');
                    next[i][j] |= ok;
                }
            }
            for (int i = 0; i < m; i++) {
                boolean ok = false;
                for (int j = n - 1; j >= 0; j--) {
                    ok |= can[j][i];
                    ok &= (a[j][i] != '*');
                    next[j][i] |= ok;
                }
            }
            can = next;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
//                System.err.print(can[i][j]?1:0);
                if (can[i][j] && a[i][j] == 'T') {
                    out.println("YES");
                    return;
                }
            }
//            System.err.println("");
        }
        out.println("NO");
    }

    private void run() {
        try {
            in = new FastScanner(new File("B.in"));
            out = new PrintWriter(new File("B.out"));

            solve();

            out.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    private void runIO() {
        in = new FastScanner(System.in);
        out = new PrintWriter(System.out);

        solve();

        out.close();
    }

    private class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        FastScanner(File f) {
            try {
                br = new BufferedReader(new FileReader(f));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        FastScanner(InputStream f) {
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
        new B().runIO();
    }
}