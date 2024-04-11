import sun.reflect.generics.tree.Tree;

import java.io.*;
import java.lang.reflect.Array;
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
        ArrayList<Integer> v = new ArrayList<>();
        v.add(a[0].id * 2);
        for(int i = 1;i < n;i++) {
            v.add(a[i].id * 2);
            pw.println(a[i].id * 2 + " " + a[i - 1].id * 2);
        }

        for(int i = 0;i < n;i++) {
            pw.println(a[i].id * 2 - 1 + " " + v.get(i + a[i].x - 1));
            if (i + a[i].x - 1 == v.size() - 1) v.add(a[i].id * 2 - 1);
        }

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
    int x, id;
    pair(int x, int id) {
        this.x = x;
        this.id = id;
    }

    pair() {}

    @Override
    public int compare(pair o1, pair o2) {
        return -Integer.compare(o1.x, o2.x);
    }
}