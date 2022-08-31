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
        int MAXLEN = 252;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int q = in.nextInt();
            String s = in.next();
            int[][] next = new int[26][s.length() + 1];
            for (int w = 0; w < 26; ++w) {
                int nxt = s.length();
                next[w][nxt] = nxt;
                for (int i = s.length() - 1; i >= 0; --i) {
                    if (s.charAt(i) == ('a' + w)) {
                        nxt = i;
                    }
                    next[w][i] = nxt;
                }
            }
            int[][][] a = new int[MAXLEN][MAXLEN][MAXLEN];
            a[0][0][0] = 0;
            int[] len = new int[3];
            int[][] content = new int[3][MAXLEN];
            int[] t = new int[3];
            for (int qi = 0; qi < q; ++qi) {
                String what = in.next();
                if (what.equals("+")) {
                    int which = in.nextInt() - 1;
                    int ch = in.next().charAt(0) - 'a';
                    content[which][len[which]] = ch;
                    int o1 = (which + 1) % 3;
                    int o2 = (which + 2) % 3;
                    for (int p1 = 0; p1 <= len[o1]; ++p1) {
                        for (int p2 = 0; p2 <= len[o2]; ++p2) {
                            t[o1] = p1;
                            t[o2] = p2;
                            t[which] = len[which];
                            int val = a[t[0]][t[1]][t[2]];
                            if (val <= s.length()) val = next[ch][val] + 1;
                            ++t[which];
                            int best = val;
                            if (p1 > 0) {
                                --t[o1];
                                val = a[t[0]][t[1]][t[2]];
                                if (val <= s.length()) val = next[content[o1][p1 - 1]][val] + 1;
                                best = Math.min(best, val);
                                ++t[o1];
                            }
                            if (p2 > 0) {
                                --t[o2];
                                val = a[t[0]][t[1]][t[2]];
                                if (val <= s.length()) val = next[content[o2][p2 - 1]][val] + 1;
                                best = Math.min(best, val);
                                ++t[o2];
                            }
                            a[t[0]][t[1]][t[2]] = best;
                        }
                    }
                    ++len[which];
                } else {
                    int which = in.nextInt() - 1;
                    --len[which];
                }
                out.println(a[len[0]][len[1]][len[2]] <= s.length() ? "YES" : "NO");
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