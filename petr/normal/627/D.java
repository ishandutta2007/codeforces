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
        TaskD solver = new TaskD();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskD {
        Node[] nodes;
        static int k;
        static int n;
        static int middle;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            n = in.nextInt();
            k = in.nextInt();
            nodes = new Node[n];
            int minScore = Integer.MAX_VALUE;
            int maxScore = Integer.MIN_VALUE;
            for (int i = 0; i < n; ++i) {
                nodes[i] = new Node();
                nodes[i].score = in.nextInt();
                maxScore = Math.max(maxScore, nodes[i].score);
                minScore = Math.min(minScore, nodes[i].score);
            }
            for (int i = 0; i < n - 1; ++i) {
                Node a = nodes[in.nextInt() - 1];
                Node b = nodes[in.nextInt() - 1];
                Edge ab = new Edge();
                Edge ba = new Edge();
                ab.dest = b;
                ba.dest = a;
                ab.rev = ba;
                ba.rev = ab;
                a.outgo.add(ab);
                b.outgo.add(ba);
            }
            int left = minScore;
            int right = maxScore + 1;
            while (right - left > 1) {
                middle = (left + right) / 2;
                if (enough()) {
                    left = middle;
                } else {
                    right = middle;
                }
            }
            out.println(left);
        }

        private boolean enough() {
            for (Node n : nodes) {
                n.numBadChildren = -1;
                n.someBadChild = null;
                n.skipped = null;
            }
            nodes[0].dfs0(null);
            for (Node n : nodes) {
                n.dfs1(null);
            }
            return nodes[0].dfs2(null) >= k;
        }

        static class Edge {
            Edge rev;
            Node dest;
            boolean nice;

        }

        static class Node {
            int score;
            List<Edge> outgo = new ArrayList<>(1);
            int numBadChildren = -1;
            Edge someBadChild = null;
            Edge skipped = null;
            int subtreeSize;

            public boolean dfs1(Node parent) {
                if (score < middle) {
                    return false;
                }
                if (numBadChildren < 0) {
                    numBadChildren = 0;
                    for (Edge e : outgo) {
                        if (e.dest != parent) {
                            e.nice = e.dest.dfs1(this);
                            if (!e.nice) {
                                ++numBadChildren;
                                someBadChild = e;
                            }
                        } else {
                            skipped = e;
                        }
                    }
                    return numBadChildren == 0;
                }
                if (skipped != null && skipped.dest != parent) {
                    skipped.nice = skipped.dest.dfs1(this);
                    if (!skipped.nice) {
                        ++numBadChildren;
                        someBadChild = skipped;
                    }
                    skipped = null;
                }
                return (numBadChildren == 0 || (numBadChildren == 1 && someBadChild.dest == parent));
            }

            public int dfs2(Node parent) {
                if (score < middle) {
                    int res = 0;
                    for (Edge e : outgo) {
                        if (e.dest != parent) {
                            res = Math.max(res, e.dest.dfs2(this));
                        }
                    }
                    if (res < k) res = 0;
                    return res;
                }
                int res = 1;
                int parentExtra = 0;
                int best = 0;
                int secondBest = 0;
                for (Edge e : outgo) {
                    if (e.dest != parent) {
                        int child = e.dest.dfs2(this);
                        if (e.nice) {
                            res += e.dest.subtreeSize;
                        } else {
                            if (child > best) {
                                secondBest = best;
                                best = child;
                            } else if (child > secondBest) {
                                secondBest = child;
                            }
                        }
                    } else {
                        if (e.nice) {
                            parentExtra = n - subtreeSize;
                        }
                    }
                }
                if (res + parentExtra + best + secondBest >= k) {
                    return k;
                }
                return res + best;
            }

            public void dfs0(Node parent) {
                subtreeSize = 1;
                for (Edge e : outgo) {
                    if (e.dest != parent) {
                        e.dest.dfs0(this);
                        subtreeSize += e.dest.subtreeSize;
                    }
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

    }
}