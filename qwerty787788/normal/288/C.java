import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class CF {
    FastScanner in;
    PrintWriter out;

    int[] perm;
    ArrayList<int[]> bestPermAll = new ArrayList<>();
    int[] bestPerm;
    boolean[] was;
    int n;

    long best;

    long beuty() {
        long ans = 0;
        for (int i = 0; i < n; i++) {
            ans += perm[i] ^ i;
        }
        return ans;
    }

    void go(int v) {
        if (v == n) {
            long b = beuty();
            if (b > best) {
                bestPermAll.clear();
            }
            if (b >= best) {
                best = b;
                int[] tmp = new int[n];
                for (int i = 0; i < n; i++) {
                    tmp[i] = perm[i];
                }
                bestPermAll.add(tmp);
            }
        } else {
            for (int i = 0; i < n; i++) {
                if (!was[i]) {
                    was[i] = true;
                    perm[v] = i;
                    go(v + 1);
                    was[i] = false;
                }
            }
        }
    }

    void sol(int n) {
        this.n = n;
        was = new boolean[n];
        perm = new int[n];
        bestPerm = new int[n];
        bestPermAll.clear();
        best = -1;
        go(0);
        out.println(best);
        for (int[] x : bestPermAll) {
            for (int i = 0; i < n; i++) {
                out.print((x[i] ^ i) + " ");
            }
            out.println();
        }
    }

    long getPerm(int n) {
        int[] res = new int[n];
        boolean[] was = new boolean[n];
        ArrayList<Integer> powers = new ArrayList<>();
        int cur = 1;
        while (cur <= n * 2) {
            powers.add(cur - 1);
            cur *= 2;
        }
        for (int i = n - 1; i >= 0; i--) {
            int val = -1;
            for (int j = powers.size() - 1; j >= 0; j--) {
                int needVal = powers.get(j) ^ i;
                if (needVal < n && !was[needVal]) {
                    val = needVal;
                    break;
                }
            }
            if (val == -1) {
                throw new AssertionError();
            }
            was[val] = true;
            res[i] = val;
        }
        long ans = 0;
        for (int i = 0; i < n; i++) {
            ans += res[i] ^ i;
        }
        out.println(ans);
        for (int x : res) {
            out.print(x + " ");
        }
        if ((n - 1) * 1L * (n) != ans) 
            throw new AssertionError();
        return ans;
    }

    void solve() {
        getPerm(in.nextInt() + 1);
       // for (int i = 1; i <= 100; i++) {
        //    out.println(getPerm(i));
       // }
        /*
         * for (int n = 1; n <= 9; n++) { out.println(n); sol(n + 1); }
         */
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