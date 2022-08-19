import java.util.List;
import java.io.InputStreamReader;
import java.io.IOException;
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
    class Vertex {
        List<Vertex> adj = new ArrayList<Vertex>();
        int stackDepth = -1;
        int cyclePos = -1;
        Vertex parent = null;
        int subtreeSize;
        int[] depthProfile;

        public boolean findCycle(int depth) {
            if (depth != stack.size()) throw new RuntimeException();
            if (stackDepth >= 0) {
                if (stackDepth == depth - 2)
                    return false;
                for (int i = stackDepth; i < depth; ++i)
                    cycle.add(stack.get(i));
                return true;
            }
            stackDepth = depth;
            stack.add(this);
            for (Vertex v : adj) if (v.findCycle(depth + 1)) return true;
            stack.remove(stack.size() - 1);
            stackDepth = -2;
            return false;
        }

        public void buildTree() {
            subtreeSize = 1;
            for (Vertex v : adj)
                if (v != parent && v.cyclePos < 0) {
                    v.parent = this;
                    v.buildTree();
                    subtreeSize += v.subtreeSize;
                }
        }

        public double buildOneTreeAnswers() {
            double res = 0;
            int maxDepth = 0;
            for (Vertex v : adj) {
                if (v != parent && v.cyclePos < 0) {
                    res += v.buildOneTreeAnswers();
                    maxDepth = Math.max(maxDepth, v.depthProfile.length);
                }
            }
            depthProfile = new int[maxDepth + 1];
            ++depthProfile[0];
            for (Vertex v : adj) {
                if (v != parent && v.cyclePos < 0) {
                    for (int oldDepth = 1; oldDepth <= v.depthProfile.length; ++oldDepth)
                        for (int newDepth = 0; newDepth <= maxDepth; ++newDepth) {
                            res += simpleProb(oldDepth + newDepth) * depthProfile[newDepth] * v.depthProfile[oldDepth - 1];
                        }
                    for (int oldDepth = 1; oldDepth <= v.depthProfile.length; ++oldDepth)
                        depthProfile[oldDepth] += v.depthProfile[oldDepth - 1];
                    v.depthProfile = null;
                }
            }
            return res;
        }
    }

    private double simpleProb(int dist) {
        if (dist == 0) throw new RuntimeException();
        return 2.0 / (dist + 1);
    }

    List<Vertex> stack = new ArrayList<Vertex>();
    List<Vertex> cycle = new ArrayList<Vertex>();

	public void solve(int testNumber, InputReader in, PrintWriter out) {
        int n = in.nextInt();
        Vertex[] v = new Vertex[n];
        for (int i = 0; i < n; ++i) {
            v[i] = new Vertex();
        }
        for (int i = 0; i < n; ++i) {
            Vertex a = v[in.nextInt()];
            Vertex b = v[in.nextInt()];
            a.adj.add(b);
            b.adj.add(a);
        }
        v[0].findCycle(0);
        for (int i = 0; i < cycle.size(); ++i) {
            cycle.get(i).cyclePos = i;
        }
        for (Vertex vv : cycle)
            vv.buildTree();
        double res = n;
        for (Vertex vv : cycle)
            res += vv.buildOneTreeAnswers();
        for (int i = 0; i < cycle.size(); ++i) {
            for (int j = i + 1; j < cycle.size(); ++j) {
                int[] dpi = cycle.get(i).depthProfile;
                int[] dpj = cycle.get(j).depthProfile;
                for (int di = 0; di < dpi.length; ++di)
                    for (int dj = 0; dj < dpj.length; ++dj)
                        res += complexProb(j - i, cycle.size() - (j - i), di, dj) * dpi[di] * dpj[dj];
            }
        }
        out.println(res);
	}

    private double complexProb(int cycleA, int cycleB, int tree1, int tree2) {
        return 2.0 / (cycleA + tree1 + tree2 + 1) + 2.0 / (cycleB + tree1 + tree2 + 1) - 2.0 / (cycleA + cycleB + tree1 + tree2);
    }
}

class InputReader {
    private BufferedReader reader;
    private StringTokenizer tokenizer;

    public InputReader(InputStream stream) {
        reader = new BufferedReader(new InputStreamReader(stream));
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