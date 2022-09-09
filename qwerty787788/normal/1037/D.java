import java.io.*;
import java.util.*;

public class A {
    FastScanner in;
    PrintWriter out;

    List<Integer>[] g;
    int[] h;
    int[] prev;

    void go(int v, int p, int curH) {
        h[v] = curH;
        prev[v] = p;
        for (int to : g[v]) {
            if (to == p) {
                continue;
            }
            go(to, v, curH + 1);
        }
    }

    void solve() {
        int n = in.nextInt();
        g = new List[n];
        for (int i = 0; i < n; i++) {
            g[i] = new ArrayList<>();
        }
        for (int i = 0; i + 1 < n; i++) {
            int fr = in.nextInt() - 1;
            int to = in.nextInt() - 1;
            g[fr].add(to);
            g[to].add(fr);
        }
        h = new int[n];
        prev = new int[n];
        go(0, -1, 0);
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt() - 1;
        }
        final String no = "No";

        int[] pos = new int[n];
        for (int i = 0; i < n; i++) {
            pos[a[i]] = i;
        }
        for (int i = 1; i < n; i++) {
            if (h[a[i]] < h[a[i - 1]]) {
                out.println(no);
                return;
            }
            if (h[a[i]] == h[a[i - 1]]) {
                if (pos[prev[a[i]]] < pos[prev[a[i - 1]]]) {
                    out.println(no);
                    return;
                }
            }
        }
        out.println("Yes");
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