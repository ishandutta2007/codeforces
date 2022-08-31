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
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskB {
        String CHARS = "ACTG";

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int height = in.nextInt();
            int width = in.nextInt();
            char[][] data = new char[height][];
            for (int row = 0; row < height; ++row) data[row] = in.next().toCharArray();
            int bestFlip = -1;
            int bestMatches = -1;
            char[][] best = null;
            for (int flip = 0; flip < 2; ++flip) {
                char[] ch = new char[4];
                int[] first = new int[height];
                for (int i1 = 0; i1 < CHARS.length(); ++i1) {
                    for (int i2 = i1 + 1; i2 < CHARS.length(); ++i2) {
                        int i3 = 0;
                        while (i3 == i1 || i3 == i2) ++i3;
                        int i4 = i3 + 1;
                        while (i4 == i1 || i4 == i2) ++i4;
                        ch[0] = CHARS.charAt(i1);
                        ch[1] = CHARS.charAt(i2);
                        ch[2] = CHARS.charAt(i3);
                        ch[3] = CHARS.charAt(i4);
                        int matches = 0;
                        for (int r = 0; r < height; ++r) {
                            int curBest = -1;
                            int curBestVia = -1;
                            int delta = 2 * (r % 2);
                            for (int f = 0; f < 2; ++f) {
                                int cur = 0;
                                for (int c = 0; c < width; ++c) {
                                    char got = ch[delta + (f ^ (c & 1))];
                                    if (got == data[r][c]) ++cur;
                                }
                                if (cur > curBest) {
                                    curBest = cur;
                                    curBestVia = f;
                                }
                            }
                            matches += curBest;
                            first[r] = curBestVia;
                        }
                        if (matches > bestMatches) {
                            bestMatches = matches;
                            bestFlip = flip;
                            best = new char[height][width];
                            for (int r = 0; r < height; ++r) {
                                int delta = 2 * (r % 2);
                                int f = first[r];
                                for (int c = 0; c < width; ++c) {
                                    char got = ch[delta + (f ^ (c & 1))];
                                    best[r][c] = got;
                                }
                            }
                        }
                    }
                }
                {
                    char[][] ndata = flipMatrix(height, width, data);
                    int tmp = height;
                    height = width;
                    width = tmp;
                    data = ndata;
                }
            }
            if (bestFlip == 1) {
                best = flipMatrix(width, height, best);
            }
            for (int row = 0; row < height; ++row) {
                out.println(new String(best[row]));
            }
        }

        private char[][] flipMatrix(int height, int width, char[][] data) {
            char[][] ndata = new char[width][height];
            for (int row = 0; row < height; ++row) {
                for (int col = 0; col < width; ++col) {
                    ndata[col][row] = data[row][col];
                }
            }
            return ndata;
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