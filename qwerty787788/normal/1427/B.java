import java.io.*;
import java.util.*;

public class A {
    FastScanner in;
    PrintWriter out;

    void solve() {
        int tc = in.nextInt();
        for (int t = 0; t < tc; t++) {
            int n = in.nextInt();
            int k = in.nextInt();
            char[] s = in.next().toCharArray();
            int first = 0;
            while (first != n && s[first] != 'W') {
                first++;
            }
            int rfirst = first;
            List<Segment> segs = new ArrayList<>();
            while (first != n) {
                int next = first + 1;
                while (next != n && s[next] == 'L') {
                    next++;
                }
                if (next != first + 1 && next != n) {
                    segs.add(new Segment(first + 1, next - 1));
                }
                first = next;
            }
            Collections.sort(segs);
            for (Segment seg : segs) {
                for (int pos = seg.from; pos <= seg.to; pos++) {
                    if (k > 0) {
                        s[pos] = 'W';
                        k--;
                    }
                }
            }
            for (int i = rfirst - 1; i >= 0; i--) {
                if (s[i] == 'L' && k > 0) {
                    k--;
                    s[i] = 'W';
                }
            }
            for (int i = 0; i < n; i++) {
                if (s[i] == 'L' && k > 0) {
                    k--;
                    s[i] = 'W';
                }
            }
            int res = 0;
            for (int i = 0; i < n; i++) {
                if (s[i] == 'W') {
                    res++;
                    if (i > 0 && s[i - 1] == 'W') {
                        res++;
                    }
                }
            }
            out.println(res);
        }
    }

    class Segment implements Comparable<Segment> {
        int from, to;
        int len;

        public Segment(int from, int to) {
            this.from = from;
            this.to = to;
            len = to - from;
        }

        @Override
        public int compareTo(Segment o) {
            return Integer.compare(len, o.len);
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