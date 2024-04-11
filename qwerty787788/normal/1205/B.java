import java.io.*;
import java.util.*;

public class A {
    FastScanner in;
    PrintWriter out;

    void solve() {
        List<Long> a = new ArrayList<>();
        final int M = 62;
        int[] cnt = new int[M];
        int aLen = in.nextInt();
        for (int i = 0; i < aLen; i++) {
            long v = in.nextLong();
            if (v == 0) {
                continue;
            }
            a.add(v);
            for (int j = 0; j < M; j++) {
                if (((1L << j) & v) != 0) {
                    cnt[j]++;
                }
            }
        }
        for (int i = 0; i < M; i++) {
            if (cnt[i] >= 3) {
                out.println(3);
                return;
            }
        }
        int n = a.size();
        if (n > M * 2) {
            throw new AssertionError();
        }
        int res = Integer.MAX_VALUE;
        int[] dist = new int[n];
        int[] prev = new int[n];
        int[] q = new int[n];
        for (int start = 0; start < n; start++) {
            Arrays.fill(dist, Integer.MAX_VALUE);
            Arrays.fill(prev, -1);
            dist[start] = 0;
            q[0] = start;
            int qIt = 0, qSz = 1;
            while (qIt < qSz) {
                int v = q[qIt++];
                for (int u = 0; u < n; u++) {
                    if (prev[v] == u || u == v) {
                        continue;
                    }
                    if ((a.get(u) & a.get(v)) == 0) {
                        continue;
                    }
                    if (dist[u] == Integer.MAX_VALUE) {
                        dist[u] = dist[v] + 1;
                        prev[u] = v;
                        q[qSz++] = u;
                    } else {
                        res = Math.min(res, dist[u] + dist[v] + 1);
                    }
                }
            }
        }
        out.println(res == Integer.MAX_VALUE ? -1 : res);
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