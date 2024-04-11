import java.io.*;
import java.util.*;

public class Main {
    static PrintWriter pw;
    static int n;
    static int parent[];
    static boolean all_one[];
    static int c[];
    static ArrayList<Integer> gr[];
    static ArrayList<Boolean> gr1[];
    static boolean dfs(int v) {
        boolean ans = true;
        for(int i : gr[v]) ans &= dfs(i);
        if (c[v] == 0) ans = false;
        all_one[v] = ans;
        return c[v] == 1;
    }
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        n = nextInt();
        parent = new int [n];
        c = new int [n];
        all_one = new boolean[n];
        gr = new ArrayList[n];
        gr1 = new ArrayList[n];
        for(int i = 0;i < n;i++) {
            gr[i] = new ArrayList<>();
            gr1[i] = new ArrayList<>();
        }
        int root = 0;
        for(int i = 0;i < n;i++) {
            parent[i] = nextInt() - 1;
            c[i] = nextInt();
            if (parent[i] == -2) {
                parent[i]++;
                root = i;
            }else{
             gr[parent[i]].add(i);
            }
        }
        dfs(root);
        ArrayList<Integer> ans = new ArrayList<>();
        for(int i = 0;i < n;i++) {
            if (all_one[i] == true) ans.add(i + 1);
        }
        Collections.sort(ans);
        for(int i = 0;i < ans.size();i++) pw.print(ans.get(i) + " ");
        if (ans.size() == 0) pw.print(-1);
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