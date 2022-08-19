import java.io.*;
import java.util.*;

public class Template implements Runnable {
    private void solve() throws IOException {
        int t = nextInt();
        for (int it = 0; it < t; ++it) {
            int n = nextInt();
            int m = nextInt();
            String[] a = new String[n + 2];
            StringBuilder b = new StringBuilder();
            for (int i = 0; i < m + 2; ++i)
                b.append("0");
            a[0] = b.toString();
            a[n + 1] = a[0];
            for (int i = 0; i < n; ++i) {
                a[i + 1] = "0" + nextToken() + "0";
            }
            n += 2;
            m += 2;
            int[][][][] am = new int[2][n][m][9];
            for (int what = 0; what < 2; ++what) {
                for (int dr = -1; dr <= 1; ++dr)
                    for (int dc = -1; dc <= 1; ++dc)
                        if (dr != 0 || dc != 0) {
                            int sr = 0;
                            int er = n;
                            int br = 1;
                            if (dr == 1) {
                                sr = n - 1;
                                er = -1;
                                br = -1;
                            }
                            int sc = 0;
                            int ec = m;
                            int bc = 1;
                            if (dc == 1) {
                                sc = m - 1;
                                ec = -1;
                                bc = -1;
                            }
                            int dir = (dr + 1) * 3 + (dc + 1);
                            for (int r = sr; r != er; r += br)
                                for (int c = sc; c != ec; c += bc) {
                                    if (a[r].charAt(c) != '0' + what)
                                        continue;
                                    int nr = r + dr;
                                    int nc = c + dc;
                                    int prev = 0;
                                    if (nr >= 0 && nr < n && nc >= 0 && nc < m)
                                        prev = am[what][nr][nc][dir];
                                    am[what][r][c][dir] = prev + 1;
                                }
                        }
            }
            int res = 0;
            for (int r = 1; r < n - 1; ++r)
                for (int c = 1; c < m - 1; ++c) {
                    int side = am[1][r][c][5]; // right
                    if (side >= 2) {
                        if (
                            am[1][r][c][7] >= side
                            && am[1][r + side - 1][c][5] >= side
                            && am[1][r][c + side - 1][7] >= side
                            && am[0][r - 1][c - 1][5] >= side + 2
                            && am[0][r - 1][c - 1][7] >= side + 2
                            && am[0][r + side][c - 1][5] >= side + 2
                            && am[0][r - 1][c + side][7] >= side + 2
                            && am[0][r + 1][c + 1][5] >= side - 2
                            && am[0][r + 1][c + 1][7] >= side - 2
                            && am[0][r + side - 2][c + 1][5] >= side - 2
                            && am[0][r + 1][c + side - 2][7] >= side - 2) {
                            ++res;
                        }
                    }
                    side = am[1][r][c][2]; // up-right
                    if (side >= 2) {
                        if (am[1][r - side + 1][c + side - 1][8] >= side
                            && am[1][r][c][8] >= side
                            && am[1][r + side - 1][c + side - 1][2] >= side
                            && am[0][r][c - 1][2] >= side + 1
                            && am[0][r][c + 1][2] >= side - 1
                            && am[0][r][c - 1][8] >= side + 1
                            && am[0][r][c + 1][8] >= side - 1
                            && am[0][r - 1][c - 1][2] >= side
                            && am[0][r + 1][c - 1][8] >= side
                            && am[0][r][c + 2][2] >= side - 2
                            && am[0][r][c + 2][8] >= side - 2
                            && am[0][r][c + 2 * side - 2 + 1][0] >= side + 1
                            && am[0][r][c + 2 * side - 2 - 1][0] >= side - 1
                            && am[0][r][c + 2 * side - 2 + 1][6] >= side + 1
                            && am[0][r][c + 2 * side - 2 - 1][6] >= side - 1
                            && am[0][r - 1][c + 2 * side - 2 + 1][0] >= side
                            && am[0][r + 1][c + 2 * side - 2 + 1][6] >= side
                            && am[0][r][c + 2 * side - 2 - 2][0] >= side - 2
                            && am[0][r][c + 2 * side - 2 - 2][6] >= side - 2) {
                            ++res;
                        }
                    }
                }
            writer.println(res);
        }
    }


    public static void main(String[] args) {
        new Template().run();
    }

    BufferedReader reader;
    StringTokenizer tokenizer;
    PrintWriter writer;

    public void run() {
        try {
            reader = new BufferedReader(new InputStreamReader(System.in));
            tokenizer = null;
            writer = new PrintWriter(System.out);
            solve();
            reader.close();
            writer.close();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

    int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    String nextToken() throws IOException {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(reader.readLine());
        }
        return tokenizer.nextToken();
    }
}