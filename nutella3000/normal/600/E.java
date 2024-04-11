import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;


public class Main {
    static int inf = (int) 1e9 + 7;
    static int n;
    static ArrayList<Integer> gr[];
    static int c[];
    static pair ans[];
    static long cal[];

    static void scan() throws IOException {
        n = sc.nextInt();
        gr = new ArrayList[n];
        c = new int [n];
        ans = new pair[n];
        cal = new long[n];
        for(int i = 0;i < n;i++) {
            gr[i] = new ArrayList<>();
            c[i] = sc.nextInt();
            ans[i] = new pair();
        }

        for(int i = 0;i < n - 1;i++) {
            int v1 = sc.nextInt() - 1;
            int v2 = sc.nextInt() - 1;
            gr[v1].add(v2);
            gr[v2].add(v1);
        }
    }

    static void add(pair a, pair b) {
        for(Map.Entry<Integer, Integer> i : b.a.entrySet()) {
            int k = i.getKey();
            int v = i.getValue();

            if (!a.a.containsKey(k)) a.a.put(k, 0);
            a.a.put(k, a.a.get(k) + v);

            v = a.a.get(k);

            if (v > a.max_cnt) {
                a.max_cnt = v;
                a.sum = k;
            }else if (v == a.max_cnt) {
                a.sum += k;
            }
        }
    }

    static void dfs(int v, int pr) {

        for(int i : gr[v]) {
            if (i == pr) continue;
            dfs(i, v);
        }

        int id = -1;
        int max_size = -1;

        for(int to : gr[v]) {
            if (to == pr) continue;
            if (max_size < ans[to].a.size()) {
                max_size = ans[to].a.size();
                id = to;
            }
        }

        pair ans_v = new pair();
        if (id != -1) ans_v = ans[id];

        for(int to : gr[v]) {
            if (to == pr || to == id) continue;
            add(ans_v, ans[to]);
        }

        pair temp = new pair();
        temp.max_cnt = 1;
        temp.sum = c[v];
        temp.a.put(c[v], 1);

        add(ans_v, temp);



        ans[v] = ans_v;
        cal[v] = ans[v].sum;
    }

    static void solve() throws IOException {
        scan();
        dfs(0, -1);
        for(int i = 0;i < n;i++) {
            pw.print(cal[i] + " ");
        }
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
    long sum;
    int max_cnt;
    TreeMap<Integer, Integer> a = new TreeMap<>();
    pair() {}
}