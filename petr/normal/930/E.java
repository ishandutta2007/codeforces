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
        static final int MODULO = (int) (1e9 + 7);

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int k = in.nextInt();
            int n = in.nextInt();
            int m = in.nextInt();
            TaskE.Segment[] segments = new TaskE.Segment[n + m];
            for (int i = 0; i < n; ++i) {
                segments[i] = new TaskE.Segment();
                segments[i].l = in.nextInt();
                segments[i].r = in.nextInt();
                segments[i].kind = 0;
            }
            for (int i = n; i < n + m; ++i) {
                segments[i] = new TaskE.Segment();
                segments[i].l = in.nextInt();
                segments[i].r = in.nextInt();
                segments[i].kind = 1;
            }
            Arrays.sort(segments, new Comparator<TaskE.Segment>() {

                public int compare(TaskE.Segment o1, TaskE.Segment o2) {
                    return o1.r - o2.r;
                }
            });
            TaskE.Block[] blocks = new TaskE.Block[4 * segments.length + 10];
            int numBlocks = 1;
            blocks[0] = new TaskE.Block();
            blocks[0].a0 = 1;
            blocks[0].b0 = 1;
            blocks[0].first = 0;
            blocks[0].last = 0;
            int at = 0;
            int ptr = 0;
            int[] from = new int[2];
            int[] inBlock = new int[2];
            int[] sum = new int[2];
            Arrays.fill(sum, 1);
            while (at < k) {
                ++at;
                boolean anyChanges = false;
                while (ptr < segments.length && segments[ptr].r == at) {
                    int kind = segments[ptr].kind;
                    int dest = segments[ptr].l;
                    while (from[kind] < dest) {
                        anyChanges = true;
                        TaskE.Block b = blocks[inBlock[kind]];
                        if (b.first > from[kind]) throw new RuntimeException();
                        if (b.last < from[kind]) throw new RuntimeException();
                        if (b.last < dest) {
                            sum[kind] = (int) ((sum[kind] - (kind == 0 ? b.a0 : b.b0) * (pow(2, b.last - b.first + 1) - pow(2, from[kind] - b.first) + MODULO) % MODULO + MODULO) % MODULO);
                            from[kind] = b.last + 1;
                            ++inBlock[kind];
                        } else {
                            sum[kind] = (int) ((sum[kind] - (kind == 0 ? b.a0 : b.b0) * (pow(2, dest - b.first) - pow(2, from[kind] - b.first) + MODULO) % MODULO + MODULO) % MODULO);
                            from[kind] = dest;
                        }
                    }
                    ++ptr;
                }
                int upto = at;
                if (!anyChanges && at < k) {
                    upto = k - 1;
                    if (ptr < segments.length) upto = Math.min(upto, segments[ptr].r - 1);
                }
                TaskE.Block b = new TaskE.Block();
                b.first = at;
                b.last = upto;
                b.a0 = sum[1];
                b.b0 = sum[0];
                long mult = pow(2, upto - at + 1) - 1 + MODULO;
                sum[0] = (int) ((sum[0] + b.a0 * mult) % MODULO);
                sum[1] = (int) ((sum[1] + b.b0 * mult) % MODULO);
                blocks[numBlocks++] = b;
                at = upto;
            }
            {
                TaskE.Block b = blocks[numBlocks - 1];
                if (b.first != k || b.last != k) throw new RuntimeException();
                out.println((b.a0 + b.b0) % MODULO);
            }
        }

        long pow(long a, int k) {
            long res = 1;
            while (k > 0) {
                if ((k & 1) != 0) {
                    res = res * a % MODULO;
                }
                a = a * a % MODULO;
                k >>= 1;
            }
            return res;
        }

        static class Segment {
            int l;
            int r;
            int kind;

        }

        static class Block {
            int a0;
            int b0;
            int first;
            int last;

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