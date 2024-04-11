import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class CF {
    FastScanner in;
    PrintWriter out;

    void solve() {
        int n = in.nextInt();
        int m = in.nextInt();
        long mod = (long) 1e9 + 7;
        long[] pow = new long[n + 10];
        pow[0] = 1;
        for (int i = 1; i < n + 10; i++) {
            pow[i] = (pow[i - 1] * 2) % mod;
        }
        boolean[] field = new boolean[n];
        for (int i = 0; i < m; i++) {
            field[in.nextInt() - 1] = true;
        }
        ArrayList<Integer> len = new ArrayList<>();
        long ans = 1;
        for (int i = 0; i < n; i++) {
            if (!field[i]) {
                int next = i;
                for (int j = i; j < n; j++)
                    if (!field[j])
                        next = j;
                    else
                        break;
                if (i != 0 && next != n - 1) {
                    ans = (ans * pow[next - i]) % mod;
                }
                len.add(next - i + 1);
                i = next;
            }
        }
        if (n == m) {
            out.println(1);
            return;
        }
        long[][] c = new long[n + 10][n + 10];
        for (int i = 0; i < n + 10; i++) {
            c[i][0] = 1;
            if (i != 0)
                for (int j = 1; j < n + 10; j++) {
                    c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
                }
        }
        int curLen = len.get(0);
        for (int i = 1; i < len.size(); i++) {
            int nextLen = len.get(i) + curLen;
            ans = (ans * c[nextLen][curLen]) % mod;
            curLen = nextLen;
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

        long nextLong() {
            return Long.parseLong(next());
        }
    }

    public static void main(String[] args) {
        new CF().runIO();
    }
}