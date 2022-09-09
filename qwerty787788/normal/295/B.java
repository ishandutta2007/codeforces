import java.io.*;
import java.util.*;

public class CF {
    FastScanner in;
    PrintWriter out;

    void solve() {
        int n = in.nextInt();
        int[][] dist = new int[n][n];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                dist[i][j] = in.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt() - 1;
        }
        long[] ans = new long[n];
        boolean[] exist = new boolean[n];
        int[][] curDist = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                curDist[i][j] = (i == j ? 0 : Integer.MAX_VALUE / 4);
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            int addV = a[i];
            for (int j = 0; j < n; j++)
                if (exist[j])
                    if (j != addV) {
                        curDist[j][addV] = dist[j][addV];
                        curDist[addV][j] = dist[addV][j];
                    }
            for (int j = 0; j < n; j++)
                for (int k = 0; k < n; k++)
                    if (curDist[k][j] + curDist[j][addV] < curDist[k][addV])
                        curDist[k][addV] = curDist[k][j] + curDist[j][addV];
            for (int j = 0; j < n; j++)
                for (int k = 0; k < n; k++)
                    if (curDist[addV][j] + curDist[j][k] < curDist[addV][k])
                        curDist[addV][k] = curDist[addV][j] + curDist[j][k];
            for (int j = 0; j < n; j++)
                for (int k = 0; k < n; k++)
                    if (curDist[j][addV] + curDist[addV][k] < curDist[j][k])
                        curDist[j][k] = curDist[j][addV] + curDist[addV][k];
            exist[addV] = true;
            long sum = 0;
            for (int j = 0; j < n; j++)
                if (exist[j])
                    for (int k = 0; k < n; k++)
                        if (exist[k])
                            if (j != k) {
                                sum += curDist[j][k];
                            }
            ans[i] = sum;
        }
        for (int i = 0; i < n; i++) {
            out.print(ans[i] + " ");
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