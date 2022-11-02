import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;


public class Main {
    static int inf = (int) 1e9 + 7;
    static int n, d, a[];
    static ArrayList<Integer> gr[];

    static long dfs(int v, int pr, int start) {
        int min = a[start];
        long ans = 1;
        for(int to : gr[v]) {
            if (to == pr) continue;
            if (a[to] < min || a[to] > min + d) continue;
            if (a[to] == min && to < start) continue;
            ans = ans * (dfs(to, v, start) + 1) % inf;
        }

        return ans;
    }

    static void scan() throws IOException {
        d = sc.nextInt();
        n = sc.nextInt();
        a = new int [n];
        gr = new ArrayList[n];
        for(int i = 0;i < n;i++) gr[i] = new ArrayList<>();
        for(int i = 0;i < n;i++) a[i] = sc.nextInt();
        for(int i = 0;i < n - 1;i++) {
            int v1 = sc.nextInt() - 1;
            int v2 = sc.nextInt() - 1;
            gr[v1].add(v2);
            gr[v2].add(v1);
        }
    }

    static void solve() throws IOException {
        scan();
        long ans = 0;
        for(int i = 0;i < n;i++) {
            ans += dfs(i, -1, i);
        }

        pw.println(ans % inf);
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