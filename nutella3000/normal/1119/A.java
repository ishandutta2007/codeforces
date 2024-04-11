import java.io.*;
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
        int a[] = new int [n];
        for(int i = 0;i < n;i++) a[i] = nextInt();
        int ans = 0;
        for(int i = n - 1;i >= 0;i--) {
            if (a[i] != a[0]) {
                ans = i;
                break;
            }
        }
        int f = n - ans;
        for(int i = 1;i < f;i++) {
            if (a[i] != a[0]) {
                ans = n - i - 1;
                break;
            }
        }
        pw.print(ans);
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