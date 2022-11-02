import java.io.*;
import java.lang.reflect.Array;
import java.math.BigInteger;
import java.util.*;

public class Main {
    static Random rand = new Random();
    static long inf_l = (long) 1e18;
    static int inf_i = (int) 1e9;

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        int n = nextInt();
        int m = nextInt();
        int a[][] = new int [n][m];
        int b[][] = new int [n][m];
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) a[i][j] = nextInt();
        }
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) b[i][j] = nextInt();
        }
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                if (b[i][j] == 1) {
                    b[i][j] = 0;
                    a[i][j] = 1 - a[i][j];
                }
            }
        }
        boolean ans = true;
        for(int i = 0;i < n;i++) {
            int cnt = 0;
            for(int j = 0;j < m;j++) cnt += a[i][j];
            if (cnt % 2 == 1) ans = false;
        }
        for(int j = 0;j < m;j++) {
            int cnt = 0;
            for(int i = 0;i < n;i++) cnt +=a[i][j];
            if (cnt % 2 == 1) ans = false;
        }
        if (ans) pw.print("Yes");
        else pw.print("No");
        pw.close();
    }

    static BufferedReader br;
    static StringTokenizer st = new StringTokenizer("");

    static int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    static long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    static double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }

    static String next() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return st.nextToken();
    }
}
class pair implements Comparator<pair> {
    int a, b;

    pair(int x, int y) {
        a = x;
        b = y;
    }

    pair() {
    }

    @Override
    public int compare(pair o1, pair o2) {
        return Integer.compare(o1.a, o2.a) * 2 + Integer.compare(o1.b, o2.b);
    }
}