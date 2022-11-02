
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
        for(int test = sc.nextInt();test > 0;test--) {
            int n = sc.nextInt();
            int k = sc.nextInt();
            int d = sc.nextInt();
            int ans = inf;
            TreeMap<Integer, Integer> a = new TreeMap<>();
            int b[] = new int [n];
            for(int i = 0;i < d;i++) {
                int v = sc.nextInt();
                b[i] = v;
                if (!a.containsKey(v)) a.put(v, 0);
                a.put(v, a.get(v) + 1);
            }
            ans = a.size();
            for(int i = d;i < n;i++) {
                b[i] = sc.nextInt();
                int v = b[i];
                a.put(b[i - d], a.get(b[i - d]) - 1);
                if (a.get(b[i - d]) == 0) a.remove(b[i - d]);

                if (!a.containsKey(b[i])) a.put(b[i], 0);
                a.put(b[i], a.get(b[i]) + 1);
                ans = Math.min(ans, a.size());
            }

            pw.println(ans);

        }
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