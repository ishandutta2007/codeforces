import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;


public class Main {
    static int inf = (int) 1e9 + 7;
    static int n, color[];
    static ArrayList<Integer> gr[];

    static boolean dfs(int v, int pr, int col) {
        if (color[v] == col) return false;
        if (color[v] != 0) return true;
        color[v] = col;
        for(int to : gr[v]) {
            if (to == pr) continue;
            if (dfs(to, v, col ^ 1)) return true;
        }
        return false;
    }

    static void solve() throws IOException {
        n = sc.nextInt();
        color = new int [n];
        gr = new ArrayList[n];
        for(int i = 0;i < n;i++) gr[i] = new ArrayList<>();
        int m = sc.nextInt();

        if (m == 0) {
            System.out.println(3 + " " + (long) n * (n - 1) * (n - 2) / 6);
            return;
        }

        for(int i = 0;i < m;i++) {
            int v1 = sc.nextInt() - 1;
            int v2 = sc.nextInt() - 1;
            gr[v1].add(v2);
            gr[v2].add(v1);
        }

        int temp = 2;
        for(int i = 0;i < n;i++) {
            if (color[i] != 0) continue;
            if (dfs(i, -1, temp)) {
                System.out.println(0 + " " + 1);
                return;
            }
            temp += 2;
        }

        long cnt[] = new long [2 * n];
        for(int i = 0;i < n;i++) cnt[color[i]]++;
        long ans = 0;
        for(int i = 0;i < 2 * n;i++) ans += cnt[i] * (cnt[i] - 1) / 2;

        if (ans != 0) {
            System.out.println(1 + " " + ans);
        }else System.out.println(2 + " " + (long)m * (n - 2));

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

class pair {
    long x, y;
    pair(long x, long y) {
        this.x = x;
        this.y = y;
    }

    pair() {}
}