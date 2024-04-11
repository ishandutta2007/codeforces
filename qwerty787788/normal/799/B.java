import java.io.*;
import java.util.*;

public class B {
    private FastScanner in;
    private PrintWriter out;

    class O implements Comparable<O> {
        int id, cost, c1, c2;

        public O(int id, int cost, int c1, int c2) {
            this.id = id;
            this.cost = cost;
            this.c1 = c1;
            this.c2 = c2;
        }

        @Override
        public int compareTo(O o) {
            if (cost != o.cost) {
                return Integer.compare(cost, o.cost);
            }
            return Integer.compare(id, o.id);
        }
    }

    private void solve() {
        int n = in.nextInt();
        int[] p = new int[n];
        int[] c1 = new int[n];
        int[] c2 = new int[n];
        for (int i = 0; i < n; i++) {
            p[i] = in.nextInt();
        }
        for (int i = 0; i < n; i++) {
            c1[i] = in.nextInt() - 1;
        }
        for (int i = 0; i < n; i++) {
            c2[i] = in.nextInt() - 1;
        }
        TreeSet<O>[] ts = new TreeSet[3];
        for (int i = 0; i < 3; i++) {
            ts[i] = new TreeSet<O>();
        }
        for (int i = 0; i < n; i++) {
            O o = new O(i, p[i], c1[i], c2[i]);
            ts[c1[i]].add(o);
            ts[c2[i]].add(o);
        }
        int m = in.nextInt();
        for (int i = 0; i < m; i++) {
            int color = in.nextInt() - 1;
            O o = ts[color].size() == 0 ? null : ts[color].pollFirst();
            if (o == null) {
                out.print("-1 ");
            } else {
                out.print(o.cost + " ");

                ts[o.c1].remove(o);
                ts[o.c2].remove(o);
            }
        }
        out.println();
    }

    private void run() {
        try {
            in = new FastScanner(new File("B.in"));
            out = new PrintWriter(new File("B.out"));

            solve();

            out.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    private void runIO() {
        in = new FastScanner(System.in);
        out = new PrintWriter(System.out);

        solve();

        out.close();
    }

    private class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        FastScanner(File f) {
            try {
                br = new BufferedReader(new FileReader(f));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        FastScanner(InputStream f) {
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
        new B().runIO();
    }
}