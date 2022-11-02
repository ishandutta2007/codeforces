
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
        int a = sc.nextInt();
        int b = sc.nextInt();
        if (a == b) {
            System.out.println(a + "0 " + b + "1");
            return;
        }
        if (a + 1 == b) {
            System.out.println(a + "9 " + b + "0");
            return;
        }
        if (a == 9 && b == 1) {
            System.out.println(9 + " " + 10);
            return;
        }
        pw.println(-1);
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