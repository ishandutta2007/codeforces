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
        TaskH solver = new TaskH();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskH {
        public static final int MAX_LEN = 7;
        int[][] ne;
        int[] cnt;
        int[] last;
        int rptr;
        int[] ra;
        int[] rb;
        int needMask;
        static final int TEN = 10;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            ne = new int[MAX_LEN][MAX_LEN];
            for (int i = 0; i < n - 1; ++i) {
                int a = in.next().length();
                int b = in.next().length();
                ++ne[Math.min(a, b)][Math.max(a, b)];
            }
            cnt = new int[MAX_LEN];
            last = new int[MAX_LEN];
            int[] first = new int[MAX_LEN];
            ra = new int[n - 1];
            rb = new int[n - 1];
            rptr = 0;
            int p10 = TEN;
            int len = 1;
            needMask = 0;
            for (int i = 0; i < n; ++i) {
                if (i + 1 >= p10) {
                    p10 *= TEN;
                    ++len;
                }
                last[len] = i + 1;
                if (first[len] == 0) first[len] = i + 1;
                needMask |= (1 << len);
                ++cnt[len];
            }
        /*for (int i = 1; i < 6; ++i) {
            for (int j = 0; j < ne[i][i]; ++j) {
                --cnt[i];
                if (cnt[i] <= 0) {
                    out.println(-1);
                    return;
                }
                ra[rptr] = last[i];
                --last[i];
                rb[rptr] = last[i];
                ++rptr;
            }
            ne[i][i] = 0;
        }*/

            --cnt[1];
            --last[1];
            if (!rec(2)) {
                out.println(-1);
                return;
            }

            for (int a = 1; a < MAX_LEN; ++a) {
                for (int b = a; b < MAX_LEN; ++b) {
                    if (ne[a][b] > 0) {
                        int left = 0;
                        int right = Math.min(ne[a][b], cnt[a]) + 1;
                        while (right - left > 1) {
                            int middle = (left + right) / 2;
                            ne[a][b] -= middle;
                            cnt[a] -= middle;
                            if (valid()) {
                                left = middle;
                            } else {
                                right = middle;
                            }
                            ne[a][b] += middle;
                            cnt[a] += middle;
                        }
                        for (int i = 0; i < left; ++i) {
                            --ne[a][b];
                            --cnt[a];
                            ra[rptr] = last[a];
                            rb[rptr] = last[b] + 1;
                            ++rptr;
                            --last[a];
                        }
                        while (ne[a][b] > 0) {
                            --ne[a][b];
                            --cnt[b];
                            ra[rptr] = last[a] + 1;
                            rb[rptr] = last[b];
                            ++rptr;
                            --last[b];
                        }
                        if (!valid()) throw new RuntimeException();
                    }
                }
            }

            if (rptr != n - 1) throw new RuntimeException();
            for (int i = 1; i < MAX_LEN; ++i) {
                if (first[len] > 0 && last[len] != first[len] - 1) throw new RuntimeException();
            }
            for (int i = 0; i < n - 1; ++i) {
                out.println(ra[i] + " " + rb[i]);
            }
        }

        private boolean rec(int mask) {
            if (mask == needMask) {
                return valid();
            }
            for (int src = 1; src < MAX_LEN; ++src)
                if ((mask & (1 << src)) != 0)
                    for (int dst = 1; dst < MAX_LEN; ++dst)
                        if ((mask & (1 << dst)) == 0 && ne[Math.min(src, dst)][Math.max(src, dst)] > 0 && cnt[dst] > 0) {
                            --ne[Math.min(src, dst)][Math.max(src, dst)];
                            ra[rptr] = last[src] + 1;
                            rb[rptr] = last[dst];
                            ++rptr;
                            --last[dst];
                            --cnt[dst];
                            if (rec(mask | (1 << dst))) return true;
                            ++last[dst];
                            ++cnt[dst];
                            --rptr;
                            ++ne[Math.min(src, dst)][Math.max(src, dst)];
                        }
            return false;
        }

        private boolean valid() {
            for (int badSubset = 2; badSubset < needMask; ++badSubset) {
                int maxTotal = 0;
                int total = 0;
                for (int a = 1; a < MAX_LEN; ++a) {
                    if ((badSubset & (1 << a)) != 0) total += cnt[a];
                    for (int b = a; b < MAX_LEN; ++b) {
                        if ((badSubset & (1 << a)) != 0 || ((badSubset & (1 << b))) != 0) {
                            maxTotal += ne[a][b];
                        }
                    }
                }
                if (maxTotal < total) return false;
            }
            return true;
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