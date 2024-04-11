import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.io.IOException;
import java.io.InputStreamReader;
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
        static final int MODULO = (int) (1e9 + 7);
        TaskE.Barrier bottom;
        int h;
        int[] stackTop;
        TaskE.Barrier[] stackWhat;
        int[] stackNext;
        int available;
        int now;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            h = in.nextInt();
            int w = in.nextInt();
            int n = in.nextInt();
            TaskE.Barrier[] barriers = new TaskE.Barrier[n];
            for (int i = 0; i < n; ++i) {
                TaskE.Barrier b = new TaskE.Barrier();
                b.u = in.nextInt() - 1;
                b.l = in.nextInt() - 1;
                b.r = in.nextInt() - 1;
                b.s = in.nextInt();
                barriers[i] = b;
            }
            bottom = new TaskE.Barrier();
            bottom.u = -1;
            bottom.l = 0;
            bottom.r = w - 1;
            bottom.s = h + 5;
            bottom.res = 1;
            Event[] events = new Event[2 * barriers.length];
            for (int i = 0; i < barriers.length; ++i) {
                events[i * 2] = new Event(barriers[i], true);
                events[i * 2 + 1] = new Event(barriers[i], false);
            }
            Arrays.sort(events);
            stackTop = new int[4 * w];
            stackWhat = new TaskE.Barrier[40 * n + 10];
            stackNext = new int[40 * n + 10];
            stackWhat[0] = bottom;
            stackNext[0] = -1;
            available = 1;
            Arrays.fill(stackTop, 0);
            for (Event e : events) {
                now = e.when;
                if (now >= 2 * h) break;
                if (e.appears) {
                    if (e.b.l == 0) {
                        e.b.res = 2 * whatIf(0, 0, w - 1, e.b.r + 1).res;
                    } else if (e.b.r == w - 1) {
                        e.b.res = 2 * whatIf(0, 0, w - 1, e.b.l - 1).res;
                    } else {
                        e.b.res = whatIf(0, 0, w - 1, e.b.r + 1).res + whatIf(0, 0, w - 1, e.b.l - 1).res;
                    }
                    e.b.res %= MODULO;
                    add(0, 0, w - 1, e.b.l, e.b.r, e.b);
                } else {
                    remove(0, 0, w - 1, e.b.l, e.b.r, e.b);
                }
            }
            long res = 0;
            for (int i = 0; i < w; ++i) res += whatIf(0, 0, w - 1, i).res;
            res %= MODULO;
            out.println(res);
        }

        private void add(int root, int rl, int rr, int left, int right, TaskE.Barrier b) {
            if (left > right) return;
            if (rl == left && rr == right) {
                while (true) {
                    TaskE.Barrier o = stackWhat[stackTop[root]];
                    if (o.u < 0 || o.u + o.s > b.u + b.s) break;
                    stackTop[root] = stackNext[stackTop[root]];
                }
                stackWhat[available] = b;
                stackNext[available] = stackTop[root];
                stackTop[root] = available++;
                return;
            }
            int rm = (rl + rr) >> 1;
            add(root * 2 + 1, rl, rm, left, Math.min(rm, right), b);
            add(root * 2 + 2, rm + 1, rr, Math.max(left, rm + 1), right, b);
        }

        private void remove(int root, int rl, int rr, int left, int right, TaskE.Barrier b) {
            if (left > right) return;
            if (rl == left && rr == right) {
                if (stackWhat[stackTop[root]] == b) {
                    stackTop[root] = stackNext[stackTop[root]];
                }
                return;
            }
            int rm = (rl + rr) >> 1;
            remove(root * 2 + 1, rl, rm, left, Math.min(rm, right), b);
            remove(root * 2 + 2, rm + 1, rr, Math.max(left, rm + 1), right, b);
        }

        private TaskE.Barrier whatIf(int root, int rl, int rr, int where) {
            TaskE.Barrier got = stackWhat[stackTop[root]];
            if (rl < rr) {
                int rm = (rl + rr) >> 1;
                TaskE.Barrier child;
                if (where <= rm) {
                    child = whatIf(root * 2 + 1, rl, rm, where);
                } else {
                    child = whatIf(root * 2 + 2, rm + 1, rr, where);
                }
                if (child.u > got.u) {
                    got = child;
                }
            }
            return got;
        }

        static class Barrier {
            int u;
            int l;
            int r;
            int s;
            int res;

        }

        class Event implements Comparable<Event> {
            TaskE.Barrier b;
            boolean appears;
            int when;

            public Event(TaskE.Barrier b, boolean appears) {
                this.b = b;
                this.appears = appears;
                if (appears) {
                    when = 2 * b.u;
                } else {
                    when = 2 * (Math.min(h + 2, b.u + b.s)) + 1;
                }
            }


            public int compareTo(Event o) {
                return when - o.when;
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