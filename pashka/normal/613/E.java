import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Random;
import java.util.StringTokenizer;

/**
 * @author Pavel Mavrin
 */
public class E {

    private static final long MOD = (long) (1e9 + 7);

    private void solve() throws IOException {
        String s1 = next();
        String s2 = next();
        String p = next();
        long res = calc(new String[]{s1, s2}, p);
        qfix = true;
        if (p.length() > 1)
            res += calc(new String[]{s1, s2}, reverse(p));
        while (res >= MOD) {
            res -= MOD;
        }
        out.println(res);
//        Random random = new Random();
//        while (true) {
//            int n = random.nextInt(10) + 1;
//            int m = random.nextInt(2 * n) + 1;
//            String s1 = randomString(random, n);
//            String s2 = randomString(random, n);
//            String p = randomString(random, m);
//            qfix = false;
//            long res = calc(new String[]{s1, s2}, p);
//            qfix = true;
//            if (p.length() > 1)
//                res += calc(new String[]{s1, s2}, reverse(p));
//            long res2 = 0;
//            boolean[] z1 = new boolean[n];
//            boolean[] z2 = new boolean[n];
//            for (int i = 0; i < n; i++) {
//                res2 += bt(s1, s2, p, z1, z2, i, 0);
//                res2 += bt(s2, s1, p, z2, z1, i, 0);
//            }
//            if (res2 != res) {
//                System.out.println(s1 + "\n" + s2 + "\n" + p + "\n" + res + " " + res2);
//                return;
//            } else {
//                System.out.println("!");
//            }
//        }
    }

    private long bt(String s1, String s2, String p, boolean[] z1, boolean[] z2, int i, int j) {
        if (s1.charAt(i) != p.charAt(j)) return 0;
        if (z1[i]) return 0;
        if (j == p.length() - 1) {
            return 1;
        }
        z1[i] = true;
        long res = 0;
        res += bt(s2, s1, p, z2, z1, i, j + 1);
        if (i > 0) {
            res += bt(s1, s2, p, z1, z2, i - 1, j + 1);
        }
        if (i < s1.length() - 1) {
            res += bt(s1, s2, p, z1, z2, i + 1, j + 1);
        }
        z1[i] = false;
        return res;
    }

    private String randomString(Random random, int n) {
        String res = "";
        for (int i = 0; i < n; i++) {
            res += (char) ('a' + random.nextInt(3));
        }
        return res;
    }

    private String reverse(String s) {
        return new StringBuffer(s).reverse().toString();
    }

    boolean qfix;

    private long calc(String[] s, String p) {
        boolean[][][] lp = new boolean[2][][];
        boolean[][][] rp = new boolean[2][][];
        lp[0] = getLp(s[0], s[1], p);
        lp[1] = getLp(s[1], s[0], p);
        rp[0] = reverse(getLp(reverse(s[0]), reverse(s[1]), reverse(p)));
        rp[1] = reverse(getLp(reverse(s[1]), reverse(s[0]), reverse(p)));

        int n = s[0].length();
        int m = p.length();
        long res = 0;
        long[][][] d = new long[2][n][m];
        for (int i = 0; i < n; i++) {
            if (!qfix) {
                if (lp[0][i][p.length()]) res++;
                if (lp[1][i][p.length()]) res++;
                if (rp[0][i][p.length()]) res++;
                if (rp[1][i][p.length()]) res++;
            }
            if (i < n - 1)
                for (int j = 4; j <= p.length(); j += 2) {
                    for (int q = 0; q < 2; q++) {
                        if (lp[q][i][j] && rp[q][i + 1][p.length() - j]) {
                            res++;
                        }
                    }
                }
            while (res >= MOD) {
                res -= MOD;
            }
            for (int j = 0; j < p.length(); j++) {
                for (int q = 0; q < 2; q++) {
                    if (s[q].charAt(i) == p.charAt(j)) {
                        if (j == 0) {
                            d[q][i][j] = 1;
                        } else {
                            if (j == 1)
                                d[q][i][j] = d[1 - q][i][j - 1];
                            else if (i > 0 && s[1 - q].charAt(i) == p.charAt(j - 1)) {
                                d[q][i][j] = d[1 - q][i - 1][j - 2];
                                if (lp[1 - q][i - 1][j - 1]) {
                                    d[q][i][j]++;
                                }
                            }
                            if (qfix && p.length() == 2)
                                d[q][i][j] = 0;
                            if (i > 0) {
                                d[q][i][j] += d[q][i - 1][j - 1];
                                if (lp[q][i - 1][j]) {
                                    d[q][i][j]++;
                                }
                                while (d[q][i][j] >= MOD) {
                                    d[q][i][j] -= MOD;
                                }
                            }
                        }
                        if (j == p.length() - 1) {
                            res += d[q][i][j];
                        }
                        if (i < s[q].length() - 1) {
                            if (rp[q][i + 1][p.length() - 1 - j]) {
                                res += d[q][i][j];
                            }
                        }
//                        if (res > 0) {
//                            System.out.println("!!!");
//                        }
                        while (res >= MOD) {
                            res -= MOD;
                        }
                    }
                }
            }
        }
//        System.out.println("!" + res);
        return res;

    }

    private boolean[][] getLp(String s1, String s2, String p) {
        int[][] lcp1 = getLcp(s1, p);
        int[][] lcp2 = reverse(getLcp(reverse(s2), p));
        boolean[][] res = new boolean[s1.length()][p.length() + 1];
        for (int i = 0; i < s1.length(); i++) {
            for (int j = 4; j <= p.length(); j += 2) {
                res[i][j] = lcp2[i][0] >= j / 2 && lcp1[i - j / 2 + 1][j / 2] >= j / 2;
            }
        }
        return res;
    }

    private int[][] reverse(int[][] q) {
        int i = 0;
        int j = q.length - 1;
        while (i < j) {
            int[] t = q[i];
            q[i] = q[j];
            q[j] = t;
            i++;
            j--;
        }
        return q;
    }

    private boolean[][] reverse(boolean[][] q) {
        int i = 0;
        int j = q.length - 1;
        while (i < j) {
            boolean[] t = q[i];
            q[i] = q[j];
            q[j] = t;
            i++;
            j--;
        }
        return q;
    }

    private int[][] getLcp(String s, String p) {
        int[][] res = new int[s.length()][p.length()];
        for (int i = s.length() - 1; i >= 0; i--) {
            for (int j = p.length() - 1; j >= 0; j--) {
                if (s.charAt(i) == p.charAt(j)) {
                    if (i < s.length() - 1 && j < p.length() - 1) {
                        res[i][j] = 1 + res[i + 1][j + 1];
                    } else {
                        res[i][j] = 1;
                    }
                }
            }
        }
        return res;
    }


    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st;
    PrintWriter out = new PrintWriter(System.out);

    String next() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return st.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    public static void main(String[] args) throws IOException {
        new E().run();
    }

    private void run() throws IOException {
        solve();
        out.close();
    }

}