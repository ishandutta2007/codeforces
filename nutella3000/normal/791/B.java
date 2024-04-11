import java.io.*;
import java.util.*;

public class Main {
    static int inf = (int) 1e9 + 7;

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        int n = nextInt();
        int m = nextInt();
        dsu a = new dsu(n);
        for(int i = 0;i < m;i++) {
            int v = nextInt() - 1;
            int to = nextInt() - 1;
            a.union(v, to);
        }

        boolean bad = false;
        for(int i = 0;i < n;i++) {
            if (a.parent[i] != i) continue;
            int ans = a.cnt[i];
            long q = (long)a.cnt1[i] * (a.cnt1[i] - 1) / 2;
            if (q != ans) bad = true;
        }

        if (bad) pw.println("NO");
        else pw.println("YES");
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
    int cnt[];
    int cnt1[];
    dsu(int n) {
        parent = new int [n];
        cnt = new int [n];
        for(int i = 0;i < n;i++) parent[i] = i;
        cnt1 = new int [n];
        for(int i = 0;i < n;i++) cnt1[i] = 1;
    }

    int get(int v) {
        if (parent[v] == v) return v;
        return parent[v] = get(parent[v]);
    }

    void union(int a, int b) {
        a = get(a);
        b = get(b);
        cnt[a]++;
        if (a != b) {
            cnt[b] += cnt[a];
            cnt1[b] += cnt1[a];
            parent[a] = b;
        }
    }

}