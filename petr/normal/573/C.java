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
        static Node furthest;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            Node[] nodes = new Node[n];
            for (int i = 0; i < n; ++i) {
                nodes[i] = new Node();
            }
            for (int i = 0; i < n - 1; ++i) {
                Node a = nodes[in.nextInt() - 1];
                Node b = nodes[in.nextInt() - 1];
                a.adj.add(b);
                b.adj.add(a);
            }
            for (Node a : nodes) if (a.adj.size() == 1) a.markOutside();
            for (Node a : nodes) {
                int others = 0;
                int outsides = 0;
                for (Node b : a.adj)
                    if (b.outsidePart) ++outsides;
                    else ++others;
                if (outsides == 2 && others == 1) a.partOfTriangle = true;
            }
            Node any = null;
            for (Node a : nodes) if (!a.outsidePart && !a.partOfTriangle) any = a;
            if (any == null) {
                out.println("Yes");
                return;
            }
            String res1 = "Yes";
            for (Node a : nodes)
                if (!a.outsidePart && !a.partOfTriangle) {
                    int cnt = 0;
                    for (Node b : a.adj) if (!b.outsidePart && !b.partOfTriangle) ++cnt;
                    if (cnt >= 3) {
                        res1 = "No";
                        break;
                    }
                }
            String res2 = "Yes";
            furthest = any;
            any.findFurthest(null);
            Node oneEnd = furthest;
            oneEnd.dist = 0;
            oneEnd.findFurthest(null);
            for (Node a : nodes) {
                a.dist2 = a.dist;
            }
            Node secondEnd = furthest;
            secondEnd.dist = 0;
            secondEnd.findFurthest(null);
            for (Node a : nodes)
                if (!a.outsidePart && !a.partOfTriangle) {
                    if (a.dist + a.dist2 != oneEnd.dist) {
                        res2 = "No";
                        break;
                    }
                }
            if (!res1.equals(res2)) {
                throw new RuntimeException();
            }
            out.println(res1);
        }

        static class Node {
            int dist;
            int dist2;
            List<Node> adj = new ArrayList<>(1);
            boolean outsidePart = false;
            boolean partOfTriangle = false;

            public void findFurthest(Node src) {
                if (!outsidePart && !partOfTriangle && dist > furthest.dist) {
                    furthest = this;
                }
                for (Node other : adj)
                    if (other != src) {
                        other.dist = dist + 1;
                        other.findFurthest(this);
                    }
            }

            public void markOutside() {
                outsidePart = true;
                for (Node other : adj)
                    if (!other.outsidePart && other.adj.size() == 2) {
                        other.markOutside();
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