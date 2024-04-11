import java.io.*;
import java.util.*;

public class A {
    FastScanner in;
    PrintWriter out;

    void solve() {
        int n = in.nextInt();
        int m = in.nextInt();
        int[] cntLeft = new int[n];
        List<Integer>[] goRight = new List[n];
        for (int i = 0; i < goRight.length; i++) {
            goRight[i] = new ArrayList<>();
        }
        for (int i = 0; i < m; i++) {
            int x = in.nextInt() - 1;
            int y = in.nextInt() - 1;
            int fr = Math.min(x, y), to = Math.max(x, y);
            cntLeft[to]++;
            goRight[fr].add(to);
        }
        long res = 0;
        for (int i = 0; i < n; i++) {
            res += (long) cntLeft[i] * goRight[i].size();
        }
        out.println(res);
        int q = in.nextInt();
        for (int it = 0; it < q; it++) {
            int id = in.nextInt() - 1;
            for (int to : goRight[id]) {
                res -= cntLeft[id];
                res -= goRight[to].size();
                goRight[to].add(id);
                cntLeft[to]--;
                res += cntLeft[to];
            }
            cntLeft[id] += goRight[id].size();
            goRight[id].clear();
            out.println(res);
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