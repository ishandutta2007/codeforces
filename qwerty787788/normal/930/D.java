import java.io.*;
import java.util.*;

public class A {
    FastScanner in;
    PrintWriter out;

    class SegmentTree {
        int[][] cnt;
        int[][] sum;
        int n;

        SegmentTree(int n) {
            this.n = n;
            cnt = new int[4][4 * n];
            sum = new int[4 * n][16];
            fill(0, 0, n - 1);
        }

        void fill(int v, int l, int r) {
            if (l == r) {
                sum[v][0] = 1;
            } else {
                int m = (l + r) >> 1;
                fill(v * 2 + 1, l, m);
                fill(v * 2 + 2, m + 1, r);
                relax(v);
            }
        }

        void add(int l, int r, int type, int value) {
            add(0, 0, n - 1, l, r, type, value);
        }

        void relax(int v) {
            for (int i = 0; i < 16; i++) {
                sum[v][i] = 0;
            }
            for (int it = 0; it < 2; it++) {
                int node = v * 2 + it + 1;
                int mask = getMask(node);
                for (int m = 0; m < 16; m++) {
                    sum[v][m | mask] += sum[node][m];
                }
            }
        }

        int getMask(int v) {
            int r = 0;
            for (int i = 0; i < 4; i++) {
                if (cnt[i][v] != 0) {
                    r |= 1 << i;
                }
            }
            return r;
        }

        void add(int v, int l, int r, int needL, int needR, int type, int value) {
            if (needL > needR) {
                return;
            }
            if (l == needL && r == needR) {
                cnt[type][v] += value;
            } else {
                int m = (l + r) >> 1;
                add(v * 2 + 1, l, m, needL, Math.min(needR, m), type, value);
                add(v * 2 + 2, m + 1, r, Math.max(m + 1, needL), needR, type, value);
                relax(v);
            }
        }

        int getAnswer() {
            int mask = getMask(0);
            int r = 0;
            for (int m = 0; m < 16; m++) {
                if ((m | mask) == 15) {
                    r += sum[0][m];
                }
            }
            return r;
        }
    }

    int solveStupid(ArrayList<Point> pts) {
        final int MAX = MAX2 + 1;
        int[][] v = new int[MAX][MAX];
        for (Point p : pts) {
            {
                int sz = 0;
                for (int x = p.x - 1; x >= 0; x--) {
                    sz++;
                    for (int y1 = (sz - 1) % 2; y1 < sz; y1 += 2) {
                        if (p.y - y1 >= 0) {
                            v[x][p.y - y1] |= 1;
                        }
                        if (p.y + y1 < MAX) {
                            v[x][p.y + y1] |= 1;
                        }
                    }
                }
            }
            {
                int sz = 0;
                for (int x = p.x + 1; x < MAX; x++) {
                    sz++;
                    for (int y1 = (sz - 1) % 2; y1 < sz; y1 += 2) {
                        if (p.y - y1 >= 0) {
                            v[x][p.y - y1] |= 2;
                        }
                        if (p.y + y1 < MAX) {
                            v[x][p.y + y1] |= 2;
                        }
                    }
                }
            }
            {
                int sz = 0;
                for (int y = p.y - 1; y >= 0; y--) {
                    sz++;
                    for (int x1 = (sz - 1) % 2; x1 < sz; x1 += 2) {
                        if (p.x - x1 >= 0) {
                            v[p.x - x1][y] |= 4;
                        }
                        if (p.x + x1 < MAX) {
                            v[p.x + x1][y] |= 4;
                        }
                    }
                }
            }
            {
                int sz = 0;
                for (int y = p.y + 1; y < MAX; y++) {
                    sz++;
                    for (int x1 = (sz - 1) % 2; x1 < sz; x1 += 2) {
                        if (p.x - x1 >= 0) {
                            v[p.x - x1][y] |= 8;
                        }
                        if (p.x + x1 < MAX) {
                            v[p.x + x1][y] |= 8;
                        }
                    }
                }
            }
        }
        int res = 0;
        for (int x = 0; x < MAX; x++)
            for (int y = 0; y < MAX; y++) {
                if (v[x][y] == 15) {
                    res++;
                }
            }
        return res;
    }

    final int MAX2 = 50;

    void solve2222() {
        Random rnd = new Random(123);
        for (int it = 0; it < 123123; it++) {
            System.err.println("it = " + it);
            final int MAXN = 20;
            int n = 1 + rnd.nextInt(MAXN);
            ArrayList<Point> pts = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                pts.add(new Point(rnd.nextInt(MAX2) + 1, 1 + rnd.nextInt(MAX2)));
            }
//            System.err.println(pts);
            int stup = solveStupid(pts);
            int my = solveMy(pts);
            if (my != stup) {
                System.err.println("my = " + my);
                System.err.println("correct = " + stup);
                System.err.println("pts = " + pts);
                throw new AssertionError();
            }
        }
    }

    private int solveMy(ArrayList<Point> pts1) {
        int res = 0;
        ArrayList<Point>[] pts = new ArrayList[2];
        for (int i = 0; i < 2; i++) {
            pts[i] = new ArrayList<>();
        }
        for (Point p : pts1) {
            pts[p.even()].add(p);
        }
        for (int i = 0; i < 2; i++) {
            res += solve(pts[i]);
        }
        return res;
    }

    void solve123() {
        int n = in.nextInt();
        ArrayList<Point> pts = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            pts.add(new Point(in.nextInt() + 50, in.nextInt() + 50));
        }
        out.println(solveStupid(pts));
    }

    void solve() {
        int n = in.nextInt();
        ArrayList<Point>[] pts = new ArrayList[2];
        for (int i = 0; i < 2; i++) {
            pts[i] = new ArrayList<>();
        }
        for (int i = 0; i < n; i++) {
            Point p = new Point(in.nextInt(), in.nextInt());
            pts[p.even()].add(p);
        }
        long res = 0;
        for (int i = 0; i < 2; i++) {
            res += solve(pts[i]);
        }
        out.println(res);
    }

    long solve(ArrayList<Point> pts) {
        if (pts.size() == 0) {
            return 0;
        }
        Point first = pts.get(0);
        boolean needChane = (Math.abs(first.y + first.x) % 2 == 0);
        if (needChane) {
            for (Point p : pts) {
                p.y++;
            }
        }
        ArrayList<Event> allEvents = new ArrayList<>();
        SegmentTree st = new SegmentTree(MAX * 2);
        for (Point p : pts) {
            {
                int nx = newX(p.x, p.y - 1);
                int ny = newY(p.x, p.y - 1);
                allEvents.add(new Event(0, nx, ny + 1, 0, -1));
                allEvents.add(new Event(0, nx, 0, 0, 1));
            }
            {
                int nx = newX(p.x - 1, p.y);
                int ny = newY(p.x - 1, p.y);
                allEvents.add(new Event(0, nx, ny, 1, 1));
            }
            {
                int nx = newX(p.x, p.y + 1);
                int ny = newY(p.x, p.y + 1);
                allEvents.add(new Event(nx, MAX * 2 - 1, ny, 2, 1));
            }
            {
                int nx = newX(p.x + 1, p.y);
                int ny = newY(p.x + 1, p.y);
                allEvents.add(new Event(nx, MAX * 2 - 1, 0, 3, 1));
                allEvents.add(new Event(nx, MAX * 2 - 1, ny + 1, 3, -1));
            }
        }
        Collections.sort(allEvents);
        int it = 0;
        long res = 0;
        for (int y = 0; y < MAX * 2; y++) {
            while (it < allEvents.size() && allEvents.get(it).y == y) {
                Event e = allEvents.get(it++);
                st.add(e.xFr, e.xTo, e.type, e.value);
            }
            res += st.getAnswer();
        }
        if (needChane) {
            for (Point p : pts) {
                p.y--;
            }
        }
        return res;
    }

    class Event implements Comparable<Event> {
        int xFr, xTo, y;
        int type;
        int value;

        public Event(int xFr, int xTo, int y, int type, int value) {
            this.xFr = xFr;
            this.xTo = xTo;
            this.y = y;
            this.type = type;
            this.value = value;
        }

        @Override
        public int compareTo(Event event) {
            return Integer.compare(y, event.y);
        }

        @Override
        public String toString() {
            return "Event{" +
                    "xFr=" + xFr +
                    ", xTo=" + xTo +
                    ", y=" + y +
                    ", type=" + type +
                    ", value=" + value +
                    '}';
        }
    }

    final int MAX = (int) 1e5 + 10;

    int newX(int x, int y) {
        if ((x + y) % 2 != 0) {
            throw new AssertionError();
        }
        return (x + y) / 2 + MAX;
    }

    int newY(int x, int y) {
        return (y - x) / 2 + MAX;
    }

    class Point {
        int x, y;

        int even() {
            return Math.abs(x + y) % 2;
        }

        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public String toString() {
            return "Point{" +
                    "x=" + x +
                    ", y=" + y +
                    '}';
        }
    }

    void run() {
        try {
            in = new FastScanner(new File("A.in"));
            out = new PrintWriter(new File("A.out"));

            solve();

            out.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    void runIO() {

        in = new FastScanner(System.in);
        out = new PrintWriter(System.out);

        solve();

        out.close();
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(File f) {
            try {
                br = new BufferedReader(new FileReader(f));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        public FastScanner(InputStream f) {
            br = new BufferedReader(new InputStreamReader(f));
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                String s = null;
                try {
                    s = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (s == null)
                    return null;
                st = new StringTokenizer(s);
            }
            return st.nextToken();
        }

        boolean hasMoreTokens() {
            while (st == null || !st.hasMoreTokens()) {
                String s = null;
                try {
                    s = br.readLine();
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (s == null)
                    return false;
                st = new StringTokenizer(s);
            }
            return true;
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }
    }

    public static void main(String[] args) {
        new A().runIO();
    }
}