import java.io.*;
import java.util.*;

public class Main {
    static int max(int a[]) {
        int ans = Integer.MIN_VALUE;
        for(int i = 0;i < a.length;i++) ans = Math.max(ans, a[i]);
        return ans;
    }

    static int min(int a[]) {
        int ans = Integer.MAX_VALUE;
        for(int i = 0;i < a.length;i++) ans = Math.min(ans, a[i]);
        return ans;
    }

    static int cnt(int a[], int num) {
        int ans = 0;
        for(int i = 0;i < a.length;i++) if (a[i] == num) ans++;
        return ans;
    }

    static int cnt(boolean a[]) {
        int ans = 0;
        for(int i = 0;i < a.length;i++) if (a[i]) ans++;
        return ans;
    }

    static void fill(int a[], int num) {
        for(int i = 0;i < a.length;i++) a[i] = num;
    }



    static int inf = (int) 1e9 + 7;
    static int n, k, d;
    static ArrayList<pair> gr[];
    static int dist[];
    static int comp[];
    static boolean cop[];
    static boolean ans[];

    static void scan() throws IOException {
        n = sc.nextInt();
        k = sc.nextInt();
        d = sc.nextInt();
        gr = new ArrayList[n];
        for(int i = 0;i < n;i++) gr[i] = new ArrayList<>();
        dist = new int [n];
        fill(dist, inf);
        ans = new boolean[n + 1];
        cop = new boolean[n];

        for(int i = 0;i < k;i++) cop[sc.nextInt() - 1] = true;
        for(int i = 0;i < n - 1;i++) {
            int v1 = sc.nextInt() - 1;
            int v2 = sc.nextInt() - 1;
            gr[v1].add(new pair(v2, i + 1));
            gr[v2].add(new pair(v1, i + 1));
        }
    }

    static void bfs() {
        Deque<Integer> bfs = new ArrayDeque<>();
        comp = new int [n];
        for(int i = 0;i < n;i++) comp[i] = -1;
        for(int i = 0;i < n;i++) {
            if (cop[i]) {
                bfs.add(i);
                dist[i] = 0;
                comp[i] = i;
            }
        }
        while(!bfs.isEmpty()) {
            int v = bfs.pollFirst();
            for(pair to : gr[v]) {
                if (comp[to.a] == comp[v]) continue;
                if (dist[to.a] > dist[v] + 1) {
                    dist[to.a] = dist[v] + 1;
                    comp[to.a] = comp[v];
                    bfs.add(to.a);
                }else ans[to.b] = true;

            }

        }
    }

    public static void main(String[] args) throws IOException {
        sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        scan();
        bfs();
        pw.println(cnt(ans));
        for(int i = 0;i < n;i++) if (ans[i]) pw.print(i + " ");
        pw.close();
    }

    static Scanner sc;
    static PrintWriter pw;
    static class Scanner {
        BufferedReader br ;
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

class pair implements Comparator<pair>{
    int a, b;
    pair(int a, int b) {
        this.a = a;
        this.b = b;
    }

    pair() {}

    @Override
    public int compare(pair o1, pair o2) {
        return Integer.compare(o1.a, o2.a) * 2 + Integer.compare(o1.b, o2.b);
    }
}