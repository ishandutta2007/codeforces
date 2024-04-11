import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class CF {
    FastScanner in;
    PrintWriter out;

    void solve() {
        int n = in.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
        }
        final int MAX = 2500;
        char[][] ans = new char[MAX][MAX];
        for (int i = 0; i < ans.length; i++)
            Arrays.fill(ans[i], ' ');
        int x = 0, y = MAX / 2;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                for (int j = 0; j < a[i]; j++) {
                    ans[y--][x++] = '/';
                }
                y++;
            } else {
                for (int j = 0; j < a[i]; j++) {
                    ans[y++][x++] = '\\';
                }
                y--;
            }
        }
        int su = 0;
        for (int i = 0; i < n; i++)
            su += a[i];
        int min = Integer.MAX_VALUE, max = -1;
        for (int i = 0; i < MAX; i++)
            for (int j = 0; j < MAX; j++)
                if (ans[i][j] != ' ') {
                    min = Math.min(i, min);
                    max = Math.max(i, max);
                }
        for (int i = min; i <= max; i++) {
            StringBuilder sb = new StringBuilder();
            for (int j = 0; j < su; j++) {
                sb.append(ans[i][j]);
            }
            out.println(sb.toString());
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