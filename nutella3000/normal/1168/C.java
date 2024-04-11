import java.io.*;
import java.lang.reflect.Array;
import java.math.BigInteger;
import java.util.*;

public class Main {
    static int inf = (int) 1e9 + 7;

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        int n = nextInt();
        int q = nextInt();
        int a[] = new int [n];
        for(int i = 0;i < n;i++) a[i] = nextInt();
        int id[][] = new int [n][21];
        int min[][] = new int [21][21];
        for(int i = 0;i < 21;i++) {
            for(int j = 0;j < 21;j++) min[i][j] = inf;
        }
        for(int i = n - 1;i >= 0;i--) {
            for(int j = 0;j < 21;j++) {
                int min_ans = inf;
                for(int k = 0;k < 21;k++) {
                    if ((a[i] & (1 << k)) == 0) continue;
                    if (k == j) min_ans = i;
                    min_ans = Math.min(min_ans,min[k][j]);
                }
                id[i][j] = min_ans;
            }
            for(int k = 0;k < 21;k++) {
                if ((a[i] & (1 << k)) == 0) continue;
                for(int j = 0;j < 21;j++) min[k][j] = Math.min(min[k][j], id[i][j]);
            }
        }
        for(int i = 0;i < q;i++) {
            int l = nextInt() - 1;
            int r = nextInt() - 1;
            boolean can = false;
            for(int j = 0;j < 21;j++) {
                if ((a[r] & (1 << j)) == 0) continue;
                if (id[l][j] <= r) can = true;
            }
            if (can) pw.println("Shi");
            else pw.println("Fou");
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