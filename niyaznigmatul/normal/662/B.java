import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.IOException;
import java.util.InputMismatchException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.io.Writer;
import java.io.BufferedReader;
import java.util.Collections;
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
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskB {
        static List<Edge>[] edges;
        static int[] cv;
        static List<Integer>[] tocolor;

        static boolean dfs(int v, int c) {
            cv[v] = c;
            tocolor[c].add(v);
            for (int i = 0; i < edges[v].size(); i++) {
                Edge e = edges[v].get(i);
                if (cv[e.to] < 0) {
                    dfs(e.to, c ^ e.c);
                }
                if (cv[e.to] != (c ^ e.c)) {
                    return false;
                }
            }
            return true;
        }

        public void solve(int testNumber, FastScanner in, FastPrinter out) {
            int n = in.nextInt();
            int m = in.nextInt();
            int[] from = new int[m];
            int[] to = new int[m];
            int[] color = new int[m];
            for (int i = 0; i < m; i++) {
                from[i] = in.nextInt() - 1;
                to[i] = in.nextInt() - 1;
                color[i] = in.next().charAt(0) == 'B' ? 0 : 1;
            }
            List<Integer> answer = null;
            tocolor = new List[2];
            tocolor[0] = new ArrayList<>();
            tocolor[1] = new ArrayList<>();
            for (int c = 0; c < 2; c++) {
                edges = new List[n];
                for (int i = 0; i < n; i++) {
                    edges[i] = new ArrayList<>();
                }
                for (int i = 0; i < m; i++) {
                    edges[from[i]].add(new Edge(from[i], to[i], color[i] == c ? 1 : 0));
                    edges[to[i]].add(new Edge(to[i], from[i], color[i] == c ? 1 : 0));
                }
                cv = new int[n];
                Arrays.fill(cv, -1);
                List<Integer> cur = new ArrayList<>();
                boolean ok = true;
                for (int i = 0; i < n; i++) {
                    if (cv[i] >= 0) continue;
                    tocolor[0].clear();
                    tocolor[1].clear();
                    if (!dfs(i, 0)) {
                        ok = false;
                        break;
                    }
                    if (tocolor[0].size() > tocolor[1].size()) {
                        cur.addAll(tocolor[1]);
                    } else {
                        cur.addAll(tocolor[0]);
                    }
                }
                if (!ok) continue;
                if (answer == null || cur.size() < answer.size()) {
                    answer = cur;
                }
            }
            if (answer == null) {
                out.println(-1);
                return;
            }
            out.println(answer.size());
            Collections.sort(answer);
            int[] z = ArrayUtils.toPrimitiveArrayInteger(answer);
            for (int i = 0; i < z.length; i++) {
                z[i]++;
            }
            out.printArray(z);
        }

        static class Edge {
            int from;
            int to;
            int c;

            public Edge(int from, int to, int c) {
                this.from = from;
                this.to = to;
                this.c = c;
            }

        }

    }

    static class ArrayUtils {
        static public int[] toPrimitiveArrayInteger(List<Integer> list) {
            int[] ret = new int[list.size()];
            for (int i = 0; i < ret.length; i++) {
                ret[i] = list.get(i);
            }
            return ret;
        }

    }

    static class FastPrinter extends PrintWriter {
        public FastPrinter(OutputStream out) {
            super(out);
        }

        public FastPrinter(Writer out) {
            super(out);
        }

        public void printArray(int[] a) {
            for (int i = 0; i < a.length; i++) {
                if (i > 0) {
                    print(' ');
                }
                print(a[i]);
            }
            println();
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

        public String next() {
            StringBuilder sb = new StringBuilder();
            int c = read();
            while (isWhiteSpace(c)) {
                c = read();
            }
            if (c < 0) {
                return null;
            }
            while (c >= 0 && !isWhiteSpace(c)) {
                sb.appendCodePoint(c);
                c = read();
            }
            return sb.toString();
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