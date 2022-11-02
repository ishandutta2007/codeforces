import javax.smartcardio.ATR;
import java.io.*;
import java.util.*;

public class Main {
    static int n;
    static HashMap<Integer,Integer> gr[];
    static HashSet<Integer> p[];
    static dsu lol;
    static void union(int a, int b) {
        a = lol.get(a);
        b = lol.get(b);
        if (p[a].size() > p[b].size()) {
            int t = a;
            a = b;
            b = t;
        }
        lol.union(a, b);
        if (a != b) {
            for (int color : p[a]) {
                p[b].add(color);
            }
            p[a].clear();
        }
    }
    static void set(int a, int b, int c) {
        if (gr[a].get(c) != null) {
            union(gr[a].get(c), b);
        }
        if (gr[b].get(c) != null) {
            union(gr[b].get(c), a);
        }
        p[lol.get(b)].add(a);
        p[lol.get(a)].add(b);
        gr[a].put(c, b);
        gr[b].put(c, a);
    }
    public static void main(String[] args) throws IOException {
        Locale.setDefault(Locale.US);
        br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        n = nextInt();
        lol = new dsu(n);
        int m = nextInt();
        nextInt();
        int q = nextInt();
        gr = new HashMap[n];
        p = new HashSet[n];
        for(int i = 0;i < n;i++) {
            gr[i] = new HashMap<>();
            p[i] = new HashSet<>();
            p[i].add(i);
        }
        for(int i = 0;i < m;i++) {
            int x = nextInt() - 1;
            int y = nextInt() - 1;
            int c1 = nextInt();
            set(x, y, c1);
        }
        for(int i = 0;i < q;i++) {
            String s = next();
            if (s.equals("+")) {
                set(nextInt() - 1, nextInt() - 1, nextInt());
            }else{
                int a = nextInt() - 1;
                int b = nextInt() - 1;
                if (p[lol.get(a)].contains(b)) pw.println("Yes");
                else pw.println("No");
            }
        }
        pw.close();
    }

    static BufferedReader br;
    static StringTokenizer st = new StringTokenizer("");

    public static int nextInt() throws IOException {
        if (!st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return Integer.parseInt(st.nextToken());
    }

    public static long nextLong() throws IOException {
        if (!st.hasMoreTokens()) {
            st = new StringTokenizer((br.readLine()));
        }
        return Long.parseLong(st.nextToken());
    }

    public static double nextDouble() throws IOException {
        if (!st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return Double.parseDouble(st.nextToken());
    }

    public static String next() throws IOException {
        if (!st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return st.nextToken();
    }
}
class dsu {
    int parent[];
    dsu(int n) {
        parent = new int [n];
        for(int i = 0;i < n;i++) parent[i] = i;
    }
    int get(int a) {
        int p = a;
        while(a != parent[a]) a = parent[a];
        while(a != p) {
            int t = parent[p];
            parent[p] = a;
            p = t;
        }
        return a;
    }
    void union(int a, int b) {
        parent[get(a)] = get(b);
    }
}