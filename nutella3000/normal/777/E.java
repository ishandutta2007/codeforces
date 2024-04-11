import java.io.*;
import java.util.*;
public class Main {
    static int inf = (int) 1e9 + 7;

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        int n = nextInt();
        ring a[] = new ring[n];
        segment_tree b = new segment_tree(n);
        for(int i = 0;i < n;i++) a[i] = new ring(nextInt(), nextInt(), nextInt());
        Arrays.sort(a, new ring());


        for(int i = 0;i < n;i++) {
            int l = -1;
            int r = i;
            while(r - l > 1) {
                int m = ((l + r) >> 1);
                if (a[m].b <= a[i].a) l = m;
                else r = m;
            }

            b.set(i, b.get(r, i - 1) + a[i].h);
        }

        pw.println(b.get(0, n - 1));
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

class ring implements Comparator<ring>{
    int a, b, h;
    ring(int a, int b, int h) {
        this.a = a;
        this.b = b;
        this.h = h;
    }

    ring() {}

    @Override
    public int compare(ring o1, ring o2) {
        return Integer.compare(o1.b, o2.b) * 2 + Integer.compare(o1.a, o2.a);
    }
}

class segment_tree {
    long max[];
    int last;

    segment_tree(int n) {
        last = n - 1;
        max = new long [n * 4];
    }

    void set(int id, long x) {
        set(1, 0, last, id, x);
    }

    void set(int v, int l, int r, int id, long x) {
        if (l > id || r < id) return;
        if (l == id && r == id) {
            max[v] = x;
            return;
        }

        int m = ((l + r) >> 1);
        set(v * 2, l, m, id, x);
        set(v * 2 + 1, m + 1, r, id, x);
        max[v] = Math.max(max[v * 2], max[v * 2 + 1]);
    }

    long get(int l, int r) {
        return get(1, 0, last, l, r);
    }

    long get(int v, int l, int r, int left, int right) {
        if (l > right || r < left) return 0;
        if (l >= left && r <= right) return max[v];

        int m = ((l + r) >> 1);
        return Math.max(get(v * 2, l, m, left, right), get(v * 2 + 1, m + 1, r, left, right));
    }
}