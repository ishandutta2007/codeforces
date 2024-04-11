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
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskE {
        static final long MODULO = (long) (1e9 + 7);

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            String[] lines = new String[2];
            for (int i = 0; i < 2; ++i) lines[i] = in.next();
            int width = lines[0].length();
            String need = in.next();
            int len = need.length();
            long res = 0;
            if (need.length() == 1) {
                for (int row = 0; row < 2; ++row)
                    for (int col = 0; col < width; ++col)
                        if (lines[row].charAt(col) == need.charAt(0))
                            ++res;
            } else {
                short[][][] matchRight = new short[2][width][len];
                short[][][] matchLeft = new short[2][width][len];
                Descriptor normal = new Descriptor(lines, need, matchLeft, matchRight, null);
                for (int col = 0; col < width; ++col) {
                    for (int row = 0; row < 2; ++row) {
                        for (int cur = 0; cur < len; ++cur)
                            if (normal.matchRight[row][col][cur] >= 2) {
                                normal.waysGoingRight[row][col + 1][cur + 1] += normal.waysGoingRight[row][col][cur];
                                normal.waysGoingRight[row][col + 1][cur + 1] %= MODULO;
                            }
                        for (int cur = 0; cur + 1 < len; ++cur)
                            if (normal.matchRight[1 - row][col][cur + 1] >= 2) {
                                normal.waysGoingRight[1 - row][col + 1][cur + 2] += normal.waysGoingRight[row][col][cur];
                                normal.waysGoingRight[1 - row][col + 1][cur + 2] %= MODULO;
                            }
                    }
                }
                for (int col = width - 1; col >= 0; --col) {
                    for (int row = 0; row < 2; ++row) {
                        for (int cur = 0; cur < len; ++cur)
                            if (normal.matchLeft[row][col][cur] >= 2) {
                                normal.waysGoingLeft[row][col - 1][cur + 1] += normal.waysGoingLeft[row][col][cur];
                                normal.waysGoingLeft[row][col - 1][cur + 1] %= MODULO;
                            }
                        for (int cur = 0; cur + 1 < len; ++cur)
                            if (normal.matchLeft[1 - row][col][cur + 1] >= 2) {
                                normal.waysGoingLeft[1 - row][col - 1][cur + 2] += normal.waysGoingLeft[row][col][cur];
                                normal.waysGoingLeft[1 - row][col - 1][cur + 2] %= MODULO;
                            }
                    }
                }
                StringBuilder needRev = new StringBuilder(need);
                Descriptor reversed = new Descriptor(lines, needRev.reverse().toString(), matchLeft, matchRight, normal);
                res += reversed.res;
            }
            res %= MODULO;
            out.println(res);
        }

        static class Descriptor {
            long res;
            short[][][] matchRight;
            short[][][] matchLeft;
            int[][][] waysGoingRight;
            int[][][] waysGoingLeft;

            public Descriptor(String[] lines, String need, short[][][] matchRight, short[][][] matchLeft, Descriptor normal) {
                this.matchRight = matchRight;
                this.matchLeft = matchLeft;
                for (short[][] x : matchRight) for (short[] y : x) Arrays.fill(y, (short) 0);
                for (short[][] x : matchLeft) for (short[] y : x) Arrays.fill(y, (short) 0);
                res = 0;
                int width = lines[0].length();
                int len = need.length();
                for (int row = 0; row < 2; ++row) {
                    for (int col = 0; col < width; ++col) {
                        for (int pos = 0; pos < len; ++pos) {
                            if (need.charAt(pos) == lines[row].charAt(col)) {
                                matchLeft[row][col][pos] = 1;
                                if (pos + 1 < len && col > 0)
                                    matchLeft[row][col][pos] += matchLeft[row][col - 1][pos + 1];
                            }
                        }
                    }
                }
                for (int row = 0; row < 2; ++row) {
                    for (int col = width - 1; col >= 0; --col) {
                        for (int pos = 0; pos < len; ++pos) {
                            if (need.charAt(pos) == lines[row].charAt(col)) {
                                matchRight[row][col][pos] = 1;
                                if (pos + 1 < len && col + 1 < width)
                                    matchRight[row][col][pos] += matchRight[row][col + 1][pos + 1];
                            }
                        }
                    }
                }
                if (normal == null) {
                    waysGoingLeft = new int[2][width][len];
                    waysGoingRight = new int[2][width][len];
                }
                for (int row = 0; row < 2; ++row) {
                    for (int col = 0; col < width; ++col) {
                        int maxLeft = matchLeft[row][col][0];
                        for (int goLeft = 1; goLeft <= maxLeft; ++goLeft) {
                            if (goLeft == len) {
                                ++res;
                            } else if (lines[1 - row].charAt(col - goLeft + 1) == need.charAt(goLeft)) {
                                if (goLeft + 1 == len) {
                                    ++res;
                                } else {
                                    int ml = matchLeft[1 - row][col - goLeft + 1][goLeft];
                                    if (ml >= 2) {
                                        if (normal == null) {
                                            ++waysGoingLeft[1 - row][col - goLeft][goLeft + 1];
                                        } else {
                                            res += normal.waysGoingRight[1 - row][col - goLeft + 1][len - (goLeft + 1)];
                                        }
                                    }
                                    if (goLeft + ml == len) {
                                        ++res;
                                    }
                                    int mr = matchRight[1 - row][col - goLeft + 1][goLeft];
                                    if (mr >= 1 + goLeft) {
                                        if (normal == null) {
                                            ++waysGoingRight[1 - row][col + 1][2 * goLeft];
                                        } else {
                                            res += normal.waysGoingLeft[1 - row][col][len - (2 * goLeft)];
                                        }
                                    }
                                    if (goLeft + mr == len) {
                                        ++res;
                                    }
                                }
                            }
                        }
                        int maxRight = matchRight[row][col][0];
                        for (int goRight = 2; goRight <= maxRight; ++goRight) {
                            if (goRight == len) {
                                ++res;
                            } else if (lines[1 - row].charAt(col + goRight - 1) == need.charAt(goRight)) {
                                if (goRight + 1 == len) {
                                    ++res;
                                } else {
                                    int mr = matchRight[1 - row][col + goRight - 1][goRight];
                                    if (mr >= 2) {
                                        if (normal == null) {
                                            ++waysGoingRight[1 - row][col + goRight][goRight + 1];
                                        } else {
                                            res += normal.waysGoingLeft[1 - row][col + goRight - 1][len - (goRight + 1)];
                                        }
                                    }
                                    if (goRight + mr == len) {
                                        ++res;
                                    }
                                    int ml = matchLeft[1 - row][col + goRight - 1][goRight];
                                    if (ml >= 1 + goRight) {
                                        if (normal == null) {
                                            ++waysGoingLeft[1 - row][col - 1][2 * goRight];
                                        } else {
                                            res += normal.waysGoingRight[1 - row][col][len - (2 * goRight)];
                                        }
                                    }
                                    if (goRight + ml == len) {
                                        ++res;
                                    }
                                }
                            }
                        }
                    }
                }
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

    }
}