import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class CF {
    FastScanner in;
    PrintWriter out;

    long ans = 0;
    int[] next = new int[10];
    int k;

    int[] can = new int[10];

    boolean canGet(int v, boolean st) {
        if (v == 0)
            return true;
        if (can[v] != -1) {
            if (can[v] == 0) {
                return false;
            }
            return true;
        } else {
            can[v] = 0;
            // System.err.println(v);
            if (canGet(next[v], false)) {
                can[v] = 1;
                return true;
            } else {
                can[v] = 0;
                return false;
            }
        }
    }

    void go(int v) {
        if (v == k) {
            boolean ok = true;
            Arrays.fill(can, -1);
            for (int i = 0; i < k; i++)
                if (!canGet(i, true)) {
                    ok = false;
                    break;
                }
            if (ok) {
                ans++;
                //System.err.println(Arrays.toString(next));
            }
        } else {
            for (int i = 0; i < k; i++) {
                next[v] = i;
                if (i != v || v == 0) {
                    go(v + 1);
                }
            }
        }
    }

    void solve() {
        int n = in.nextInt();
        k = in.nextInt();
        long mod = (long) (1e9 + 7);
        long ost = n - k;
        long curAns = 1;
        for (int i = 0; i < ost; i++) {
            curAns = (curAns * ost) % mod;
        }
        go(0);
        ans = (ans * curAns) % mod;
        out.println(ans);
    }

    void run() {
        try {
            in = new FastScanner(new File("cap.sol"));
            out = new PrintWriter(new File("cap.dat"));

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