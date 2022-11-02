import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {
    static int inf = (int) 1e9;
    static ArrayList<Integer> child[];
    static long sz[], dp1[], dp2[];
    static int n;
    static void build_tree(int v, int pr, ArrayList<Integer> gr[]) {
        sz[v] = 1;
        for(int i : gr[v]) {
            if (i == pr) continue;
            build_tree(i, v, gr);
            child[v].add(i);
            sz[v] += sz[i];
        }
    }
    static void dfs(int v) {
        for(int i : child[v]) dfs(i);
        long sum = 0;
        for(int i : child[v]) sum += dp1[i];
        dp1[v] = sum + sz[v];
        for(int i : child[v]) {
            dp2[v] = Math.max(dp2[v], sum - dp1[i] + dp2[i] + n - sz[i]);
        }
        if (child[v].isEmpty()) {
            dp2[v] = n;
        }
    }
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        n = nextInt();
        ArrayList<Integer> gr[] = new ArrayList[n];
        child = new ArrayList[n];
        for(int i = 0;i < n;i++) {
            gr[i] = new ArrayList<>();
            child[i] = new ArrayList<>();
        }
        sz = new long [n];
        dp1 = new long [n];
        dp2 = new long [n];
        for(int i = 0;i < n - 1;i++) {
            int v = nextInt() - 1;
            int u = nextInt() - 1;
            gr[v].add(u);
            gr[u].add(v);
        }
        build_tree(0,-1, gr);
        dfs(0);
        pw.println(dp2[0]);
        pw.close();
    }

    static BufferedReader br;
    static StringTokenizer st = new StringTokenizer("");

    public static int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    public static long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    public static double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }

    public static String next() throws IOException {
        if (!st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return st.nextToken();
    }
}