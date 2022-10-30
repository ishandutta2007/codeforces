import java.io.*;
import java.util.*;

public class Main {
    static int inf = (int) 1e9 + 7;

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        int n = nextInt();
        int m = nextInt();
        int a[][] = new int [n][m];
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                a[i][j] = -1;
            }
        }
        boolean have_ans = true;
        for(int i = 0;i < n;i++) {
            int v = nextInt();
            for(int j = 0;j < v;j++) {
                if (a[i][j] == 0) have_ans = false;
                a[i][j] = 1;
            }
            if (v < m) {
                if (a[i][v] == 1) have_ans = false;
                a[i][v] = 0;
            }
        }

        for(int j = 0;j < m;j++) {
            int v = nextInt();
            for(int i = 0;i < v;i++) {
                if (a[i][j] == 0) have_ans = false;
                a[i][j] = 1;
            }

            if (v < n) {
                if (a[v][j] == 1) have_ans = false;
                a[v][j] = 0;
            }
        }

        if (!have_ans) pw.println(0);
        else{
            int ans = 1;
            for(int i = 0;i < n;i++) {
                for(int j = 0;j < m;j++) {
                    if (a[i][j] == -1) {
                        ans = (ans * 2) % inf;
                    }
                }
            }
            pw.println(ans);
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

    static double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }
}