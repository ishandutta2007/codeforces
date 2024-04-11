import java.io.*;
import java.util.*;

public class Main {
    static int inf = (int) 1e9 + 7;
    static int n;
    static boolean gr[][];
    static int in[];
    static int ans = inf;
    static int start = -1;
    static void dfs(int v, int time, int pr) {
        in[v] = time;
        for(int to = 0;to < n;to++) {
            if (to == v || !gr[v][to] || to == pr) continue;
            if (to == start && time > 2) ans = Math.min(ans, time);
            if (in[to] <= time + 1) continue;
            dfs(to, time + 1, v);
        }
    }
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        n = nextInt();
        long temp[] = new long [n];
        int temp1 = 0;
        for(int i = 0;i < n;i++) {
            temp[i] = nextLong();
            if (temp[i] != 0) temp1++;
        }
        if (temp1 > 300) {
            pw.println(3);
        }else{
            n = temp1;
            long a[] = new long [n];
            int temp2 = 0;
            for(int i = 0;i < temp.length;i++) {
                if (temp[i] != 0) {
                    a[temp2] = temp[i];
                    temp2++;
                }
            }

            gr = new boolean[n][n];
            in = new int [n];
            for(int i = 0;i < n;i++) {
                for(int j = 0;j < n;j++) {
                    if ((a[i] & a[j]) != 0) gr[i][j] = true;
                }
            }
            for(int i = 0;i < n;i++) {
                for(int j = 0;j < n;j++) in[j] = inf;
                start = i;
                dfs(i, 1, -1);
            }
            if (ans == inf) pw.println(-1);
            else pw.println(ans);
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