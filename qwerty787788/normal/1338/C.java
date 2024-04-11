import java.io.*;
import java.util.*;

public class A {
    FastScanner in;
    PrintWriter out;

    long calc(long id) {
        if (id == 24) {
            System.err.println("!");
        }
        long maxPowOf2 = Long.highestOneBit(id);
        long size = maxPowOf2;
        if (id < cache.length) {
            return cache[(int) id];
        }
        long part = size / 4;
        long add = maxPowOf2 >> 2;
        long prev = id & (~maxPowOf2) & (~(maxPowOf2 >> 1) & (~(maxPowOf2 >> 2)));
        prev += add;
        long base = calc(prev) & (~(maxPowOf2 >> 1));
        id -= size;
        long fadd = part;
        if (id < part) {

        } else if (id < 2 * part) {
            base += fadd * 2;
        } else if (id < 3 * part) {
            base += fadd * 3;
        } else {
            base += fadd;
        }
        return base + maxPowOf2 * 2;
    }

    int[] cache = new int[10];

    class Segment {
        long from, to;
        long len;

        public Segment(long from, long to) {
            this.from = from;
            this.to = to;
            len = to - from;
        }
    }

    void solve() {
        solve123();
        List<Segment> segs = new ArrayList<>();
        for (long start = 1, len = 1; start < 1e18; start *= 4, len *= 4) {
            segs.add(new Segment(start, start + len));
        }
        int tc = in.nextInt();
        for (int t = 0; t < tc; t++) {
            long posMain = in.nextLong() - 1;
            long pos = posMain / 3;
            long id = posMain % 3;
            for (Segment s : segs) {
                if (pos < s.len) {
                    long value = s.from + pos;
                    long value2 = calc(value);
                    if (id == 0) {
                        out.println(value);
                    } else if (id == 1) {
                        out.println(value2);
                    } else {
                        out.println(value ^ value2);
                    }
                    break;
                } else {
                    pos -= s.len;
                }
            }

        }
    }

    void solve123() {
        Set<Integer> set = new HashSet<>();
        final int MAX = 20;
        int[][] res = new int[MAX][];
        res[0] = new int[]{0, 0};
        for (int it = 1; it < MAX; it++) {
            if (!set.contains(it)) {
                for (int y = 1; ; y++) {
                    if (!set.contains(y) && (it ^ y) > 0 && !set.contains(it ^ y)) {
                        set.add(it);
                        set.add(y);
                        if (it < cache.length) {
                            cache[it] = y;
                        }
                        set.add(it ^ y);
                        res[it] = new int[]{y, it ^ y};
//                        int maxPowOf2 = Integer.highestOneBit(it);
//                        int add = maxPowOf2 >> 2;
//                        int prev = it & (~maxPowOf2) & (~(maxPowOf2 >> 1) & (~(maxPowOf2 >> 2)));
//                        prev+= add;
                        break;
                    }
                }
            }
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