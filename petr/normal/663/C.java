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
        TaskC solver = new TaskC();
        solver.solve(1, in, out);
        out.close();
    }

    static class TaskC {
        static final int INF = (int) 1e9;
        static int nextGeneration = 0;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int m = in.nextInt();
            Node[] nodes = new Node[n];
            for (int i = 0; i < n; ++i) {
                nodes[i] = new Node();
            }
            for (int i = 0; i < m; ++i) {
                Node a = nodes[in.nextInt() - 1];
                Node b = nodes[in.nextInt() - 1];
                String s = in.next();
                if (s.equals("R")) {
                    a.adjRed.add(b);
                    b.adjRed.add(a);
                } else {
                    a.adjBlue.add(b);
                    b.adjBlue.add(a);
                }
            }
            int bc = -1;
            int bestOverall = INF;
            for (int col = 0; col < 3; ++col) {
                if (col == 2 && bestOverall >= INF) {
                    out.println(-1);
                    return;
                }
                int curStart = nextGeneration;
                boolean needRed = (col == 0) || (col == 2 && bc == 0);
                int curOverall = 0;
                for (int start = 0; start < n; ++start) {
                    if (nodes[start].generation > curStart) continue;
                    int bf = -1;
                    int best = INF;
                    for (int flip = 0; flip < 2; ++flip) {
                        ++nextGeneration;
                        int got = nodes[start].dfs(needRed, flip == 1);
                        if (got < best) {
                            best = got;
                            bf = flip;
                        }
                    }
                    if (best >= INF) {
                        curOverall = INF;
                        break;
                    }
                    curOverall += best;
                    ++nextGeneration;
                    nodes[start].dfs(needRed, bf == 1);
                }
                if (curOverall < bestOverall) {
                    bestOverall = curOverall;
                    bc = col;
                }
            }
            out.println(bestOverall);
            boolean first = true;
            for (int i = 0; i < nodes.length; ++i) {
                if (nodes[i].flip) {
                    if (first) first = false;
                    else out.print(" ");
                    out.print(i + 1);
                }
            }
            out.println();
        }

        static class Node {
            boolean flip;
            int generation = 0;
            List<Node> adjRed = new ArrayList<>(1);
            List<Node> adjBlue = new ArrayList<>(1);

            public int dfs(boolean needRed, boolean mustFlip) {
                if (generation == nextGeneration) {
                    if (flip != mustFlip) return INF;
                    return 0;
                }
                generation = nextGeneration;
                flip = mustFlip;
                int res = flip ? 1 : 0;
                for (Node node : adjRed) {
                    int child = node.dfs(needRed, flip ^ needRed ^ true);
                    if (child >= INF) return INF;
                    res += child;
                }
                for (Node node : adjBlue) {
                    int child = node.dfs(needRed, flip ^ needRed);
                    if (child >= INF) return INF;
                    res += child;
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