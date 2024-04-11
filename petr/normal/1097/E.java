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
        int testCount = Integer.parseInt(in.next());
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class TaskE {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int[] f = new int[n + 1];
            for (int a = 1; a <= n; ++a) {
                int best = 0;
                for (int x = 1; x <= a; ++x) {
                    if (f[a - x] + 1 <= x) {
                        best = Math.max(best, f[a - x] + 1);
                        break;
                    }
                    best = Math.max(best, x);
                }
                f[a] = best;
            }

            int allowed = f[n];
            int done = 0;

            int[] seq = new int[n];
            for (int i = 0; i < n; ++i) seq[i] = in.nextInt();

            boolean[] alive = new boolean[n];
            Arrays.fill(alive, true);

            int[][] res = new int[allowed][];

            int[] best = new int[n + 1];
            int[] bestPos = new int[n + 1];
            int[] level = new int[n];
            int[] via = new int[n];
            while (true) {
                best[0] = 0;
                bestPos[0] = -1;
                int max = 0;
                boolean any = false;
                for (int i = 0; i < n; ++i)
                    if (alive[i]) {
                        any = true;
                        int x = seq[i];
                        int left = 0;
                        int right = max + 1;
                        while (right - left > 1) {
                            int mid = (left + right) >> 1;
                            if (best[mid] < x) {
                                left = mid;
                            } else {
                                right = mid;
                            }
                        }
                        level[i] = left;
                        via[i] = bestPos[left];
                        best[right] = x;
                        bestPos[right] = i;
                        if (right > max) {
                            ++max;
                        }
                    }
                if (!any) break;

                if (done + max <= allowed) {
                    int[] cnt = new int[max];
                    for (int i = 0; i < n; ++i) if (alive[i]) ++cnt[level[i]];
                    for (int i = 0; i < max; ++i) {
                        res[done + i] = new int[cnt[i]];
                    }
                    Arrays.fill(cnt, 0);
                    for (int i = 0; i < n; ++i)
                        if (alive[i]) {
                            res[done + level[i]][cnt[level[i]]++] = seq[i];
                            alive[i] = false;
                        }
                    done += max;
                } else {
                    res[done] = new int[max];
                    boolean found = false;
                    for (int i = 0; i < n; ++i)
                        if (alive[i] && level[i] == max - 1) {
                            found = true;
                            int j = max - 1;
                            int at = i;
                            while (at >= 0) {
                                res[done][j] = seq[at];
                                alive[at] = false;
                                at = via[at];
                                --j;
                            }
                            if (j != -1) throw new RuntimeException();
                            break;
                        }
                    if (!found) throw new RuntimeException();
                    ++done;
                }
            }

            out.println(done);
            for (int i = 0; i < done; ++i) {
                int[] cur = res[i];
                out.print(cur.length);
                for (int x : cur) {
                    out.print(" ");
                    out.print(x);
                }
                out.println();
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