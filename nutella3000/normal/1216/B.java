import java.io.*;
import java.lang.reflect.Array;
import java.math.BigDecimal;
import java.math.MathContext;
import java.math.RoundingMode;
import java.util.*;


public class Main {
    static int inf = (int) 1e9 + 7;
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        int n = nextInt();
        pair a[] = new pair[n];
        for(int i = 0;i < n;i++) a[i] = new pair(nextInt(), i + 1);
        Arrays.sort(a, new pair());

        int ans = 0;

        for(int i = 0;i < n;i++) ans += a[i].x * i + 1;

        pw.println(ans);

        for(int i = 0;i < n;i++) pw.print(a[i].y + " ");
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

class pair implements Comparator<pair>{
    int x, y;
    pair(int x, int y) {
        this.x = x;
        this.y = y;
    }

    pair() {}

    @Override
    public int compare(pair o1, pair o2) {
        return -Integer.compare(o1.x, o2.x);
    }
}