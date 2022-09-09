import java.io.*;
import java.util.*;

public class CF {
    FastScanner in;
    PrintWriter out;

    ArrayList<Integer>[] g;
    boolean[] was;
    int myId;
    int height = -1;
    ArrayList<Integer> sort = new ArrayList<>();

    void go(int v) {
        was[v] = true;
        for (int x : g[v]) {
            if (!was[x])
                go(x);
        }
        sort.add(v);
    }

    ArrayList<Integer> heights = new ArrayList<>();

    void go2(int v, int h, boolean add) {
        was[v] = true;
        if (v == myId) {
            height = h;
            add = false;
        }
        for (int x : g[v])
            go2(x, h + 1, add);
        if (g[v].size() == 0 && add)
            heights.add(h + 1);
    }

    void solve() {
        int n = in.nextInt();
        myId = in.nextInt() - 1;
        int[] pr = new int[n];
        g = new ArrayList[n];
        for (int i = 0; i < n; i++)
            g[i] = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            pr[i] = in.nextInt();
            if (pr[i] != 0) {
                g[pr[i] - 1].add(i);
            }
        }
        was = new boolean[n];
        for (int i = 0; i < n; i++)
            if (!was[i])
                go(i);
        Arrays.fill(was, false);
        for (int i = n - 1; i >= 0; i--) {
            int id = sort.get(i);
            if (!was[id])
                go2(id, 0, true);
        }
        boolean[] canSum = new boolean[n + 1];
        canSum[0] = true;
        for (int z : heights) {
            for (int cur = n - 1; cur >= z; cur--) {
                if (canSum[cur - z])
                    canSum[cur] = true;
            }
        }
        for (int i = 0; i < n; i++)
            if (canSum[i]) {
                out.println(i + height + 1);
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

        long nextLong() {
            return Long.parseLong(next());
        }
    }

    public static void main(String[] args) {
        new CF().runIO();
    }
}