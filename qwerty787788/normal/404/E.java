import java.io.*;
import java.util.*;

public class CF {
    FastScanner in;
    PrintWriter out;

    void solve() {
        String s = in.next();
        if (s.endsWith("L")) {
            char[] tmp = new char[s.length()];
            for (int i = 0; i < s.length(); i++)
                tmp[i] = (char) ('L' + 'R' - s.charAt(i));
            s = new String(tmp);
        }
        int max = 0, cur = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == 'R') {
                cur++;
            } else {
                cur--;
            }
            if (i != s.length() - 1)
                max = Math.max(max, cur);
        }
        if (cur > max) {
            out.println(1);
            return;
        }

        int l = -1, r = (int) 1e6 + 123;
        while (r - l > 1) {
            int m = (l + r) >> 1;
            max = 0;
            cur = 0;
            for (int i = 0; i < s.length(); i++) {
                if (s.charAt(i) == 'R') {
                    cur++;
                } else {
                    cur--;
                }
                if (cur < -m)
                    cur = -m;
                if (i != s.length() - 1)
                    max = Math.max(max, cur);
            }
            if (max >= cur) {
                r = m;
            } else {
                l = m;
            }
        }

        out.println(r);
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