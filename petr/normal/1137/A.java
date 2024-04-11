import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Random;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.io.BufferedReader;
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
        TaskA solver = new TaskA();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskA {
        Random random = new Random(543715635151L + System.currentTimeMillis());

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int height = in.nextInt();
            int width = in.nextInt();
            int[][] a = new int[height][width];
            for (int r = 0; r < height; ++r) {
                for (int c = 0; c < width; ++c) {
                    a[r][c] = in.nextInt();
                }
            }
            int[][] res1 = new int[height][width];
            int[][] res2 = new int[height][width];
            {
                int[] tmp = new int[height];
                for (int c = 0; c < width; ++c) {
                    for (int r = 0; r < height; ++r) {
                        tmp[r] = a[r][c];
                    }
                    int cnt = sortUnique(tmp);
                    for (int r = 0; r < height; ++r) {
                        int pos = Arrays.binarySearch(tmp, 0, cnt, a[r][c]);
                        res1[r][c] = pos;
                        res2[r][c] = cnt - 1 - pos;
                    }
                }
            }
            {
                int[] tmp = new int[width];
                for (int r = 0; r < height; ++r) {
                    for (int c = 0; c < width; ++c) {
                        tmp[c] = a[r][c];
                    }
                    int cnt = sortUnique(tmp);
                    for (int c = 0; c < width; ++c) {
                        int pos = Arrays.binarySearch(tmp, 0, cnt, a[r][c]);
                        res1[r][c] = Math.max(res1[r][c], pos);
                        res2[r][c] = Math.max(res2[r][c], cnt - 1 - pos);
                    }
                }
            }
            for (int r = 0; r < height; ++r) {
                for (int c = 0; c < width; ++c) {
                    out.print(1 + res1[r][c] + res2[r][c]);
                    out.print(" ");
                }
                out.println();
            }
        }

        private int sortUnique(int[] tmp) {
            for (int i = 0; i < tmp.length; ++i) {
                int j = random.nextInt(i + 1);
                int t = tmp[i];
                tmp[i] = tmp[j];
                tmp[j] = t;
            }
            Arrays.sort(tmp);
            int cnt = 0;
            for (int i = 0; i < tmp.length; ++i) {
                if (cnt == 0 || tmp[i] != tmp[i - 1]) {
                    tmp[cnt++] = tmp[i];
                }
            }
            return cnt;
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