import java.io.*;
import java.util.*;


public class Main {
    static int inf = (int) (1e9 + 7);
    static int n;
    static ArrayList<edge> gr[];
    static int used[];
    static int col[];

    static void dfs(int v) {
        used[v] = 1;
        for(edge to : gr[v]) {
            if (used[to.to] == 1) {
                col[to.id] = 2;
            }else {
                col[to.id] = 1;
                if (used[to.to] == 0) dfs(to.to);
            }
        }
        used[v] = 2;
    }

    static void solve() throws IOException {
        n = sc.nextInt();
        int m = sc.nextInt();
        gr = new ArrayList[n];
        for(int i = 0;i < n;i++) gr[i] = new ArrayList<>();
        used = new int[n];
        col = new int [m];
        for(int i = 0;i < m;i++) {
            int v1 = sc.nextInt() - 1;
            int v2 = sc.nextInt() - 1;
            gr[v1].add(new edge(v2, i));
        }

        for(int i = 0;i < n;i++) if (used[i] == 0) dfs(i);

        int ans = 0;
        for(int i = 0;i < m;i++) ans = Math.max(ans, col[i]);
        pw.println(ans);
        for(int i = 0;i < m;i++) pw.print(col[i] + " ");
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

class edge {
    int to, id;
    edge(int to, int id) {
        this.to = to;
        this.id = id;
    }

    edge() {}
}