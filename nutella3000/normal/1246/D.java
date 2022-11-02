
import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {
    static int inf = (int) 1e9 + 7;
    static int n;
    static ArrayList<Integer> gr[];
    static int ans[], id = 0;
    static int p[], dist[];
    static boolean bad[];

    static void dfs(int v) {
        ans[id++] = v;
        for(int i : gr[v]) {
            if (!bad[i]) dfs(i);
        }
        for(int i : gr[v]) {
            if (bad[i]) dfs(i);
        }
    }


    public static void main(String[] args) throws IOException {
        sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        n = sc.nextInt();
        gr = new ArrayList[n];
        p = new int [n];
        dist = new int [n];
        bad = new boolean[n];

        for(int i = 0;i < n;i++) gr[i] = new ArrayList<>();
        for(int i = 1;i < n;i++) {
            p[i] = sc.nextInt();
            gr[p[i]].add(i);
            dist[i] = dist[p[i]] + 1;
        }

        int max = -1;
        int v = -1;
        for(int i = 0;i < n;i++) {
            if (dist[i] > max) {
                max = dist[i];
                v = i;
            }
        }

        while(v != 0) {
            bad[v] = true;
            v = p[v];
        }


        ans = new int [n];
        id = 0;
        dfs(0);


        ArrayList<Integer> ans1 = new ArrayList<>();
        id = 1;
        dsu a = new dsu(n);
        for(int i = 2;i < n;i++) {
            while(true) {
                if (p[ans[i]] == ans[id]) {
                    id = i;
                    break;
                }
                a.union(id, id - 1);
                id = a.get(id);
                ans1.add(ans[i]);
            }
        }

        for(int i : ans) pw.print(i + " ");
        pw.println();
        pw.println(ans1.size());
        for(int i : ans1) pw.print(i + " ");
        pw.close();
    }

    static Scanner sc;
    static PrintWriter pw;

    static class Scanner {
        BufferedReader br;
        StringTokenizer st = new StringTokenizer("");

        Scanner(InputStream in) throws FileNotFoundException {
            br = new BufferedReader(new InputStreamReader(in));
        }

        Scanner(String in) throws FileNotFoundException {
            br = new BufferedReader(new FileReader(in));
        }

        String next() throws IOException {
            while (!st.hasMoreTokens()) st = new StringTokenizer(br.readLine());
            return st.nextToken();
        }

        int nextInt() throws IOException {
            return Integer.parseInt(next());
        }

        long nextLong() throws IOException {
            return Long.parseLong(next());
        }

        double nextDouble() throws IOException {
            return Double.parseDouble(next());
        }
    }
}

class dsu {
    int parent[];
    dsu(int n) {
        parent = new int [n];
        for(int i = 0;i < n;i++) parent[i] = i;
    }

    int get(int v) {
        if (v == parent[v]) return v;
        return parent[v] = get(parent[v]);
    }

    void union(int v1, int v2) {
        parent[get(v1)] = get(v2);
    }
}