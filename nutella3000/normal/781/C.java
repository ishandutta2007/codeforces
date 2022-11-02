import java.io.*;
import java.lang.reflect.Array;
import java.util.*;

public class Main {
    static int inf = (int) 1e9 + 7;
    static int n, k;
    static ArrayList<Integer> gr[], ans[];
    static int id = 0;
    static boolean used[];

    static int dfs(int v, int st) {
        if (st == (2 * n + k - 1) / k + 1) {
            id++;
            st = 1;
        }
        used[v] = true;
        ans[id].add(v + 1);
        for(int i : gr[v]) {
            if (!used[i]) {
                st = dfs(i, st + 1);
                if (st == (2 * n + k - 1) / k + 1) {
                    id++;
                    st = 1;
                }

                ans[id].add(v + 1);
            }
        }

        return st + 1;
    }

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        n = nextInt();
        int m = nextInt();
        k = nextInt();
        gr = new ArrayList[n];
        ans = new ArrayList[n];
        for(int i = 0;i < n;i++) {
            gr[i] = new ArrayList<>();
            ans[i] = new ArrayList<>();
        }
        used = new boolean[n];
        dsu var = new dsu(n);
        for(int i = 0;i < m;i++) {
            int v1 = nextInt() - 1;
            int v2 = nextInt() - 1;
            if (var.get(v1) != var.get(v2)) {
                gr[v1].add(v2);
                gr[v2].add(v1);
                var.union(v1, v2);
            }
        }

        dfs(0, 1);

        while(id < k) {
            if (ans[id].isEmpty()) ans[id].add(1);
            id++;
        }

        for(int i = 0;i < k;i++) {
            pw.print(ans[i].size() + " ");
            for(int j : ans[i]) pw.print(j + " ");
            pw.println();
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

class dsu {
    int parent[];
    dsu (int n) {
        parent = new int [n];
        for(int i = 0;i < n;i++) parent[i] = i;
    }

    int get(int v) {
        if (v == parent[v]) return v;
        return parent[v] = get(parent[v]);
    }

    void union(int a, int b) {
        parent[get(a)] = get(b);
    }
}