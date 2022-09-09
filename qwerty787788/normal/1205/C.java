import java.io.*;
import java.util.*;

public class C {
    FastScanner in;
    PrintWriter out;

    boolean existPal(boolean[][] a, int x1, int y1, int x2, int y2) {
        if (x1 > x2 || y1 > y2) {
            return false;
        }
        if (a[x1][y1] != a[x2][y2]) {
            return false;
        }
        if (Math.abs(x1 - x2) + Math.abs(y1 - y2) <= 1) {
            return true;
        }
        boolean ok = false;
        ok |= existPal(a, x1 + 1, y1, x2 - 1, y2);
        ok |= existPal(a, x1 + 1, y1, x2, y2 - 1);
        ok |= existPal(a, x1, y1 + 1, x2 - 1, y2);
        ok |= existPal(a, x1, y1 + 1, x2, y2 - 1);
        return ok;
    }

    boolean is(int x1, int y1, int x2, int y2) {
        x1++;
        y1++;
        x2++;
        y2++;
        out.println("? " + x1 + " " + y1 + " " + x2 + " " + y2);
        out.flush();
        return in.nextInt() == 1;
    }

    boolean correct(int start, boolean[][] a, boolean[][] b) {
        int n = 3;
        for (int x1 = 0; x1 < n; x1++) {
            for (int y1 = 0; y1 < n; y1++) {
                for (int x2 = x1; x2 < n; x2++) {
                    for (int y2 = y1; y2 < n; y2++) {
                        if (x2 + y2 - x1 - y1 >= 2) {
                            if (existPal(a, x1, y1, x2, y2) != existPal(b, x1, y1, x2, y2)) {
                                if (existPal(a, x1, y1, x2, y2) == is(x1 + start, y1 + start, x2 + start, y2 + start)) {
                                    return true;
                                } else {
                                    return false;
                                }
                            }
                        }
                    }
                }
            }
        }
        throw new AssertionError();
    }

    void solve() {
        int n = in.nextInt();
        boolean[][] a = new boolean[n][n];
        a[0][0] = true;
        a[0][1] = false;
        for (int i = 2; i < n; i++) {
            if (is(0, i - 2, 0, i)) {
                a[0][i] = a[0][i - 2];
            } else {
                a[0][i] = !a[0][i - 2];
            }
        }
        for (int row = 1; row < n; row++) {
            if (is(row - 1, 0, row, 1)) {
                a[row][1] = a[row - 1][0];
            } else {
                a[row][1] = !a[row - 1][0];
            }
            if (is(row - 1, 1, row, 2)) {
                a[row][2] = a[row - 1][1];
            } else {
                a[row][2] = !a[row - 1][1];
            }
            if (is(row, 0, row, 2)) {
                a[row][0] = a[row][2];
            } else {
                a[row][0] = !a[row][2];
            }
            for (int col = 3; col < n; col++) {
                if (is(row, col - 2, row, col)) {
                    a[row][col] = a[row][col - 2];
                } else {
                    a[row][col] = !a[row][col - 2];
                }
            }
        }
        boolean[][] cur = new boolean[3][3];
        boolean[][] neg = new boolean[3][3];
        for (int start = 0; ; start += 2) {
            if (a[start][start] != a[start + 2][start + 2]) {
                int it = 0;
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        cur[i][j] = a[start + i][start + j];
                        if (it % 2 == 1) {
                            neg[i][j] = !cur[i][j];
                        } else {
                            neg[i][j] = cur[i][j];
                        }
                        it++;
                    }
                }
                if (!correct(start, cur, neg)) {
                    it = 0;
                    for (int i = 0; i < n; i++) {
                        for (int j = 0; j < n; j++) {
                           if (it % 2 == 1) {
                               a[i][j] = !a[i][j];
                           }
                           it++;
                        }
                    }
                }
                break;
            }
        }
        out.println("!");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                out.print(a[i][j] ? 1 : 0);
            }
            out.println();
        }
    }

    void solve123() {
        int n = 3;
        boolean[][] a = new boolean[n][n];
        boolean[][] b = new boolean[n][n];
        for (int mask = 0; mask < 1 << n * n; mask++) {
            int it = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (((mask & (1 << it)) != 0)) {
                        a[i][j] = true;
                    } else {
                        a[i][j] = false;
                    }
                    if (it % 2 == 1) {
                        b[i][j] = !a[i][j];
                    } else {
                        b[i][j] = a[i][j];
                    }
                    it++;
                }
            }
            boolean found = false;
            for (int x1 = 0; x1 < n; x1++) {
                for (int y1 = 0; y1 < n; y1++) {
                    for (int x2 = x1; x2 < n; x2++) {
                        for (int y2 = y1; y2 < n; y2++) {
                            if (x2 + y2 - x1 - y1 >= 2) {
                                if (existPal(a, x1, y1, x2, y2) != existPal(b, x1, y1, x2, y2)) {
                                    found = true;
                                }
                            }
                        }
                    }
                }
            }
            if (!found && a[0][0]) {
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        System.err.print(a[i][j] ? 1 : 0);
                    }
                    System.err.println();
                }
                System.err.println();

//                System.err.println();
//                for (int i = 0; i < n; i++) {
//                    for (int j = 0; j < n; j++) {
//                        System.err.print(b[i][j] ? 1 : 0);
//                    }
//                    System.err.println();
//                }
//                throw new AssertionError();
            }
        }
    }

    void run() {
        try {
            in = new FastScanner(new File("C.in"));
            out = new PrintWriter(new File("C.out"));

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
        new C().runIO();
    }
}