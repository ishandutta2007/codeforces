import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.util.Comparator;
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
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int m = in.nextInt();
            TaskE.Contestant[] contestants = new TaskE.Contestant[n];
            for (int i = 0; i < n; ++i) {
                contestants[i] = new TaskE.Contestant();
                contestants[i].x = in.nextInt();
                contestants[i].y = in.nextInt();
            }
            for (int i = 0; i < m; ++i) {
                TaskE.Contestant a = contestants[in.nextInt() - 1];
                TaskE.Contestant b = contestants[in.nextInt() - 1];
                long score = Math.min(a.x + b.y, a.y + b.x);
                a.answer -= score;
                b.answer -= score;
            }
            TaskE.Contestant[] sorted = contestants.clone();
            Arrays.sort(sorted, new Comparator<TaskE.Contestant>() {

                public int compare(TaskE.Contestant o1, TaskE.Contestant o2) {
                    long s1 = o1.x - o1.y;
                    long s2 = o2.x - o2.y;
                    return Long.compare(s1, s2);
                }
            });
            long[] prefixSumX = new long[n + 1];
            long[] prefixSumY = new long[n + 1];
            for (int i = 0; i < n; ++i) {
                prefixSumX[i + 1] = prefixSumX[i] + sorted[i].x;
                prefixSumY[i + 1] = prefixSumY[i] + sorted[i].y;
            }
            for (int i = 0; i < n; ++i) {
                TaskE.Contestant c = sorted[i];
                c.answer += c.y * i + prefixSumX[i];
                c.answer += c.x * (n - 1 - i) + prefixSumY[n] - prefixSumY[i + 1];
            }
            for (TaskE.Contestant c : contestants) {
                out.print(c.answer + " ");
            }
            out.println();
        }

        static class Contestant {
            long x;
            long y;
            long answer;

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