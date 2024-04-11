import java.io.*;
import java.lang.reflect.Array;
import java.util.*;

public class Main {
    static int inf = (int) 1e9 + 7;
    static int n, k;
    static boolean good[];
    static int cnt[];
    static ArrayList<Integer> gr[];
    static boolean used[];

    static void dfs1(int v) {
        if (used[v]) return;
        used[v] = true;
        for (int to : gr[v]) {
            dfs1(to);
            good[v] |= good[to];
        }
    }

    static ArrayList<Integer> ans = new ArrayList<>();

    static void dfs2(int v) {
        if (!good[v]) return;
        if (--cnt[v] > 0) return;
        ans.add(v);
        for (int i : gr[v]) {
            dfs2(i);
        }
    }

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        n = nextInt();
        k = nextInt();
        good = new boolean[n];
        cnt = new int[n];
        gr = new ArrayList[n];
        for (int i = 0; i < n; i++) gr[i] = new ArrayList<>();
        used = new boolean[n];
        for (int i = 0; i < k; i++) good[nextInt() - 1] = true;

        for (int i = 0; i < n; i++) {
            int c = nextInt();
            for (int j = 0; j < c; j++) {
                int to = nextInt() - 1;
                gr[to].add(i);
            }
            cnt[i] = c;
        }

        for (int i = 0; i < n; i++) dfs1(i);

        boolean var[] = new boolean[n];
        for (int i = 0; i < n; i++)
            if (cnt[i] == 0) var[i] = true;

        for (int i = 0; i < n; i++) {
            if (var[i]) dfs2(i);
        }

        int c = 0;
        for(int i = 0;i < n;i++) if (good[i]) c++;
        for(int i : ans) {
            if (good[i]) c--;
        }
        if (c == 0) {
            pw.println(ans.size());
            for(int i : ans) pw.print(i + 1 + " ");
        }else pw.println(-1);
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