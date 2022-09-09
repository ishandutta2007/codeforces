import java.io.*;
import java.util.*;

public class C {
    FastScanner in;
    PrintWriter out;

    boolean isOk(char[] symbols) {
        for (int i = 0; i < symbols.length; i++) {
            if (symbols[i] == 0) {
                symbols[i] = (char) i;
            }
        }
        for (int start = 0; start < symbols.length; start++) {
            for (int end = start + 1; end < symbols.length; end++) {
                boolean hasZero = false;
                boolean isPal = true;
                for (int i = start; i <= end; i++) {
                    if (symbols[i] == 0) {
                        hasZero = true;
                    }

                }
                for (int i = start, j = end; i < j; i++, j--) {
                    if (symbols[i] != symbols[j]) {
                        isPal = false;
                    }
                }
                if (isPal && !hasZero) {
                    return false;
                }
            }
        }
        return true;
    }

    void solve() {
        int tc = in.nextInt();
        for (int t = 0; t < tc; t++) {
            char[] s = in.next().toCharArray();
            int[] dp = new int[4];
            int[] ndp = new int[4];
            Arrays.fill(dp, Integer.MAX_VALUE / 2);
            dp[0] = 0;
            char[] symbols = new char[3];
            for (int pos = 0; pos < s.length; pos++) {
                Arrays.fill(ndp, Integer.MAX_VALUE / 2);
                for (int mask = 0; mask < dp.length; mask++) {
                    for (int ch = 0; ch < 2; ch++) {
                        int nmask = ((mask << 1) | ch) & 3;
                        Arrays.fill(symbols, (char) 0);
                        for (int i = 0; i < symbols.length; i++) {
                            if (pos - i >= 0) {
                                symbols[i] = s[pos - i];
                            }
                        }
                        if (ch == 1) {
                            symbols[0] = 0;
                        }
                        if ((mask & 1) == 1) {
                            symbols[1] = 0;
                        }
                        if ((mask & 2) == 2) {
                            symbols[2] = 0;
                        }
                        if (!isOk(symbols)) {
                            continue;
                        }
                        ndp[nmask] = Math.min(ndp[nmask], dp[mask] + ch);
                    }
                }
                int[] tmp = dp;
                dp = ndp;
                ndp = tmp;
            }
            int res = Integer.MAX_VALUE;
            for (int x : dp) {
                res = Math.min(res, x);
            }
            out.println(res);
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