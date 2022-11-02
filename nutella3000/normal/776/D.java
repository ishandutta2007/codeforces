import java.io.*;
import java.util.*;

public class Main {
    static int inf = (int) 1e9 + 7;
    static int to1[][];
    static ArrayList<Integer> to2[];
    static int n, m;
    static boolean open[], used[];
    static boolean start_opens[];

    static boolean dfs(int v) {
        for (int i : to1[v]) {
            if (used[i]) continue;
            used[i] = true;
            if (!open[v]) {
                for (int j : to2[i]) {
                    open[j] = !open[j];
                }

            }
            for (int j : to2[i]) {
                if (!dfs(j)) return false;
            }
        }
        return open[v];
    }

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        n = nextInt();
        m = nextInt();
        open = new boolean[n];
        used = new boolean[m];
        start_opens = new boolean[n];

        to1 = new int[n][2];
        to2 = new ArrayList[m];
        for (int i = 0; i < m; i++) to2[i] = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            int v = nextInt();
            open[i] = v == 1;
            start_opens[i] = v == 1;
            to1[i][0] = -1;
        }

        for (int i = 0; i < m; i++) {
            for (int cnt = nextInt(); cnt > 0; cnt--) {
                int v = nextInt() - 1;
                to2[i].add(v);
                if (to1[v][0] == -1) to1[v][0] = i;
                else to1[v][1] = i;
            }
        }

        for (int i = 0; i < n; i++) {
            if (open[i]) continue;
            //used[to1[i][1]] = true;
            if (!dfs(i)) {
                for (int j = 0; j < m; j++) {
                    used[j] = false;
                }
                for (int j = 0; j < n; j++) open[j] = start_opens[j];

                used[to1[i][0]] = true;
                if (!dfs(i)) {
                    System.out.println("NO");
                    return;
                }
            }

            //break;
        }

        System.out.println("YES");
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