import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;


public class Main {
    static int inf = (int) 1e9 + 7;
    static int n, a[], b[];
    static ArrayList<Integer> gr[];
    static ArrayList<edge> e;
    static int s, f;
    static boolean used[];

    static boolean dfs(int v, int k) {
        if (v == f) return true;
        if (used[v]) return false;
        used[v] = true;
        for(int i : gr[v]) {
            int to = e.get(i).to;
            int f = e.get(i).f;
            int c = e.get(i).c;
            if (c - f < k) continue;
            if (dfs(to, k)) {
                edge temp1 = new edge(to, f + k, c);
                edge temp2 = new edge(e.get(i ^ 1).to, e.get(i ^ 1).f - k, e.get(i ^ 1).c);
                e.set(i, temp1);
                e.set(i ^ 1, temp2);
                return true;
            }
        }
        return false;
    }

    static void flow() {
        int k = inf;
        while(k != 0) {
            while(dfs(s, k)) {
                for (int i = 0; i < 2 * n + 2; i++) used[i] = false;
            }
            for (int i = 0; i < 2 * n + 2; i++) used[i] = false;
            k /= 2;
        }
    }

    static void add_edge(int v, int to, int c) {
        gr[v].add(e.size());
        e.add(new edge(to, 0, c));

        gr[to].add(e.size());
        e.add(new edge(v, 0, 0));
    }

    static void scan() throws IOException {
        n = sc.nextInt();
        int m = sc.nextInt();
        a = new int [n];
        b = new int [n];
        gr = new ArrayList[2 * n + 2];
        e = new ArrayList<>();
        used = new boolean[2 * n + 2];

        for(int i = 0;i < 2 * n + 2;i++) gr[i] = new ArrayList<>();
        for(int i = 0;i < n;i++) a[i] = sc.nextInt();
        for(int i = 0;i < n;i++) b[i] = sc.nextInt();


        s = 2 * n;
        f = 2 * n + 1;
        for(int i = 0;i < n;i++) {
            add_edge(s, i, a[i]);
        }

        for(int i = 0;i < n;i++) {
            add_edge(i + n, f, b[i]);
        }

        for(int i = 0;i < n;i++) {
            add_edge(i, i + n, inf);
        }

        for(int i = 0;i < m;i++) {
            int v1 = sc.nextInt() - 1;
            int v2 = sc.nextInt() - 1;

            add_edge(v1, v2 + n, inf);
            add_edge(v2, v1 + n, inf);
        }
    }

    static void solve() throws IOException {
        scan();
        flow();
        boolean bad = false;
        for(int i = 0;i < 4 * n;i+= 2) if (e.get(i).f != e.get(i).c) bad = true;

        if (bad) pw.println("NO");
        else{
            pw.println("YES");
            int ans[][] = new int [n][n];
            for(int i = 0;i < n;i++) {
                for(int j : gr[i]) {
                    if (e.get(j).f > 0) ans[i][e.get(j).to - n] = e.get(j).f;
                }
            }
            for(int i = 0;i < n;i++) {
                for(int j = 0;j < n;j++) pw.print(ans[i][j] + " ");
                pw.println();
            }
        }
    }

    public static void main(String[] args) throws IOException {
        sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        solve();
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

class edge {
    int to, f, c;

    edge(int to, int f,int c) {
        this.to = to;
        this.f = f;
        this.c = c;
    }

    edge() {}
}