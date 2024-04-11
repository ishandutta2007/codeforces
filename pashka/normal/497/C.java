import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

/**
 * @author Pavel Mavrin
 */
public class C {

    private void solve() throws IOException {
        int n = nextInt();
        List<Segment> a = new ArrayList<Segment>();
        for (int i = 0; i < n; i++) {
            a.add(new Segment(nextInt() * 2, nextInt() * 2, false, i));
        }
        int m = nextInt();
        for (int i = 0; i < m; i++) {
            a.add(new Segment(nextInt() * 2 - 1, nextInt() * 2 + 1, nextInt(), true, i));
        }
        List<Position> p = new ArrayList<Position>();
        for (Segment segment : a) {
            p.add(new Position(segment.l, segment, true));
            p.add(new Position(segment.r, segment, false));
        }
        Collections.sort(p);
        int c = 0;
        for (Position position : p) {
            if (position.l) {
                position.segment.l = c++;
            } else {
                position.segment.r = c++;
            }
        }
        SegmentTree segmentTree = new SegmentTree(p.size());
        Collections.sort(a);
        int[] res = new int[n];
        int cc = 0;
        Segment[] z = new Segment[p.size()];
        for (Segment segment : a) {
            if (segment.a) {
                for (int i = 0; i < segment.k; i++) {
                    int x = segmentTree.findAfter(segment.l);
                    if (x > segment.r) {
                        break;
                    } else {
                        int j = z[x].id;
                        res[j] = segment.id;
                        cc++;
                        segmentTree.set(x, false);
                    }
                }

            } else {
                segmentTree.set(segment.l, true);
                z[segment.l] = segment;
            }
        }
        if (cc == n) {
            out.println("YES");
            for (int i = 0; i < res.length; i++) {
                out.print(res[i] + 1 + " ");
            }
        } else {
            out.println("NO");
        }

    }

    class Segment implements Comparable<Segment>{
        int l;
        int r;
        int k;
        int id;
        boolean a;
        public Segment(int l, int r, boolean a, int id) {
            this.l = l;
            this.r = r;
            this.a = a;
            this.id = id;
        }

        public Segment(int l, int r, int k, boolean a, int id) {
            this.l = l;
            this.r = r;
            this.k = k;
            this.a = a;
            this.id = id;
        }

        public int compareTo(Segment o) {
            return Integer.compare(r, o.r);
        }
    }

    class Position implements Comparable<Position>{
        int x;
        boolean l;
        Segment segment;

        public Position(int x, Segment segment, boolean l) {
            this.x = x;
            this.l = l;
            this.segment = segment;
        }

        public int compareTo(Position o) {
            return Integer.compare(x, o.x);
        }
    }

    class SegmentTree {

        private int[] a;
        private int size;

        public SegmentTree(int n) {
            int size = 1;
            while (size < n) size *= 2;
            this.size = size;
            a = new int[2 * size];
            Arrays.fill(a, -1);
        }

        private void set(int i, boolean v) {
            set(0, 0, size, i, v);
        }

        private void set(int n, int l, int r, int i, boolean v) {
            if (r == l + 1) {
                a[n] = v ? l : -1;
            } else {
                int m = (l + r) / 2;
                if (i < m) {
                    set(n * 2 + 1, l, m, i, v);
                } else {
                    set(n * 2 + 2, m, r, i, v);
                }
                a[n] = Math.max(a[n * 2 + 1], a[n * 2 + 2]);
            }
        }

        private int get(int i) {
            return get(0, 0, size, i);
        }

        private int get(int n, int l, int r, int i) {
            if (r == l + 1) {
                return a[n];
            } else {
                int m = (l + r) / 2;
                if (i < m) {
                    return get(n * 2 + 1, l, m, i);
                } else {
                    return get(n * 2 + 2, m, r, i);
                }
            }
        }

        public int findAfter(int x) {
            return findAfter(0, 0, size, x);
        }

        private int findAfter(int n, int l, int r, int x) {
            if (a[n] < 0) return size;
            if (r == l + 1) return a[n];
            if (a[n * 2 + 1] >= x) {
                return findAfter(2 * n + 1, l, (l + r) / 2, x);
            } else {
                return findAfter(2 * n + 2, (l + r) / 2, r, x);
            }
        }
    }

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