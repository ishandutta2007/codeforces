import java.io.*;
import java.util.*;

public class CF {
    FastScanner in;
    PrintWriter out;

    long mod = (long) 1e9 + 7;
    int mul = 37;

    class Obj {
        int[] vals;
        int[] moves;

        public Obj(int[] vals, int[] moves) {
            super();
            this.vals = vals;
            this.moves = moves;
        }

        long hh() {
            long res = 0;
            for (int i = 0; i < vals.length; i++) {
                res = (vals[i] + res * mul) % mod;
            }
            return res;
        }

        long hh2() {
            long res = 0;
            for (int i = 0; i < vals.length; i++) {
                res = (vals[i] + res * mul) % mod;
            }
            for (int i = 0; i < vals.length; i++) {
                res = (moves[i] + res * mul) % mod;
            }
            return res;
        }
    }

    long getAns2(int x, int y) {
        /*
        if (x <= y) {
            long res = 1;
            for (int i = 1; i <= x + y; i++) {
                res *= i;
                res %= mod;
            }
            return res;
        }
        */
        long[] v1 = { 1, 1, 2, 4, 10, 26, 76, 232, 764, 2620, 9496, 35696,
                140152, 568504, 2390480, 10349536, 46206736, 211799312,
                997313824, 4809701440L, 23758664096L, 119952692896L };
        long res = v1[x];
        for (int i = 0; i < y; i++) {
            res = (res * (x + i + 1)) % mod;
        }
        return res;
    }

    long getAns(int x, int y) {
        if (x <= y) {
            long res = 1;
            for (int i = 1; i <= x + y; i++)
                res *= i;
            return res;
        }
        int n = x + y;
        int[] vals = new int[n];
        int[] moves = new int[n];
        for (int i = 0; i < n; i++) {
            vals[i] = i + 1;
            if (i < x) {
                moves[i] = 1;
            } else {
                moves[i] = 2;
            }
        }
        Obj o1 = new Obj(vals, moves);
        HashSet<Long> hs = new HashSet<>();
        HashSet<Long> hs2 = new HashSet<>();
        hs2.add(o1.hh2());
        ArrayList<Obj> ar = new ArrayList<>();
        ar.add(o1);
        int it = 0;
        while (it < ar.size()) {
            Obj o = ar.get(it);
            hs.add(o.hh());
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (i != j) {
                        if (o.moves[i] > 0 && o.moves[j] > 0) {
                            int[] vals1 = new int[n];
                            int[] mov1 = new int[n];
                            for (int k = 0; k < n; k++) {
                                vals1[k] = o.vals[k];
                                mov1[k] = o.moves[k];
                            }
                            mov1[i]--;
                            mov1[j]--;
                            int tmp = vals1[i];
                            vals1[i] = vals1[j];
                            vals1[j] = tmp;
                            Obj next = new Obj(vals1, mov1);
                            long hh = next.hh2();
                            if (hs2.contains(hh))
                                continue;
                            hs2.add(hh);
                            ar.add(next);
                        }
                    }
                }
            }
            it++;
        }

        return hs.size();
    }

    void solve() {
        /*
         * int n = 10; System.err.println(getAns2(3, 3)); for (int i = 0; i < n;
         * i++) { long last = 1; for (int j = 0; j < n; j++) { long nn =
         * getAns(i, j); System.out.print(nn / last + " "); last = nn; }
         * System.out.println(); }
         */

        int n = in.nextInt();
        int f = 0;
        for (int i = 0; i < n; i++) {
            if (in.nextInt() == 1) {
                f++;
            }
        }
        out.println(getAns2(f, n - f));

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