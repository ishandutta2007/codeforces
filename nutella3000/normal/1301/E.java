import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;


public class Main {
    static int inf = (int) 1e9 + 7;
    static int n, m, q;
    static char h[][];
    static int sz[][];
    static sparse_table a;
    static void scan() throws IOException {
        n = sc.nextInt();
        m = sc.nextInt();
        q = sc.nextInt();
        h = new char[n][m];
        for(int i = 0;i < n;i++) h[i] = sc.next().toCharArray();
        sz = new int [n][m];
    }

    static boolean check(int x, int y) {
        return x >= 0 && y >= 0 && x < n && y < m;
    }

    static char sgn(int x, int y) {
        if (x >= 0 && y >= 0) return 'B';
        if (x >= 0) return 'Y';
        if (y >= 0) return 'G';
        return 'R';
    }

    static boolean check(int xc, int yc, int x, int y) {
        return check(x, y) && sgn(x - xc, y - yc) == h[x][y];
    }


    static boolean check(int xc, int yc, int s) {
        int x1 = xc - s;
        int y1 = yc - s;
        boolean q = true;
        for(int i = 0;i < 2 * s;i++) {
            q &= check(xc, yc, i + x1, y1);
            q &= check(xc, yc, i + x1, y1 + 2 * s - 1);
            q &= check(xc, yc, x1, i + y1);
            q &= check(xc, yc, x1 + 2 * s - 1, i + y1);
        }
        return q;
    }

    static void build_sz() {
        for(int xc = 0;xc < n;xc++) {
            for(int yc = 0;yc < m;yc++) {
                int s = 1;
                while (true) {
                    if (!check(xc, yc, s)) break;
                    s++;
                }
                sz[xc][yc] = s - 1;
            }
        }
    }

    static int get(int x1, int y1, int x2, int y2) {
        int l = 0;
        int r = 500;
        while(r - l > 1) {
            int mid = ((l + r) >> 1);
            if (a.get(x1 + mid, y1 + mid, x2 - mid + 1, y2 - mid + 1) >= mid) l = mid;
            else r = mid;
        }
        return l * l * 4;
    }

    static void solve() throws IOException {
        scan();
        build_sz();
        a = new sparse_table(sz);
        for(int i = 0;i < q;i++) {
            int ans = get(sc.nextInt() - 1, sc.nextInt() - 1, sc.nextInt() - 1, sc.nextInt() - 1);
            pw.println(ans);
        }
    }


    public static void main(String[] args) throws IOException {
        sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        solve();
        pw.close();
    }

    static Scanner sc;
    static PrintWriter pw;

    static class Scanner {
        BufferedReader br;
        StringTokenizer st = new StringTokenizer("");

        Scanner(InputStream in) throws FileNotFoundException {
            br = new BufferedReader(new InputStreamReader(in));
        }

        Scanner(String in) throws FileNotFoundException {
            br = new BufferedReader(new FileReader(in));
        }

        String next() throws IOException {
            while (!st.hasMoreTokens()) st = new StringTokenizer(br.readLine());
            return st.nextToken();
        }

        int nextInt() throws IOException {
            return Integer.parseInt(next());
        }

        long nextLong() throws IOException {
            return Long.parseLong(next());
        }

        double nextDouble() throws IOException {
            return Double.parseDouble(next());
        }
    }
}

class sparse_table {
    int log[] = new int [501];
    int n, m, log_n = 10, log_m = 10;
    int max[][][][];

    sparse_table(int sz[][]) {
        log[1] = 0;
        for(int i = 2;i <= 500;i++) log[i] = log[i / 2] + 1;
        n = sz.length;
        m = sz[0].length;
        max = new int [log_n][log_m][n][m];
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                max[0][0][i][j] = sz[i][j];
            }
        }

        for(int q = 0;q < log_n;q++) {
            for(int w = 0;w < log_m;w++) {
                if (q == 0 && w == 0) continue;
                for(int i = 0;i < n;i++) {
                    for(int j = 0;j < m;j++) {
                        int ans;
                        if (q == 0) {
                            ans = Math.max(max[q][w - 1][i][j],
                                    max[q][w - 1][i][Math.min(m - 1, j + (1 << (w - 1)))]);
                        }else{
                            ans = Math.max(max[q - 1][w][i][j],
                                    max[q - 1][w][Math.min(n - 1, i + (1 << (q - 1)))][j]);
                        }
                        max[q][w][i][j] = ans;
                    }
                }
            }
        }
    }

    int get(int x1, int y1, int x2, int y2) {
        if (y1 > y2 || x1 > x2) return 0;
        int log1 = log[x2 - x1 + 1];
        int log2 = log[y2 - y1 + 1];
        int ans1 = max[log1][log2][x1][y1];
        int ans2 = max[log1][log2][x2 - (1 << log1) + 1][y1];
        int ans3 = max[log1][log2][x1][y2 - (1 << log2) + 1];
        int ans4 = max[log1][log2][x2 - (1 << log1) + 1][y2 - (1 << log2) + 1];
        return Math.max(ans1, Math.max(ans2, Math.max(ans3, ans4)));
    }
}