import java.io.*;
import java.lang.reflect.Array;
import java.util.*;


public class Main {
    static int inf = (int) 1e9 + 7;
    static int n, m;
    static dsu a;
    static int b[];
    static int c[];

    public static void main(String[] args) throws IOException {
        sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        n = sc.nextInt();
        m = sc.nextInt();
        a = new dsu(n);
        b = new int [n];
        c = new int [n];
        for(int i = 0;i < m;i++) {
            int v1 = sc.nextInt() - 1;
            int v2 = sc.nextInt() - 1;
            a.union(v1, v2);
        }
        for(int i = 0;i < n;i++) {
            c[i] = a.get(i);
            b[a.get(i)] = i;
        }
        int ans = 0;
        int r = -1;
        int num = 0;
        for(int i = 0;i < n;i++) {
            if (i > r) {
                r = b[c[i]];
                num = c[i];
            }else{

                if (b[c[i]] > r) {
                    r = b[c[i]];
                    if (num != a.get(c[i])) ans++;

                    a.union(num, c[i]);
                    num = a.get(c[i]);
                }else{
                    if (num != a.get(c[i])) {
                        ans++;
                        a.union(c[i], num);
                    }
                }

            }
        }
        pw.println(ans);
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