import java.io.*;
import java.util.*;

public class CF {
    FastScanner in;
    PrintWriter out;

    void solve() {
        String s = in.next();
        int xx = 0;
        long cnt = 1;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '?') {
                if (i == 0) {
                    cnt *= 9;
                } else {
                    xx++;
                }
            }
        }
        HashSet<Character> hs = new HashSet<>();
        boolean firstS = false;
        for (int i = 0; i < s.length(); i++) {
            char cc = s.charAt(i);
            if (cc >= 'A' && cc <= 'Z') {
                hs.add(cc);
                if (i == 0)
                    firstS = true;
            }
        }
        int cn = hs.size();
        if (!firstS) {
            for (int i = 0; i < cn; i++) {
                cnt *= 10L - i;
            }
        } else {
            cnt *= 9;
            for (int i = 1; i < cn; i++)
                cnt *= 10L - i;
        }
        out.print(cnt);
        for (int i = 0; i < xx; i++) {
            out.print("0");
        }
        out.println();
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