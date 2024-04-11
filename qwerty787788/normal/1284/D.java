import java.io.*;
import java.util.*;

public class A {
    FastScanner in;
    PrintWriter out;
    int mod;

    public static void main(String[] args) {
        new A().runIO();
    }

    boolean ok(int[] xs, int[] xe, int[] ys, int[] ye) {
//        System.err.println("start");
        TreeSet<Integer> allX = new TreeSet<>();
        for (int x : xs) {
            allX.add(x);
        }
        for (int x : xe) {
            allX.add(x);
        }
        List<Integer> allXList = new ArrayList<>(allX);
//        System.err.println(allXList);
        int n = xs.length;
        Event[] events = new Event[n * 2];
        for (int i = 0; i < n; i++) {
            xs[i] = Collections.binarySearch(allXList, xs[i]);
            xe[i] = Collections.binarySearch(allXList, xe[i]);
            events[i * 2 + 0] = new Event(0, xs[i], xe[i], ys[i], ye[i]);
            events[i * 2 + 1] = new Event(1, xs[i], xe[i], ys[i], ye[i]);
        }
        final int MAX = allXList.size();
        SegmentTreePush st = new SegmentTreePush(MAX);
        Arrays.sort(events);
        for (Event e : events) {
//            System.err.println(e.type + " " + e.start + " " + e.end + " " + e.y);
            if (e.type == 0) {
                int curMin = st.get(e.start, e.end);
//                System.err.println("min for " + e.start + " " + e.end + " is " + curMin + ", my value = " + e.yStart);
                if (curMin < e.yStart) {
                    return false;
                }
            } else {
                st.add(e.start, e.end, e.yEnd);
            }
        }
        return true;
    }

    void solve() {
        int n = in.nextInt();
        int[] xs = new int[n];
        int[] xe = new int[n];
        int[] ys = new int[n];
        int[] ye = new int[n];
        for (int i = 0; i < n; i++) {
            xs[i] = in.nextInt();
            xe[i] = in.nextInt();
            ys[i] = in.nextInt();
            ye[i] = in.nextInt();
        }
        if (ok(xs, xe, ys, ye) && ok(ys, ye, xs, xe)) {
            out.println("YES");
        } else {
            out.println("NO");
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

    public class SegmentTreePush {
        // min on segment

        int[] pushAdd;
        int[] min;
        final int NEUTRAL_ELEMENT = Integer.MAX_VALUE;
        final int START_ELEMENT = Integer.MAX_VALUE;
        final int NEUTRAL_PUSH = Integer.MAX_VALUE;

        int n;

        SegmentTreePush(int n) {
            this.n = n;
            pushAdd = new int[n * 4];
            Arrays.fill(pushAdd, NEUTRAL_PUSH);
            min = new int[n * 4];
            init(0, 0, n - 1);
        }

        void init(int v, int l, int r) {
            if (l == r) {
                min[v] = START_ELEMENT;
            } else {
                int m = (l + r) >> 1;
                init(v * 2 + 1, l, m);
                init(v * 2 + 2, m + 1, r);
                min[v] = join(min[v * 2 + 1], min[v * 2 + 2]);
            }
        }

        // TODO: change it
        int join(int leftValue, int rightValue) {
            return Math.min(leftValue, rightValue);
        }

        // TODO: change it
        void apply(int v, int l, int r, int addValue) {
            pushAdd[v] = Math.min(addValue, pushAdd[v]);
            min[v] = Math.min(min[v], addValue);
        }

        void push(int v, int l, int r) {
            if (pushAdd[v] == NEUTRAL_PUSH) {
                return;
            }
            int m = (l + r) >> 1;
            apply(v * 2 + 1, l, m, pushAdd[v]);
            apply(v * 2 + 2, m + 1, r, pushAdd[v]);
            pushAdd[v] = NEUTRAL_PUSH;
        }

        int get(int v, int l, int r, int needL, int needR) {
            if (needL > needR) {
                return NEUTRAL_ELEMENT;
            }
            if (l == needL && r == needR) {
                return min[v];
            }
            int m = (l + r) >> 1;
            push(v, l, r);
            int leftAns = get(v * 2 + 1, l, m, needL, Math.min(needR, m));
            int rightAns = get(v * 2 + 2, m + 1, r, Math.max(needL, m + 1), needR);
            return join(leftAns, rightAns);
        }

        int get(int l, int r) {
            return get(0, 0, n - 1, l, r);
        }

        void add(int v, int l, int r, int needL, int needR, int addValue) {
            if (needL > needR) {
                return;
            }
            if (l == needL && r == needR) {
                apply(v, l, r, addValue);
            } else {
                int m = (l + r) >> 1;
                push(v, l, r);
                add(v * 2 + 1, l, m, needL, Math.min(needR, m), addValue);
                add(v * 2 + 2, m + 1, r, Math.max(needL, m + 1), needR, addValue);
                min[v] = join(min[v * 2 + 1], min[v * 2 + 2]);
            }
        }

        void add(int l, int r, int addValue) {
            add(0, 0, n - 1, l, r, addValue);
        }
    }

    class Event implements Comparable<Event> {
        // 0 - begin
        // 1 - end
        int type;
        int start, end;
        int yStart, yEnd;
        int y;


        public Event(int type, int start, int end, int yStart, int yEnd) {
            this.type = type;
            this.start = start;
            this.end = end;
            this.yStart = yStart;
            this.yEnd = yEnd;
            y = type == 0 ? yStart : yEnd;
        }

        @Override
        public int compareTo(Event o) {
            return Integer.compare(y, o.y);
        }
    }

    class Seg implements Comparable<Seg> {
        int from, to;

        Seg(int from, int to) {
            this.from = from;
            this.to = to;
        }

        @Override
        public int compareTo(Seg o) {
            return Integer.compare(to, o.to);
        }
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
}