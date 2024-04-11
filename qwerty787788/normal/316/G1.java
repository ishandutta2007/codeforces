import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class CF {
    FastScanner in;
    PrintWriter out;

    long mod = 1000001237;
    long mul = 37;

    long[] hash(String s) {
        int n = s.length();
        long[] res = new long[n];
        for (int i = 0; i < n; i++) {
            res[i] = s.charAt(i) - 'a' + 1;
            if (i > 0)
                res[i] += res[i - 1] * mul;
            res[i] %= mod;
        }
        return res;
    }

    long[] pow = new long[10000];

    long getHash(long[] h, int fr, int to) {
        int len = to - fr + 1;
        long h1 = h[to];
        long h2 = fr > 0 ? h[fr - 1] : 0;
        h2 = (h2 * pow[len]) % mod;
        h1 -= h2;
        if (h1 < 0)
            h1 += mod;
        if (h1 >= mod)
            h1 -= mod;
        return h1;
    }

    void solve() {
        pow[0] = 1;
        for (int i = 1; i < pow.length; i++)
            pow[i] = (pow[i - 1] * mul) % mod;
        String s = in.next();
        long[] strHash = hash(s);
        int n = in.nextInt();
        HashMap<Long, Integer>[][] hm = new HashMap[n][s.length() + 1];
        int[][] needCnt = new int[3][n];
        for (int i = 0; i < n; i++) {
            String s1 = in.next();
            needCnt[0][i] = in.nextInt();
            needCnt[1][i] = in.nextInt();
            needCnt[2][i] = s1.length();
            for (int j = 0; j < hm[i].length; j++)
                hm[i][j] = new HashMap<>();
            //System.err.println(i);
            for (int st = 0; st < s1.length(); st++) {
                long curH = 0;
                for (int len = 1; len <= s1.length() - st; len++) {
                    if (len > s.length())
                        continue;
                    curH *= mul;
                    curH += s1.charAt(st + len - 1) - 'a' + 1;
                    curH %= mod;
                    Integer curCnt = hm[i][len].get(curH);
                    if (curCnt == null)
                        curCnt = 0;
                    hm[i][len].put(curH, curCnt + 1);
                }
            }
        }
        HashSet<Long> all = new HashSet<>();
        for (int st = 0; st < s.length(); st++) {
            //System.err.println(st);
            for (int len = 1; len <= s.length(); len++) {
                if (st + len <= s.length()) {
                    long h1 = getHash(strHash, st, st + len - 1);
                    if (all.contains(h1))
                        continue;
                    boolean ok = true;
                    for (int i = 0; i < n; i++) {
                        Integer cc = hm[i][len].get(h1);
                        if (cc == null)
                            cc = 0;
                        if (cc < needCnt[0][i] || cc > needCnt[1][i]) {
                            ok = false;
                            break;
                        }
                    }
                    if (!ok)
                        continue;
                    all.add(h1);
                    // out.println(s.substring(st, st + len));
                }
            }
        }
        out.println(all.size());
    }

    void run() {
        long st = System.currentTimeMillis();
        try {
            in = new FastScanner(new File("test.in"));
            out = new PrintWriter(new File("test.out"));

            solve();

            out.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
        long sp = System.currentTimeMillis() - st;
        System.err.println(sp);
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