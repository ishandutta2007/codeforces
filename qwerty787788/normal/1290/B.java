import java.io.*;
import java.util.*;

public class A {
    FastScanner in;
    PrintWriter out;

    void solve() {
        char[] s = in.next().toCharArray();
        int[][] pref = new int[26][s.length + 1];
        for (int i = 0; i < pref.length; i++) {
            char c = (char) ('a' + i);
            for (int j = 0; j < s.length; j++) {
                pref[i][j + 1] = pref[i][j] + (s[j] == c ? 1 : 0);
            }
        }
        int q = in.nextInt();
        for (int i = 0; i < q; i++) {
            int l = in.nextInt() - 1;
            int r = in.nextInt() - 1;
            boolean exist = false;
            if (l == r) {
                exist = true;
            } else {
                if (s[l] != s[r]) {
                    exist = true;
                } else {
                    int cnt = 0;
                    int bad = s[l] - 'a';
                    for (int c = 0; c < pref.length; c++) {
                        if (c == bad) {
                            continue;
                        }
                        cnt += (pref[c][r + 1] - pref[c][l] > 0 ? 1 : 0);
                    }
                    exist = cnt >= 2;
                }
            }
            out.println(exist ? "Yes" : "No");
        }
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