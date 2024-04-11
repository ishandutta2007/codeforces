import java.io.*;
import java.util.*;

public class CF {
    FastScanner in;
    PrintWriter out;

    void solve() {
        int n = in.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
        }
        int res = 0;
        ArrayList<Integer> intersting = new ArrayList<>();
        boolean[] alive = new boolean[n];
        int[] next = new int[n];
        for (int i = 0; i < n; i++) {
            if (i != n - 1)
                intersting.add(i);
            alive[i] = true;
            next[i] = i + 1;
        }
        next[n - 1] = -1;
        for (;;) {
            boolean rem = false;
            for (int i = 0; i < intersting.size(); i++) {
                int to = next[intersting.get(i)];
                if (a[to] < a[intersting.get(i)]) {
                    alive[to] = false;
                    rem = true;
                }
            }
            ArrayList<Integer> newInt = new ArrayList<>();
            for (int i = intersting.size() - 1; i >= 0; i--) {
                int to = next[intersting.get(i)];
                if (!alive[to]) {
                    while (to != -1 && !alive[to]) {
                        to = next[to];
                    }
                    next[intersting.get(i)] = to;
                    if (next[intersting.get(i)] != -1 && alive[intersting.get(i)]) {
                        newInt.add(intersting.get(i));
                    }
                }
            }
            intersting = newInt;
            if (rem) {
                res++;
            } else {
                break;
            }
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