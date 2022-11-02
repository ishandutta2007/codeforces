import java.io.*;
import java.lang.reflect.Array;
import java.util.*;

public class Main {
    static int inf = (int) 1e9 + 7;

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        int n = nextInt();
        int b[] = new int [n];
        for(int i = 0;i < n;i++) b[i] = nextInt();
        segment_tree a = new segment_tree(b);
        int q = nextInt();
        for(int i = 0;i < q;i++) {
            int t = nextInt();
            if (t == 1) {
                int p = nextInt() - 1;
                int x = nextInt();
                a.set(x, p);
            }else a.set2(nextInt());
        }
        for(int i = 0;i < n;i++) pw.print(a.get(i) + " ");
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

class segment_tree {
    int min[], last;
    segment_tree(int a[]) {
        int n = a.length;
        last = n - 1;
        min = new int [n * 4];
        build(0, 0, last, a);
    }

    void build(int v, int l, int r, int a[]) {
        if (l == r) {
            min[v] = a[l];
            return;
        }
        int m = ((l + r) >> 1);
        build(v * 2 + 1, l, m, a);
        build(v * 2 + 2, m + 1, r, a);
        min[v] = Math.min(min[v * 2 + 1], min[v * 2 + 2]);
    }

    void set(int x, int id) {
        set(0, 0, last, x, id);
    }
    void set(int v, int l, int r, int x, int id) {
        if (l > id || r < id) return;
        if (l == id && r == id) {
            min[v] = x;
            return;
        }
        int m = ((l + r) >> 1);
        min[v * 2 + 1] = Math.max(min[v], min[v * 2 + 1]);
        min[v * 2 + 2] = Math.max(min[v], min[v * 2 + 2]);
        set(v * 2 + 1, l, m, x, id);
        set(v * 2 + 2, m + 1, r, x, id);
        min[v] = Math.min(min[v * 2 + 1], min[v * 2 + 2]);
    }

    void set2(int x) {
        min[0] = Math.max(min[0], x);
    }

    int get(int id) {
        return get(0, 0, last, id);
    }
    int get(int v, int l, int r, int id) {
        if (l > id || r < id) return 1000000001;
        if (l == id && r == id) return min[v];
        int m = ((l + r) >> 1);
        min[v * 2 + 1] = Math.max(min[v], min[v * 2 + 1]);
        min[v * 2 + 2] = Math.max(min[v], min[v * 2 + 2]);
        return Math.min(get(v * 2 + 1, l, m, id), get(v * 2 + 2, m + 1, r, id));
    }
}