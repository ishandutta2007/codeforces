import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.OutputStream;
import java.io.Writer;
import java.io.IOException;
import java.util.InputMismatchException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
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
        TaskF2 solver = new TaskF2();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskF2 {
        public void solve(int testNumber, FastScanner in, FastPrinter out) {
            int n = in.nextInt();
            int m = in.nextInt();
            int D = in.nextInt();
            int[] from = new int[m];
            int[] to = new int[m];
            for (int i = 0; i < m; i++) {
                from[i] = in.nextInt() - 1;
                to[i] = in.nextInt() - 1;
                if (from[i] > to[i]) {
                    int t = from[i];
                    from[i] = to[i];
                    to[i] = t;
                }
            }
            DisjointSetUnion dsu = new DisjointSetUnion(n);
            for (int i = 0; i < m; i++) {
                if (from[i] != 0) {
                    dsu.union(from[i], to[i]);
                }
            }
            boolean[] get = new boolean[m];
            int cc = 0;
            for (int i = 0; i < m; i++) {
                if (from[i] == 0) {
                    if (dsu.get(from[i]) != dsu.get(to[i])) {
                        get[i] = true;
                        dsu.union(from[i], to[i]);
                        cc++;
                    }
                }
            }
            if (cc > D) {
                out.println("NO");
                return;
            }
            dsu.clear();
            for (int i = 0; i < m; i++) if (get[i]) dsu.union(from[i], to[i]);
            for (int i = 0; cc < D && i < m; i++) {
                if (get[i] || from[i] != 0) continue;
                if (dsu.get(from[i]) != dsu.get(to[i])) {
                    get[i] = true;
                    dsu.union(from[i], to[i]);
                    cc++;
                }
            }
            if (cc != D) {
                out.println("NO");
                return;
            }
            for (int i = 0; i < m; i++) {
                if (from[i] == 0) continue;
                if (dsu.get(from[i]) != dsu.get(to[i])) {
                    get[i] = true;
                    dsu.union(from[i], to[i]);
                }
            }
            out.println("YES");
            for (int i = 0; i < m; i++) {
                if (get[i]) {
                    out.println((from[i] + 1) + " " + (to[i] + 1));
                }
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

    static class DisjointSetUnion {
        int[] p;

        public DisjointSetUnion(int n) {
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