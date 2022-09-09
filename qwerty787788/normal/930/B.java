import java.io.*;
import java.util.*;

public class A {
    FastScanner in;
    PrintWriter out;

    void solve() {
        char[] s = in.next().toCharArray();
        int[] x = new int[s.length];
        for (int i = 0; i < s.length; i++) {
            x[i] = s[i] - 'a';
        }
        int[] pos = new int[s.length];
        long res = 0;
        int[] cnt = new int[26];
        int[] time = new int[26];
        int curT = 0;
        for (char c = 'a'; c <= 'z'; c++) {
            int sz = 0;
            for (int i = 0; i < s.length; i++) {
                if (s[i] == c) {
                    pos[sz++] = i;
                }
            }
            int maxCnt = 0;
            for (int shift = 1; shift < s.length; shift++) {
                curT++;
                int val = 0;
                for (int i = 0; i < sz; i++) {
                    int p = pos[i] + shift;
                    if (p >= s.length) {
                        p -= s.length;
                    }
                    int v = x[p];
                    if (time[v] != curT) {
                        time[v] = curT;
                        val++;
                        cnt[v] = 1;
                    } else {
                        cnt[v]++;
                        if (cnt[v] == 2) {
                            val--;
                        }
                    }
                }
                maxCnt = Math.max(maxCnt, val);
            }
            res += maxCnt;
        }
        double l = s.length;
        out.printf(Locale.US, "%.17f\n", res / l);
    }

    void run() {
        try {
            in = new FastScanner(new File("A.in"));
            out = new PrintWriter(new File("A.out"));

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
        new A().runIO();
    }
}