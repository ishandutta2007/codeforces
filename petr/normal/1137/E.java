import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.TreeSet;
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
            int m = in.nextInt();
            TaskE.Group first;
            TaskE.Group last;
            first = last = new TaskE.Group(0, n, 0, null, null);
            TreeSet<TaskE.Event> events = new TreeSet<>();

            long sumb = 0;
            long sums = 0;
            for (int i = 0; i < m; ++i) {
                int kind = in.nextInt();
                switch (kind) {
                    case 1: {
                        int count = in.nextInt();
                        int nfirst = first.first - count;
                        first = new TaskE.Group(nfirst, count, -(sumb + sums * nfirst), first, null);
                        first.next.prev = first;
                        first.createEvent();
                        events.add(first.event);
                        break;
                    }

                    case 2: {
                        int count = in.nextInt();
                        int nfirst = last.first + last.count;
                        last = new TaskE.Group(nfirst, count, -(sumb + sums * nfirst), null, last);
                        last.prev.next = last;
                        last.prev.createEvent();
                        events.add(last.prev.event);
                        break;
                    }

                    case 3:
                        long b = in.nextLong();
                        long s = in.nextLong();
                        sumb += b + (-first.first) * s;
                        sums += s;
                        break;
                }
                while (!events.isEmpty() && events.first().when <= sums) {
                    TaskE.Event event = events.pollFirst();
                    TaskE.Group left = event.left;
                    TaskE.Group right = left.next;
                    if (right.event != null) {
                        events.remove(right.event);
                    }
                    left.count += right.count;
                    left.next = right.next;
                    if (left.next != null) left.next.prev = left;
                    else last = left;
                    if (right.event != null) {
                        left.updateEvent();
                        events.add(left.event);
                    } else {
                        left.event = null;
                    }
                }
                out.println((last.first - first.first + 1) + " " + (last.firstScore + sumb + sums * last.first));
            }
        }

        static class Group {
            int first;
            int count;
            long firstScore;
            TaskE.Group next;
            TaskE.Group prev;
            TaskE.Event event;

            public Group(int first, int count, long firstScore, TaskE.Group next, TaskE.Group prev) {
                this.first = first;
                this.count = count;
                this.firstScore = firstScore;
                this.next = next;
                this.prev = prev;
            }

            public void createEvent() {
                event = new TaskE.Event(this, -1);
                updateEvent();
            }

            private void updateEvent() {
                // fs <= nfs + count * x
                // x * count >= fs - nfs
                // x >= (fs - nfs) / count
                long when;
                if (firstScore <= next.firstScore)
                    when = 0;
                else {
                    when = (firstScore - next.firstScore + count - 1) / count;
                }
                event.when = when;
            }

        }

        static class Event implements Comparable<TaskE.Event> {
            TaskE.Group left;
            long when;

            public Event(TaskE.Group left, long when) {
                this.left = left;
                this.when = when;
            }

            public int compareTo(TaskE.Event o) {
                int z = Long.compare(when, o.when);
                if (z == 0)
                    z = Integer.compare(left.first, o.left.first);
                return z;
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