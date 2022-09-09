import java.io.*;
import java.util.*;

public class A {
    FastScanner in;
    PrintWriter out;

    void solve() {
        int w = in.nextInt();
        int n = in.nextInt();
        int m = in.nextInt();
        int[] cnt = new int[1 << w];
        int[][] t = new int[1 << w][1 << w];
        for (int x = 0; x < t.length; x++) {
            for (int y = x; y < t.length; y++) {
                int value = 0;
                for (int bit = 0; bit < w; bit++) {
                    value = value * 3;
                    int z0 = (x >> bit) & 1;
                    int z1 = (y >> bit) & 1;
                    value += (z0 + z1);
                }
                t[x][y] = value;
                t[y][x] = value;
            }
        }
        int max3 = 1;
        for (int i = 0; i < w; i++) {
            max3 *= 3;
        }
        total = new int[max3];
        for (int i = 0; i < n; i++) {
            int var = in.nextInt();
            for (int prev = 0; prev < cnt.length; prev++) {
                int count = cnt[prev];
                if (count == 0) {
                    continue;
                }
                int mask = t[var][prev];
                total[mask] += count * 2;
            }
            total[t[var][var]]++;
            cnt[var]++;
        }
        String pattern = "AOXaox";
        int[][] pp = new int[][]{{0, 1}, {0}, {0, 2}, {2}, {1, 2}, {1}};
        for (int i = 0; i < m; i++) {
            char[] s = in.next().toCharArray();
            int[][] pos = new int[s.length][];
            for (int j = 0; j < s.length; j++) {
                pos[j] = pp[pattern.indexOf(s[s.length - 1 - j])];
            }
            p = pos;
            long sum = go(0, 0);
            out.println(sum);
        }
    }

    int[] total;
    int[][] p;

    long go(int pos, int value) {
        if (pos == p.length) {
            return total[value];
        }
        long r = 0;
        for (int i = 0; i < p[pos].length; i++) {
            r += go(pos + 1, value * 3 + p[pos][i]);
        }
        return r;
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