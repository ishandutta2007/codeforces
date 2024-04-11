import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class CF {
    FastScanner in;
    PrintWriter out;

    ArrayList<Integer> cur = new ArrayList<>();
    ArrayList<ArrayList<Integer>> all = new ArrayList<>();

    int n, k, d;

    void go() {
        if (cur.size() == d) {
            all.add((ArrayList<Integer>) cur.clone());
        } else {
            for (int bus = 1; bus <= k; bus++) {
                cur.add(bus);
                go();
                if (all.size() == n)
                    break;
                cur.remove(cur.size() - 1);
            }
        }
    }

    void solve() {
        n = in.nextInt();
        k = in.nextInt();
        d = in.nextInt();
        go();
        if (all.size() == n) {
            for (int j = 0; j < d; j++) {
                for (int i = 0; i < n; i++)

                    out.print(all.get(i).get(j) + " ");
                out.println();
            }
        } else {
            out.println(-1);
        }
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