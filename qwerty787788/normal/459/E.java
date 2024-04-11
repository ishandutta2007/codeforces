import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class CF {
    FastScanner in;
    PrintWriter out;

    class Edge implements Comparable<Edge> {
        int fr, to, cost;

        public Edge(int fr, int to, int cost) {
            super();
            this.fr = fr;
            this.to = to;
            this.cost = cost;
        }

        @Override
        public int compareTo(Edge o) {
            return -Integer.compare(cost, o.cost);
        }

    }

    void solve() {
        int n = in.nextInt();
        int m = in.nextInt();
        Edge[] all = new Edge[m];
        for (int i = 0; i < m; i++) {
            int fr = in.nextInt() - 1;
            int to = in.nextInt() - 1;
            int cost = in.nextInt();
            all[i] = new Edge(fr, to, cost);
        }
        Arrays.sort(all);
        int[] ans1 = new int[n];
        int[] ans2 = new int[n];
        int answer = 0;
        for (int i = 0; i < m;) {
            int j = i;
            while (j != m && all[j].cost == all[i].cost)
                j++;
            for (int k = i; k < j; k++) {
                Edge e = all[k];
                ans2[e.fr] = Math.max(ans2[e.fr], ans1[e.to] + 1);
            }
            while (i != j) {
                Edge e = all[i++];
                ans1[e.fr] = ans2[e.fr];
                answer = Math.max(answer, ans1[e.fr]);
            }
        }
        out.println(answer);
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