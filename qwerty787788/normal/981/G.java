import java.io.*;
import java.util.*;

public class A {
    FastScanner in;
    PrintWriter out;

    final int mod = 998244353;

    int mul(int x, int y) {
        return (int)(x*1L*y%mod);
    }

    int add(int x, int y) {
        x += y;
        return x >= mod ? (x - mod) : x;
    }

    class SegmentTree {
        int[] realSum;
        int[] mul;
        int[] add;

        SegmentTree(int n) {
            realSum = new int[n * 4];
            mul = new int[n * 4];
            add = new int[n * 4];
            Arrays.fill(mul, 1);
        }

        void go(int v, int a, int b, int fr, int to) {
            mul[v] = mul(mul[v], a);
            add[v] = add(mul(a, add[v]), b);
            realSum[v] = add(mul(realSum[v], a), mul(b, to - fr + 1));
        }

        void relax(int v, int fr, int to) {
            int m = (fr+ to) >> 1;
            go(v * 2 + 1, mul[v], add[v], fr, m);
            go(v * 2 + 2, mul[v], add[v], m + 1, to);
            mul[v] = 1;
            add[v] = 0;
        }


        void join(int v) {
            realSum[v] = add(realSum[v * 2 + 1], realSum[v * 2+  2]);
        }

        void addOne(int v, int fr, int to, int needFr, int needTo) {
            if (needFr > to || needTo < fr) {
                return;
            }
            if (needFr <= fr && needTo >= to) {
                add[v] = add(add[v], 1);
                realSum[v] = add(realSum[v], to - fr + 1);
                return;
            }
            relax(v, fr, to);
            int m = (fr + to) >> 1;
            addOne(v * 2 + 1, fr, m, needFr, needTo);
            addOne(v * 2 + 2, m + 1, to, needFr, needTo);
            join(v);
        }

        void mulTwo(int v, int fr, int to, int needFr, int needTo) {
            if (needFr > to || needTo < fr) {
                return;
            }
            if (needFr <= fr && needTo >= to) {
                mul[v] = add(mul[v], mul[v]);
                add[v] = add(add[v], add[v]);
                realSum[v] = add(realSum[v], realSum[v]);
                return;
            }
            relax(v, fr, to);
            int m = (fr + to) >> 1;
            mulTwo(v * 2 + 1, fr, m, needFr, needTo);
            mulTwo(v * 2 + 2, m + 1, to, needFr, needTo);
            join(v);
        }

        int getSum(int v, int fr, int to, int needFr, int needTo) {
            if (needFr > to || needTo < fr) {
                return 0;
            }
            if (needFr <= fr && needTo >= to) {
                return realSum[v];
            }
            relax(v, fr, to);
            int m = (fr + to )>> 1;
            return add(getSum(v * 2 + 1, fr, m, needFr, needTo), getSum(v * 2 + 2, m + 1, to, needFr, needTo));
        }
    }

    void solve() {
        int n = in.nextInt();
        int q = in.nextInt();
        SegmentTree st = new SegmentTree(n);
        TreeSet<Segment>[] segs = new TreeSet[n];
        for (int i =0 ; i < n; i++) {
            segs[i] = new TreeSet<>();
        }
        Segment empty = new Segment(0, Integer.MAX_VALUE);
        for (int i =0 ; i < q; i++) {
            if (in.nextInt() == 1) {
                int fr = in.nextInt() - 1;
                int to = in.nextInt() - 1;
                int x = in.nextInt() - 1;
                TreeSet<Segment> ss = segs[x];
                empty.fr = to;
                List<Segment> all = new ArrayList<>();
                while (true) {
                    Segment z = ss.lower(empty);
                    if (z != null && z.to >= fr) {
                        all.add(z);
                        ss.remove(z);
                    } else {
                        break;
                    }
                }
                if (all.size() == 0) {
                    ss.add(new Segment(fr, to));
                    st.addOne(0, 0, n - 1, fr, to);
                } else {
                    if (to > all.get(0).to) {
                        st.addOne(0, 0, n - 1, all.get(0).to + 1, to);
                    }
                    if (fr < all.get(all.size() - 1).fr) {
                        st.addOne(0, 0, n - 1, fr, all.get(all.size() - 1).fr - 1);
                    }
                    for (int j = 0; j + 1 < all.size(); j++) {
                        int curTo = all.get(j).fr - 1;
                        int curFr = all.get(j + 1).to + 1;
                        if (curFr <= curTo) {
                            st.addOne(0, 0, n - 1, curFr, curTo);
                        }
                    }
                    for (Segment s : all) {
                        st.mulTwo(0, 0, n - 1, Math.max(s.fr, fr), Math.min(s.to, to));
                    }
                    fr = Math.min(fr, all.get(all.size() - 1).fr);
                    to = Math.max(to, all.get(0).to);
                    ss.add(new Segment(fr, to));
                }
            } else {
                int fr = in.nextInt() - 1;
                int to = in.nextInt() - 1;
                out.println(st.getSum(0, 0, n - 1, fr, to));
            }
        }
    }

    class Segment implements Comparable<Segment> {
        int fr, to;

        public Segment(int fr, int to) {
            this.fr = fr;
            this.to = to;
        }

        @Override
        public int compareTo(Segment o) {
            if (fr != o.fr) {
                return Integer.compare(fr, o.fr);
            }
            return Integer.compare(to, o.to);
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