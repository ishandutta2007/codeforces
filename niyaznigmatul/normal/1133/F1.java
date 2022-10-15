import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.OutputStream;
import java.io.IOException;
import java.util.InputMismatchException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.io.Writer;
import java.io.BufferedReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author Niyaz Nigmatullin
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        FastScanner in = new FastScanner(inputStream);
        FastPrinter out = new FastPrinter(outputStream);
        TaskF1 solver = new TaskF1();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskF1 {
        public void solve(int testNumber, FastScanner in, FastPrinter out) {
            int n = in.nextInt();
            int m = in.nextInt();
            int[] from = new int[m];
            int[] to = new int[m];
            List<Integer>[] edges = new List[n];
            for (int i = 0; i < n; i++) edges[i] = new ArrayList<>();
            for (int i = 0; i < m; i++) {
                from[i] = in.nextInt() - 1;
                to[i] = in.nextInt() - 1;
                if (from[i] > to[i]) {
                    int t = from[i];
                    from[i] = to[i];
                    to[i] = t;
                }
                edges[from[i]].add(to[i]);
                edges[to[i]].add(from[i]);
            }
            TaskF1.MyDSU dsu = new TaskF1.MyDSU(n);
            boolean[] get = new boolean[m];
            int mx = 0;
            int who = -1;
            for (int i = 0; i < n; i++) {
                if (edges[i].size() > mx) {
                    mx = edges[i].size();
                    who = i;
                }
            }
            for (int i = 0; i < m; i++) {
                if (from[i] == who || to[i] == who) {
                    get[i] = true;
                    dsu.union(from[i], to[i]);
                }
            }
            for (int i = 0; i < m; i++) {
                if (from[i] != who && to[i] != who) {
                    if (dsu.get(from[i]) != dsu.get(to[i])) {
                        get[i] = true;
                        dsu.union(from[i], to[i]);
                    }
                }
            }
            for (int i = 0; i < m; i++) {
                if (get[i]) {
                    out.println((from[i] + 1) + " " + (to[i] + 1));
                }
            }
        }

        static class MyDSU {
            int[] p;

            public MyDSU(int n) {
                p = new int[n];
                clear();
            }

            public void clear() {
                for (int i = 0; i < p.length; i++) {
                    p[i] = i;
                }
            }

            public int get(int x) {
                int y = x;
                while (y != p[y]) {
                    y = p[y];
                }
                while (x != p[x]) {
                    int t = p[x];
                    p[x] = y;
                    x = t;
                }
                return y;
            }

            public boolean union(int a, int b) {
                a = get(a);
                b = get(b);
                p[a] = b;
                return a != b;
            }

        }

    }

    static class FastScanner extends BufferedReader {
        public FastScanner(InputStream is) {
            super(new InputStreamReader(is));
        }

        public int read() {
            try {
                int ret = super.read();
//            if (isEOF && ret < 0) {
//                throw new InputMismatchException();
//            }
//            isEOF = ret == -1;
                return ret;
            } catch (IOException e) {
                throw new InputMismatchException();
            }
        }

        static boolean isWhiteSpace(int c) {
            return c >= 0 && c <= 32;
        }

        public int nextInt() {
            int c = read();
            while (isWhiteSpace(c)) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            int ret = 0;
            while (c >= 0 && !isWhiteSpace(c)) {
                if (c < '0' || c > '9') {
                    throw new NumberFormatException("digit expected " + (char) c
                            + " found");
                }
                ret = ret * 10 + c - '0';
                c = read();
            }
            return ret * sgn;
        }

        public String readLine() {
            try {
                return super.readLine();
            } catch (IOException e) {
                return null;
            }
        }

    }

    static class FastPrinter extends PrintWriter {
        public FastPrinter(OutputStream out) {
            super(out);
        }

        public FastPrinter(Writer out) {
            super(out);
        }

    }
}