import java.io.*;
import java.util.*;


public class Main {
    static long inf = (long) 1e15 + 7;

    static int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }


    public static void main(String[] args) throws IOException {
        sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        int n = sc.nextInt();
        long a[] = new long [n];
        int id = -1;
        for(int i = 0;i < n;i++) {
            a[i] = sc.nextInt();
            if (a[i] == -1) {
                id = i;
                a[id] = inf;
            }

            if (id == -1) a[i] = 0;
        }

        long dp[][] = new long [n][20];
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < 20;j++) dp[i][j] = inf;
        }


        for(int i = 0;i < n;i++) {
            for(int j = 0;j < 20;j++) {
                if (i == id) {
                    if (i == 0) dp[i][j] = inf;
                    else dp[i][j] = dp[i - 1][j];
                }else{
                    int cnt = i + 1;
                    if (i > id) cnt--;

                    if ((1 << (j + 1)) - 1 > cnt) dp[i][j] = inf;

                    else{
                        if (i == 0) dp[i][j] = a[i];
                        else if (j == 0) {
                            dp[i][j] = Math.min(a[i], dp[i - 1][j]);

                        }else dp[i][j] = Math.min(a[i] + dp[i - 1][j - 1], dp[i - 1][j]);
                    }
                }
            }
        }

        for(int i = 0;i < 20;i++) {
            if (dp[n - 1][i] >= inf) {
                id = i - 1;
                break;
            }
        }

        pw.println(dp[n - 1][id]);

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

class mine implements Comparator<mine>{
    int l, r, x;
    mine(int l, int r, int x) {
        this.l = l;
        this.r = r;
        this.x = x;
    }

    mine() {}

    @Override
    public int compare(mine o1, mine o2) {
        return -Integer.compare(o1.x, o2.x);
    }
}

class dsu {
    int parent[];
    dsu(int n) {
        parent = new int [n];
        for(int i = 0;i < n;i++) parent[i] = i;
    }

    int get(int v) {
        if (parent[v] == v) return v;
        return parent[v] = get(parent[v]);
    }

    void union(int v1, int v2) {
        v1 = get(v1);
        v2 = get(v2);
        parent[v1] = v2;
    }

}