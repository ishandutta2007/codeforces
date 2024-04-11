import java.io.*;
import java.util.*;


public class Main {
    static int inf = (int) 1e9 + 7;

    static int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }


    public static void main(String[] args) throws IOException {
        sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        int m = sc.nextInt();
        int n = sc.nextInt();
        int k = sc.nextInt();
        int t = sc.nextInt();
        int a[] = new int [m];
        for(int i = 0;i < m;i++) a[i] = -sc.nextInt();
        Arrays.sort(a);
        for(int i = 0;i < m;i++) a[i] = -a[i];

        mine b[] = new mine[k];
        for(int i = 0;i < k;i++) {
            b[i] = new mine(sc.nextInt(), sc.nextInt(), sc.nextInt());
        }

        Arrays.sort(b, new mine());

        dsu c = new dsu(n + 1);

        int v_t = n + 1;
        int id = 0;
        for(int i = 0;i <= m;i++) {
            if (i == m) {
                System.out.println(m);
                return;
            }

            while(id != k && b[id].x > a[i]) {
                int v = c.get(b[id].l - 1);

                while(v < b[id].r) {
                    v_t += 2;
                    c.union(v, v + 1);
                    v = c.get(v);
                }
                id++;

            }

            if (v_t > t) {
                System.out.println(i);
                return;
            }

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

class mine implements Comparator<mine>{
    int l, r, x;
    mine(int l, int r, int x) {
        this.l = l;
        this.r = r;
        this.x = x;
    }

    mine() {}

    @Override
    public int compare(mine o1, mine o2) {
        return -Integer.compare(o1.x, o2.x);
    }
}

class dsu {
    int parent[];
    dsu(int n) {
        parent = new int [n];
        for(int i = 0;i < n;i++) parent[i] = i;
    }

    int get(int v) {
        if (parent[v] == v) return v;
        return parent[v] = get(parent[v]);
    }

    void union(int v1, int v2) {
        v1 = get(v1);
        v2 = get(v2);
        parent[v1] = v2;
    }

}