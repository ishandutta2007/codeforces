import java.io.*;
import java.lang.reflect.Array;
import java.util.*;
public class Main {
    static int inf = (int) 1e9 + 7;
    static int xr[] = new int []{1, 0, 0, -1};
    static int yr[] = new int []{0, -1, 1, 0};
    static char dir[] = new char[]{'D', 'L', 'R', 'U'};
    static int n, m;

    static boolean check(int x, int y) {
        return x >= 0 && y >= 0 && x < n && y < m;
    }

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        n = nextInt();
        m = nextInt();
        int k = nextInt();
        if (k % 2 == 1) {
            System.out.println("IMPOSSIBLE");
            return;
        }
        char a[][] = new char[n][m];
        for(int i = 0;i < n;i++) a[i] = next().toCharArray();
        int s_x = 0;
        int s_y = 0;
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                if (a[i][j] == 'X') {
                    s_x = i;
                    s_y = j;
                }
            }
        }
        boolean bad = true;
        for(int i = 0;i < 4;i++) {
            pair to = new pair(xr[i] + s_x, yr[i] + s_y);
            if (check(to.x, to.y) && a[to.x][to.y] != '*') bad = false;
        }

        if (bad) {
            System.out.println("IMPOSSIBLE");
            return;
        }

        int dp[][] = new int [n][m];

        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) dp[i][j] = inf;
        }
        dp[s_x][s_y] = 0;

        Deque<pair> bfs = new ArrayDeque<>();
        bfs.add(new pair(s_x, s_y));

        while(!bfs.isEmpty()) {
            pair v = bfs.pollFirst();
            for(int i = 0;i < 4;i++) {
                pair to = new pair(xr[i] + v.x, yr[i] + v.y);

                if (!check(to.x, to.y) || a[to.x][to.y] == '*') continue;

                if (dp[to.x][to.y] > dp[v.x][v.y] + 1) {
                    dp[to.x][to.y] = dp[v.x][v.y] + 1;
                    bfs.add(new pair(to.x, to.y));
                }
            }
        }

        int v_x = s_x;
        int v_y = s_y;

        while(k != 0) {
            for(int i = 0;i < 4;i++) {
                pair to = new pair(v_x + xr[i], v_y + yr[i]);
                if (!check(to.x, to.y) || a[to.x][to.y] == '*' || dp[to.x][to.y] > k - 1) continue;
                pw.print(dir[i]);
                k--;
                v_x = to.x;
                v_y = to.y;
                break;
            }
        }

        pw.close();
    }

    static BufferedReader br;
    static StringTokenizer st = new StringTokenizer("");
    static PrintWriter pw;

    static String next() throws IOException {
        while (!st.hasMoreTokens()) st = new StringTokenizer(br.readLine());
        return st.nextToken();
    }

    static int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    static long nextLong() throws IOException {
        return Long.parseLong(next());
    }
}

class pair {
    int x, y;
    pair(int x, int y) {
        this.x = x;
        this.y = y;
    }

    pair() {}

}