import java.io.*;
import java.util.*;

public class CF {
    FastScanner in;
    PrintWriter out;

    class Vertex implements Comparable<Vertex> {
        int id, dist;

        Vertex(int id, int dist) {
            this.id = id;
            this.dist = dist;
        }

        @Override
        public int compareTo(Vertex arg0) {
            return Integer.compare(dist, arg0.dist);
        }
    }

    void solve() {
        int n = in.nextInt();
        int k = in.nextInt();
        Vertex[] a = new Vertex[n];
        for (int i = 0; i < n; i++)
            a[i] = new Vertex(i + 1, in.nextInt());
        Arrays.sort(a);
        ArrayList<Integer>[] g = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            g[i] = new ArrayList<>();
        }
        if (a[0].dist != 0) {
            out.println(-1);
            return;
        }
        int it = 0;
        for (int i = 1; i < n; i++) {
            while (a[it].dist + 1 < a[i].dist || g[it].size() >= k)
                it++;
            if (a[it].dist + 1 != a[i].dist) {
                out.println(-1);
                return;
            }
            {
                g[it].add(i);
                g[i].add(it);
            }
        }
        out.println(n - 1);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < g[i].size(); j++)
                if (a[i].id < a[g[i].get(j)].id)
                    out.println(a[i].id + " " + (a[g[i].get(j)].id));
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