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
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int[] t = new int[n];
            int max = 0;
            for (int i = 0; i < n; ++i) {
                t[i] = in.nextInt();
                max += t[i];
            }
            --t[0];
            int[][] dirMask = new int[2 * max + 1][2 * max + 1];
            int[][] newDirMask = new int[2 * max + 1][2 * max + 1];
            // 0 1 2
            // 3 4 5
            // 6 7 8
            dirMask[max][max] = 1 << 1;
            int[] next = new int[]{1, 2, 5, 0, 4, 8, 3, 6, 7};
            int[] prev = new int[9];
            for (int i = 0; i < 9; ++i) prev[next[i]] = i;
            for (int step : t) {
                for (int i = 0; i < step; ++i) {
                    for (int[] x : newDirMask) Arrays.fill(x, 0);
                    for (int r = 0; r <= 2 * max; ++r) {
                        for (int c = 0; c <= 2 * max; ++c) {
                            int m = dirMask[r][c];
                            if (m != 0) {
                                m |= 1 << 4;
                                for (int dr = -1; dr <= 1; ++dr) {
                                    for (int dc = -1; dc <= 1; ++dc) {
                                        if ((m & (1 << (3 * (dr + 1) + (dc + 1)))) != 0) {
                                            newDirMask[r + dr][c + dc] |= (1 << (3 * (dr + 1) + (dc + 1)));
                                        }
                                    }
                                }
                            }
                        }
                    }
                    int[][] tmp = dirMask;
                    dirMask = newDirMask;
                    newDirMask = tmp;
                }
                {
                    for (int[] x : newDirMask) Arrays.fill(x, 0);
                    for (int r = 0; r <= 2 * max; ++r) {
                        for (int c = 0; c <= 2 * max; ++c) {
                            int m = dirMask[r][c];
                            if (m != 0) {
                                m |= 1 << 4;
                                for (int j = 0; j < 9; ++j) {
                                    if ((m & (1 << j)) != 0) {
                                        newDirMask[r][c] |= 1 << prev[j];
                                        newDirMask[r][c] |= 1 << next[j];
                                    }
                                }
                            }
                        }
                    }
                    int[][] tmp = dirMask;
                    dirMask = newDirMask;
                    newDirMask = tmp;
                }
            }
            int res = 0;
            for (int[] x : dirMask) {
                for (int y : x) {
                    if (y != 0) ++res;
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