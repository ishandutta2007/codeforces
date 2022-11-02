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
        long a[] = new long [n];
        for(int i = 0;i < n;i++) a[i] = nextLong();
        Arrays.sort(a);
        long b[] = new long [n - 1];
        for(int i = 0;i < n - 1;i++) b[i] = a[i + 1] - a[i];
        Arrays.sort(b);
        long pref[] = new long [n - 1];
        if (n > 1) pref[0] = b[0];
        for(int i = 1;i < n - 1;i++) pref[i] = b[i] + pref[i - 1];

        int q = nextInt();
        for(int i = 0;i < q;i++) {
            long l = nextLong();
            long r = nextLong();
            int left = -1;
            int right = n - 1;
            while(right - left > 1) {
                int mid = (left + right) / 2;
                if (b[mid] < r - l + 1) left = mid;
                else right = mid;
            }
            long ans = (n - right) * (r - l + 1) + (left < 0 ? 0 : pref[left]);
            pw.print(ans + " ");
        }
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