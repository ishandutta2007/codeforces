import java.io.*;
import java.lang.reflect.Array;
import java.util.*;

public class Main {
    static int inf = 998244353;

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        int a = nextInt();
        int b = nextInt();
        int ans = 1;
        for(int i = 0;i < a + b;i++) {
            ans = (ans << 1) % inf;
        }
        pw.println(ans);
        pw.close();
    }

    static BufferedReader br;

    static StringTokenizer st = new StringTokenizer("");
    static PrintWriter pw;
    /*static String next() throws IOException {
        int c = br.read();
        while (Character.isWhitespace(c)) c = br.read();
        StringBuilder sb = new StringBuilder();
        while (!Character.isWhitespace(c)) {
            sb.appendCodePoint(c);
            c = br.read();
        }
        return sb.toString();
    }*/

    static String next() throws IOException {
        if (!st.hasMoreTokens()) st = new StringTokenizer(br.readLine());
        return st.nextToken();
    }

    static int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    static long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    static Double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }
}

class ball implements Comparator<ball>{
    int in, out;
    ball(int in, int out) {
        this.in = in;
        this.out = out;
    }
    ball() {}

    @Override
    public int compare(ball o1, ball o2) {
        return Integer.compare(o1.in, o2.in);
    }
}

class pair {
    int x, y;
    pair(int a, int b) {
        x = a;
        y = b;
    }
    pair() {}
}

class segment_tree {
    static int mod  = (int) 1e9 + 7;
    int min[], sum[], last;
    segment_tree(int n) {
        last = n - 1;
        min = new int [n * 4];
        sum = new int [n * 4];
        for(int i = 0;i < n * 4;i++) min[i] = mod;
    }

    void set(pair a, int id) {
        set(0, 0, last, a, id);
    }

    void set(int v, int l, int r, pair a, int id) {
        if (l > id || r < id) return;
        if (l == id && r == id) {
            min[v] = a.x;
            sum[v] = a.y;
            return;
        }
        int m = ((l + r) >> 1);
        set(v * 2 + 1, l, m, a, id);
        set(v * 2 + 2, m + 1, r, a, id);
        min[v] = Math.min(min[v * 2 + 1], min[v * 2 + 2]);
        sum[v] = 0;
        if (min[v * 2 + 1] == min[v]) sum[v] += sum[v * 2 + 1];
        if (min[v * 2 + 2] == min[v]) sum[v] += sum[v * 2 + 2];
        if (sum[v] >= mod) sum[v] -= mod;
    }

    int get_sum(int l) {
        return get_sum(0, 0, last, get_min(l), l);
    }

    int get_min(int l) {
        return get_min(0, 0, last, l);
    }

    int get_min(int v, int l, int r, int left) {
        if (r < left) return mod;
        if (l >= left) return min[v];
        int m = ((l + r) >> 1);
        return Math.min(get_min(v * 2 + 1, l, m, left), get_min(v * 2 + 2, m + 1, r, left));
    }

    int get_sum(int v, int l, int r, int min_c, int left) {
        if (r < left) return 0;
        if (l >= left) return min[v] == min_c ? sum[v] : 0;
        int m = ((l + r) >> 1);
        return (get_sum(v * 2 + 1, l, m, min_c, left) + get_sum(v * 2 + 2, m + 1, r, min_c, left)) % mod;
    }

}