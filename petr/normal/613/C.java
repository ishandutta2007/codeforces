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
            int numColors = in.nextInt();
            int[] count = new int[numColors];
            int n = 0;
            for (int i = 0; i < numColors; ++i) {
                count[i] = in.nextInt();
                n += count[i];
            }
            int best = 0;
            int bestPeriod = -1;
            for (int period = 1; period <= n; ++period) {
                if (n % period != 0) continue;
                int bigGroup;
                int bigGroupCount;
                int smallGroup;
                int smallGroupCount;
                if (period % 2 == 0) {
                    bigGroupCount = period / 2;
                    bigGroup = 2 * (n / period);
                    smallGroup = bigGroup;
                    smallGroupCount = 0;
                } else {
                    bigGroupCount = period / 2;
                    bigGroup = 2 * (n / period);
                    smallGroupCount = 1;
                    smallGroup = n / period;
                }
                int numSmalls = 0;
                boolean ok = true;
                for (int cnt : count) {
                    if (cnt % bigGroup == 0) {
                        continue;
                    }
                    if ((cnt >= smallGroup) && (cnt - smallGroup) % bigGroup == 0) {
                        ++numSmalls;
                        continue;
                    }
                    ok = false;
                    break;
                }
                if (!ok) continue;
                if (numSmalls != smallGroupCount) continue;
                int cur;
                if (n % 2 == 0) {
                    if (period % 2 == 0) {
                        cur = 2 * (n / period);
                    } else {
                        cur = 2 * (n / (2 * period));
                    }
                } else {
                    cur = n / period;
                }
                if (cur > best) {
                    best = cur;
                    bestPeriod = period;
                }
            }
            out.println(best);
            char[] b = new char[n];
            if (best == 0) {
                int ptr = 0;
                for (int i = 0; i < numColors; ++i) {
                    for (int j = 0; j < count[i]; ++j) {
                        b[ptr++] = ((char) ('a' + i));
                    }
                }
            } else {
                int period = bestPeriod;
                int bigGroup;
                int bigGroupCount;
                int smallGroup;
                int smallGroupCount;
                if (period % 2 == 0) {
                    bigGroupCount = period / 2;
                    bigGroup = 2 * (n / period);
                    smallGroup = bigGroup;
                    smallGroupCount = 0;
                } else {
                    bigGroupCount = period / 2;
                    bigGroup = 2 * (n / period);
                    smallGroupCount = 1;
                    smallGroup = n / period;
                }
                int smallId = -1;
                for (int i = 0; i < count.length; ++i) {
                    int cnt = count[i];
                    if (cnt % bigGroup == 0) {
                        continue;
                    }
                    if ((cnt >= smallGroup) && (cnt - smallGroup) % bigGroup == 0) {
                        smallId = i;
                        continue;
                    }
                    break;
                }
                if (smallId >= 0) {
                    count[smallId] -= smallGroup;
                    for (int i = 0; i < n / period; ++i) {
                        b[i * period + (period / 2)] = (char) ('a' + smallId);
                    }
                }
                int nextColor = 0;
                for (int j = 0; j < bigGroupCount; ++j) {
                    while (count[nextColor] == 0) ++nextColor;
                    count[nextColor] -= bigGroup;
                    for (int i = 0; i < n / period; ++i) {
                        b[i * period + j] = (char) ('a' + nextColor);
                        b[i * period + period - 1 - j] = (char) ('a' + nextColor);
                    }
                }
                for (int x : count) if (x != 0) throw new RuntimeException();
            }
            out.println(new String(b));
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