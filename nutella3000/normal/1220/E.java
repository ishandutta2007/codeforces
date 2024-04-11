import java.io.*;
import java.util.*;


public class Main {
    static int inf = (int) (1e9 + 7);
    static int n;
    static ArrayList<Integer> gr[];
    static int deg[];
    static boolean bad[], taked[];
    static int w[];

    static boolean go_good(int v, int pr) {
        if (!bad[v]) return true;
        taked[v] = true;
        for(int to : gr[v]) {
            if (to == pr) continue;
            if (go_good(to, v)) return true;
        }
        taked[v] = false;
        return false;
    }

    static long max = 0;
    static void go_bad(int v, int pr, long ans) {
        if (!taked[v]) ans += w[v];
        max = Math.max(max, ans);
        for(int to : gr[v]) {
            if (to != pr && bad[to]) go_bad(to, v, ans);
        }
    }

    static void solve() throws IOException {
        n = sc.nextInt();
        int m = sc.nextInt();
        gr = new ArrayList[n];
        for(int i = 0;i < n;i++) gr[i] = new ArrayList<>();
        deg = new int [n];
        bad = new boolean[n];
        taked = new boolean[n];
        w = new int [n];

        for(int i = 0;i < n;i++) w[i] = sc.nextInt();

        for(int i = 0;i < m;i++) {
            int v1 = sc.nextInt() - 1;
            int v2 = sc.nextInt() - 1;
            gr[v1].add(v2);
            gr[v2].add(v1);
            deg[v1]++;
            deg[v2]++;
        }

        ArrayDeque<Integer> temp = new ArrayDeque<>();
        for(int i = 0;i < n;i++) if (deg[i] == 1) temp.add(i);

        while(!temp.isEmpty()) {
            int v = temp.pollFirst();
            deg[v] = 0;
            bad[v] = true;
            for(int to : gr[v]) {
                deg[to]--;
                if (deg[to] == 1) temp.add(to);
            }
        }

        int s = sc.nextInt() - 1;
        boolean qq = go_good(s, -1);

        if (qq) {
            for (int i = 0; i < n; i++) {
                if (!bad[i]) continue;
                int good = -1;
                for (int j : gr[i]) {
                    if (!bad[j]) {
                        good = j;
                    }
                }
                if (good != -1) go_bad(i, -1, 0);
            }

        }else {
            go_bad(s, -1, 0);
        }

        long all_ans = max;

        for(int i = 0;i < n;i++) {
            if (taked[i] || !bad[i]) all_ans += w[i];
        }

        pw.println(all_ans);
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