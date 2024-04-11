import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Triangles implements Runnable {
    static class Result {
        int[][] am = new int[4][4];
        
        public Result(int n) {
            if (n != 0)
                throw new RuntimeException();
        }

        public Result(int n, boolean[][] seen) {
            int w1 = 0;
            if (seen[n][0])
                w1 = 1;
            int w2 = 0;
            if (seen[n][n])
                w2 = 1;
            int w3 = 0;
            if (seen[n - 2][0])
                w3 = 1;
            int w4 = 0;
            if (seen[n - 2][n - 2])
                w4 = 1;
            ++am[w1 * 2 + w2][w3 * 2 + w4];
        }

        void add(int by, Result x) {
            for (int i = 0; i < 4; ++i)
                for (int j = 0; j < 4; ++j)
                    am[i][j] += by * x.am[i][j];
        }

        public String print() {
            String res = "";
            for (int i = 0; i < 4; ++i) {
                for (int j = 0; j < 4; ++j)
                    res += am[i][j] + ", ";
                res += "\n";
            }
            return res;
        }
    }

    long MODULO = 1000000009;

    private void solve() throws IOException {
        int n = nextInt();
        long[] am = new long[]{6, 2, 2, 2};
        long u = 1;
        for (int i = 2; i <= n / 2; ++i) {
            long[] nam = new long[4];
            long v = (u * 3 + 1) % MODULO;
            long v2 = (v * v) % MODULO;
            long uv = (u * v) % MODULO;
            long u2 = (u * u) % MODULO;
            nam[0] = (am[0] + v * am[1] + v * am[2] + v2 * am[3]) % MODULO;
            nam[1] = (u * am[1] + uv * am[3]) % MODULO;
            nam[2] = (u * am[2] + uv * am[3]) % MODULO;
            nam[3] = u2 * am[3] % MODULO;
            am = nam;
            u = (u * 2 + 3) % MODULO;
        }
        writer.println(((am[0] + am[1] + am[2] + am[3] - 2) % MODULO + MODULO) % MODULO);
    }

    private Result doit(int row, int col, int n, boolean[][] seen) {
        if (seen[row][col]) {
            if (row == 0 && col == 0)
                return new Result(n, seen);
            else
                return new Result(0);
        }
        seen[row][col] = true;
        Result res = new Result(0);
        if (col < row) {
            int am = getCountRight(row, col);
            if (am != 0) {
                res.add(am,doit(row, col + 1, n, seen));
            }
        }
        if (col > 0) {
            int am = getCountRight(row, col - 1);
            if (am != 0) {
                res.add(am,doit(row, col - 1, n, seen));
            }
        }
        if (row < n) {
            int am = getCountDownLeft(row, col);
            if (am != 0) {
                res.add(am,doit(row + 1, col, n, seen));
            }
        }
        if (row < n) {
            int am = getCountDownRight(row, col);
            if (am != 0) {
                res.add(am,doit(row + 1, col + 1, n, seen));
            }
        }
        if (row > 0 && col > 0) {
            int am = getCountDownRight(row - 1, col - 1);
            if (am != 0) {
                res.add(am,doit(row - 1, col - 1, n, seen));
            }
        }
        if (row > 0 && col < row) {
            int am = getCountDownLeft(row - 1, col);
            if (am != 0) {
                res.add(am,doit(row - 1, col, n, seen));
            }
        }
        seen[row][col] = false;
        return res;
    }

    private int getCountDownRight(int row, int col) {
        if (row % 2 != 0) {
            return (col == 0 || col == row || col == row - 1) ? 1 : 0;
        } else {
            if (row <= 2)
                return 1;
            if (col == row / 2)
                return 0;
            if (col == row / 2 - 1)
                return 2;
            return 1;
        }
    }

    private int getCountDownLeft(int row, int col) {
        if (row % 2 != 0) {
            return (col == 0 || col == 1 || col == row) ? 1 : 0;
        } else {
            if (row <= 2)
                return 1;
            if (col == row / 2)
                return 0;
            if (col == row / 2 + 1)
                return 2;
            return 1;
        }
    }

    private int getCountRight(int row, int col) {
        if (row % 2 != 0) {
            if (row == 1 || col != row / 2) {
                if (col == 0 || col == row - 1)
                    return 1;
                else
                    return 2;
            } else {
                return 0;
            }
        } else {
            if (row == 2 || (col != row / 2 && col != row / 2 - 1)) {
                return 1;
            } else {
                return 0;
            }
        }
    }


    public static void main(String[] args) {
        new Triangles().run();
    }

    BufferedReader reader;
    StringTokenizer tokenizer;
    PrintWriter writer;

    public void run() {
        try {
            reader = new BufferedReader(new InputStreamReader(System.in));
            tokenizer = null;
            writer = new PrintWriter(System.out);
            solve();
            reader.close();
            writer.close();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

    int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    String nextToken() throws IOException {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(reader.readLine());
        }
        return tokenizer.nextToken();
    }
}