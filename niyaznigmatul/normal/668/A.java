import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
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
        TaskA solver = new TaskA();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskA {
        public void solve(int testNumber, FastScanner in, FastPrinter out) {
            int n = in.nextInt();
            int m = in.nextInt();
            int q = in.nextInt();
            int[][] ans = new int[n][m];
            int[][] id = new int[n][m];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    id[i][j] = i * m + j;
                }
            }
            for (int i = 0; i < q; i++) {
                int t = in.nextInt();
                if (t == 1) {
                    int row = in.nextInt() - 1;
                    int tmp = id[row][0];
                    for (int j = 0; j + 1 < m; j++) {
                        id[row][j] = id[row][j + 1];
                    }
                    id[row][m - 1] = tmp;
                } else if (t == 2) {
                    int col = in.nextInt() - 1;
                    int tmp = id[0][col];
                    for (int j = 0; j + 1 < n; j++) {
                        id[j][col] = id[j + 1][col];
                    }
                    id[n - 1][col] = tmp;
                } else {
                    int x = in.nextInt() - 1;
                    int y = in.nextInt() - 1;
                    int z = in.nextInt();
                    ans[id[x][y] / m][id[x][y] % m] = z;
                }
            }
            for (int[] e : ans) {
                out.printArray(e);
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
}