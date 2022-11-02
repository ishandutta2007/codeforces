import java.io.*;
import java.lang.reflect.Array;
import java.util.*;

public class Main {
    static int inf = (int) 1e9 + 7;
    static long binpow(long a, long b) {
        long ans = 1;
        while(b > 0) {
            if ((b & 1) == 1) ans = (ans * a) % inf;
            a = (a * a) % inf;
            b /= 2;
        }
        return ans;
    }

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        int n = nextInt();
        int ans[] = new int [n * n];
        for(int i = 0;i < n * n;i++) {
            ans[i] = i % n;
            if (i + n < n * n) ans[i + n] = n - 1 - (i % n);
            if (i % n == n - 1) i += n;
        }

        int a[][] = new int [n][n];
        int id[] = new int [n];
        for(int i = 0;i < n * n;i++) {
            a[ans[i]][id[ans[i]]++] = i + 1;
        }
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < n;j++) {
                pw.print(a[i][j] + " ");
            }
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