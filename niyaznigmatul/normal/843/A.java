import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.OutputStream;
import java.util.Arrays;
import java.io.IOException;
import java.util.InputMismatchException;
import java.util.Random;
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
        public void solve(int testNumber, FastScanner in, FastPrinter out) {
            int n = in.nextInt();
            int[] a = in.readIntArray(n);
            int[] b = ArrayUtils.sortAndUnique(a);
            for (int i = 0; i < n; i++) {
                a[i] = Arrays.binarySearch(b, a[i]);
            }
            DisjointSetUnion dsu = new DisjointSetUnion(n);
            for (int i = 0; i < n; i++) {
                dsu.union(i, a[i]);
            }
            int count = 0;
            List<Integer>[] answer = new List[n];
            for (int i = 0; i < n; i++) {
                if (dsu.get(i) == i) {
                    ++count;
                    answer[i] = new ArrayList<>();
                }
            }
            out.println(count);
            for (int i = 0; i < n; i++) {
                answer[dsu.get(i)].add(i);
            }
            for (int i = 0; i < n; i++) {
                if (dsu.get(i) == i) {
                    out.print(answer[i].size());
                    for (int j : answer[i]) {
                        out.print(" " + (1 + j));
                    }
                    out.println();
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

        public int[] readIntArray(int n) {
            int[] ret = new int[n];
            for (int i = 0; i < n; i++) {
                ret[i] = nextInt();
            }
            return ret;
        }

    }

    static class ArrayUtils {
        static final long seed = System.nanoTime();
        static final Random rand = new Random(seed);

        static public int[] sortAndUnique(int[] a) {
            int[] ret = a.clone();
            sort(ret);
            if (ret.length == 0) {
                return ret;
            }
            int last = ret[0];
            int j = 1;
            for (int i = 1; i < ret.length; i++) {
                if (last != ret[i]) {
                    ret[j++] = ret[i];
                    last = ret[i];
                }
            }
            return Arrays.copyOf(ret, j);
        }

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

    static class FastPrinter extends PrintWriter {
        public FastPrinter(OutputStream out) {
            super(out);
        }

        public FastPrinter(Writer out) {
            super(out);
        }

    }
}