import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

/**
 * @author Pavel Mavrin
 */
public class H {

    private void solve() throws IOException {
        int tmin = nextInt();
        int tmax = nextInt();
        int n = nextInt();
        int m = nextInt();
        int[] l = new int[n];
        int[] r = new int[n];
        for (int i = 0; i < n; i++) {
            l[i] = nextInt();
            r[i] = nextInt();
        }
        init(n, m);
        for (int i = 0; i < m; i++) {
            addEdge(nextInt() - 1, nextInt() - 1);
        }
        lefts = new TreeSet<MyInteger>();
        rights = new TreeSet<MyInteger>();
        List<Event> events = new ArrayList<Event>();
        int end = Integer.MAX_VALUE;
        zh = 1;
        events.add(new ZhEvent(0));
        for (int i = 0; i < n; i++) {
            if (z[i] == -1) {
                Arrays.fill(pn, 0);
                if (!dfs(i, 0)) {
                    out.println("IMPOSSIBLE");
                    return;
                }
                if (pn[1] == 0) {
                    MyInteger ll = new MyInteger(l[i]);
                    MyInteger rr = new MyInteger(r[i]);
                    lefts.add(ll);
                    rights.add(rr);
                    events.add(new RemoveEvent(l[i], ll, rr));
                    end = Math.min(end, r[i] + 1);
                } else {
                    int l1 = Integer.MIN_VALUE;
                    int l2 = Integer.MIN_VALUE;
                    int r1 = Integer.MAX_VALUE;
                    int r2 = Integer.MAX_VALUE;
                    for (int j = 0; j < pn[0]; j++) {
                        l1 = Math.max(l1, l[p[0][j]]);
                        r1 = Math.min(r1, r[p[0][j]]);
                    }
                    for (int j = 0; j < pn[1]; j++) {
                        l2 = Math.max(l2, l[p[1][j]]);
                        r2 = Math.min(r2, r[p[1][j]]);
                    }
                    if (r1 < l1 || r2 < l2) {
                        out.println("IMPOSSIBLE");
                        return;
                    }
                    if (l2 < l1) {
                        int t = l2; l2 = l1; l1 = t;
                        t = r2; r2 = r1; r1 = t;
                    }
                    zh++;
                    end = Math.min(end, r1 + 1);
                    end = Math.min(end, r2 + 1);

                    events.add(new ZhEvent(l1));
                    MyInteger ll = new MyInteger(l2);
                    lefts.add(ll);
                    MyInteger rr = new MyInteger(r2);
                    rights.add(rr);
                    if (l2 > r1) {
                    } else if (r2 > r1) {
                    } else {
                        rights.add(new MyInteger(r1));
                        events.add(new RemoveEvent(l2, null, rr));
                    }
                }
            }
        }
        events.add(new ZhEvent(end));
        Collections.sort(events);
        for (int i = 0; i < events.size() - 1; i++) {
            events.get(i).action();
            int n1 = events.get(i).x;
            if (n1 == end) break;
            int n2 = events.get(i + 1).x - 1;
            if (n2 >= n1 && zh == 0) {
                int ll = Math.max(tmin - n2, lefts.isEmpty() ? Integer.MIN_VALUE : lefts.last().val);
                int rr = Math.min(tmax - n1, rights.isEmpty() ? Integer.MAX_VALUE : rights.first().val);
                int d2 = rr;
                int d1 = Math.max(n1, tmin - d2);
                if (rr >= ll && d2 >= d1) {
                    if (d1 < n1 || d1 > n2 || d2 < ll || d2 > rr) {
                        throw new RuntimeException();
                    }
                    Arrays.fill(z, -1);
                    int[] res = new int[n];
                    for (int j = 0; j < n; j++) {
                        if (z[j] == -1) {
                            Arrays.fill(pn, 0);
                            dfs(j, 0);
                            if (pn[1] == 0) {
                                if (l[j] <= d1 && r[j] >= d1) {
                                    res[j] = 1;
                                } else if (l[j] <= d2 && r[j] >= d2) {
                                    res[j] = 2;
                                } else {
                                    throw new RuntimeException();
//                                    out.println("Zhopa");
//                                    return;
                                }
                            } else {
                                int l1 = Integer.MIN_VALUE;
                                int l2 = Integer.MIN_VALUE;
                                int r1 = Integer.MAX_VALUE;
                                int r2 = Integer.MAX_VALUE;
                                for (int q = 0; q < pn[0]; q++) {
                                    l1 = Math.max(l1, l[p[0][q]]);
                                    r1 = Math.min(r1, r[p[0][q]]);
                                }
                                for (int q = 0; q < pn[1]; q++) {
                                    l2 = Math.max(l2, l[p[1][q]]);
                                    r2 = Math.min(r2, r[p[1][q]]);
                                }
                                if (l1 <= d1 && r1 >= d1 && l2 <= d2 && r2 >= d2) {
                                    for (int q = 0; q < pn[0]; q++) {
                                        res[p[0][q]] = 1;
                                    }
                                    for (int q = 0; q < pn[1]; q++) {
                                        res[p[1][q]] = 2;
                                    }
                                } else if (l1 <= d2 && r1 >= d2 && l2 <= d1 && r2 >= d1) {
                                    for (int q = 0; q < pn[0]; q++) {
                                        res[p[0][q]] = 2;
                                    }
                                    for (int q = 0; q < pn[1]; q++) {
                                        res[p[1][q]] = 1;
                                    }
                                } else {
                                    throw new RuntimeException();
//                                    out.println("Vashe zhopa");
                                }
                            }
                        }
                    }
                    out.println("POSSIBLE");
                    out.println(d1 + " " + d2);
                    for (int j = 0; j < n; j++) {
                        out.print(res[j]);
                    }
                    out.println();

                    return;
                }
            }
        }
        out.println("IMPOSSIBLE");
    }

    TreeSet<MyInteger> lefts;
    TreeSet<MyInteger> rights;
    int zh;

    class MyInteger implements Comparable<MyInteger> {
        int val;

        public MyInteger(int val) {
            this.val = val;
        }

        public int compareTo(MyInteger o) {
            int res = Integer.compare(val, o.val);
            if (res == 0) {
                return Integer.compare(hashCode(), o.hashCode());
            } else {
                return res;
            }
        }
    }

    abstract class Event implements Comparable<Event> {
        int x;
        public Event(int x) {
            this.x = x;
        }
        abstract void action();

        public int compareTo(Event o) {
            return Integer.compare(x, o.x);
        }
    }

    class RemoveEvent extends Event {
        MyInteger l;
        MyInteger r;

        public RemoveEvent(int x, MyInteger l, MyInteger r) {
            super(x);
            this.l = l;
            this.r = r;
        }

        @Override
        void action() {
            if (l != null) lefts.remove(l);
            if (r != null) rights.remove(r);
        }
    }

    class ZhEvent extends Event {
        public ZhEvent(int x) {
            super(x);
        }
        @Override
        void action() {
            zh--;
        }
    }

    void init(int n, int m) {
        m *= 2;
        this.n = n;
        this.m = m;
        last = 0;
        head = new int[n];
        nx = new int[m];
        dst = new int[m];
        p = new int[2][n];
        z = new int[n];
        Arrays.fill(z, -1);
        Arrays.fill(head, -1);
    }

    void addEdge(int x, int y) {
        nx[last] = head[x];
        dst[last] = y;
        head[x] = last;
        last++;
        nx[last] = head[y];
        dst[last] = x;
        head[y] = last;
        last++;
    }

    int[][] p;
    int[] z;
    int[] pn = new int[2];

    private boolean dfs(int x, int c) {
        p[c][pn[c]++] = x;
        z[x] = c;
        int j = head[x];
        while (j >= 0) {
            int y = dst[j];
            if (z[y] == c) {
                return false;
            } else if (z[y] == -1) {
                if (!dfs(y, 1 - c)) {
                    return false;
                }
            }
            j = nx[j];
        }
        return true;
    }

    int n, m;
    int[] head;
    int[] nx;
    int[] dst;
    int last;


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
        new H().run();
    }

    private void run() throws IOException {
        solve();
        out.close();
    }

}