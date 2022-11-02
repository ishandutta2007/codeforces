import java.io.*;
import java.lang.reflect.Array;
import java.util.*;
public class Main {
    static int inf = (int) 1e9 + 7;
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        int n = nextInt();
        int a[] = new int [n];
        for(int i = 0;i < n;i++) a[i] = nextInt();
        int min[] = new int [n];
        for(int i = 0;i < n;i++) min[i] = inf;
        for(int i = 1;i < n - 1;i++) {
            int dist = n - i - 1;
            int dist1 = i;
            min[dist] = Math.min(min[dist], Math.min(a[i], a[n - 1]));
            min[dist1] = Math.min(min[dist1], Math.min(a[i], a[0]));
        }
        min[n - 1] = Math.min(a[0], a[n - 1]);
        int l = -1;
        int r = 1312313331;
        while(l != r - 1) {
            int m = (l + r) / 2;
            boolean ll = true;
            for(int i = 0;i < n;i++) if (min[i] < m * i) ll = false;
            if (ll) l = m;
            else r = m;
        }
        pw.println(l);
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