import java.io.*;
import java.util.*;

public class A {
    FastScanner in;
    PrintWriter out;

    int convertFromA(int v) {
        out.println("A " + (v + 1));
        out.flush();
        return in.nextInt() - 1;
    }

    int convertFromB(int v) {
        out.println("B " + (v + 1));
        out.flush();
        return in.nextInt() - 1;
    }

    void solve() {
        int tc = in.nextInt();
        for (int t = 0; t < tc; t++) {
            int n = in.nextInt();
            List<Integer>[] g = new List[n];
            for (int i = 0; i < n; i++) {
                g[i] = new ArrayList<>();
            }
            for (int i = 0; i + 1 < n; i++) {
                int fr = in.nextInt() - 1;
                int to = in.nextInt() - 1;
                g[fr].add(to);
                g[to].add(fr);
            }
            int k = in.nextInt();
            int[] ids = new int[k];
            boolean[] colored = new boolean[n];
            for (int i = 0; i < k; i++) {
                ids[i] = in.nextInt() - 1;
                colored[ids[i]] = true;
            }
            int k2 = in.nextInt();
            int[] ids2 = new int[k2];
            for (int i = 0; i < k2; i++) {
                ids2[i] = in.nextInt() - 1;
            }
            int root = convertFromB(ids2[0]);
            int clo = go(root, root, g, colored);
            int inSecond = convertFromA(clo);
            boolean good = false;
            for (int z : ids2) {
                if (inSecond == z) {
                    good = true;
                    break;
                }
            }
            if (!good) {
                clo = -1;
            } else {
                clo++;
            }
            out.println("C " + clo);
            out.flush();
        }
    }

    int go(int v, int p, List<Integer>[] g, boolean[] colored) {
        if (colored[v]) {
            return v;
        }
        for (int to : g[v]) {
            if (to == p) {
                continue;
            }
            int r = go(to, v, g, colored);
            if (r != -1) {
                return r;
            }
        }
        return -1;
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