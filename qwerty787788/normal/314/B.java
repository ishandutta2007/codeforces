import java.io.*;
import java.util.*;

public class CF {
    FastScanner in;
    PrintWriter out;

    void solve() {
        int b = in.nextInt();
        int d = in.nextInt();
        String a = in.next();
        String c = in.next();
        long[][] oneC = new long[40][a.length()];
        boolean[] usedChC = new boolean[26];
        for (int i = 0; i < c.length(); i++) {
            usedChC[c.charAt(i) - 'a'] = true;
        }
        boolean[] usedChA = new boolean[26];
        for (int i = 0; i < a.length(); i++) {
            usedChA[a.charAt(i) - 'a'] = true;
        }
        for (int i = 0; i < 26; i++) {
            if (usedChC[i] && !usedChA[i]) {
                out.println(0);
                return;
            }
        }
        int mod = a.length();
        for (int st = 0; st < a.length(); st++) {
            int curPosC = 0;
            int curPosA = st;
            while (curPosC != c.length()) {
                if (c.charAt(curPosC) == a.charAt(curPosA % mod)) {
                    curPosC++;
                }
                curPosA++;
            }
            oneC[0][st] = curPosA - st;
        }
        for (int pow = 0; pow < oneC.length - 1; pow++) {
            for (int st = 0; st < a.length(); st++) {
                long need = oneC[pow][st]
                        + oneC[pow][(int) ((st + oneC[pow][st]) % mod)];
                if (need > 1e15) {
                    need = (long) 1e15;
                }
                oneC[pow + 1][st] = need;
            }
        }
        long l = 0, r = 1L << 37;
        long have = b * a.length();
        while (r - l > 1) {
            long m = (l + r) / 2;
            long need = 0;
            int curSt = 0;
            for (int pow = 0; pow < 40; pow++) {
                if (((1L << pow) & m) != 0) {
                    need += oneC[pow][curSt];
                    curSt = (int) ((curSt + oneC[pow][curSt]) % mod);
                }
            }
            if (need <= have) {
                l = m;
            } else {
                r = m;
            }
        }
        long canMakeC = l;
        long ans = canMakeC / d;
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