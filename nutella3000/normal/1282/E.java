import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;


public class Main {
    static int inf = (int) 1e9 + 7;
    static int n, tri[][];
    static ArrayList<Integer> gr[];
    static TreeSet<Integer> cnt[];

    public static void main(String[] args) throws IOException {
        sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        for(int test = sc.nextInt();test > 0;test--) {
            n = sc.nextInt();
            cnt = new TreeSet[n + 1];
            gr = new ArrayList[n + 1];
            for(int i = 0;i <= n;i++) {
                cnt[i] = new TreeSet<>();
                gr[i] = new ArrayList<>();
            }

            tri = new int [n - 2][3];
            for(int i = 0;i < n - 2;i++) {
                for(int j = 0;j < 3;j++) {
                    tri[i][j] = sc.nextInt();
                    cnt[tri[i][j]].add(i);
                }
            }

            if (n == 3) {
                pw.println(1 + " " + 2 + " " + 3);
                pw.println(1);
                continue;
            }


            ArrayDeque<Integer> bfs = new ArrayDeque<>();

            for(int i = 0;i <= n;i++) {
                if (cnt[i].size() == 1) bfs.add(i);
            }

            ArrayList<Integer> ans2 = new ArrayList<>();
            ArrayList<Integer> ans1 = new ArrayList<>();
            dsu cal = new dsu(n + 1);

            while(!bfs.isEmpty()) {
                int v = bfs.pollFirst();

                if (cnt[v].isEmpty()) continue;

                int id = cnt[v].first();
                ans2.add(id + 1);

                for(int i = 0;i < 3;i++) {
                    cnt[tri[id][i]].remove(id);

                    if (tri[id][i] == v) continue;

                    if (cal.get(tri[id][i]) != cal.get(v)) {
                        gr[v].add(tri[id][i]);
                        gr[tri[id][i]].add(v);
                        cal.union(tri[id][i], v);
                    }



                    if (cnt[tri[id][i]].size() == 1) bfs.add(tri[id][i]);
                }
            }

            int v = 1;
            for(int i = 1;i <= n;i++) if (gr[i].size() == 1) v = i;
            int pr = -1;
            while(ans1.size() != n) {
                ans1.add(v);
                for(int to : gr[v]) {
                    if (to != pr) {
                        pr = v;
                        v = to;
                        break;
                    }
                }
            }

            for(int i : ans1) pw.print(i + " ");
            pw.println();
            for(int i : ans2) pw.print(i + " ");
            pw.println();

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

class matrix {
    long a[][];
    static long mod = (long) 1e18 + 7;
    int n;

    matrix(int n) {
        this.n = n;
        a = new long[n][n];
    }

    matrix(long b[][]) {
        n = b.length;
        a = new long [n][n];

        for(int i = 0;i < n;i++) {
            for(int j = 0;j < n;j++) {
                a[i][j] = b[i][j];
            }
        }
    }

    matrix add(matrix b) {
        matrix c = new matrix(n);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < n;j++) {
                c.a[i][j] = (a[i][j] + b.a[i][j]) % mod;
            }
        }
        return c;
    }

    matrix mul(matrix b) {
        matrix c = new matrix(n);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < n;j++) {
                for(int k = 0;k < n;k++) {
                    c.a[i][j] = (c.a[i][j] + a[i][k] * b.a[k][j]) % mod;
                }
            }
        }
        return c;
    }

    matrix pow(long pow) {
        matrix ans = new matrix(n);
        matrix temp = new matrix(a);
        for(int i = 0;i < n;i++) ans.a[i][i] = 1;

        while(pow != 0) {
            if ((pow & 1) == 1) ans = ans.mul(temp);
            temp = temp.mul(temp);

            pow >>= 1;
        }

        return ans;
    }


}

class dsu {
    int parent[];

    dsu(int n) {
        parent = new int [n];
        for(int i = 0;i < n;i++) parent[i] = i;
    }

    int get(int v) {
        if (parent[v] != v) return parent[v] = get(parent[v]);
        return v;
    }

    void union(int a1, int b1) {
        parent[get(a1)] = get(b1);
    }
}