import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.OutputStream;
import java.io.IOException;
import java.util.InputMismatchException;
import java.io.InputStreamReader;
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
            char[][] c = in.readCharacterFieldTokens(n, m);
            int startX = -1;
            int startY = -1;
            int finishX = -1;
            int finishY = -1;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (c[i][j] == 'S') {
                        startX = i;
                        startY = j;
                    } else if (c[i][j] == 'T') {
                        finishX = i;
                        finishY = j;
                    }
                }
            }
            int[] q = new int[n * m * 3 * 4];
            int head = 0;
            int tail = 0;
            boolean[][][][] was = new boolean[3][4][n][m];
            for (int dir = 0; dir < 4; dir++) {
                q[tail++] = (startX * m + startY) + dir * n * m;
                was[0][dir][startX][startY] = true;
            }
            final int[] DX = {1, 0, -1, 0};
            final int[] DY = {0, 1, 0, -1};
            while (head < tail) {
                int v = q[head++];
                int turn = v / (n * m * 4);
                int dir = v / (n * m) % 4;
                int cx = v / m % n;
                int cy = v % m;
                if (c[cx][cy] == 'T') {
                    out.println("YES");
                    return;
                }
                for (int nDir = 0; nDir < 4; nDir++) {
                    int nTurn = turn + (nDir == dir ? 0 : 1);
                    if (nTurn > 2) continue;
                    int nx = cx + DX[nDir];
                    int ny = cy + DY[nDir];
                    if (nx < 0 || ny < 0 || nx >= n || ny >= m || c[nx][ny] == '*' || was[nTurn][nDir][nx][ny])
                        continue;
                    was[nTurn][nDir][nx][ny] = true;
                    q[tail++] = nTurn * 4 * n * m + nDir * n * m + nx * m + ny;
                }
            }
            out.println("NO");
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

        public char[][] readCharacterFieldTokens(int n, int m) {
            char[][] ret = new char[n][];
            for (int i = 0; i < n; i++) {
                ret[i] = next().toCharArray();
                if (ret[i].length != m) {
                    throw new AssertionError("length expected " + m + ", found " + ret[i].length);
                }
            }
            return ret;
        }

    }
}