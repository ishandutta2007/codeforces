import java.io.*;
import java.util.*;

public class CF {
    FastScanner in;
    PrintWriter out;

    int[][] sum;
    int[][] was;

    int[] dx = { -1, 0, 0, 1 };
    int[] dy = { 0, -1, 1, 0 };
    int n, m;

    boolean inside(int x, int y) {
        return x >= 0 && x < n && y >= 0 && y < m;
    }

    boolean isOk(int x, int y, int[][] sum) {
        final int p = 4;
        for (int dx = -p; dx <= p; dx++) {
            int ych = p - Math.abs(dx);
            for (int dy = -ych; dy < ych; dy++) {
                if (x + dx < 0 || x + dx >= sum.length)
                    return false;
                if (y + dy < 0 || y + dy >= sum[0].length - 1)
                    return false;
                if (sum[x + dx][y + dy + 1] - sum[x + dx][y + dy] == 0)
                    return false;
            }
        }
        return true;
    }

    int getAns(int[][] sum) {
        int minX = Integer.MAX_VALUE;
        int minY = Integer.MAX_VALUE;
        int maxX = Integer.MIN_VALUE;
        int maxY = Integer.MIN_VALUE;
        for (int x = 0; x < sum.length; x++)
            for (int y = 0; y < sum[0].length; y++) {
                if (isOk(x, y, sum)) {
                    minX = Math.min(minX, x);
                    maxX = Math.max(maxX, x);
                    minY = Math.min(minY, y);
                    maxY = Math.max(maxY, y);
                }
            }
        //System.err.println(minX + " " + minY + " " + maxX + " " + maxY);
        int xc = (minX + maxX) / 2;
        int yc = (minY + maxY) / 2;
        int r1 = maxX - xc;
        int r2 = maxY - yc;
        r1 += 8;
        r2 += 8;
        final int DIV = 2000;
        double dalpha = Math.PI * 2 / DIV;
        double alpha = 0;
        boolean[] is = new boolean[DIV];
        for (int i = 0; i < DIV; i++) {
            int xx = (int) (xc + Math.cos(alpha) * r1);
            int yy = (int) (yc + Math.sin(alpha) * r2);
            if (xx >= 0 && xx < sum.length - 1)
                if (yy >= 0 && yy < sum[0].length - 1)
                    if (sum[xx][yy + 1] - sum[xx][yy] == 1) {
                        is[i] = true;
                    }
            alpha += dalpha;
        }
        int res = is[0] ? 1 : 0;
        for (int i = 1; i < DIV; i++) {
            if (is[i] && !is[i - 1])
                res++;
        }
        if (is[DIV - 1] && is[0])
            res--;
        return res;
    }

    void solve() {
        n = in.nextInt();
        m = in.nextInt();
        sum = new int[n][m + 1];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                sum[i][j + 1] = in.nextInt() + sum[i][j];
            }
        }
        was = new int[n][m];
        ArrayList<Integer> answer = new ArrayList<>();
        int color = 1;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                if (sum[i][j + 1] - sum[i][j] != 0) {
                    if (was[i][j] == 0) {
                        ArrayList<Integer> xx = new ArrayList<>();
                        ArrayList<Integer> yy = new ArrayList<>();
                        xx.add(i);
                        yy.add(j);
                        was[i][j] = color;
                        int it = 0;
                        int minX = Integer.MAX_VALUE;
                        int minY = Integer.MAX_VALUE;
                        int maxX = Integer.MIN_VALUE;
                        int maxY = Integer.MIN_VALUE;
                        while (it < xx.size()) {
                            int x = xx.get(it);
                            int y = yy.get(it);
                            minX = Math.min(minX, x);
                            minY = Math.min(minY, y);
                            maxX = Math.max(maxX, x);
                            maxY = Math.max(maxY, y);
                            for (int k = 0; k < 4; k++) {
                                if (inside(x + dx[k], y + dy[k]))
                                    if (sum[x + dx[k]][y + 1 + dy[k]]
                                            - sum[x + dx[k]][y + dy[k]] == 1) {
                                        if (was[x + dx[k]][y + dy[k]] == 0) {
                                            was[x + dx[k]][y + dy[k]] = color;
                                            xx.add(x + dx[k]);
                                            yy.add(y + dy[k]);
                                        }
                                    }
                            }
                            it++;
                        }
                        int hh = maxX - minX + 1;
                        int ww = maxY - minY + 1;
                        int[][] summ = new int[hh][ww + 1];
                        for (int ii = 0; ii < hh; ii++)
                            for (int jj = 0; jj < ww; jj++) {
                                summ[ii][jj + 1] = summ[ii][jj];
                                if (was[ii + minX][jj + minY] == color) {
                                    summ[ii][jj + 1]++;
                                }
                            }
                        answer.add(getAns(summ));
                        color++;
                    }
                }
            }
        out.println(answer.size());
        Collections.sort(answer);
        for (int x : answer) {
            out.print(x + " ");
        }
    }

    void run() {
        long st = System.currentTimeMillis();
        try {
            in = new FastScanner(new File("test.in"));
            out = new PrintWriter(new File("test.out"));

            solve();

            out.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
        long sp = System.currentTimeMillis() - st;
        System.err.println(sp);
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
    }

    public static void main(String[] args) {
        new CF().runIO();
    }
}