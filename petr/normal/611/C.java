import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
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
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int rows = in.nextInt();
            int cols = in.nextInt();
            String[] field = new String[rows];
            for (int row = 0; row < rows; ++row) {
                field[row] = in.next();
            }
            int[][] vert = new int[rows + 1][cols + 1];
            for (int row = 1; row < rows; ++row)
                for (int col = 0; col < cols; ++col) {
                    if (field[row].charAt(col) == '.' && field[row - 1].charAt(col) == '.') ++vert[row + 1][col + 1];
                }
            Counter vc = new Counter(vert);
            int[][] horz = new int[rows + 1][cols + 1];
            for (int row = 0; row < rows; ++row)
                for (int col = 1; col < cols; ++col) {
                    if (field[row].charAt(col) == '.' && field[row].charAt(col - 1) == '.') ++horz[row + 1][col + 1];
                }
            Counter hc = new Counter(horz);
            int numQueries = in.nextInt();
            for (int queryId = 0; queryId < numQueries; ++queryId) {
                int r1 = in.nextInt();
                int c1 = in.nextInt();
                int r2 = in.nextInt();
                int c2 = in.nextInt();
                int res = 0;
                if (r1 < r2) {
                    res += vc.get(r1 + 1, c1, r2, c2);
                }
                if (c1 < c2) {
                    res += hc.get(r1, c1 + 1, r2, c2);
                }
                out.println(res);
            }
        }

        static class Counter {
            int[][] v;

            public Counter(int[][] v) {
                for (int i = 0; i < v.length; ++i)
                    for (int j = 0; j < v[0].length; ++j) {
                        if (i > 0) v[i][j] += v[i - 1][j];
                        if (j > 0) v[i][j] += v[i][j - 1];
                        if (i > 0 && j > 0) v[i][j] -= v[i - 1][j - 1];
                    }
                this.v = v;
            }

            int get(int r1, int c1, int r2, int c2) {
                return v[r2][c2] - v[r1 - 1][c2] - v[r2][c1 - 1] + v[r1 - 1][c1 - 1];
            }

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