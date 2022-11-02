import java.io.*;
import java.lang.reflect.Array;
import java.util.*;

public class Main {
    static int inf = (int) 1e9 + 7;
    static int n;
    static ArrayList<Integer> gr[];
    static int col[];
    static void dfs(int v, int cl, int pr) {
        int v_cl = 1;

        for(int i : gr[v]) {
            if (cl == v_cl) v_cl++;
            if (v_cl == col[v]) v_cl++;
            if (cl == v_cl) v_cl++;
            if (pr == i) continue;
            col[i] = v_cl++;
            dfs(i, col[v], v);
        }
    }

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        n = nextInt();
        gr = new ArrayList[n];
        for(int i = 0;i < n;i++) gr[i] = new ArrayList<>();
        for(int i = 0;i < n - 1;i++) {
            int v1 = nextInt() - 1;
            int v2 = nextInt() - 1;
            gr[v1].add(v2);
            gr[v2].add(v1);
        }
        col = new int [n];
        col[0] = 1;
        dfs(0, 0, -1);
        int ans = 0;
        for(int i = 0;i < n;i++) ans = Math.max(ans, col[i]);
        pw.println(ans);
        for(int i = 0;i < n;i++) pw.print(col[i] + " ");
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

class polygon {
    int x[], sz, id;

    polygon(int a[], int id) {
        x = a;
        sz = a.length;
        this.id = id;
    }
}