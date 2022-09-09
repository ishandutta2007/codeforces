import java.io.*;
import java.util.*;

public class CF {
    FastScanner in;
    PrintWriter out;

    boolean ok(long x, long y, long m) {
        return x >= m || y >= m;
    }

    void solve() {
        long x = in.nextLong();
        long y = in.nextLong();
        long m = in.nextLong();
        if (ok(x, y, m)) {
            out.println(0);
            return;
        }
        if (x <= 0 && y <= 0) {
            out.println(-1);
            return;
        }
        if (x > y) {
            long tmp = x;
            x = y;
            y = tmp;
        }
        //x <= y
        long res = 0;
        if (x < 0) {
            long add = -x / y;
            res += add;
            x += add * y;
        }
        while (!ok(x, y, m)) {
            long s = x + y;
            if (x < y) {
                x = s;
            } else {
                y = s;
            }
            res++;
        }
        out.println(res);
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