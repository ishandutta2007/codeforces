import java.io.*;
import java.util.*;
import java.util.Map.Entry;
import java.util.concurrent.atomic.AtomicLong;

public class CF {
    FastScanner in;
    PrintWriter out;

    char[][] a;
    int k;

    void solve() {
        int n = in.nextInt();
        int m = in.nextInt();
        k = in.nextInt();
        a = new char[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                a[i][j] = in.next().charAt(0);
            }
        }
        int ans = Integer.MAX_VALUE;
        if (n > k) {
            for (int i = 0; i < m; i++) {
                int curCost = 0;
                for (int i2 = 0; i2 < m; i2++) {
                    if (i2 == i)
                        continue;
                    int nCh = 0, ch = 0;
                    for (int j = 0; j < n; j++) {
                        if (a[j][i2] == a[j][i]) {
                            ch++;
                        } else {
                            nCh++;
                        }
                    }
                    curCost += Math.min(ch, nCh);
                }
                if (curCost <= k)
                    ans = Math.min(curCost, ans);
            }
        } else {
            for (int st = 0; st < 1 << n; st++) {
                int curCost = Integer.bitCount(st);
                for (int j = 1; j < m; j++) {
                    int c = 0;
                    for (int i = 0; i < n; i++) {
                        char need = a[i][0];
                        if (((1 << i) & st) != 0)
                            need = (char) ('0' + '1' - need);
                        if (a[i][j] != need)
                            c++;
                    }
                    curCost += Math.min(c, n - c);
                }
                if (curCost <= k)
                    ans = Math.min(curCost, ans);
            }
        }
        if (ans == Integer.MAX_VALUE) {
            ans = -1;
        }
        out.println(ans);
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