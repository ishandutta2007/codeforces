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
import java.util.Collections;
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
        TaskF solver = new TaskF();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskF {
        static final long INF = (long) (4e18);
        static final long MODULO = (long) (1e9 + 7);

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int height = in.nextInt();
            int width = in.nextInt();
            String pattern = in.next();
            long[] firstByY = solveOneDir(height, pattern, 'D', 'U');
            long[] firstByX = solveOneDir(width, pattern, 'R', 'L');
            List<Event> events = new ArrayList<>();
            for (int i = 0; i < firstByY.length; ++i) {
                if (firstByY[i] < INF) {
                    events.add(new Event(true, i - height, firstByY[i]));
                }
            }
            for (int i = 0; i < firstByX.length; ++i) {
                if (firstByX[i] < INF) {
                    events.add(new Event(false, i - width, firstByX[i]));
                }
            }
            Collections.sort(events);
            int minY = 0;
            int maxY = height - 1;
            int minX = 0;
            int maxX = width - 1;
            long res = 0;
            for (Event e : events) {
                if (minY > maxY || minX > maxX) break;
                if (e.when == 0) continue;
                if (e.isY) {
                    res += e.when * (maxX - minX + 1);
                    res %= MODULO;
                    if (e.coord > 0) {
                        --maxY;
                    } else {
                        ++minY;
                    }
                } else {
                    res += e.when * (maxY - minY + 1);
                    res %= MODULO;
                    if (e.coord > 0) {
                        --maxX;
                    } else {
                        ++minX;
                    }
                }

            }
            if (minY > maxY || minX > maxX) {
                out.println(res);
            } else {
                out.println(-1);
            }
        }

        private long[] solveOneDir(int size, String pattern, char inc, char dec) {
            long[] firstAt = new long[2 * size + 1];
            Arrays.fill(firstAt, INF);
            firstAt[size] = 0;
            int at = 0;
            int n = pattern.length();
            for (int i = 0; i < n; ++i) {
                char ch = pattern.charAt(i);
                if (ch == inc) ++at;
                else if (ch == dec) --at;
                if (size + at >= 0 && size + at < firstAt.length && firstAt[size + at] == INF) {
                    firstAt[size + at] = i + 1;
                }
            }
            if (at > 0) {
                for (int i = size; i < firstAt.length; ++i) if (firstAt[i] == INF) firstAt[i] = firstAt[i - at] + n;
            }
            if (at < 0) {
                for (int i = size; i >= 0; --i) if (firstAt[i] == INF) firstAt[i] = firstAt[i - at] + n;
            }
            return firstAt;
        }

        static class Event implements Comparable<Event> {
            boolean isY;
            int coord;
            long when;

            public Event(boolean isY, int coord, long when) {
                this.isY = isY;
                this.coord = coord;
                this.when = when;
            }


            public int compareTo(Event o) {
                return Long.compare(when, o.when);
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