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
        TaskF solver = new TaskF();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskF {
        static int nextId;
        static TaskF.Vertex[] seq;
        int n;
        static final long BIG = (long) 1e12;
        boolean[] interesting;
        int[] interestingList;
        int[] degree;
        int numInteresting;
        int[][] children;
        int[][] childEdge;
        int[][] freeEdges;
        long[][] freeEdgePrefixSum;
        long[][] interestingGains;
        int[] numInterestingGains;
        long[] interestingSum;
        int[] numFreeEdges;
        int[] parent;
        int[] parentEdge;
        int[] numChildren;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            n = in.nextInt();
            TaskF.Vertex[] vs = new TaskF.Vertex[n];
            for (int i = 0; i < n; ++i) {
                vs[i] = new TaskF.Vertex();
            }
            for (int i = 0; i < n - 1; ++i) {
                TaskF.Vertex a = vs[in.nextInt() - 1];
                TaskF.Vertex b = vs[in.nextInt() - 1];
                int c = in.nextInt();
                a.adj.add(new TaskF.Edge(b, c));
                b.adj.add(new TaskF.Edge(a, c));
            }
            for (TaskF.Vertex v : vs) {
                Collections.sort(v.adj, new Comparator<TaskF.Edge>() {

                    public int compare(TaskF.Edge o1, TaskF.Edge o2) {
                        return o1.len - o2.len;
                    }
                });
            }
            TaskF.Vertex root = vs[0];
            nextId = 0;
            seq = new TaskF.Vertex[n];
            root.dfs();
            if (nextId != n) throw new RuntimeException();

            vs = seq;
            children = new int[n][];
            childEdge = new int[n][];
            freeEdges = new int[n][];
            interestingGains = new long[n][];
            numInterestingGains = new int[n];
            interestingSum = new long[n];
            numFreeEdges = new int[n];
            freeEdgePrefixSum = new long[n][];
            numChildren = new int[n];
            degree = new int[n];
            parent = new int[n];
            parentEdge = new int[n];
            for (int i = 0; i < n; ++i) {
                int ne = vs[i].adj.size();
                degree[i] = ne;
                children[i] = new int[ne];
                childEdge[i] = new int[children[i].length];
                interestingGains[i] = new long[ne + 1];
                freeEdges[i] = new int[ne];
                freeEdgePrefixSum[i] = new long[ne + 1];
                int ptr = 0;
                parent[i] = -1;
                for (TaskF.Edge e : vs[i].adj) {
                    if (e.dest.id < i) {
                        parent[i] = e.dest.id;
                        parentEdge[i] = e.len;
                    }
                    children[i][ptr] = e.dest.id;
                    childEdge[i][ptr] = e.len;
                    ++ptr;
                }
                if (ptr != children[i].length) throw new RuntimeException();
            }

            TaskF.Vertex[] byDegree = vs.clone();
            Arrays.sort(byDegree, new Comparator<TaskF.Vertex>() {

                public int compare(TaskF.Vertex o1, TaskF.Vertex o2) {
                    return o2.adj.size() - o1.adj.size();
                }
            });

            int at = n - 1;
            long[] res = new long[n];
            interesting = new boolean[n];
            interestingList = new int[n];

            for (TaskF.Vertex v : byDegree) {
                if (at >= v.adj.size()) {
                    buildAuxiliary();
                    for (int i = at; i >= v.adj.size(); --i) {
                        res[i] = recompute(i);
                    }
                }
                at = v.adj.size() - 1;
                interesting[v.id] = true;
            }
            if (at >= 0) {
                buildAuxiliary();
                for (int i = at; i >= 0; --i) {
                    res[i] = recompute(i);
                }
            }

            for (long x : res) {
                out.print(x + " ");
            }
            out.println();
        }

        private void buildAuxiliary() {
            numInteresting = 0;
            for (int i = 0; i < n; ++i)
                if (interesting[i]) {
                    interestingList[numInteresting++] = i;
                    numFreeEdges[i] = 0;
                    for (int j = 0; j < children[i].length; ++j) {
                        if (interesting[children[i][j]]) {

                        } else {
                            freeEdges[i][numFreeEdges[i]++] = childEdge[i][j];
                        }
                    }
                    for (int j = 0; j < numFreeEdges[i]; ++j) {
                        freeEdgePrefixSum[i][j + 1] = freeEdgePrefixSum[i][j] + freeEdges[i][j];
                    }
                }
        }

        private long recompute(int maxDegree) {
            for (int i = 0; i < numInteresting; ++i) {
                numInterestingGains[interestingList[i]] = 0;
                interestingSum[interestingList[i]] = 0;
            }
            long res = 0;
            for (int DO_NOT_USE_ptr = numInteresting - 1; DO_NOT_USE_ptr >= 0; --DO_NOT_USE_ptr) {
                int i = interestingList[DO_NOT_USE_ptr];
                int toSave = degree[i] - maxDegree;
                if (toSave <= 0) throw new RuntimeException();
                Arrays.sort(interestingGains[i], 0, numInterestingGains[i]);
                interestingGains[i][numInterestingGains[i]++] = BIG;
                --toSave;
                long sofar = interestingSum[i];
                int freeEdgePtr = 0;
                int interestingPtr = 0;
                while (interestingPtr < numInterestingGains[i] && interestingGains[i][interestingPtr] <= 0) {
                    sofar += interestingGains[i][interestingPtr];
                    --toSave;
                    ++interestingPtr;
                }
                long minusOne = 0;
                long minusZero = 0;
                for (int iter = 0; iter < 2; ++iter) {
                    if (iter == 1) {
                        ++toSave;
                    }
                    while (toSave > 0) {
                        long nextInteresting = interestingGains[i][interestingPtr];
                        if (freeEdgePtr < numFreeEdges[i] && freeEdges[i][freeEdgePtr] <= nextInteresting) {
                            int p2 = 1;
                            while (p2 + 1 <= toSave && freeEdgePtr + p2 < numFreeEdges[i] && freeEdges[i][freeEdgePtr + p2] <= nextInteresting)
                                p2 *= 2;

                            int jump = 0;
                            for (; p2 >= 1; p2 >>= 1) {
                                if (jump + p2 + 1 <= toSave && freeEdgePtr + jump + p2 < numFreeEdges[i] && freeEdges[i][freeEdgePtr + jump + p2] <= nextInteresting) {
                                    jump += p2;
                                }
                            }

                            freeEdgePtr += jump + 1;
                            toSave -= jump + 1;
                        } else {
                            sofar += interestingGains[i][interestingPtr];
                            --toSave;
                            ++interestingPtr;
                        }
                    }
                    if (iter == 0) {
                        minusOne = sofar + freeEdgePrefixSum[i][freeEdgePtr];
                    } else {
                        minusZero = sofar + freeEdgePrefixSum[i][freeEdgePtr];
                    }
                }
                if (i > 0 && interesting[parent[i]]) {
                    interestingSum[parent[i]] += minusZero;
                    interestingGains[parent[i]][numInterestingGains[parent[i]]++] = minusOne + parentEdge[i] - minusZero;
                } else {
                    res += minusZero;
                }
            }
            return res;
        }

        static class Vertex {
            int id = -1;
            List<TaskF.Edge> adj = new ArrayList<>();

            public void dfs() {
                id = nextId++;
                seq[id] = this;
                for (TaskF.Edge e : adj) {
                    if (e.dest.id < 0) {
                        e.dest.dfs();
                    }
                }
            }

        }

        static class Edge {
            TaskF.Vertex dest;
            int len;

            public Edge(TaskF.Vertex dest, int len) {
                this.dest = dest;
                this.len = len;
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