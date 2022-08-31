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
        static final int INF = (int) 1e9;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int[][] score = new int[n][3];
            boolean[][] hackable = new boolean[n][3];
            int totalHackable = 0;
            int[] hackableProblems = new int[3];
            int[] solvedProblems = new int[3];
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < 3; ++j) {
                    int x = in.nextInt();
                    if (x != 0) {
                        ++solvedProblems[j];
                        if (x < 0) {
                            hackable[i][j] = true;
                            ++totalHackable;
                            ++hackableProblems[j];
                            x = -x;
                        }
                        score[i][j] = 2 * (250 - x);
                    }
                }
            }
            if (totalHackable >= 90) {
                out.println(1);
                return;
            }
            int[][][] best = new int[hackableProblems[0] + 1][hackableProblems[1] + 1][hackableProblems[2] + 1];
            int[] s = new int[3];
            int[] minHacks = new int[3];
            int[] maxHacks = new int[3];
            int res = n;
            for (s[0] = 1; s[0] <= 6; ++s[0]) {
                for (s[1] = 1; s[1] <= 6; ++s[1]) {
                    outer:
                    for (s[2] = 1; s[2] <= 6; ++s[2]) {
                        for (int j = 0; j < 3; ++j) {
                            minHacks[j] = INF;
                            maxHacks[j] = -INF;
                            for (int hacks = 0; hacks <= hackableProblems[j]; ++hacks) {
                                int standing = solvedProblems[j] - hacks;
                                if ((s[j] == 6 || n < (standing << s[j])) && (standing << s[j]) <= 2 * n) {
                                    minHacks[j] = Math.min(minHacks[j], hacks);
                                    maxHacks[j] = Math.max(maxHacks[j], hacks);
                                }
                            }
                            if (minHacks[j] > hackableProblems[j]) continue outer;
                        }
                        for (int[][] xx : best) for (int[] yy : xx) Arrays.fill(yy, -1);
                        int our = 0;
                        for (int j = 0; j < 3; ++j) {
                            our += score[0][j] * s[j];
                            our += 100 * maxHacks[j];
                        }
                        best[0][0][0] = 0;
                        int definite = 0;
                        for (int i = 1; i < n; ++i) {
                            int canHack = 0;
                            for (int j = 0; j < 3; ++j) if (hackable[i][j]) canHack |= 1 << j;
                            if (canHack == 0) {
                                int their = 0;
                                for (int j = 0; j < 3; ++j) {
                                    their += score[i][j] * s[j];
                                }
                                if (their <= our) {
                                    ++definite;
                                }
                            } else {
                                for (int old0 = maxHacks[0]; old0 >= 0; --old0) {
                                    for (int old1 = maxHacks[1]; old1 >= 0; --old1) {
                                        for (int old2 = maxHacks[2]; old2 >= 0; --old2) {
                                            int ow = best[old0][old1][old2];
                                            if (ow < 0) continue;
                                            for (int toHack = canHack; ; toHack = (toHack - 1) & canHack) {
                                                int their = 0;
                                                for (int j = 0; j < 3; ++j) {
                                                    if ((toHack & (1 << j)) == 0) their += score[i][j] * s[j];
                                                }
                                                int new0 = old0 + ((toHack & (1 << 0)) != 0 ? 1 : 0);
                                                int new1 = old1 + ((toHack & (1 << 1)) != 0 ? 1 : 0);
                                                int new2 = old2 + ((toHack & (1 << 2)) != 0 ? 1 : 0);
                                                int got = their <= our ? 1 : 0;
                                                best[new0][new1][new2] = Math.max(best[new0][new1][new2], ow + got);
                                                if (toHack == 0) break;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        for (int old0 = maxHacks[0]; old0 >= 0; --old0) {
                            for (int old1 = maxHacks[1]; old1 >= 0; --old1) {
                                for (int old2 = maxHacks[2]; old2 >= 0; --old2) {
                                    int ow = best[old0][old1][old2];
                                    if (ow >= 0) {
                                        res = Math.min(res, n - ow - definite);
                                    }
                                }
                            }
                        }
                    }
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