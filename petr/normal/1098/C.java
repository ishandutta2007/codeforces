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
            int n = in.nextInt();
            long max = n * (long) (n + 1) / 2;
            long s = in.nextLong();
            if (s > max) {
                out.println("No");
                return;
            }
            for (int d = 1; d < n; d++) {
                long thisLevel = 1;
                long min = 1;
                long togo = n - 1;
                int level = 1;
                while (togo > 0) {
                    ++level;
                    thisLevel *= d;
                    long by = Math.min(togo, thisLevel);
                    min += by * level;
                    togo -= by;
                }
                if (min > s) continue;
                int[] p = new int[n];
                p[0] = -1;
                for (int i = 1; i < n; ++i) p[i] = i - 1;
                long got = n * (long) (n + 1) / 2;
                int[] firstByLevel = new int[n + 1];
                int[] nextByLevel = new int[n + 1];
                int[] lastByLevel = new int[n + 1];
                int[] numChildren = new int[n + 1];
                for (int i = 0; i < n; ++i) {
                    firstByLevel[i + 1] = lastByLevel[i + 1] = i;
                    nextByLevel[i] = -1;
                    if (i + 1 < n) ++numChildren[i];
                }
                level = 2;
                for (int i = n - 1; i > 0 && got > s; --i) {
                    while (true) {
                        if (firstByLevel[level - 1] < 0) {
                            ++level;
                            continue;
                        }
                        if (numChildren[firstByLevel[level - 1]] == d) {
                            firstByLevel[level - 1] = nextByLevel[firstByLevel[level - 1]];
                            continue;
                        }
                        break;
                    }
                    int from = i + 1;
                    int to = level;
                    if (from <= to) throw new RuntimeException();
                    int by = (int) Math.min(from - to, got - s);
                    got -= by;
                    to = from - by;
                    if (i != firstByLevel[i + 1]) throw new RuntimeException();
                    firstByLevel[i + 1] = nextByLevel[i];
                    --numChildren[p[i]];
                    p[i] = firstByLevel[to - 1];
                    ++numChildren[p[i]];
                    if (numChildren[p[i]] > d) throw new RuntimeException();
                    nextByLevel[lastByLevel[to]] = i;
                    nextByLevel[i] = -1;
                    lastByLevel[to] = i;
                }
                out.println("Yes");
                for (int i = 1; i < n; ++i) {
                    out.print(p[i] + 1);
                    out.print(" ");
                }
                out.println();
                return;
            }
            out.println("No");
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

        public long nextLong() {
            return Long.parseLong(next());
        }

    }
}