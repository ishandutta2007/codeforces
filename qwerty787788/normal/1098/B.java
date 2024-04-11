import java.io.*;
import java.util.*;

public class A {
    FastScanner in;
    PrintWriter out;

    class Solution {
        int diff;
        char[][] s;

        public Solution(int diff, char[][] s) {
            this.diff = diff;
            this.s = s;
        }
    }

    String str = "ACGT";

    Solution solve(char[][] a) {
        int n = a.length;
        int m = a[0].length;
        int[][][] cnt = new int[str.length()][2][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cnt[str.indexOf(a[i][j])][i & 1][j]++;
            }
        }
        Solution res = new Solution(Integer.MAX_VALUE, new char[n][m]);
        for (int mask = 0; mask < 1 << 4; mask++) {
            if (Integer.bitCount(mask) != 2) {
                continue;
            }
            int[][] chars = new int[2][2];
            int[] sz = new int[2];
            for (int i = 0; i < str.length(); i++) {
                if (((1 << i) & mask) != 0) {
                    chars[0][sz[0]++] = i;
                } else {
                    chars[1][sz[1]++] = i;
                }
            }
            int sum = 0;
            for (int i = 0; i < m; i++) {
                int cur = Math.max(cnt[chars[i & 1][0]][0][i] + cnt[chars[i & 1][1]][1][i], cnt[chars[i & 1][0]][1][i] + cnt[chars[i & 1][1]][0][i]);
                sum += cur;
            }
            sum = n * m - sum;
            if (sum < res.diff) {
                res.diff = sum;
                for (int i = 0; i < m; i++) {
                    int change = 0;
                    if (cnt[chars[i & 1][0]][0][i] + cnt[chars[i & 1][1]][1][i] < cnt[chars[i & 1][0]][1][i] + cnt[chars[i & 1][1]][0][i]) {
                        change = 1;
                    }
                    for (int j = 0; j < n; j++) {
                        res.s[j][i] = str.charAt(chars[i & 1][(j & 1) ^ change]);
                    }
                }
            }
        }
        return res;
    }

    void solve() {
        int n = in.nextInt();
        int m = in.nextInt();
        char[][] a = new char[n][];
        for (int i = 0; i < n; i++) {
            a[i] = in.next().toCharArray();
        }
        Solution s1 = solve(a);
        a = rev(a);
        Solution s2 = solve(a);
        if (s2.diff < s1.diff) {
            s1.s = rev(s2.s);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                out.print(s1.s[i][j]);
            }
            out.println();
        }
    }

    char[][] rev(char[][] a) {
        char[][] res = new char[a[0].length][a.length];
        for (int i = 0; i < a.length; i++) {
            for (int j = 0; j < a[0].length; j++) {
                res[j][i] = a[i][j];
            }
        }
        return res;
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