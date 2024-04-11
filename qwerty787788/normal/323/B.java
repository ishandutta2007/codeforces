import java.io.*;
import java.util.*;

public class CF {
    FastScanner in;
    PrintWriter out;

    void solve() {
        int n = in.nextInt();
        if (n == 4) {
            out.println(-1);
            return;
        }
        int m = n - (n % 2 == 0 ? 1 : 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    out.print("0 ");
                } else {
                    boolean f = true;
                    if (i < j) {
                        f = !f;
                    } 
                    if (i + j == m - 1) 
                        f = !f;
                    if (m != n && ((i == 0 && j == n - 1) || (i == n - 1 && j == 0))) 
                        f = !f;
                    if (m != n && ((i == 1 && j == n - 1) || (i == n - 1 && j == 1))) 
                        f = !f;
                    if (f) {
                        out.print("1 ");
                    } else {
                        out.print("0 ");
                    }
                }
            }
            out.println();
        }
        out.println();
        /*
        boolean[][] ok = new boolean[n][n];
        for (int st = 0; st < 1 << id; st++) {
            for (int i = 0; i < n; i++)
                Arrays.fill(ok[i], false);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (index[i][j] != 0) {
                        boolean isRoad = false;
                        int id2 = Math.abs(index[i][j]) - 1;
                        if (((1 << id2) & st) != 0)
                            isRoad = true;
                        if (index[i][j] < 0)
                            isRoad = !isRoad;
                        ok[i][j] = isRoad;
                    }
                }
                ok[i][i] = true;
            }
            boolean okay = true;
            for (int i = 0; i < n; i++) {
                boolean[] can1 = new boolean[n];
                for (int j = 0; j < n; j++)
                    if (ok[i][j])
                        for (int k = 0; k < n; k++)
                            if (ok[j][k])
                                can1[k] = true;
                boolean okay2 = true;
                for (int j = 0; j < n; j++)
                    if (!can1[j])
                        okay2 = false;
                if (!okay2) {
                    okay = false;
                    break;
                }
            }
            if (okay) {
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        if (ok[i][j] && i != j)
                            out.print("1");
                        else
                            out.print("0");
                    }
                    out.println();
                }
                return;
            }
        }
        */
    }

    void run() {
        try {
            in = new FastScanner(new File("object.in"));
            out = new PrintWriter(new File("object.out"));

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