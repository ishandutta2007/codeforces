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
        TaskE solver = new TaskE();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskE {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int[][] sets = new int[n][(n + 31) / 32];
            boolean haveAll = true;
            int[] setCounts = new int[n];
            for (int i = 0; i < n; ++i) {
                int k = in.nextInt();
                setCounts[i] = k;
                if (k < n) haveAll = false;
                for (int j = 0; j < k; ++j) {
                    int a = in.nextInt() - 1;
                    sets[i][a >> 5] |= 1 << (a & 31);
                }
            }
            if (haveAll) {
                for (int i = 2; i <= n; ++i) {
                    out.println(1 + " " + i);
                }
                return;
            }
            TaskE.Node[] nodes = new TaskE.Node[n];
            for (int i = 0; i < n; ++i) {
                nodes[i] = new TaskE.Node(i + 1);
            }
            boolean[][] got = new boolean[n][n];
            int numGot = 0;
            TaskE.Node la = null;
            TaskE.Node lb = null;
            for (int i = 0; i < n; ++i) {
                outer:
                for (int j = 0; j < n; ++j) {
                    int v1 = -1;
                    int v2 = -1;
                    for (int k = 0; k < sets[i].length; ++k) {
                        int z = sets[i][k] & sets[j][k];
                        while (z != 0) {
                            if (v1 < 0) {
                                v1 = Integer.numberOfTrailingZeros(z);
                                z ^= (1 << v1);
                                v1 += (k << 5);
                            } else if (v2 < 0) {
                                v2 = Integer.numberOfTrailingZeros(z);
                                z ^= (1 << v2);
                                v2 += (k << 5);
                            } else {
                                continue outer;
                            }
                        }
                    }
                    if (v2 >= 0 && !got[v1][v2]) {
                        ++numGot;
                        got[v1][v2] = true;
                        la = nodes[v1];
                        lb = nodes[v2];
                        nodes[v1].adj.add(nodes[v2]);
                        nodes[v2].adj.add(nodes[v1]);
                    }
                }
            }

            if (numGot == 1) {
                for (int i = 0; i < n; ++i)
                    if (setCounts[i] < n) {
                        for (int j = 0; j < n; ++j)
                            if (nodes[j].adj.isEmpty()) {
                                if ((sets[i][j >> 5] & (1 << (j & 31))) != 0) {
                                    nodes[j].adj.add(la);
                                    la.adj.add(nodes[j]);
                                } else {
                                    nodes[j].adj.add(lb);
                                    lb.adj.add(nodes[j]);
                                }
                            }
                        break;
                    }
            } else {
                TaskE.Node[] toAdd = new TaskE.Node[n];
                TaskE.Node[] toAdd2 = new TaskE.Node[n];
                int nToAdd = 0;
                outer3:
                for (int j = 0; j < n; ++j)
                    if (nodes[j].adj.isEmpty()) {
                        int bs = -1;
                        for (int i = 0; i < n; ++i)
                            if ((sets[i][j >> 5] & (1 << (j & 31))) != 0) {
                                if (bs < 0 || setCounts[i] < setCounts[bs]) bs = i;
                            }
                        int needCount = 0;
                        for (int k = 0; k < n; ++k) {
                            if ((sets[bs][k >> 5] & (1 << (k & 31))) != 0 && !nodes[k].adj.isEmpty()) {
                                ++needCount;
                            }
                        }
                        outer2:
                        for (TaskE.Node a : nodes)
                            if (!a.adj.isEmpty() && (sets[bs][(a.index - 1) >> 5] & (1 << ((a.index - 1) & 31))) != 0) {
                                if (a.adj.size() + 1 == needCount) {
                                    for (TaskE.Node b : a.adj) {
                                        if ((sets[bs][(b.index - 1) >> 5] & (1 << ((b.index - 1) & 31))) == 0) {
                                            continue outer2;
                                        }
                                    }
                                    toAdd[nToAdd] = nodes[j];
                                    toAdd2[nToAdd] = a;
                                    ++nToAdd;
                                    continue outer3;
                                }
                            }
                        throw new RuntimeException();
                    }
                for (int i = 0; i < nToAdd; ++i) {
                    toAdd[i].adj.add(toAdd2[i]);
                    toAdd2[i].adj.add(toAdd[i]);
                }
            }

            for (TaskE.Node a : nodes)
                for (TaskE.Node b : a.adj)
                    if (b.index > a.index) {
                        out.println(a.index + " " + b.index);
                    }
        }

        static class Node {
            int index;
            List<TaskE.Node> adj = new ArrayList<>();

            public Node(int index) {
                this.index = index;
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