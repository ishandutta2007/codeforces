import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
import java.io.BufferedReader;
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
            TaskE.Vertex[] v = new TaskE.Vertex[n];
            for (int i = 0; i < n; ++i) {
                v[i] = new TaskE.Vertex();
            }
            for (int i = 0; i < n - 1; ++i) {
                TaskE.Vertex a = v[in.nextInt() - 1];
                TaskE.Vertex b = v[in.nextInt() - 1];
                long len = in.nextLong();
                TaskE.Edge ab = new TaskE.Edge(a, b, len);
                TaskE.Edge ba = new TaskE.Edge(b, a, len);
                ab.rev = ba;
                ba.rev = ab;
                a.edges.add(ab);
                b.edges.add(ba);
            }
            TaskE.Vertex police = v[in.nextInt() - 1];
            int m = in.nextInt();
            for (int i = 0; i < m; ++i) {
                ++v[in.nextInt() - 1].startCount;
            }
            for (TaskE.Vertex u : v) {
                for (TaskE.Edge e : u.edges) {
                    e.res = new long[m + 1][m + 1];
                    for (long[] x : e.res) Arrays.fill(x, -1);
                }
            }
            police.findSubtreeSums(null);
            long res = Long.MAX_VALUE;
            for (TaskE.Edge e : police.edges)
                if (e.dst.subtreeSum > 0) {
                    res = Math.min(res, e.solve(m, e.dst.subtreeSum));
                }
            out.println(res);
        }

        static class Edge {
            TaskE.Vertex src;
            TaskE.Vertex dst;
            TaskE.Edge rev;
            long[][] res;
            long len;

            public Edge(TaskE.Vertex src, TaskE.Vertex dst, long len) {
                this.src = src;
                this.dst = dst;
                this.len = len;
            }

            public long solve(int totalRemaining, int inSubtree) {
                if (totalRemaining == 0) return 0;
                if (res[totalRemaining][inSubtree] >= 0) return res[totalRemaining][inSubtree];
                boolean any = false;
                long[] worst = new long[totalRemaining + 1];
                Arrays.fill(worst, -1);
                worst[0] = Long.MAX_VALUE;
                for (TaskE.Edge e : dst.edges) {
                    if (e.dst != src) {
                        any = true;
                        for (int before = worst.length - 1; before >= 0; --before)
                            if (worst[before] >= 0) {
                                for (int here = 1; before + here <= totalRemaining; ++here) {
                                    long got = e.solve(totalRemaining, here);
                                    worst[before + here] = Math.max(worst[before + here], Math.min(worst[before], got));
                                }
                            }
                    }
                }
                if (!any) {
                    for (int a = 1; a <= totalRemaining; ++a) {
                        res[totalRemaining][a] = len + rev.solve(totalRemaining - a, totalRemaining - a);
                    }
                } else {
                    for (int a = 1; a <= totalRemaining; ++a) {
                        res[totalRemaining][a] = len + worst[a];
                    }
                }
                return res[totalRemaining][inSubtree];
            }

        }

        static class Vertex {
            int startCount;
            int subtreeSum;
            List<TaskE.Edge> edges = new ArrayList<>();

            public void findSubtreeSums(TaskE.Vertex parent) {
                subtreeSum = startCount;
                for (TaskE.Edge e : edges)
                    if (e.dst != parent) {
                        e.dst.findSubtreeSums(this);
                        subtreeSum += e.dst.subtreeSum;
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

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public long nextLong() {
            return Long.parseLong(next());
        }

    }
}