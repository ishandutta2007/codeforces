import java.io.*;
import java.lang.reflect.Array;
import java.util.*;

public class Main {
    static int inf = (int) 1e9 + 7;
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        //Scanner sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);

        int n = nextInt();
        double x[] = new double[n];
        double v[] = new double[n];
        for(int i = 0;i < n;i++) x[i] = nextInt();
        for(int i = 0;i < n;i++) v[i] = nextInt();

        double l = 0;
        double r = 1e9;
        double ans = 0;
        for(int iter = 0;iter < 100;iter++) {
            double m = (l + r) / 2;
            double ans1 = 0;
            double max1 = 0;
            double max2 = 0;
            for(int i = 0;i < n;i++) {
                double t = Math.abs(x[i] - m);
                double e = t / v[i];
                if (x[i] <= m && max1 < e) max1 = e;
                if (x[i] >= m && max2 < e) max2 = e;

                ans1 = Math.max(ans1, e);
            }
            if (max1 - max2 <= 0) l = m;
            else r = m;
            ans = ans1;
        }

        pw.println(ans)
        ;
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