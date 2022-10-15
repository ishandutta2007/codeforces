import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.OutputStream;
import java.util.Arrays;
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
        TaskB2 solver = new TaskB2();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskB2 {
        public void solve(int testNumber, FastScanner in, FastPrinter out) {
            int n = in.nextInt();
            int m = in.nextInt();
            int[][] a = new int[n][n];
            for (int[] e : a) Arrays.fill(e, Integer.MAX_VALUE);
            for (int i = 0; i < m; i++) {
                int from = in.nextInt() - 1;
                int to = in.nextInt() - 1;
                a[from][to] = a[to][from] = 1;
            }
            for (int i = 0; i < n; i++) {
                a[i][i] = 0;
            }
            for (int k = 0; k < n; k++) {
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        if (a[i][k] != Integer.MAX_VALUE && a[k][j] != Integer.MAX_VALUE) {
                            a[i][j] = Math.min(a[i][j], a[i][k] + a[k][j]);
                        }
                    }
                }
            }
            int s = in.nextInt();
            int b = in.nextInt();
            int k = in.nextInt();
            int h = in.nextInt();
            TaskB2.Ship[] ships = new TaskB2.Ship[s];
            for (int i = 0; i < s; i++) {
                ships[i] = new TaskB2.Ship(in.nextInt() - 1, in.nextInt(), in.nextInt());
            }
            TaskB2.Base[] bases = new TaskB2.Base[b];
            for (int i = 0; i < b; i++) {
                bases[i] = new TaskB2.Base(in.nextInt() - 1, in.nextInt());
            }
            KuhnMatchingGraph g = new KuhnMatchingGraph(s, b);
            for (int i = 0; i < s; i++) {
                TaskB2.Ship e = ships[i];
                for (int j = 0; j < b; j++) {
                    TaskB2.Base f = bases[j];
                    if (f.d > e.a || e.f < a[e.x][f.x]) continue;
                    g.addEdge(i, j);
                }
            }
            int have = g.getMaximalMatching();
            out.println(Math.min((long) h * s, (long) k * have));
        }

        static class Ship {
            int x;
            int a;
            int f;

            public Ship(int x, int a, int f) {
                this.x = x;
                this.a = a;
                this.f = f;
            }

        }

        static class Base {
            int x;
            int d;

            public Base(int x, int d) {
                this.x = x;
                this.d = d;
            }

        }

    }

    static class KuhnMatchingGraph {
        int n;
        int m;
        List<Integer>[] edges;
        int[] p1;
        int[] p2;
        int[] was;
        int VER;

        public KuhnMatchingGraph(int n, int m) {
            this.n = n;
            this.m = m;
            edges = new ArrayList[n];
            for (int i = 0; i < n; i++) {
                edges[i] = new ArrayList<Integer>(2);
            }
        }

        public void addEdge(int from, int to) {
            edges[from].add(to);
        }

        public int getMaximalMatching() {
            p1 = new int[n];
            p2 = new int[m];
            was = new int[n];
            VER = 0;
            Arrays.fill(p1, -1);
            Arrays.fill(p2, -1);
            int answer = 0;
            for (int i = 0; i < n; i++) {
                for (int j : edges[i]) {
                    if (p2[j] < 0) {
                        p2[j] = i;
                        p1[i] = j;
                        answer++;
                        break;
                    }
                }
            }
            for (int i = 0; i < n; i++) {
                if (p1[i] >= 0) {
                    continue;
                }
                VER++;
                if (dfs(i)) {
                    answer++;
                }
            }
            return answer;
        }

        boolean dfs(int v) {
            if (was[v] == VER) {
                return false;
            }
            was[v] = VER;
            for (int i = 0; i < edges[v].size(); i++) {
                int e = edges[v].get(i);
                if (p2[e] < 0 || dfs(p2[e])) {
                    p2[e] = v;
                    p1[v] = e;
                    return true;
                }
            }
            return false;
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