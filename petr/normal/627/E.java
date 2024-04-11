import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.util.Random;
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
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskE {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int rows = in.nextInt();
            int cols = in.nextInt();
            int violas = in.nextInt();
            int need = in.nextInt();
            int[] violaCol = new int[violas];
            int[] nextSameRow = new int[violas];
            int[] firstByRow = new int[rows];
            Arrays.fill(firstByRow, -1);
            for (int i = 0; i < violas; ++i) {
                int row = in.nextInt() - 1;
                nextSameRow[i] = firstByRow[row];
                firstByRow[row] = i;
                violaCol[i] = in.nextInt() - 1;
            }
            long res = rows * (rows + 1) / 2 * (long) (cols * (cols + 1) / 2);
            Random random = new Random(3274342331L + System.currentTimeMillis());
            int layers = 1;
            while ((1 << layers) <= cols) ++layers;
            int[] colCount = new int[cols];
            int[][] next = new int[layers][cols + 1];
            int[][] prev = new int[layers][cols + 1];
            int sentinel = cols;
            for (int bottom = 0; bottom < rows; ++bottom) {
                Arrays.fill(colCount, 0);
                for (int layer = 0; layer < layers; ++layer) {
                    next[layer][sentinel] = prev[layer][sentinel] = sentinel;
                }
                int sofar = cols * (cols + 1) / 2;
                for (int top = bottom; top < rows; ++top) {
                    int cur = firstByRow[top];
                    while (cur >= 0) {
                        int col = violaCol[cur];
                        ++colCount[col];
                        if (colCount[col] == 1) {
                            int upto = Integer.numberOfTrailingZeros(random.nextInt(1 << (layers - 1)) + 1);
                            int at = sentinel;
                            for (int layer = layers - 1; layer >= 0; --layer) {
                                while (next[layer][at] < col) at = next[layer][at];
                                if (layer <= upto) {
                                    next[layer][col] = next[layer][at];
                                    prev[layer][col] = at;
                                    next[layer][prev[layer][col]] = col;
                                    prev[layer][next[layer][col]] = col;
                                }
                            }
                        }
                        int inside = colCount[col];
                        int left = col;
                        int right = col;
                        while (inside < need) {
                            if (next[0][right] < sentinel) {
                                right = next[0][right];
                                inside += colCount[right];
                            } else {
                                break;
                            }
                        }
                        while (true) {
                            if (inside == need) {
                                int leftFree = left + 1;
                                if (prev[0][left] < sentinel)
                                    leftFree -= prev[0][left] + 1;
                                int rightFree = cols - right;
                                if (next[0][right] < sentinel) {
                                    rightFree -= cols - next[0][right];
                                }
                                sofar -= leftFree * rightFree;
                            }
                            if (prev[0][left] == sentinel) {
                                break;
                            }
                            left = prev[0][left];
                            inside += colCount[left];
                            while (right > left && inside - colCount[right] >= need) {
                                inside -= colCount[right];
                                right = prev[0][right];
                            }
                            if (right < col) break;
                        }
                        cur = nextSameRow[cur];
                    }
                    res -= sofar;
                }
            }
            out.println(res);
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