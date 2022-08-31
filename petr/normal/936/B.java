import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.List;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;
import java.util.ArrayList;

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
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int m = in.nextInt();
            TaskB.Vertex[] vs = new TaskB.Vertex[2 * n];
            for (int i = 0; i < 2 * n; ++i) {
                vs[i] = new TaskB.Vertex(i / 2 + 1);
            }
            for (int i = 0; i < n; ++i) {
                int c = in.nextInt();
                for (int j = 0; j < c; ++j) {
                    int k = in.nextInt() - 1;
                    vs[2 * i].outgo.add(vs[2 * k + 1]);
                    vs[2 * i + 1].outgo.add(vs[2 * k]);
                }
            }
            TaskB.Vertex start = vs[2 * (in.nextInt() - 1)];
            start.dfs(null);
            for (int i = 0; i < n; ++i) {
                TaskB.Vertex dest = vs[2 * i + 1];
                if (dest.state == 2 && dest.outgo.isEmpty()) {
                    out.println("Win");
                    int[] seq = new int[2 * n];
                    int nseq = 0;
                    while (dest != null) {
                        seq[nseq++] = dest.index;
                        dest = dest.reach;
                    }
                    for (int j = nseq - 1; j >= 0; --j) {
                        out.print(seq[j] + " ");
                    }
                    out.println();
                    return;
                }
            }
            for (TaskB.Vertex v : vs)
                if (v.reachCycle) {
                    out.println("Draw");
                    return;
                }
            out.println("Lose");
        }

        static class Vertex {
            TaskB.Vertex reach;
            boolean reachCycle;
            int state = 0;
            int index;
            List<TaskB.Vertex> outgo = new ArrayList<>(2);

            public Vertex(int index) {
                this.index = index;
            }

            public void dfs(TaskB.Vertex via) {
                state = 1;
                reach = via;
                for (TaskB.Vertex v : outgo) {
                    if (v.state == 0) {
                        v.dfs(this);
                    } else if (v.state == 1) {
                        reachCycle = true;
                    }
                }
                state = 2;
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