import java.io.*;
import java.util.*;

public class A {
    FastScanner in;
    PrintWriter out;

    void solve() {
        int n = in.nextInt();
        int m = in.nextInt();
        int k = in.nextInt();
        int[] fr = new int[m];
        int[] to = new int[m];
        List<Integer>[] g = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            g[i] = new ArrayList<>();
        }
        for (int i = 0; i < m; i++) {
            fr[i] = in.nextInt() - 1;
            to[i] = in.nextInt() - 1;
            g[fr[i]].add(i);
            g[to[i]].add(i);
        }
        boolean[] can = new boolean[n];
        Arrays.fill(can, true);
        int[] cntNeigh = new int[n];
        List<Integer> toRemove = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            cntNeigh[i] = g[i].size();
            if (cntNeigh[i] < k) {
                toRemove.add(i);
                can[i] = false;
            }
        }
        int res = n;
        int[] f = new int[m];
        for (int i = m - 1; i >= 0; i--) {
            while (toRemove.size() > 0) {
                int v = toRemove.get(toRemove.size() - 1);
                toRemove.remove(toRemove.size() - 1);
                res--;
                for (int id : g[v]) {
                    if (id > i) {
                        break;
                    }
                    int toC = fr[id] + to[id] - v;
                    if (can[toC]) {
                        cntNeigh[toC]--;
                        if (cntNeigh[toC] < k) {
                            toRemove.add(toC);
                            can[toC] = false;
                        }
                    }
                }
            }
            f[i] = res;
            if (can[fr[i]] && can[to[i]]) {
                for (int v : new int[]{fr[i], to[i]}) {
                    cntNeigh[v]--;
                    if (cntNeigh[v] < k && can[v]) {
                        can[v] = false;
                        toRemove.add(v);
                    }
                }
            }
        }
        for (int x : f) {
            out.println(x);
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