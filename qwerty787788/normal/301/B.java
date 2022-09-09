import java.io.*;
import java.util.*;

public class CF {
    FastScanner in;
    PrintWriter out;

    class Road implements Comparable<Road> {
        int to;
        long energy;

        public Road(int to, long energy) {
            super();
            this.to = to;
            this.energy = energy;
        }

        @Override
        public int compareTo(Road arg0) {
            return -Long.compare(energy, arg0.energy);
        }

    }

    void solve() throws IOException {
        int n = in.nextInt();
        int d = in.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n - 2; i++) {
            a[i + 1] = in.nextInt();
        }
        int[] x = new int[n];
        int[] y = new int[n];
        for (int i = 0; i < n; i++) {
            x[i] = in.nextInt();
            y[i] = in.nextInt();
        }
        int l = 0, r = 4 * (int) 1e7 + 100;
        while (r - l > 1) {
            int me = (l + r) / 2;
            boolean[] was = new boolean[n];
            long[] cost = new long[n];
            Arrays.fill(cost, -1);
            cost[0] = me;
            PriorityQueue<Road> pq = new PriorityQueue<>();
            pq.add(new Road(0, me));
            while (pq.size() > 0) {
                Road ro = pq.remove();
                was[ro.to] = true;
                if (cost[ro.to] > ro.energy)
                    continue;
                if (ro.energy == 0)
                    continue;
                for (int i = 0; i < n; i++) {
                    if (!was[i]) {
                        long newCost = ro.energy
                                - d
                                * (Math.abs(x[i] - x[ro.to]) + Math.abs(y[i]
                                        - y[ro.to]));
                        if (newCost >= 0)
                            newCost += a[i];
                        if (newCost > cost[i]) {
                            pq.add(new Road(i, newCost));
                            cost[i] = newCost;
                        }
                    }
                }
            }
            if (cost[n - 1] >= 0) {
                r = me;
            } else {
                l = me;
            }
        }
        out.println(r);
    }

    void run() throws IOException {
        try {
            in = new FastScanner(new File("test.in"));
            out = new PrintWriter(new File("test.out"));

            solve();

            out.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    void runIO() throws IOException {
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

    public static void main(String[] args) throws IOException {
        new CF().runIO();
    }
}