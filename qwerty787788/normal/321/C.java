import java.io.*;
import java.util.*;

public class CF {
    FastScanner in;
    PrintWriter out;

    ArrayList<Integer>[] g;
    char[] res;

    int go(int v, int parent, char c, int needSz) {
        if (res[v] != 0) {
            return 0;
        }
        int sz = 1;
        for (int i = 0; i < g[v].size(); i++)
            if (g[v].get(i) != parent) {
                sz += go(g[v].get(i), v, c, needSz);
                if (sz < 0) {
                    return Integer.MIN_VALUE;
                }
            }
        if (sz >= needSz || parent == -1) {
            res[v] = c;
            for (int j = 0; j < g[v].size(); j++)
                if (res[g[v].get(j)] == 0)
                    go(g[v].get(j), -1, (char) (c + 1), needSz / 2);
            return Integer.MIN_VALUE;
        }
        return sz;
    }

    void solve() {
        //int n = 100000;
        int n = in.nextInt();
        g = new ArrayList[n];
        for (int i = 0; i < n; i++)
            g[i] = new ArrayList<>();
        for (int i = 0; i < n - 1; i++) {
            int fr = in.nextInt() - 1;
            int to = in.nextInt() - 1;
            //int fr = i;
            //int to = i + 1;
            g[fr].add(to);
            g[to].add(fr);
        }
        res = new char[n];
        go(0, -1, 'A', (int) 1e5);
        for (int i = 0; i < n; i++)
            if (res[i] > 'Z')
                throw new AssertionError();
        for (int i = 0; i < n; i++) {
            out.print(res[i] + " ");
        }
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