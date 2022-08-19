import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Set;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashSet;
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
        TaskF solver = new TaskF();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskF {
        int time;
        int[] delta;
        int[] min;
        int[] numMins;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int q = in.nextInt();
            Vertex[] vs = new Vertex[n];
            for (int i = 0; i < n; ++i) vs[i] = new Vertex();
            for (int i = 0; i < n - 1; ++i) {
                Vertex a = vs[in.nextInt() - 1];
                Vertex b = vs[in.nextInt() - 1];
                a.adj.add(b);
                b.adj.add(a);
            }
            Vertex root = vs[0];
            time = 0;
            root.dfs(null);
            if (time != n) throw new RuntimeException();
            Set<Long> have = new HashSet<>();
            delta = new int[4 * n + 10];
            min = new int[4 * n + 10];
            numMins = new int[4 * n + 10];
            initTree(0, 0, n - 1);
            for (int qi = 0; qi < q; ++qi) {
                int ia = in.nextInt() - 1;
                int ib = in.nextInt() - 1;
                if (ia > ib) {
                    int tmp = ia;
                    ia = ib;
                    ib = tmp;
                }
                long key = ia * n + ib;
                Vertex a = vs[ia];
                Vertex b = vs[ib];
                int upd;
                if (have.contains(key)) {
                    upd = -1;
                    have.remove(key);
                } else {
                    upd = 1;
                    have.add(key);
                }
                if (a.enterTime <= b.enterTime && a.exitTime > b.enterTime) {
                    Vertex p = b.jumpToDepth(a.depth + 1);
                    treeUpd(0, 0, n - 1, p.enterTime, p.exitTime - 1, upd);
                    treeUpd(0, 0, n - 1, b.enterTime, b.exitTime - 1, -upd);
                } else if (b.enterTime <= a.enterTime && b.exitTime > a.enterTime) {
                    Vertex p = a.jumpToDepth(b.depth + 1);
                    treeUpd(0, 0, n - 1, p.enterTime, p.exitTime - 1, upd);
                    treeUpd(0, 0, n - 1, a.enterTime, a.exitTime - 1, -upd);
                } else {
                    treeUpd(0, 0, n - 1, 0, n - 1, upd);
                    treeUpd(0, 0, n - 1, a.enterTime, a.exitTime - 1, -upd);
                    treeUpd(0, 0, n - 1, b.enterTime, b.exitTime - 1, -upd);
                }

                int globalMin = min[0] + delta[0];
                if (globalMin == 0) {
                    out.println(numMins[0]);
                } else {
                    if (globalMin < 0) throw new RuntimeException();
                    out.println(0);
                }
            }
        }

        private void treeUpd(int root, int rl, int rr, int left, int right, int upd) {
            if (left > right) return;
            if (rl == left && rr == right) {
                delta[root] += upd;
                return;
            }
            int rm = (rl + rr) >> 1;
            treeUpd(root * 2 + 1, rl, rm, left, Math.min(rm, right), upd);
            treeUpd(root * 2 + 2, rm + 1, rr, Math.max(rm + 1, left), right, upd);
            int leftMin = min[root * 2 + 1] + delta[root * 2 + 1];
            int rightMin = min[root * 2 + 2] + delta[root * 2 + 2];
            if (leftMin < rightMin) {
                min[root] = leftMin;
                numMins[root] = numMins[root * 2 + 1];
            } else if (leftMin > rightMin) {
                min[root] = rightMin;
                numMins[root] = numMins[root * 2 + 2];
            } else {
                min[root] = leftMin;
                numMins[root] = numMins[root * 2 + 1] + numMins[root * 2 + 2];
            }
        }

        private void initTree(int root, int rl, int rr) {
            numMins[root] = rr - rl + 1;
            if (rl == rr) return;
            int rm = (rl + rr) >> 1;
            initTree(root * 2 + 1, rl, rm);
            initTree(root * 2 + 2, rm + 1, rr);
        }

        class Vertex {
            int enterTime;
            int exitTime;
            int depth;
            Vertex parent;
            Vertex[] jump;
            List<Vertex> adj = new ArrayList<>();

            public void dfs(Vertex parent) {
                this.parent = parent;
                if (parent != null) depth = 1 + parent.depth;
                int p2 = 0;
                while ((1 << p2) <= depth) {
                    ++p2;
                }
                jump = new Vertex[p2];
                if (p2 > 0) {
                    jump[0] = parent;
                    for (int i = 1; i < p2; ++i) {
                        jump[i] = jump[i - 1].jump[i - 1];
                    }
                }
                enterTime = time;
                ++time;
                for (Vertex v : adj)
                    if (v != parent) {
                        v.dfs(this);
                    }
                exitTime = time;
            }

            Vertex jumpToDepth(int depth) {
                Vertex cur = this;
                if (cur.depth < depth) throw new RuntimeException();
                for (int i = jump.length - 1; i >= 0; --i) {
                    if (i < cur.jump.length && cur.jump[i].depth >= depth) cur = cur.jump[i];
                }
                if (cur.depth != depth) throw new RuntimeException();
                return cur;
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