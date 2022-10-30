import java.io.*;
import java.util.*;


public class Main {
    static int inf = (int) 1e9 + 7;
    static int n;
    static ArrayList<Integer> gr[];
    static boolean used[];
    static int ans = 0;
    static int comp[];
    static int sz = 0;

    static void dfs(int v, int pr) {
        if (used[v]) {
            return;
        }
        comp[v] = sz;
        used[v] = true;
        for(int to : gr[v]) if (to != pr) dfs(to, v);
    }

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        pw = new PrintWriter(System.out);
        int n = nextInt();
        int m = nextInt();
        gr = new ArrayList[n];
        for(int i = 0;i < n;i++) gr[i] = new ArrayList<>();
        used = new boolean[n];
        comp = new int [n];
        for(int i = 0;i < m;i++) {
            int to1 = nextInt() - 1;
            int to2 = nextInt() - 1;
            gr[to1].add(to2);
            gr[to2].add(to1);
        }

        for(int i = 0;i < n;i++) {
            if(!used[i]) {
                dfs(i, -1);
                sz++;
            }
        }

        int num1[] = new int [sz];
        int num2[] = new int [sz];

        for(int i = 0;i < n;i++) {
            num1[comp[i]]++;
            num2[comp[i]] += gr[i].size();
        }
        for(int i = 0;i < sz;i++) num2[i] /= 2;

        for(int i = 0;i < sz;i++) {
            ans += num2[i] - (num1[i] - 1);
        }

        pw.println(ans);

        pw.close();
    }

    static BufferedReader br;
    static StringTokenizer st = new StringTokenizer("");
    static PrintWriter pw;

    static String next() throws IOException {
        while (!st.hasMoreTokens()) st = new StringTokenizer(br.readLine());
        return st.nextToken();
    }

    static int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    static long nextLong() throws IOException {
        return Long.parseLong(next());
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
    public int compare(pair pair, pair t1) {
        return Integer.compare(pair.a, t1.a) * 2 + Integer.compare(pair.b, t1.b);
    }
}