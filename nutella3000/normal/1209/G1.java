import java.io.*;
import java.util.*;


public class Main {
    static int inf = (int) 1e9 + 7;

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        int n = nextInt();
        int q = nextInt();
        int max_n = 200_001;
        int a[] = new int [n];
        int l[] = new int [max_n];
        int r[] = new int [max_n];
        for(int i = 0;i < max_n;i++) l[i] = inf;
        for(int i = 0;i < n;i++) {
            a[i] = nextInt();
            if (l[a[i]] == inf) l[a[i]] = i;
            r[a[i]] = i;
        }
        int ans = n;
        TreeMap<Integer, Integer> b = new TreeMap<>();
        int max_r = 0;
        int max_num = 0;
        for(int i = 0;i < n;i++) {
            max_r = Math.max(max_r, r[a[i]]);
            if (!b.containsKey(a[i])) b.put(a[i], 0);
            b.put(a[i], b.get(a[i]) + 1);
            if (max_num < b.get(a[i])) max_num = b.get(a[i]);
            if (max_r == i) {
                ans -= max_num;
                max_num = 0;
                b.clear();
            }

        }

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

class pair implements Comparator<pair>{
    int x, y;
    pair(int x, int y) {
        this.x = x;
        this.y = y;
    }

    pair() {}

    @Override
    public int compare(pair o1, pair o2) {
        return Integer.compare(o1.x, o2.x);
    }
}