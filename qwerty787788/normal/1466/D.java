import java.io.*;
import java.util.*;

public class D {
    FastScanner in;
    PrintWriter out;

    void solve() {
        int tc = in.nextInt();
        for (int t = 0; t < tc; t++) {
            int n = in.nextInt();
            int[] w = new int[n];
            long sum = 0;
            for (int i = 0; i < n; i++) {
                w[i] = in.nextInt();
                sum += w[i];
            }
            int[] sz = new int[n];
            for (int i = 0; (i + 1) < n; i++) {
                sz[in.nextInt() - 1]++;
                sz[in.nextInt() - 1]++;
            }
            List<Integer> canChoose = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                while (sz[i] > 1) {
                    canChoose.add(w[i]);
                    sz[i]--;
                }
            }
            Collections.sort(canChoose);
            for (int i = 0; i + 1 < n; i++) {
                out.print(sum + " ");
                if (i < canChoose.size()) {
                    sum += canChoose.get(canChoose.size() - 1 - i);
                }
            }
            out.println();
        }
    }

    void run() {
        try {
            in = new FastScanner(new File("D.in"));
            out = new PrintWriter(new File("D.out"));

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
        new D().runIO();
    }
}