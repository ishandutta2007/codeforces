import java.io.*;
import java.util.*;


public class Main {
    static int inf = (int)(1e9);
    static int n, m, k;
    static boolean good[];
    static int dist1[], dist2[];
    static ArrayList<Integer> gr[];

    static void bfs(int start, int res[]) {
        for(int i = 0;i < n;i++) res[i] = inf;
        res[start] = 0;
        ArrayDeque<Integer> bfs = new ArrayDeque<>();
        bfs.add(start);
        while(!bfs.isEmpty()) {
            int v = bfs.pollFirst();
            for(int to : gr[v]) {
                if (res[to] == inf) {
                    res[to] = res[v] + 1;
                    bfs.add(to);
                }
            }
        }
    }

    static void scan() throws IOException {
        n = sc.nextInt();
        m = sc.nextInt();
        k = sc.nextInt();
        good = new boolean[n];
        dist1 = new int [n];
        dist2 = new int [n];
        gr = new ArrayList[n];

        for(int i = 0;i < k;i++) good[sc.nextInt() - 1] = true;

        for(int i = 0;i < n;i++) gr[i] = new ArrayList<>();
        for(int i = 0;i < m;i++) {
            int v1 = sc.nextInt() - 1;
            int v2 = sc.nextInt() - 1;
            gr[v1].add(v2);
            gr[v2].add(v1);
        }

        bfs(0, dist1);
        bfs(n - 1, dist2);
    }

    static void solve() throws IOException {
        scan();

        Integer id[] = new Integer [k];
        int temp = 0;
        for(int i = 0;i < n;i++) {
            if (good[i]) id[temp++] = i;
        }

        Arrays.sort(id, new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                return Integer.compare(dist2[o1], dist2[o2]) * 2 + Integer.compare(o1, o2);
            }
        });

        int suf[] = new int [k];
        suf[k - 1] = dist1[id[k - 1]];
        for(int i = k - 2;i >= 0;i--) {
            suf[i] = Math.max(suf[i + 1], dist1[id[i]]);
        }

        int max_ans = 0;
        for(int i = 0;i < k - 1;i++) {
            max_ans = Math.max(max_ans, dist2[id[i]] + suf[i + 1] + 1);
        }

        max_ans = Math.min(max_ans, dist1[n - 1]);

        pw.println(max_ans);

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