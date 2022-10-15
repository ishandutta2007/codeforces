import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.OutputStream;
import java.util.Arrays;
import java.util.HashMap;
import java.io.IOException;
import java.util.InputMismatchException;
import java.util.Random;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;
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
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskB {
        public void solve(int testNumber, FastScanner in, FastPrinter out) {
            int n = in.nextInt();
            int m = in.nextInt();
            List<Integer>[] edges = new List[n];
            for (int i = 0; i < n; i++) edges[i] = new ArrayList<>();
            for (int i = 0; i < m; i++) {
                int a = in.nextInt() - 1;
                int b = in.nextInt() - 1;
                edges[a].add((b - a + n) % n);
                edges[b].add((a - b + n) % n);
            }
            Map<TaskB.Neighbors, Integer> classes = new HashMap<>();
            int[] a = new int[n];
            for (int i = 0; i < n; i++) {
                int[] z = new int[edges[i].size()];
                for (int j = 0; j < z.length; j++) {
                    z[j] = edges[i].get(j);
                }
                ArrayUtils.sort(z);
                TaskB.Neighbors cur = new TaskB.Neighbors(z);
                Integer got = classes.get(cur);
                if (got == null) {
                    got = classes.size();
                    classes.put(cur, got);
                }
                a[i] = got;
            }
            int[] p = new int[n];
            int k = -1;
            p[0] = -1;
            for (int i = 1; i < n; i++) {
                while (k > -1 && a[i] != a[k + 1]) k = p[k];
                if (a[i] == a[k + 1]) ++k;
                p[i] = k;
            }
            k = -1;
            for (int i = 1; i + 1 < n + n; i++) {
                int c = a[i % n];
                while (k > -1 && c != a[k + 1]) k = p[k];
                if (c == a[k + 1]) ++k;
                if (k == n - 1) {
                    out.println("Yes");
                    return;
                }
            }
            out.println("No");
        }

        static class Neighbors {
            int[] a;

            public Neighbors(int[] a) {
                this.a = a;
            }

            public boolean equals(Object o) {
                if (this == o) return true;
                if (o == null || getClass() != o.getClass()) return false;
                TaskB.Neighbors neighbors = (TaskB.Neighbors) o;
                return Arrays.equals(a, neighbors.a);
            }

            public int hashCode() {
                return Arrays.hashCode(a);
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

    static class ArrayUtils {
        static final long seed = System.nanoTime();
        static final Random rand = new Random(seed);

        public static void sort(int[] a) {
            shuffle(a);
            Arrays.sort(a);
        }

        public static void shuffle(int[] a) {
            for (int i = 0; i < a.length; i++) {
                int j = rand.nextInt(i + 1);
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
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
}