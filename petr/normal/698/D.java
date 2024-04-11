import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Set;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int k = in.nextInt();
            int n = in.nextInt();
            TaskD.Point[] a = new TaskD.Point[k];
            TaskD.Point[] m = new TaskD.Point[n];
            for (int i = 0; i < k; ++i) {
                a[i] = readPoint(in);
            }
            for (int i = 0; i < n; ++i) {
                m[i] = readPoint(in);
                m[i].next = new TaskD.Point[k];
            }
            for (int origin = 0; origin < k; ++origin) {
                TaskD.Point[] sorted = m.clone();
                TaskD.OriginComparator cmp = new TaskD.OriginComparator(a[origin]);
                Arrays.sort(sorted, cmp);
                for (int i = 1; i < sorted.length; ++i) {
                    TaskD.Point prev = sorted[i - 1];
                    TaskD.Point cur = sorted[i];
                    if (cmp.compare(prev, cur) == -1) {
                        cur.next[origin] = prev;
                    }
                }
            }
            int res = 0;
            for (int who = 0; who < n; ++who) {
                Set<TaskD.Point> toKill = new HashSet<>();
                toKill.add(m[who]);
                if (canKill(toKill, k, (1 << k) - 1)) {
                    ++res;
                }
            }
            out.println(res);
        }

        private boolean canKill(Set<TaskD.Point> toKill, int k, int available) {
            if (toKill.isEmpty()) return true;
            int cntAvailable = Integer.bitCount(available);
            for (int via = 0; via < k; ++via)
                if ((available & (1 << via)) != 0) {
                    outer:
                    for (TaskD.Point dest : toKill) {
                        Set<TaskD.Point> newToKill = new HashSet<>(toKill);
                        newToKill.remove(dest);
                        while (dest.next[via] != null) {
                            newToKill.add(dest.next[via]);
                            if (newToKill.size() > cntAvailable - 1) {
                                continue outer;
                            }
                            dest = dest.next[via];
                        }
                        if (canKill(newToKill, k, available ^ (1 << via))) return true;
                    }
                }
            return false;
        }

        private TaskD.Point readPoint(InputReader in) {
            TaskD.Point p = new TaskD.Point();
            p.x = in.nextLong();
            p.y = in.nextLong();
            return p;
        }

        static class Point {
            long x;
            long y;
            TaskD.Point[] next;

        }

        static class OriginComparator implements Comparator<TaskD.Point> {
            TaskD.Point origin;

            public OriginComparator(TaskD.Point origin) {
                this.origin = origin;
            }


            public int compare(TaskD.Point o1, TaskD.Point o2) {
                long dx1 = o1.x - origin.x;
                long dx2 = o2.x - origin.x;
                long dy1 = o1.y - origin.y;
                long dy2 = o2.y - origin.y;
                int half1 = (dy1 > 0 || dy1 == 0 && dx1 > 0) ? 0 : 1;
                int half2 = (dy2 > 0 || dy2 == 0 && dx2 > 0) ? 0 : 1;
                if (half1 != half2) {
                    return 2 * (half1 - half2);
                }
                long z = dx1 * dy2 - dx2 * dy1;
                if (z > 0) {
                    return -2;
                } else if (z < 0) {
                    return 2;
                }
                z = Math.abs(dx1) + Math.abs(dy1) - Math.abs(dx2) - Math.abs(dy2);
                if (z < 0) {
                    return -1;
                } else if (z > 0) {
                    return 1;
                } else {
                    return 0;
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