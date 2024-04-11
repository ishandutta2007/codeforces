import java.io.*;
import java.util.*;

public class Main {
    static int inf = (int) 1e9 + 7;

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        int n = nextInt();
        int a[] = new int [n];
        for(int i = 0;i < n;i++) a[i] = nextInt();
        int max_num = 10000010;
        dsu next = new dsu(max_num);
        int prev[] = new int [max_num];
        for(int i = 1;i < max_num;i++) {
            for(int j = i * 2;j < max_num;j += i) {
                prev[j] = i;
            }
        }

        boolean good = false;

        for(int i = 0;i < n;i++) {
            int v = 2;
            if (!good) v = a[i];

            int new_num = next.get(v);
            pw.print(new_num + " ");
            if (new_num > a[i]) good = true;
            while(new_num != 1) {
                int d = new_num / prev[new_num];
                new_num = prev[new_num];
                for(int j = d;j < max_num - 1;j+= d) {
                    next.union(j, j + 1);
                }
            }
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

    static double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }
}

class dsu {
    int parent[];
    dsu(int n) {
        parent = new int[n];
        for(int i = 0;i < n;i++) parent[i] = i;
    }

    int get(int v) {
        int p = v;
        while(v != parent[v]) v = parent[v];
        while(p != v) {
            int t = parent[p];
            parent[p] = v;
            p = t;
        }
        return v;
    }

    void union(int o1, int o2) {
        parent[o1] = o2;
    }
}