import java.io.*;
import java.util.*;

public class F {
    FastScanner in;
    PrintWriter out;

    long[] vals = new long[3];

    int whoCant = -1;

    void move(long value) {
        out.println(value);
        out.flush();
        int id = in.nextInt() - 1;
        if (id == -1) {
            System.exit(0);
        }
        vals[id] += value;
        whoCant = id;
    }

    int getMaxId() {
        int r = 0;
        for (int i = 1; i < vals.length; i++) {
            if (vals[i] > vals[r]) {
                r = i;
            }
        }
        return r;
    }

    int getMinId() {
        int r = 0;
        for (int i = 1; i < vals.length; i++) {
            if (vals[i] < vals[r]) {
                r = i;
            }
        }
        return r;
    }

    void solve() {
        for (int i = 0; i < 3; i++) {
            vals[i] = in.nextLong();
        }
        out.println("First");
        out.flush();
        move(5);
        while (true) {
            int mxId = getMaxId();
            int mnId = getMinId();
            long[] sorted = vals.clone();
            Arrays.sort(sorted);
            if (whoCant == mxId) {
                long d1 = sorted[1] - sorted[0], d2 = sorted[2] - sorted[1];
                if (d1 == d2) {
                    move(d1);
                } else {
                    move(d1 + 2 * d2);
                }
            } else {
                if (whoCant == mnId) {
                    move(sorted[2] - sorted[1]);
                } else {
                    move(sorted[2] - sorted[0]);
                }
            }
        }
    }

    void run() {
        try {
            in = new FastScanner(new File("F.in"));
            out = new PrintWriter(new File("F.out"));

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
        new F().runIO();
    }
}