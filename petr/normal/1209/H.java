import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.SortedSet;
import java.util.Set;
import java.util.NavigableSet;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.TreeSet;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.util.Comparator;
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
        TaskH solver = new TaskH();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskH {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int len = in.nextInt();
            int[] x = new int[n];
            int[] y = new int[n];
            double[] s = new double[n];
            for (int i = 0; i < n; ++i) {
                x[i] = in.nextInt();
                y[i] = in.nextInt();
                s[i] = in.nextDouble();
            }
            List<TaskH.Segment> segments = new ArrayList<>();
            int pos = 0;
            for (int i = 0; i < n; ++i) {
                if (x[i] > pos) {
                    segments.add(new TaskH.Segment(pos, x[i], 0.0));
                }
                segments.add(new TaskH.Segment(x[i], y[i], s[i]));
                pos = y[i];
            }
            if (pos < len) {
                segments.add(new TaskH.Segment(pos, len, 0.0));
            }
            out.println(solveOne(segments));
        }

        private double solveOne(List<TaskH.Segment> segments) {
            int n = segments.size();
            for (int i = 0; i < n; ++i) {
                TaskH.Segment s = segments.get(i);
                s.ptr = i;
                s.curEnergy = 0.0;
                s.maxEnergy = (s.right - s.left) / s.s;
                s.minEnergy = -(s.right - s.left) / (s.s + 2);
            }
            List<TaskH.Segment> segmentsByS = new ArrayList<>(segments);
            Collections.sort(segmentsByS, new Comparator<TaskH.Segment>() {

                public int compare(TaskH.Segment o1, TaskH.Segment o2) {
                    int z = Double.compare(o2.s, o1.s);
                    if (z == 0) {
                        z = Integer.compare(o2.left, o1.left);
                    }
                    return z;
                }
            });
            TreeSet<TaskH.Segment> available = new TreeSet<>(new Comparator<TaskH.Segment>() {

                public int compare(TaskH.Segment o1, TaskH.Segment o2) {
                    return o1.ptr - o2.ptr;
                }
            });
            available.addAll(segments);
            for (TaskH.Segment s : segmentsByS) {
                if (s.s == 0.0) break;
                s.alive = false;
                available.remove(s);
                NavigableSet<TaskH.Segment> after = available.tailSet(s, false);
                double capacity = s.maxEnergy - s.curEnergy;
                double spent = 0.0;
                while (!after.isEmpty()) {
                    TaskH.Segment t = after.first();
                    if (t.alive) {
                        double t1 = t.curEnergy - t.minEnergy;
                        double t2 = capacity - spent;
                        double transfer = Math.min(t1, t2);
                        spent += transfer;
                        t.curEnergy -= transfer;
                        if (t1 <= t2) {
                            available.remove(t);
                        } else {
                            break;
                        }
                    }
                }
                s.curEnergy += spent;
            }
            double res = 0.0;
            for (TaskH.Segment s : segments) {
                double v = (s.right - s.left - s.curEnergy * s.s) / (s.right - s.left + s.curEnergy);
                res += (s.right - s.left) / (s.s + v);
            }
            return res;
        }

        static class Segment {
            int left;
            int right;
            int ptr;
            double s;
            boolean alive = true;
            double minEnergy;
            double curEnergy;
            double maxEnergy;

            public Segment(int left, int right, double s) {
                this.left = left;
                this.right = right;
                this.s = s;
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

        public double nextDouble() {
            return Double.parseDouble(next());
        }

    }
}