import java.io.*;
import java.util.*;

public class A {
    FastScanner in;
    PrintWriter out;

    final int mod = (int) 1e9 + 7;

    int add(int x, int y) {
        x += y;
        return x >= mod ? (x - mod) : x;
    }

    int mul(int x, int y) {
        int r = (int) ((x * 1L * y % mod));
        return r < 0 ? (r + mod) : r;
    }

    int sumAns;
    int sumDelta;

    class Segment {
        int value;
        boolean alive = true;
        boolean goLeft;
        boolean decRight;
        int len;
        int curTime;
        Segment left, right;
        boolean iAmFake;

        int getScore() {
            if (iAmFake) {
                return 0;
            }
            int delta = (goLeft ? 1 : 0) - (decRight ? 1 : 0);
            return delta * value;
        }

        Segment(int value) {
            this.value = value;
            curTime = 1;
            len = 1;
        }

        void relax() {
            int delta = (goLeft ? 1 : 0) - (decRight ? 1 : 0);
            len += (nowTime - curTime) * delta;
            curTime = nowTime;
        }

        void updateEvents() {
            int delta = (goLeft ? 1 : 0) - (decRight ? 1 : 0);
            if (delta < 0) {
                int more = len / Math.abs(delta);
                int endTime = curTime + more;
                if (endTime < events.length) {
                    events[endTime].add(this);
                }
            }
        }

        @Override
        public String toString() {
            return "Segment{" +
                    "value=" + value +
                    ", alive=" + alive +
                    ", goLeft=" + goLeft +
                    ", decRight=" + decRight +
                    ", len=" + len +
                    ", curTime=" + curTime +
                    '}';
        }
    }

    List<Segment>[] events;

    void addToScore(Segment s, int m) {
        sumDelta = add(sumDelta, mul(s.getScore(), m));
    }

    void join(Segment l, Segment r, boolean start) {
        if (!start) {
            addToScore(l, -1);
            addToScore(r, -1);
        }
        l.relax();
        r.relax();
        if (l.value < r.value) {
            l.decRight = true;
            r.goLeft = true;
        } else {
            l.decRight = false;
            r.goLeft = false;
        }
        l.right = r;
        r.left = l;
        l.updateEvents();
        r.updateEvents();
        if (!start) {
            addToScore(l, +1);
            addToScore(r, +1);
        }
    }

    int nowTime = 1;

    int solve(int n, int k, int[] vals) {
        nowTime = 1;
        sumAns = 0;
        sumDelta = 0;
        Segment[] segs = new Segment[n];
        for (int i = 0; i < n; i++) {
            segs[i] = new Segment(vals[i]);
//            addToScore(segs[i], 1);
            sumAns = add(sumAns, segs[i].value);
        }
        Segment fakeLeft = new Segment(Integer.MAX_VALUE);
        Segment fakeRight = new Segment(Integer.MAX_VALUE);
        fakeLeft.iAmFake = fakeRight.iAmFake = true;
        events = new List[n + 1];
        for (int i = 0; i < events.length; i++) {
            events[i] = new ArrayList<>();
        }
        join(fakeLeft, segs[0], true);
        for (int i = 0; i + 1 < n; i++) {
            join(segs[i], segs[i + 1], true);
        }
        join(segs[n - 1], fakeRight, true);
        for (int i = 0; i < n; i++) {
            addToScore(segs[i], +1);
        }
        int res = 0;
        for (nowTime = 2; nowTime <= n; nowTime++) {
            sumAns = add(sumAns, sumDelta);
            for (Segment s : events[nowTime]) {
                if (!s.alive) {
                    continue;
                }
                s.alive = false;
                s.relax();
                if (s.len == 0) {
                    join(s.left, s.right, false);
                }
                addToScore(s, -1);
            }
            if (nowTime % (k - 1) == 1 % (k - 1)) {
                res = add(res, sumAns);
            }
        }
        return res;
    }

    int solveStupid(int[] a, int k) {
        if (a.length < k) {
            return 0;
        }
        int[] b = new int[a.length - k + 1];
        int res = 0;
        for (int i = 0; i < b.length; i++) {
            int v = 0;
            for (int j = 0; j < k; j++) {
                v = Math.max(v, a[i + j]);
            }
            b[i] = v;
            res = add(res, v);
        }
        return add(res, solveStupid(b, k));
    }

    void solve123() {
        Random rnd = new Random(123);
        final int MAX = 100;
        for (int it = 0; it < 123123; it++) {
            System.err.println("it = " + it);
            int n = rnd.nextInt(MAX) + 2;
            int k = 2 + rnd.nextInt(n - 2 + 1);
            int[] a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = rnd.nextInt(MAX);
            }
            int my = solve(n, k, a.clone());
            int correct = solveStupid(a.clone(), k);
            if (my != correct) {
                System.err.println("A = " + Arrays.toString(a) + ", k = " + k);
                System.err.println("my = " + my + ", correct = " + correct);
                solve(n, k, a.clone());
                throw new AssertionError();
            }
        }
    }

    void solve() {
        int n = in.nextInt();
        int k = in.nextInt();
        int[] vals = new int[n];
        for(int i = 0; i < n; i++) {
            vals[i] = in.nextInt();
        }
        out.println(solve(n, k, vals));
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