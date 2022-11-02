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
            for(int j = 0;j < m;j++) a[i][j] = nextInt();
        }
        int r[] = new int [n];
        int rig[] = new int [m];
        for(int i = n - 1; i >= 0;i--) {
            for(int j = 0;j < m;j++) {
                if (i == n - 1 || a[i][j] > a[i + 1][j]) rig[j] = i;
                r[i] = Math.max(r[i], rig[j]);
            }
        }

        for(int k = nextInt();k > 0;k--) {
            int l = nextInt() - 1;
            int re = nextInt() - 1;
            if (r[l] >= re) pw.println("Yes");
            else pw.println("No");
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