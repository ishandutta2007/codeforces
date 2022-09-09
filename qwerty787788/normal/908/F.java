import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class A {
    private FastScanner in;
    private PrintWriter out;

    void solve() {
        int n = in.nextInt();
        int[] p = new int[n];
        char[] color = new char[n];
        for (int i = 0; i < n; i++) {
            p[i] = in.nextInt();
            color[i] = in.next().charAt(0);
        }
        String colors = "GRB";
        int[] first = new int[3];
        int[] last = new int[3];
        Arrays.fill(first, -1);
        Arrays.fill(last, -1);
        for (int i = 0; i < n; i++) {
            int id = colors.indexOf(color[i]);
            last[id] = i;
            if (first[id] == -1) {
                first[id] = i;
            }
        }
        if (first[0] == -1) {
            int res = 0;
            for (int it = 1; it < 3; it++) {
                if (first[it] != -1) {
                    res += p[last[it]] - p[first[it]];
                }
            }
            out.println(res);
        } else {
            char[] cc = "RB".toCharArray();
            long res = 0;
            for (int it = 1; it < 3; it++) {
                if (first[it] == -1) {
                    continue;
                }
                if (first[it] < first[0]) {
                    res += p[first[0]] - p[first[it]];
                }
                if (last[it] > last[0]) {
                    res += p[last[it]] - p[last[0]];
                }
            }
            for (int x = first[0]; x != last[0]; ) {
                int y = x + 1;
                while (color[y] != 'G') {
                    y++;
                }
                int len = p[y] - p[x];
                int minAns = len * 2;
                int ss = len;
                for (char c : cc) {
                    int prev = p[x];
                    int maxx = 0;
                    for (int z = x + 1; z <= y; z++) {
                        if (z == y || color[z] == c) {
                            maxx = Math.max(maxx, p[z] - prev);
                            prev = p[z];
                        }
                    }
                    ss += len - maxx;
                }
                minAns = Math.min(minAns, ss);
                res += minAns;
                x = y;
            }
            out.println(res);
        }

    }

    private void run() {
        try {
            in = new FastScanner(new File("A.in"));
            out = new PrintWriter(new File("A.out"));

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
        new A().runIO();
    }
}