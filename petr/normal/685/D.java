import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.util.Comparator;
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
            int k = in.nextInt();
            TaskD.Event[] events = new TaskD.Event[2 * n];
            int[] allX = new int[n];
            for (int i = 0; i < n; ++i) {
                int x = in.nextInt();
                int y = in.nextInt();
                allX[i] = x;
                events[i] = new TaskD.Event(x, y, 1);
                events[i + n] = new TaskD.Event(x, y + k, -1);
            }
            Arrays.sort(allX);
            int cntX = 0;
            for (int i = 0; i < n; ++i) {
                if (i == 0 || allX[i] > allX[i - 1]) {
                    allX[cntX++] = allX[i];
                }
            }
            allX = Arrays.copyOf(allX, cntX);
            for (int i = 0; i < n; ++i) {
                events[i + n].compressedX = events[i].compressedX = Arrays.binarySearch(allX, events[i].x);
            }
            Arrays.sort(events, new Comparator<TaskD.Event>() {

                public int compare(TaskD.Event o1, TaskD.Event o2) {
                    return Integer.compare(o1.y, o2.y);
                }
            });
            int[] compressedCount = new int[cntX];
            long[] res = new long[n + 1];
            int[] around = new int[2 * k - 1];
            for (TaskD.Event e : events) {
                Arrays.fill(around, 0);
                int x = e.x;
                int y = e.y;
                int delta = e.delta;
                int cx = e.compressedX;
                around[k - 1] = compressedCount[cx];
                for (int j = cx - 1; j >= 0; --j) {
                    int dx = allX[j] - x + (k - 1);
                    if (dx < 0) break;
                    around[dx] = compressedCount[j];
                }
                for (int j = cx + 1; j < cntX; ++j) {
                    int dx = allX[j] - x + (k - 1);
                    if (dx >= 2 * k - 1) break;
                    around[dx] = compressedCount[j];
                }
                int s = 0;
                for (int i = 0; i < k; ++i) {
                    s += around[i];
                }
                for (int shift = 0; shift < k; ++shift) {
                    res[s] += y;
                    res[s + delta] -= y;
                    if (shift + 1 < k) {
                        s += around[k + shift] - around[shift];
                    }
                }
                compressedCount[cx] += delta;
            }
            for (int i = 1; i <= n; ++i) {
                if (i > 1) out.print(" ");
                out.print(res[i]);
            }
            out.println();
        }

        static class Event {
            int x;
            int compressedX;
            int y;
            int delta;

            public Event(int x, int y, int delta) {
                this.x = x;
                this.y = y;
                this.delta = delta;
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