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
        TaskA solver = new TaskA();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskA {
        static List<Integer>[] edges;
        static int[] ans;

        static void dfs(int v, int pv, int c, int cp) {
            ans[v] = c;
            int cur = 0;
            for (int i = 0; i < edges[v].size(); i++) {
                while (cur == c || cur == cp) ++cur;
                int to = edges[v].get(i);
                if (to == pv) continue;
                dfs(to, v, cur, c);
                ++cur;
            }
        }

        public void solve(int testNumber, FastScanner in, FastPrinter out) {
            int n = in.nextInt();
            edges = new List[n];
            for (int i = 0; i < n; i++) {
                edges[i] = new ArrayList<>();
            }
            int[] deg = new int[n];
            for (int i = 0; i + 1 < n; i++) {
                int a = in.nextInt() - 1;
                int b = in.nextInt() - 1;
                edges[a].add(b);
                edges[b].add(a);
                deg[a]++;
                deg[b]++;
            }
            ans = new int[n];
            int mx = 0;
            for (int i = 0; i < n; i++) mx = Math.max(mx, deg[i] + 1);
            dfs(0, -1, 0, -1);
            out.println(mx);
            for (int i = 0; i < n; i++) {
                if (i > 0) out.print(' ');
                out.print(ans[i] + 1);
            }
            out.println();
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
}