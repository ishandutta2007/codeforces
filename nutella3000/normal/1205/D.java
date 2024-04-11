import java.io.*;
import java.util.*;


public class Main {
    static int inf = (int) (1e9 + 7);
    static int n, root = -1;
    static ArrayList<Integer> gr[];
    static ArrayList<triple> res = new ArrayList<>();
    static int sz[];

    static void build_sz(int v, int pr) {
        sz[v] = 1;
        for(int to : gr[v]) {
            if (to == pr) continue;
            build_sz(to, v);
            sz[v] += sz[to];
        }
    }

    static void find_centre(int v, int pr) {
        for(int to : gr[v]) {
            if (to != pr && sz[to] > n / 2) find_centre(to, v);
        }
        if (root == -1) root = v;
    }

    static void f(int v, int pr, int mul) {
        int cnt = 0;
        for(int to : gr[v]) {
            if (to == pr) continue;
            res.add(new triple(v, to, (1 + cnt) * mul));
            f(to, v, mul);
            cnt += sz[to];
        }
    }

    static void solve() throws IOException {
        n = sc.nextInt();
        gr = new ArrayList[n];
        for(int i = 0;i < n;i++) gr[i] = new ArrayList<>();
        sz = new int [n];

        for(int i = 0;i < n - 1;i++) {
            int v1 = sc.nextInt() - 1;
            int v2 = sc.nextInt() - 1;
            gr[v1].add(v2);
            gr[v2].add(v1);
        }

        build_sz(0, -1);
        find_centre(0, -1);
        build_sz(root, -1);


        ArrayList<Integer> to = new ArrayList<>();
        for(int i : gr[root]) to.add(i);
        Collections.sort(to, new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                return Integer.compare(sz[o1], sz[o2]);
            }
        });

        int cnt1 = 0;
        int cnt2 = 0;
        for(int i : to) {
            if (cnt1 >= (n + 2) / 3) {
                res.add(new triple(root, i, (cnt2 + 1) * (cnt1 + 1)));
                f(i, root, cnt1 + 1);
                cnt2 += sz[i];
            }else{
                res.add(new triple(root, i, cnt1 + 1));
                f(i, root, 1);
                cnt1 += sz[i];
            }
        }

        for(triple i : res) {
            pw.println((i.a + 1) + " " + (i.b + 1) + " " + i.x);
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

class triple {
    int a, b, x;
    triple(int a, int b, int x) {
        this.a = a;
        this.b = b;
        this.x = x;
    }

    triple() {}
}