import java.io.*;
import java.util.*;

public class F {
    private FastScanner in;
    private PrintWriter out;

    class Segment implements Comparable<Segment> {
        int l, r;

        public Segment(int l, int r) {
            this.l = l;
            this.r = r;
        }

        @Override
        public int compareTo(Segment o) {
            return Integer.compare(l, o.l);
        }

        @Override
        public String toString() {
            return "Segment{" +
                    "l=" + l +
                    ", r=" + r +
                    '}';
        }
    }

    class Q implements Comparable<Q> {
        int id;
        int x, y;

        public Q(int id, int x, int y) {
            this.id = id;
            this.x = x;
            this.y = y;
        }

        @Override
        public int compareTo(Q o) {
            return Integer.compare(x, o.x);
        }
    }

    void addSegment(Segment s) {
        allSegments.add(s);
        if (allSegments.size() == 800) {
            int from = allSegments.get(allSegments.size() - 1).l;
            TreeSet<Integer> right = new TreeSet<>();
            for (int i = allSegments.size() - 1; i >= 0; i--) {
                right.add(allSegments.get(i).r);
                int next = i == 0 ? up[0].length : allSegments.get(i - 1).l;
                int min = Integer.MAX_VALUE;

                for (int pos = allSegments.get(i).l; pos < next; pos++) {
                    if (min == Integer.MAX_VALUE || min <= pos) {
                        min = Integer.MAX_VALUE;
                        while (right.size() > 0) {
                            int v = right.first();
                            if (v > pos) {
                                min = v;
                                break;
                            } else {
                                right.remove(v);
                            }
                        }
                    }
                    up[0][pos] = Math.min(up[0][pos], min);
                }
            }
            allSegments.clear();
            for (int i = 1; i < LOG; i++) {
                for (int j = from; j < up[i].length; j++) {
                    up[i][j] = up[i - 1][j] == Integer.MAX_VALUE ? Integer.MAX_VALUE : up[i - 1][up[i - 1][j]];
                }
            }
        }
    }

    final int LOG = 10;
    int[][] up;

    ArrayList<Segment> allSegments = new ArrayList<>();

    final int MAX = 100000;

    private void solve123() {
        long START = System.currentTimeMillis();
        int n = MAX;
        int m = MAX;
        Segment[] segs = new Segment[m];
        Random rnd = new Random(123);
        for (int i = 0; i < m; i++) {
            int fr = rnd.nextInt(MAX);
            int to = rnd.nextInt(MAX);
            if (fr > to) {
                int tmp = fr;
                fr = to;
                to = tmp;
            }
            segs[i] = new Segment(fr, to);
        }
        Arrays.sort(segs);
        int cnt = MAX;
        Q[] q = new Q[cnt];
        for (int i = 0; i < cnt; i++) {
            int fr = rnd.nextInt(MAX);
            int to = rnd.nextInt(MAX);
            if (fr > to) {
                int tmp = fr;
                fr = to;
                to = tmp;
            }
            q[i] = new Q(i, fr, to);
        }
        Arrays.sort(q);
        int[] ans = new int[q.length];
        int iter = segs.length - 1;
        up = new int[LOG][n];
        for (int j = 0; j < LOG; j++) {
            for (int i = 0; i < n; i++) {
                up[j][i] = Integer.MAX_VALUE;
            }
        }
        for (int qIt = q.length - 1; qIt >= 0; qIt--) {
//            System.err.println("!" + qIt);
            while (iter != -1 && segs[iter].l >= q[qIt].x) {
                addSegment(segs[iter]);
                iter--;
            }
            int pos = q[qIt].x;
            int max = q[qIt].y;
            int it = allSegments.size() - 1;
            while (true) {
                int wasPos = pos;
                for (int i = LOG - 1; i >= 0; i--) {
                    if (up[i][pos] <= max) {
                        pos = up[i][pos];
                    }
                }
                while (it != -1) {
                    if (allSegments.get(it).l > pos) {
                        break;
                    }
                    if (allSegments.get(it).r <= pos || allSegments.get(it).r > max) {
                        it--;
                        continue;
                    }
                    pos = Math.max(pos, allSegments.get(it).r);
                    it--;
                }
                if (pos == wasPos) {
                    break;
                }
            }
            ans[q[qIt].id] = pos;
        }
        for (int z : ans) {
//            out.println(z + 1);
        }
        System.err.println(System.currentTimeMillis() - START);
    }

    private void solve() {
        int n = in.nextInt();
        int m = in.nextInt();
        Segment[] segs = new Segment[m];
        for (int i = 0; i < m; i++) {
            segs[i] = new Segment(in.nextInt() - 1, in.nextInt() - 1);
        }
        Arrays.sort(segs);
        int cnt = in.nextInt();
        Q[] q = new Q[cnt];
        for (int i = 0; i < cnt; i++) {
            q[i] = new Q(i, in.nextInt() - 1, in.nextInt() - 1);
        }
        Arrays.sort(q);
        int[] ans = new int[q.length];
        int iter = segs.length - 1;
        up = new int[LOG][n];
        for (int j = 0; j < LOG; j++) {
            for (int i = 0; i < n; i++) {
                up[j][i] = Integer.MAX_VALUE;
            }
        }
        for (int qIt = q.length - 1; qIt >= 0; qIt--) {
            while (iter != -1 && segs[iter].l >= q[qIt].x) {
                addSegment(segs[iter]);
                iter--;
            }
            int pos = q[qIt].x;
            int max = q[qIt].y;
            int it = allSegments.size() - 1;
            while (true) {
                int wasPos = pos;
                for (int i = LOG - 1; i >= 0; i--) {
                    if (up[i][pos] <= max) {
                        pos = up[i][pos];
                    }
                }
                while (it != -1) {
                    if (allSegments.get(it).l > pos) {
                        break;
                    }
                    if (allSegments.get(it).r <= pos || allSegments.get(it).r > max) {
                        it--;
                        continue;
                    }
                    pos = Math.max(pos, allSegments.get(it).r);
                    it--;
                }
                if (pos == wasPos) {
                    break;
                }
            }
            ans[q[qIt].id] = pos;
        }
        for (int z : ans) {
            out.println(z + 1);
        }
    }

    private void run() {
        try {
            in = new FastScanner(new File("F.in"));
            out = new PrintWriter(new File("F.out"));

            solve();

            out.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    private void runIO() {
        in = new FastScanner(System.in);
        out = new PrintWriter(System.out);

        solve();

        out.close();
    }

    private class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        FastScanner(File f) {
            try {
                br = new BufferedReader(new FileReader(f));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        FastScanner(InputStream f) {
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
        new F().runIO();
    }
}