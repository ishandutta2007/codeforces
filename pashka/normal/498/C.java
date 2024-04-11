import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

/**
 * @author Pavel Mavrin
 */
public class C {

    private void solve() throws IOException {
        int n = nextInt();
        int m = nextInt();
        init(n + 2, m);
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = nextInt();
        }
        for (int i = 0; i < m; i++) {
            int x = nextInt() - 1;
            int y = nextInt() - 1;
            if (x % 2 == 0) {
                addEdge(x, y, 1000);
            } else {
                addEdge(y, x, 1000);
            }
        }
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                addEdge(n, i, 0);
            } else {
                addEdge(i, n + 1, 0);
            }
        }
        Set<Integer> primes = new HashSet<Integer>();
        for (int nn : a) {
            for (int i = 2; i * i <= nn; i++) {
                while (nn % i == 0) {
                    primes.add(i);
                    nn /= i;
                }
            }
            if (nn > 1) {
                primes.add(nn);
            }
        }
        int res = 0;
        for (Integer prime : primes) {
            for (int i = 0; i < n; i++) {
                cp[2 * m + 2 * i] = 0;
//                cp[2 * m + 2 * i + 1] = 0;
                int nn = a[i];
                while (nn % prime == 0) {
                    nn /= prime;
                    cp[2 * m + 2 * i]++;
//                    System.out.println(src[2 * m + 2 * i] + "-" + dst[2 * m + 2 * i]);
                }
            }

            res += maxFlow(n, n + 1);
//            System.out.println(prime + "  " + res);
        }
        out.println(res);

    }

    void init(int n, int m) {
        m *= 2;
        this.n = n;
        this.m = m;
        last = 0;
        head = new int[n];
        nx = new int[m];
        dst = new int[m];
        src = new int[m];
        cp = new int[m];
        fl = new int[m];
        Arrays.fill(head, -1);
        z = new boolean[n];
        queue = new int[n];
        dist = new int[n];
    }

    void addEdge(int x, int y, int capacity) {
        if (last + 2 > nx.length) {
            int size = (last + 2) * 3 / 2;
            nx = enlarge(nx, size);
            dst = enlarge(dst, size);
            src = enlarge(src, size);
            cp = enlarge(cp, size);
            fl = enlarge(fl, size);
        }
        nx[last] = head[x];
        src[last] = x;
        dst[last] = y;
        cp[last] = capacity;
        head[x] = last;
        last++;
        nx[last] = head[y];
        src[last] = y;
        dst[last] = x;
        cp[last] = 0;
        head[y] = last;
        last++;
    }

    private int[] enlarge(int[] a, int size) {
        int[] res = new int[size];
        System.arraycopy(a, 0, res, 0, a.length);
        return res;
    }

    long maxFlow(int s, int t) {
        long flow = 0;
        Arrays.fill(fl, 0);
        while (true) {
            bfs(s);
            if (dist[t] == -1) break;
            while (true) {
                Arrays.fill(z, false);
                int pushed = dfs(s, t, Integer.MAX_VALUE);
                if (pushed > 0) {
                    flow += pushed;
                } else {
                    break;
                }
            }
        }
        return flow;
    }

    private void bfs(int s) {
        Arrays.fill(dist, -1);
        dist[s] = 0;
        int h = 0; int t = 1;
        queue[0] = s;
        while (t > h) {
            int x = queue[h++];
            int j = head[x];
            while (j >= 0) {
                int y = dst[j];
                if (dist[y] == -1 && fl[j] < cp[j]) {
                    queue[t++] = y;
                    dist[y] = dist[x] + 1;
                }
                j = nx[j];
            }
        }
    }

    private int dfs(int x, int t, int f) {
        if (f == 0) return 0;
        if (x == t) return f;
        z[x] = true;
        int j = head[x];
        while (j >= 0) {
            int y = dst[j];
            if (!z[y] && fl[j] < cp[j] && dist[y] == dist[x] + 1) {
                int res = dfs(y, t, Math.min(f, cp[j] - fl[j]));
                if (res > 0) {
                    fl[j] += res;
                    fl[j ^ 1] -= res;
                    return res;
                }
            }
            j = nx[j];
        }
        return 0;
    }

    private static final long INF = Long.MAX_VALUE;

    int n, m;
    int[] head;
    int[] nx;
    int[] src;
    int[] dst;
    int[] cp;
    int[] fl;
    boolean[] z;
    int last;
    int[] queue;
    int[] dist;


    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st;
    PrintWriter out = new PrintWriter(System.out);

    String next() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return st.nextToken();
    }

    int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    public static void main(String[] args) throws IOException {
        new C().run();
    }

    private void run() throws IOException {
        solve();
        out.close();
    }

}