import java.io.*;
import java.util.*;


public class Main {
    static int inf = (int) (1e9 + 7);
    static int n;
    static ArrayList<Integer> gr[];
    static boolean used[], good[];
    static int cnt_good;


    static void find(int v, int fin) {
        if (v == fin || !good[v]) return;
        good[v] = false;
        cnt_good--;
        for(int i : gr[v]) {
            find(i, fin);
        }
    }

    static void r() {
        for(int i = 0;i < n;i++) used[i] = false;
    }

    static void solve() throws IOException {
        scan();
        cnt_good = n;
        used = new boolean[n];
        good = new boolean[n];
        for(int i = 0;i < n;i++) good[i] = true;

        int it = 0;
        while(cnt_good != 1) {
            for(int v1 = 0;v1 < n;v1++) {
                if (!good[v1]) continue;
                boolean temp = false;
                for(int i : gr[v1]) {
                    int v2 = gr[i].get(0);
                    if ((v2 == v1 || !good[v1]) && gr[i].size() >= 2) v2 = gr[i].get(1);
                    if (cnt_good == 2) v2 = i;
                    if (v2 == v1 || !good[v2]) continue;
                    pw.println("? " + (v1 + 1) + " " + (v2 + 1));
                    pw.flush();
                    int w = sc.nextInt() - 1;

                    find(v1, w);
                    r();
                    find(v2, w);
                    r();
                    temp = true;
                    break;
                 }
                if (temp) break;
            }
            it++;
            if (it > n / 2) n /= 0;
        }

        int res = 0;
        for(int i = 0;i < n;i++) if (good[i]) res = i + 1;
        pw.println("! " + res);
    }

    static void scan() throws IOException {
        n = sc.nextInt();
        gr = new ArrayList[n];
        for(int i = 0;i < n;i++) gr[i] = new ArrayList<>();
        for(int i = 0;i < n - 1;i++) {
            int v1 = sc.nextInt() - 1;
            int v2 = sc.nextInt() - 1;
            gr[v1].add(v2);
            gr[v2].add(v1);
        }
    }


    public static void main(String[] args) throws IOException {
        sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        int n = sc.nextInt();
        int m = sc.nextInt();
        ArrayList<Integer> ans = new ArrayList<>();
        int id = 1;
        if (m != 0) {
            while (true) {
                if (ans.size() / 2 > m) break;
                m -= ans.size() / 2;
                ans.add(id);
                id++;
            }
        }
        if (m != 0) {
            int cnt = ans.size();
            while (true) {
                id++;
                cnt--;
                if (cnt / 2 == m) {
                    ans.add(id);
                    m = 0;
                    break;
                }
            }
        }



        int c1 = (int) 1e9;
        int c2 = 20001;

        //if (ans.get(ans.size() - 1) * 2 >= c2) n /= 0;

        while(ans.size() < n) {
            if (c1 * 2 <= 1e9) n /= 0;
            ans.add(c1);
            c1 -= c2;
        }

        Collections.sort(ans);

        if (ans.size() > n) pw.println(-1);
        else {
            for(int i : ans) pw.print(i + " ");
        }

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
    int a, t;

    pair(int a, int t) {
        this.a = a;
        this.t = t;
    }

    pair() {
    }

}