import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        TaskD solver = new TaskD();
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class TaskD {
        static final long INF = (long) 1e18;
        long res;
        static final int UNKNOWN = Integer.MAX_VALUE;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            Bot[] bots = new Bot[4];
            for (int i = 0; i < 4; ++i) bots[i] = new Bot();
            for (int i = 0; i < 4; ++i) {
                bots[i].x = in.nextInt();
                bots[i].y = in.nextInt();
            }
            long res = solveOne(bots);
            if (res >= INF) res = -1;
            out.println(res);
            if (res >= 0) {
                for (Bot x : bots) {
                    out.println(x.dx + " " + x.dy);
                }
            }
        }

        private long solveOne(Bot[] bots) {
            Bot[] which = new Bot[4];
            boolean[] used = new boolean[4];
            res = INF;
            rec(which, used, bots, 0);
            return res;
        }

        private void rec(Bot[] which, boolean[] used, Bot[] bots, int at) {
            if (at >= which.length) {
                solveFixedOrder(which);
                return;
            }
            for (int i = 0; i < bots.length; ++i)
                if (!used[i]) {
                    used[i] = true;
                    which[at] = bots[i];
                    rec(which, used, bots, at + 1);
                    used[i] = false;
                }
        }

        private void solveFixedOrder(Bot[] which) {
            for (int xMask = 0; xMask < 16; ++xMask) {
                solveFixedMovement(which, xMask);
            }
        }

        private void solveFixedMovement(Bot[] which, int xMask) {
            int[] x = new int[2];
            int[] y = new int[2];
            Arrays.fill(x, UNKNOWN);
            Arrays.fill(y, UNKNOWN);
            for (int i = 0; i < 4; ++i) {
                if ((xMask & (1 << i)) != 0) {
                    int vy = i >> 1;
                    if (y[vy] == UNKNOWN) y[vy] = which[i].y;
                    if (y[vy] != which[i].y) return;
                } else {
                    int vx = i & 1;
                    if (x[vx] == UNKNOWN) x[vx] = which[i].x;
                    if (x[vx] != which[i].x) return;
                }
            }
            int size = UNKNOWN;
            if (x[0] != UNKNOWN && x[1] != UNKNOWN) {
                int cs = x[1] - x[0];
                if (size == UNKNOWN) size = cs;
                if (size != cs) return;
            }
            if (y[0] != UNKNOWN && y[1] != UNKNOWN) {
                int cs = y[1] - y[0];
                if (size == UNKNOWN) size = cs;
                if (size != cs) return;
            }
            if (size <= 0) return;
            if (size == UNKNOWN) throw new RuntimeException();
            if (x[0] == UNKNOWN && x[1] != UNKNOWN) {
                x[0] = x[1] - size;
            }
            if (x[0] != UNKNOWN && x[1] == UNKNOWN) {
                x[1] = x[0] + size;
            }
            if (y[0] == UNKNOWN && y[1] != UNKNOWN) {
                y[0] = y[1] - size;
            }
            if (y[0] != UNKNOWN && y[1] == UNKNOWN) {
                y[1] = y[0] + size;
            }
            if (x[0] == UNKNOWN && x[1] == UNKNOWN) {
                int[] tmpArr = new int[4];
                for (int i = 0; i < 4; ++i) {
                    int vx = i & 1;
                    tmpArr[i] = which[i].x - vx * size;
                }
                Arrays.sort(tmpArr);
                x[0] = (tmpArr[0] + tmpArr[3]) / 2;
                x[1] = x[0] + size;
            }
            if (y[0] == UNKNOWN && y[1] == UNKNOWN) {
                int[] tmpArr = new int[4];
                for (int i = 0; i < 4; ++i) {
                    int vy = i >> 1;
                    tmpArr[i] = which[i].y - vy * size;
                }
                Arrays.sort(tmpArr);
                y[0] = (tmpArr[0] + tmpArr[3]) / 2;
                y[1] = y[0] + size;
            }
            int cur = 0;
            for (int i = 0; i < 4; ++i) {
                int vy = i >> 1;
                int vx = i & 1;
                int dx = Math.abs(x[vx] - which[i].x);
                int dy = Math.abs(y[vy] - which[i].y);
                if (dx > 0 && dy > 0) throw new RuntimeException();
                cur = Math.max(cur, dx + dy);
            }
            if (cur < res) {
                res = cur;
                for (int i = 0; i < 4; ++i) {
                    int vy = i >> 1;
                    int vx = i & 1;
                    which[i].dx = x[vx];
                    which[i].dy = y[vy];
                }
            }
        }

        static class Bot {
            int x;
            int y;
            int dx;
            int dy;

        }

    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

    }
}