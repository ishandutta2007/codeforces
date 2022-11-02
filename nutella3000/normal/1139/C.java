import java.io.*;
import java.util.*;
public class Main {
    static ArrayList<Integer> gr[];
    static boolean used[];
    static int cnt = 0;
    static public void dfs(int v) {
        if (used[v]) return;
        used[v] = true;
        cnt++;
        for(int i : gr[v]) {
            dfs(i);
        }
    }
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        int n = nextInt();
        int k = nextInt();
        gr = new ArrayList[n];
        used = new boolean [n];
        for(int i = 0;i < n;i++) gr[i] = new ArrayList<>();
        for(int i = 0;i < n - 1;i++) {
            int v = nextInt() - 1;
            int u = nextInt() - 1;
            int c = nextInt();
            if (c == 1) continue;
            gr[v].add(u);
            gr[u].add(v);
        }
        long ans = n;
        int st = 1;
        int mod = (int) 1e9 + 7;
        while(st != k) {
            ans = (ans * n) % mod;
            st++;
        }
        for(int i = 0;i < n;i++) {
            if (!used[i]) {
                cnt = 0;
                dfs(i);
                st = 1;
                long u = cnt;
                while(st != k) {
                    u = (u * cnt) % mod;
                    st++;
                }
                ans -= u;
            }
        }
        pw.println((ans % mod + mod) % mod);
        pw.close();
    }

    static BufferedReader br;
    static StringTokenizer st = new StringTokenizer("");

    public static int nextInt() throws IOException {
        if (!st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return Integer.parseInt(st.nextToken());
    }

    public static long nextLong() throws IOException {
        if (!st.hasMoreTokens()) {
            st = new StringTokenizer((br.readLine()));
        }
        return Long.parseLong(st.nextToken());
    }

    public static double nextDouble() throws IOException {
        if (!st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return Double.parseDouble(st.nextToken());
    }

    public static String next() throws IOException {
        if (!st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return st.nextToken();
    }
}