import java.io.*;
import java.lang.reflect.Array;
import java.util.*;

public class Main {
    static int inf = (int) 1e9 + 7;
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        int n = nextInt();
        point a[] = new point[n];
        for(int i = 0;i < n;i++) a[i] = new point(nextInt(), nextInt());
        int m = nextInt();
        point b[] = new point[m];
        for(int i = 0;i < m;i++) b[i] = new point(nextInt(), nextInt());

        int ans = 0;

        int max = -1;
        int min = inf;
        for(int i = 0;i < n;i++) max = Math.max(max, a[i].l);
        for(int i = 0;i < m;i++) min = Math.min(min, b[i].r);
        ans = Math.max(0, max - min);
        max = -1;
        min = inf;
        for(int i = 0;i < n;i++) min = Math.min(min, a[i].r);
        for(int i = 0;i < m;i++) max = Math.max(max, b[i].l);
        ans = Math.max(ans, max - min);
        pw.println(ans);
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

class point {
    int l, r;
    point(int l, int r) {
        this.l = l;
        this.r = r;
    }

}