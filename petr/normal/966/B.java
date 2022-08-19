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
        TaskB solver = new TaskB();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskB {
        int n1;
        int n2;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            long x1 = in.nextLong();
            long x2 = in.nextLong();
            TaskB.Server[] servers = new TaskB.Server[n];
            for (int i = 0; i < n; ++i) servers[i] = new TaskB.Server(in.nextLong(), i + 1);
            Arrays.sort(servers, new Comparator<TaskB.Server>() {

                public int compare(TaskB.Server o1, TaskB.Server o2) {
                    return Long.compare(o2.c, o1.c);
                }
            });
            if (doit(x1, x2, servers)) {
                out.println("Yes");
                out.println(n1 + " " + n2);
                for (int i = 0; i < n1; ++i) {
                    out.print(servers[i].id + " ");
                }
                out.println();
                for (int i = 0; i < n2; ++i) {
                    out.print(servers[n1 + i].id + " ");
                }
                out.println();
            } else if (doit(x2, x1, servers)) {
                out.println("Yes");
                out.println(n2 + " " + n1);
                for (int i = 0; i < n2; ++i) {
                    out.print(servers[n1 + i].id + " ");
                }
                out.println();
                for (int i = 0; i < n1; ++i) {
                    out.print(servers[i].id + " ");
                }
                out.println();
            } else {
                out.println("No");
            }
        }

        private boolean doit(long x1, long x2, TaskB.Server[] servers) {
            n1 = 1;
            while (n1 <= servers.length && servers[n1 - 1].c * n1 < x1) ++n1;
            n2 = 1;
            while (n1 + n2 <= servers.length && servers[n1 + n2 - 1].c * n2 < x2) ++n2;
            return (n1 + n2 <= servers.length);
        }

        static class Server {
            long c;
            int id;

            public Server(long c, int id) {
                this.c = c;
                this.id = id;
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