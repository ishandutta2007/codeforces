import java.util.List;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.ArrayList;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.StringTokenizer;
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
}

class TaskD {
    static final int INF = (int) (1e9 + 1);

    class Node {
        Node parent;
        int parentEdge;
        List<Node> adj = new ArrayList<Node>();
        int dist;

        public void dfs(Node from, int cd) {
            if (dist >= 0) return;
            if (from != null) {
                if (parent == from) cd += parentEdge; else if (from.parent == this) cd += from.parentEdge; else throw new RuntimeException();
                if (cd > INF) cd = INF;
            }
            dist = cd;
            for (Node nn : adj) nn.dfs(this, cd);
        }
    }

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int[][] d = new int[n][n];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                d[i][j] = in.nextInt();
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if ((d[i][j] == 0) ^ (i == j)) {
                    out.println("NO");
                    return;
                }
                if (d[i][j] != d[j][i]) {
                    out.println("NO");
                    return;
                }
            }
        }

        int[] depth = new int[n];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i != j) {
                    if (d[i][j] + d[j][0] == d[i][0]) {
                        ++depth[i];
                    }
                }
            }
        }

        int[] parent = new int[n];
        int[] parentEdge = new int[n];
        Arrays.fill(parent, -1);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i != j) {
                    if (d[i][j] + d[j][0] == d[i][0] && depth[i] == depth[j] + 1) {
                        parent[i] = j;
                        parentEdge[i] = d[i][j];
                    }
                }
            }
            if ((i == 0) ^ (parent[i] == -1)) {
                out.println("NO");
                return;
            }
        }

        Node[] nodes = new Node[n];
        for (int i = 0; i < n; ++i) {
            nodes[i] = new Node();
        }

        for (int i = 1; i < n; ++i) {
            nodes[i].adj.add(nodes[parent[i]]);
            nodes[parent[i]].adj.add(nodes[i]);
            nodes[i].parent = nodes[parent[i]];
            nodes[i].parentEdge = parentEdge[i];
        }

        for (int j = 0; j < n; ++j) {
            Node start = nodes[j];
            for (Node nn : nodes) nn.dist = -1;
            start.dfs(null, 0);
            for (int i = 0; i < n; ++i)
                if (nodes[i].dist != d[i][j]) {
                    out.println("NO");
                    return;
                }
        }

        out.println("YES");
    }
}

class InputReader {
    private final BufferedReader reader;
    private StringTokenizer tokenizer;

    public InputReader(InputStream stream) {
        reader = new BufferedReader(new InputStreamReader(stream));
        tokenizer = null;
    }

    public String nextLine() {
        try {
            return reader.readLine();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public String next() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(nextLine());
        }
        return tokenizer.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

}