import java.util.List;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.ArrayList;
import java.util.Comparator;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Random;
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
		TaskB solver = new TaskB();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskB {
    static class Node {
        int v;
        boolean visible = false;
        List<Node> adj = new ArrayList<Node>(1);
        Node parent;
        int size = 1;

        Node getRoot() {
            Node root = this;
            while (root.parent != null) root = root.parent;
            Node cur = this;
            while (cur.parent != null) {
                Node tmp = cur.parent;
                cur.parent = root;
                cur = tmp;
            }
            return root;
        }
    }

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        int m = in.nextInt();
        Node[] nodes = new Node[n];
        for (int i = 0; i < n; ++i) {
            nodes[i] = new Node();
            nodes[i].v = in.nextInt();
        }
        for (int i = 0; i < m; ++i) {
            int a = in.nextInt() - 1;
            int b = in.nextInt() - 1;
            nodes[a].adj.add(nodes[b]);
            nodes[b].adj.add(nodes[a]);
        }
        Random random = new Random(43745435431L);
        for (int i = 0; i < n; ++i) {
            int j = i + random.nextInt(n - i);
            Node t = nodes[i];
            nodes[i] = nodes[j];
            nodes[j] = t;
        }
        Arrays.sort(nodes, new Comparator<Node>() {
            @Override
            public int compare(Node o1, Node o2) {
                return o2.v - o1.v;
            }
        });
        double res = 0;
        for (Node node : nodes) {
            node.visible = true;
            Node root = node.getRoot();
            for (Node other : node.adj) if (other.visible) {
                Node otherRoot = other.getRoot();
                if (otherRoot != root) {
                    otherRoot.parent = root;
                    res += (double) otherRoot.size * root.size * node.v;
                    root.size += otherRoot.size;
                }
            }
        }
        res /= (double) n * (n - 1) / 2.0;
        out.printf("%.10f\n", res);
    }
}

class InputReader {
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