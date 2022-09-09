import java.io.*;
import java.util.*;

public class F {
    FastScanner in;
    PrintWriter out;

    void solve() {
        int n = in.nextInt();
        int m = in.nextInt();
        List<Edge>[] g = new List[n];
        for (int i = 0; i < n; i++) {
            g[i] = new ArrayList<>();
        }
        for (int i = 0; i < m; i++) {
            int fr = in.nextInt() - 1;
            int to = in.nextInt() - 1;
            g[fr].add(new Edge(to, (i + 1) + ""));
            g[to].add(new Edge(fr, (i + 1) + ""));
        }
        int root = getNode(0, 0, 0);
        int[] dp = new int[n];
        Arrays.fill(dp, -1);
        dp[0] = root;
        PriorityQueue<Node> pq = new PriorityQueue<>();
        pq.add(new Node(0, root));
        boolean[] was = new boolean[n];
        while (!pq.isEmpty()) {
            Node node = pq.poll();
            if (was[node.vertex]) {
                continue;
            }
            for (Edge e : g[node.vertex]) {
                if (!was[e.to]) {
                    int len = getNext(node.len, e.s);
                    if (dp[e.to] == -1 || cmp(len, dp[e.to]) < 0) {
                        dp[e.to] = len;
                        pq.add(new Node(e.to, len));
                    }
                }
            }
        }
        for (int i = 1; i < n; i++) {
            out.println(hash[dp[i]]);
        }
    }

    int getNext(int from, String s) {
        for (int i = 0; i < s.length(); i++) {
            int t = s.charAt(i) - '0';
            if (next[t][from] == -1) {
                next[t][from] = getNode(curH[from] + 1, from, t);
            }
            from = next[t][from];
        }
        return from;
    }

    class Node implements Comparable<Node> {
        int vertex, len;

        public Node(int vertex, int len) {
            this.vertex = vertex;
            this.len = len;
        }

        @Override
        public int compareTo(Node node) {
            return cmp(len, node.len);
        }
    }

    int cmp(int n1, int n2) {
        if (curH[n1] != curH[n2]) {
            return Integer.compare(curH[n1], curH[n2]);
        }
        return lca(n1, n2);
    }

    int lca(int x, int y) {
        for (int i = up.length - 1; i >= 0; i--) {
            if (up[i][x] != up[i][y]) {
                x = up[i][x];
                y = up[i][y];
            }
        }
        return Integer.compare(prev[x], prev[y]);
    }

    final int MAX = (int) 2e5 * 7;
    int[][] next = new int[10][MAX];
    int[] curH = new int[MAX];
    int[] hash = new int[MAX];
    final int mod = (int) 1e9 + 7;
    int[][] up = new int[18][MAX];
    int[] prev = new int[MAX];
    int nodes = 0;

    int getNode(int myHieght, int parent, int digit) {
        int ret = nodes++;
        curH[ret] = myHieght;
        hash[ret] = (int) ((hash[parent] * 10L + digit) % mod);
        prev[ret] = digit;
        for (int i = 0; i < 10; i++) {
            next[i][ret] = -1;
        }
        up[0][ret] = parent;
        for (int i = 1; i < up.length; i++) {
            up[i][ret] = up[i - 1][up[i - 1][ret]];
        }
        return ret;
    }

    class Edge {
        int to;
        String s;

        public Edge(int to, String s) {
            this.to = to;
            this.s = s;
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