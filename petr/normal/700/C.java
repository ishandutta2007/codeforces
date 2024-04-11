import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.List;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
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
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        static final int INF = Integer.MAX_VALUE;
        static int nextEnterTime;

        void addRoad(TaskC.Vertex a, TaskC.Vertex b, int cost, int index) {
            TaskC.Road ab = new TaskC.Road();
            TaskC.Road ba = new TaskC.Road();
            ab.dest = b;
            ab.cost = cost;
            ab.rev = ba;
            ab.index = index;
            ba.dest = a;
            ba.cost = cost;
            ba.rev = ab;
            ba.index = index;
            a.outgo.add(ab);
            b.outgo.add(ba);
        }

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int m = in.nextInt();
            TaskC.Vertex[] vs = new TaskC.Vertex[n];
            for (int i = 0; i < n; ++i) {
                vs[i] = new TaskC.Vertex();
            }
            TaskC.Vertex s = vs[in.nextInt() - 1];
            TaskC.Vertex t = vs[in.nextInt() - 1];
            for (int i = 0; i < m; ++i) {
                TaskC.Vertex a = vs[in.nextInt() - 1];
                TaskC.Vertex b = vs[in.nextInt() - 1];
                int cost = in.nextInt();
                addRoad(a, b, cost, i + 1);
            }
            List<TaskC.Road> path = new ArrayList<>();
            if (!s.findPath(t, path)) {
                out.println(0);
                out.println(0);
                out.println();
                return;
            }
            int res = INF;
            List<TaskC.Road> resList = new ArrayList<>();
            for (TaskC.Road r : path) {
                r.deleted = true;
                r.rev.deleted = true;
                for (TaskC.Vertex v : vs) {
                    v.enterTime = 0;
                    v.minReachableUp = 0;
                    v.hasT = false;
                }
                nextEnterTime = 1;
                TaskC.Road bridge = s.findCheapestBridge(t, null);
                if (bridge == null) {
                    if (t.enterTime == 0) {
                        if (r.cost < res) {
                            res = r.cost;
                            resList.clear();
                            resList.add(r);
                        }
                    }
                } else {
                    if (r.cost + bridge.cost < res) {
                        res = r.cost + bridge.cost;
                        resList.clear();
                        resList.add(r);
                        resList.add(bridge);
                    }
                }
                r.deleted = false;
                r.rev.deleted = false;
            }
            if (res == INF) {
                out.println(-1);
                return;
            }
            out.println(res);
            out.println(resList.size());
            for (int i = 0; i < resList.size(); ++i) {
                if (i > 0) out.print(" ");
                out.print(resList.get(i).index);
            }
            out.println();
        }

        static class Road {
            int index;
            TaskC.Vertex dest;
            int cost;
            TaskC.Road rev;
            boolean deleted = false;

        }

        static class Vertex {
            List<TaskC.Road> outgo = new ArrayList<>(1);
            boolean findPathMark = false;
            int enterTime;
            int minReachableUp;
            boolean hasT;

            public boolean findPath(TaskC.Vertex t, List<TaskC.Road> path) {
                if (this == t) return true;
                if (findPathMark) return false;
                findPathMark = true;
                for (TaskC.Road r : outgo) {
                    if (r.dest.findPath(t, path)) {
                        path.add(r);
                        return true;
                    }
                }
                return false;
            }

            public TaskC.Road findCheapestBridge(TaskC.Vertex t, TaskC.Road via) {
                enterTime = nextEnterTime++;
                minReachableUp = enterTime;
                hasT = this == t;
                TaskC.Road res = null;
                for (TaskC.Road r : outgo) {
                    if (r.deleted || r == via) continue;
                    if (r.dest.enterTime == 0) {
                        TaskC.Road cur = r.dest.findCheapestBridge(t, r.rev);
                        if (cur != null) {
                            if (res == null || cur.cost < res.cost) {
                                res = cur;
                            }
                        }
                        hasT |= r.dest.hasT;
                        if (r.dest.minReachableUp == r.dest.enterTime && r.dest.hasT) {
                            if (res == null || r.cost < res.cost) {
                                res = r;
                            }
                        }
                        minReachableUp = Math.min(minReachableUp, r.dest.minReachableUp);
                    } else {
                        minReachableUp = Math.min(minReachableUp, r.dest.enterTime);
                    }
                }
                return res;
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